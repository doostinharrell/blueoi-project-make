<?php
/**
 * @file
 * Provides rules integration for medicalidfashions_engraving.
 */

/**
 * Implements hook_rules_condition_info().
 */
function medicalidfashions_engraving_rules_condition_info() {
  $info = array();
  $info['medicalidfashions_engraving_free_plate_and_engraving'] = array(
    'label' => t('Check for free plate and engraving'),
    'description' => t('Checks for products on the order that should be allow a free plate and engraving'),
    'group' => t('Medical ID Fashions'),
    'parameter' => array(
      'line_item' => array(
        'label' => t('Line Item'),
        'type' => 'commerce_line_item',
        'wrapped' => TRUE,
      ),
    ),
  );
  return $info;
}

/**
 * Rules condition to determine if a line item for engraving or plate
 * should be free.
 */
function medicalidfashions_engraving_free_plate_and_engraving($source_wrapper) {
  $order = commerce_order_load($source_wrapper->order_id->value());

  // Load a count of free items that should be available.
  $free_items = medicalidfashions_engraving_count_free_plate_and_engraving_items($order);

  // Keep a static count of awarded items.
  $awarded_items = &drupal_static(__FUNCTION__, array());

  if ($source_wrapper->type->value() == 'engraving' && $free_items >= $awarded_items['engraving'] + 1) {
    $awarded_items['engraving']++;
    return TRUE;
  }

  try {
    if ($source_wrapper->commerce_product->type->value() == 'plates' && $free_items >= $awarded_items['plate'] + 1) {
      $awarded_items['plate']++;
      return TRUE;
    }
  }
  catch (EntityMetadataWrapperException $ex) {}

  return FALSE;
}
