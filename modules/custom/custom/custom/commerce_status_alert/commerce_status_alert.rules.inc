<?php

/**
 * @file
 * Provides rules hooks for commerce_status_alert
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_status_alert_rules_action_info() {
  return array(
    'commerce_status_alert_load_orders' => array(
      'label' => t('Load paid order with an incorrect status'),
      'group' => t('Commerce Order'),
      'provides' => array(
        'orders' => array(
          'type' => 'list<commerce_order>',
          'label' => t('Commerce Orders'),
        ),
      ),
    ),
  );
}

/**
 * Action callback for loading paid orders with incorrect status.
 */
function commerce_status_alert_load_orders() {
  $orders = array();
  $statuses = array_keys(commerce_order_commerce_order_status_info());
  $sql = "SELECT o.order_id FROM `commerce_payment_transaction` cpt
    INNER JOIN commerce_order o ON cpt.order_id = o.order_id
    WHERE cpt.status != 'failure'
    AND o.status NOT IN ('" . implode('\',\'', $statuses) . "')";
  $query = db_query($sql);
  $order_ids = $query->fetchAssoc();
  if (!empty($order_ids)) {
    foreach($order_ids as $order_id) {
      $orders[] = commerce_order_load($order_id);
    }
  }
  return array('orders' => $orders);
}
