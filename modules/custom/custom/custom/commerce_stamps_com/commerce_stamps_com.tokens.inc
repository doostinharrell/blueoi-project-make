<?php

/**
 * @file
 * Defines stamps.com related tokens
 */

/**
 * Implements hook_token_info_alter().
 */
function commerce_stamps_com_token_info_alter(&$data) {
  $data['tokens']['commerce-order']['commerce_stamps_com_tracking_numbers'] = array(
    'name' => t('Stamps.com tracking numbers'),
    'description' => t('Stamps.com tracking numbers from an order'),
  );
}

/**
 * Implements hook_tokens().
 */
function commerce_stamps_com_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'commerce_stamps_com_tracking_numbers':
          $tracking_numbers = commerce_stamps_com_tracking_numbers($data['commerce-order']);
          $replacements[$original] = $tracking_numbers;
          break;
      }
    }
  }
  return $replacements;
}

/**
 *  Callback for providing a string of Stamps.com tracking numbers.
 */
function commerce_stamps_com_tracking_numbers($order) {
  $tracking_numbers = array();
  if (!empty($order->data['stamps_com'])) {
    foreach ($order->data['stamps_com'] as $indicium) {
      if (empty($indicium->status) || $indicium->status != 'canceled') {
        $tracking_number = $indicium->TrackingNumber;
        $tracking_numbers[] = $tracking_number . ' | Track: ' . COMMERCE_STAMPS_COM_USPS_TRACK_URL  . $tracking_number;
      }
    }
  }
  return implode('<br />', $tracking_numbers);
}
