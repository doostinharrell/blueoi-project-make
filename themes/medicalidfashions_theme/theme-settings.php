<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function medicalidfashions_theme_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['zurb_foundation']['medidf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Medical ID Fashion Settings'),
    'google' => array(
      '#type' => 'textfield',
      '#title' => t('Google+ URL'),
      '#default_value'=> theme_get_setting('google'),
    ),
    'twitter' => array(
      '#type' => 'textfield',
      '#title' => t('Twitter URL'),
      '#default_value'=> theme_get_setting('twitter'),
    ),
    'facebook' => array(
      '#type' => 'textfield',
      '#title' => t('Facebook URL'),
      '#default_value'=> theme_get_setting('facebook'),
    ),
    'pinterest' => array(
      '#type' => 'textfield',
      '#title' => t('Pinterest URL'),
      '#default_value'=> theme_get_setting('pinterest'),
    ),
    'phone' => array(
      '#type' => 'textfield',
      '#title' => t('Phone Number'),
      '#default_value'=> theme_get_setting('phone'),
    ),
  );

}
