<?php

/*
 * @file: Provides the admin settings for stamps.com integration.
 */

/**
 * Form builder function for module settings.
 *
 * @return string
 *   Drupal form for Stamps.com settings
 */
function commerce_stamps_com_settings_form() {
  $form = array();
  $form['auth'] = array(
    '#title' => t('Stamps.com authentication settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => variable_get('commerce_stamps_com_integration_id', NULL) ? TRUE : FALSE,
  );
  $form['auth']['commerce_stamps_com_integration_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Stamps.com integration id'),
    '#default_value' => variable_get('commerce_stamps_com_integration_id', NULL),
    '#required' => TRUE,
  );
  $form['auth']['commerce_stamps_com_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Stamps.com username'),
    '#default_value' => variable_get('commerce_stamps_com_username', NULL),
    '#required' => TRUE,
  );
  $form['auth']['commerce_stamps_com_password'] = array(
    '#type' => 'password',
    '#title' => t('Stamps.com password'),
  );
  // Check to see if the password has been set already.
  if (!variable_get('commerce_stamps_com_password')) {
    $form['auth']['commerce_stamps_com_password']['#required'] = TRUE;
  }
  else {
    $form['auth']['commerce_stamps_com_password']['#description'] = t('Only enter your Stamps.com password if you want to change it from what is already stored.');
  }
  $form['auth']['commerce_stamps_com_server'] = array(
    '#type' => 'select',
    '#title' => t('Stamps.com servers'),
    '#description' => t('Select if you would like to use the Stamps.com testing or productions servers.'),
    '#default_value' => variable_get('commerce_stamps_com_server', 'testing'),
    '#options' => array(
      'testing' => t('Testing'),
      'production' => t('Production'),
    ),
  );
  $form['auth']['commerce_stamps_com_indicium'] = array(
    '#type' => 'select',
    '#title' => t('Indicium'),
    '#description' => t('Real indiciums will generate a charge on the Stamps.com account. Use test indiciums when testing your configuration.'),
    '#default_value' => variable_get('commerce_stamps_com_indicium', 'test'),
    '#options' => array(
      'test' => t('Test'),
      'real' => t('Real'),
    ),
  );
  $form['services'] = array(
    '#title' => t('Stamps.com shipping services'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => variable_get('commerce_stamps_com_shipping_services', NULL) ? TRUE : FALSE,
  );
  $form['services']['commerce_stamps_com_shipping_services'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Stamps.com services'),
    '#default_value' => variable_get('commerce_stamps_com_shipping_services', array()),
    '#options' => _commerce_stamps_com_shipping_services(),
  );
  $form['origin'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ship From Address'),
    '#collapsible' => TRUE,
    '#collapsed' => variable_get('commerce_stamps_com_address_line_1', NULL) ? TRUE : FALSE,
  );
  $form['origin']['commerce_stamps_com_company_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Company Name'),
    '#default_value' => variable_get('commerce_stamps_com_company_name'),
  );
  $form['origin']['commerce_stamps_com_address_line_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_address_line_1'),
  );
  $form['origin']['commerce_stamps_com_address_line_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address (Additional)'),
    '#default_value' => variable_get('commerce_stamps_com_address_line_2'),
  );
  $form['origin']['commerce_stamps_com_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_city'),
  );
  $form['origin']['commerce_stamps_com_state'] = array(
    '#type' => 'textfield',
    '#title' => t('State or Province'),
    '#default_value' => variable_get('commerce_stamps_com_state'),
    '#size' => 2,
    '#maxlength' => 2,
  );
  $form['origin']['commerce_stamps_com_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Code'),
    '#size' => 5,
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_postal_code'),
  );
  $form['origin']['commerce_stamps_com_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone Number'),
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_phone'),
  );
  $form['packaging'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stamps.com Packaging'),
    '#collapsible' => TRUE,
    '#collapsed' => variable_get('commerce_stamps_com_default_package') ? TRUE : FALSE,
  );
  $form['packaging']['commerce_stamps_com_default_package'] = array(
    '#type' => 'select',
    '#title' => t('Package type'),
    '#options' => _commerce_stamps_com_packages(),
    '#default_value' => variable_get('commerce_stamps_com_default_package', 'Package'),
  );
  $form['packaging']['default_package_size'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );
  $form['packaging']['default_package_size']['commerce_stamps_com_default_package_size_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Length'),
    '#size' => 5,
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_default_package_size_length'),
  );
  $form['packaging']['default_package_size']['commerce_stamps_com_default_package_size_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#size' => 5,
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_default_package_size_width'),
  );
  $form['packaging']['default_package_size']['commerce_stamps_com_default_package_size_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#size' => 5,
    '#required' => TRUE,
    '#default_value' => variable_get('commerce_stamps_com_default_package_size_height'),
  );
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Stamps.com Options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['options']['commerce_stamps_com_addons'] = array(
    '#type' => 'checkboxes',
    '#options' => _commerce_stamps_com_addons(),
    '#title' => t('Stamps.com rate add ons'),
    '#default_value' => variable_get('commerce_stamps_com_addons', array()),
  );
  $form['options']['commerce_stamps_com_phone_field'] = array(
    '#type' => 'select',
    '#title' => t('Customer profile phone number field'),
    '#options' => array(0 => t('Select')) +  _commerce_stamps_com_phone_field_names(),
    '#default_value' => variable_get('commerce_stamps_com_phone_field', array()),
    '#description' => t('International shipping requires a phone number. Add a text field to your customer shipping profile and select it here.'),
  );
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 40,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Stamps.com settings'),
  );
  return $form;
}

function commerce_stamps_com_settings_form_validate($form, &$form_state) {
  // Only attempt the validation if other form validation passes.1`
  if (form_get_errors() == FALSE) {
    $integration_id = $form_state['values']['commerce_stamps_com_integration_id'];
    $username = $form_state['values']['commerce_stamps_com_username'];
    // Retrieve the password either from the form state or from a saved variable.
    $password = !empty($form_state['values']['commerce_stamps_com_password']) ? $form_state['values']['commerce_stamps_com_password'] : variable_get('commerce_stamps_com_password');
    $server = $form_state['values']['commerce_stamps_com_server'];
    // Attempt to validate with Stamps.com to validate the values.
    if (commerce_stamps_com_authenticate($integration_id, $username, $password, $server) == FALSE) {
      form_set_error('auth', t('The Stamps.com credentials that you entered did not authenticate with the <strong>@server</strong> server.', array('@server' => $form_state['values']['commerce_stamps_com_server'])));
    }
    else {
      drupal_set_message(t('Stamps.com authentication successfull'));
    }
  }
}

/**
 * Submit handler: Saves the Stamps.com settings
 */
function commerce_stamps_com_settings_form_submit($form, &$form_state) {
  $services = variable_get('commerce_stamps_com_shipping_services', NULL);
  foreach (_commerce_stamps_com_variables() as $variable) {
    // Do not attempt to save the password field if it is empty.
    if ($variable == 'commerce_stamps_com_password' && empty($form_state['values'][$variable])) {
      continue;
    }
    variable_set($variable, $form_state['values'][$variable]);
  }
  // If the selected services have changed then rebuild caches.
  if ($services !== $form_state['values']['commerce_stamps_com_shipping_services']) {
    commerce_shipping_services_reset();
    entity_defaults_rebuild();
    rules_clear_cache(TRUE);
    menu_rebuild();
  }
  drupal_set_message(t('The Stamps.com configuration options have been saved.'));
}
