<?php

/**
 * Implements hook_rules_event_info().
 */
function medidf_rules_rules_event_info() {
  return array(
    'customer_views_cart' => array(
      'label' => t('Customer is viewing shopping cart'),
      'group' => t('Medical ID Fashions'),
      'variables' => array(
        'commerce_order' => array(
          'label' => t('Commerce Order'),
          'type' => 'commerce_order',
        ),
      ),
    ),
    'customer_views_checkout' => array(
      'label' => t('Customer views checkout page'),
      'group' => t('Medical ID Fashions'),
      'variables' => array(
        'commerce_order' => array(
          'label' => t('Commerce Order'),
          'type' => 'commerce_order',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function medidf_rules_rules_condition_info() {
  $conditions = array();
  $conditions['order_contains_product_type'] = array(
    'label' => t('Order contains product by type'),
    'group' => t('Medical ID Fashions'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
      'type' => array(
        'type' => 'text',
        'label' => t('Product Type'),
      ),
    ),
  );

  $conditions['order_contains_line_item_type'] = array(
    'label' => t('Order contains line item type'),
    'group' => t('Medical ID Fashions'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
      'type' => array(
        'type' => 'text',
        'label' => t('Product Type'),
      ),
    ),
  );

  $conditions['order_contains_line_item_label_match'] = array(
    'label' => t('Order contains line item with matching label'),
    'group' => t('Medical ID Fashions'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
      'label' => array(
        'type' => 'text',
        'label' => t('Label'),
      ),
    ),
  );

  $conditions['order_contains_equal_plates_and_engravings'] = array(
    'label' => t('Order contains equal number of plates and engravings'),
    'group' => t('Medical ID Fashions'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
    ),
  );

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function medidf_rules_rules_action_info() {
  return array(
    'load_avaialable_special_offers' => array(
      'label' => t('Load available special offers'),
      'group' => t('Medical ID Fashions'),
      'parameter' => array(
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('Commerce Order'),
        ),
      ),
      'provides' => array(
        'special_offers' => array(
          'type' => 'list<commerce_product>',
          'label' => t('Special Offers'),
        ),
      ),
    ),
    'load_product_display_node' => array(
      'label' => t('Load product display node'),
      'group' => t('Medical ID Fashions'),
      'parameter' => array(
        'commerce_product' => array(
          'type' => 'commerce_product',
          'label' => t('Commerce Product'),
        ),
      ),
      'provides' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('node'),
        ),
      ),
    ),
  );

}
/**
 * Check to see if order contains product line item by type.
 */
function order_contains_product_type($order, $type) {
  if (!empty($order->commerce_line_items)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
      if (!empty($line_item_wrapper->commerce_product)) {
        if ($line_item_wrapper->commerce_product->type->value() == trim($type)) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

/**
 * Check to see if order contains line items by passed in type.
 */
function order_contains_line_item_type($order, $type) {
  if (!empty($order->commerce_line_items)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    foreach ($order_wrapper->commerce_line_items->value() as $line_item) {
      if ($line_item->type == trim($type)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Checks to see if a line item's title matches the passed in label.
 */
function order_contains_line_item_label_match($order, $label) {
  if (!empty($order->commerce_line_items)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    foreach ($order_wrapper->commerce_line_items->value() as $line_item) {
      if (stristr($line_item->line_item_label, $label)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Rules condition to make sure number of plates and engravings is equal.
 */
function order_contains_equal_plates_and_engravings($order) {
  if (!empty($order->commerce_line_items)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $plates = 0;
    $engravings = 0;

    foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
      if (!empty($line_item_wrapper->value()->commerce_product) && $line_item_wrapper->commerce_product->value()->type == 'plates') {
        $plates++;
      }

      if ($line_item_wrapper->value()->type == 'engraving') {
        $engravings++;
      }
    }

    // If there is an equal number
    if (($engravings + $plates == 0) || ($engravings == $plates)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Rules action to load available special offers on an order.
 */
function load_avaialable_special_offers($order) {
  $special_offers = array();
  if (!empty($order->commerce_line_items)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
      if (!empty($line_item_wrapper->value()->commerce_product)) {
        $product = $line_item_wrapper->commerce_product->value();
        if (!empty($product->field_special_offers)) {
          $offers = $line_item_wrapper->commerce_product->field_special_offers->value();
          foreach($offers as $offer) {
            $special_offers[$offer->product_id] = $offer;
          }
        }
      }
    }
  }
  return array('special_offers' => $special_offers);
}

/**
 * Rules action to load a products display node.
 *   Limited to product node bundle and 1 display node.
 */
function load_product_display_node($product) {
  $node = array();
  $efq = new EntityFieldQuery();
  $results = $efq->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'product')
  ->fieldCondition('field_product', 'product_id', $product->product_id)
  ->execute();
  if (!empty($results['node'])) {
    $nid = reset($results['node']);
    $node = node_load($nid->nid);
  }
  return array('node' => $node);
}
