<?php

/**
 * @file
 * Defines additional tokens for order email.
 */

/**
 * Implements hook_token_info_alter().
 */
function commerce_extra_tokens_token_info_alter(&$data) {
  $data['tokens']['commerce-order']['commerce_extra_tokens_line_items'] = array(
    'name' => t('Commerce extra tokens line items'),
    'description' => t('A table containing line items of the commerce order.'),
  );
  $data['tokens']['commerce-order']['commerce_extra_tokens_total'] = array(
    'name' => t('Commerce extra tokens order total'),
    'description' => t('A table containing the totals and taxes of the commerce order.'),
  );
  $data['tokens']['commerce-order']['commerce_extra_tokens_payments'] = array(
    'name' => t('Commerce extra tokens payments'),
    'description' => t('A table containing the payment transactions on the order.'),
  );
}

/**
 * Implements hook_tokens().
 */
function commerce_extra_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'commerce_extra_tokens_line_items':
          $order_items = commerce_extra_tokens_line_items($data['commerce-order']);
          $replacements[$original] = $order_items;
          break;
        case 'commerce_extra_tokens_total':
          $order_items = commerce_extra_tokens_total($data['commerce-order']);
          $replacements[$original] = $order_items;
          break;
        case 'commerce_extra_tokens_payments':
          $order_items = commerce_extra_tokens_payments($data['commerce-order']);
          $replacements[$original] = $order_items;
          break;
      }
    }
  }
  return $replacements;
}
