<?php

/**
 * @file: Provides custom rules integration for commerce_stamps_com
 */

/**
 *  Implements hook_rules_condition_info().
 */
function commerce_stamps_com_rules_condition_info() {
  return array(
    'commerce_stamps_com_order_has_tracking_numbers' => array(
      'label' => t('Order contains stamps.com tracking numbers'),
      'group' => t('Stamps.com'),
      'parameter' => array(
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),
          ),
        ),
      ),
    );
}

/**
 *  Implements hook_rules_action_info().
 */
function commerce_stamps_com_rules_action_info() {
  return array(
    'commerce_stamps_com_order_get_tracking_numbers' => array(
      'label' => t('Stamps.com Get Tracking Numbers'),
      'group' => t('Stamps.com'),
      'parameter' => array(
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),
          ),
        ),
      'provides' => array(
        'tracking_numbers' => array(
          'label' => t('Tracking Numbers'),
          'type' => 'list<text>',
          ),
        ),
      ),
    );
}

function commerce_stamps_com_order_has_tracking_numbers($order) {
  $tracking_numbers = array();
  if (!empty($order->data['stamps_com'])) {
    foreach ($order->data['stamps_com'] as $indicium) {
      if (!empty($indicium->TrackingNumber)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

function commerce_stamps_com_order_get_tracking_numbers($order) {
  $tracking_numbers = array();
  if (!empty($order->data['stamps_com'])) {
    foreach ($order->data['stamps_com'] as $indicium) {
      $tracking_number = $indicium->TrackingNumber;
      $tracking_numbers[] = $tracking_number . ' | Track: ' . COMMERCE_STAMPS_COM_USPS_TRACK_URL  . $tracking_number;
    }
  }
  return array('tracking_numbers' => $tracking_numbers);
}
