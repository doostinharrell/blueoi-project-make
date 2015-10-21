<?php

/**
 * @file: Provides rules extensions for medicalidfashions PAP integration.
 */


/**
 * Implements hook_rules_condition_info().
 */
function medicalidfashions_pap_rules_condition_info() {
  return array(
    'medicalidfashions_pap_rules_affiliate_id_match' => array(
      'label' => t('Affiliate ID Match'),
      'group' => t('Post Affiliate Pro'),
      'parameter' => array(
        'affiliate_id' => array(
          'type' => 'text',
          'label' => t('Affiliate ID'),
        ),
      ),
    ),
  );
}
/**
 * Implements hook_rules_action_info().
 */
function medicalidfashions_pap_rules_action_info() {
  return array(
    'medicalidfashions_pap_rules_sales_notify' => array(
      'label' => t('Notify PAP of product sales'),
      'group' => t('Commerce Order'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Commerce Order'),
        ),
      ),
    ),
  );
}

/**
 * Rules condition to match affiliate ID.
 */
function medicalidfashions_pap_rules_affiliate_id_match($affiliate_id) {
  // Check the session variable.
  if (!empty($_SESSION['aff_flag']) && $_SESSION['aff_flag'] == $affiliate_id) {
    return TRUE;
  }

  // Check the cookie variable
  if (!empty($_COOKIE['aff_flag']) && $_COOKIE['aff_flag'] == $affiliate_id) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Rules action to notify Post Affiliate Pro.
 */
function medicalidfashions_pap_rules_sales_notify($commerce_order) {
  $account_id = variable_get('commerce_post_affiliate_pro_merchant_id', NULL);
  if (!$account_id) {
    watchdog('commerce_post_affiliate_pro', 'Could not register sale for order @order, merchant id is not set, please visit admin pages.', array('@order' => $commerce_order->order_id));
    return;
  }
  $order_wrapper = entity_metadata_wrapper('commerce_order', $commerce_order);
  $amount = 0;
  foreach ($order_wrapper->commerce_line_items as $line_item_wrapper) {
    $line_item = $line_item_wrapper->value();
    if ($line_item->type == 'product') {
      $amount += $line_item_wrapper->commerce_total->amount->value();
    }
  }

  // If the orders shipping address is IL
  if ($order_wrapper->commerce_customer_shipping->commerce_customer_address->administrative_area->value() == 'IL') {
    // Load the IL tax rate.
    $il_tax = commerce_tax_rate_load('illinois_state_sales_tax');
    if (!empty($il_tax['rate'])){
      // Deduct the tax rate from the amount.
      $amount -= $amount * $il_tax['rate'];
    }
  }

  $path = libraries_get_path('pap');
  require_once($path . '/PapApi.class.php');
  module_load_include('php', 'commerce_post_affiliate_pro', 'DrupalPapApi.class');

  $sale_tracker = new Pap_Api_SaleTracker(variable_get('commerce_post_affiliate_pro_merchant_url_prefix', 'http://demo.qualityunit.com/pax4/'). "scripts/sale.php");

  $sale_tracker->setAccountId($account_id);

  $sale = $sale_tracker->createSale();
  $sale->setTotalCost(commerce_currency_amount_to_decimal($amount, commerce_default_currency()));
  $sale->setOrderID($commerce_order->order_id);

  $result = $sale_tracker->register();
  watchdog('commerce_post_affiliate_pro', 'Result: sale registration for order @order: @result', array('@order' => $commerce_order->order_id, '@result' => $result));
}
