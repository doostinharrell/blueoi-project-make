<?php

/**
 * Implements template_preprocess_page().
 */
function medicalidfashions_theme_preprocess_page(&$variables) {
  $google = theme_get_setting('google');
  $facebook = theme_get_setting('facebook');
  $twitter = theme_get_setting('twitter');
  $pinterest = theme_get_setting('pinterest');
  $phone = theme_get_setting('phone');
  $social_media = '';
  $links = '';
  $options = array(
    'attributes' => array(),
    'html' => TRUE,
  );
  if ($google != '') {
    $social_media .= l('<i class="fa fa-google-plus"></i>', $google, $options);
  }
  if ($facebook != '') {
    $social_media .= l('<i class="fa fa-facebook"></i>', $facebook, $options);
  }
  if ($twitter != '') {
    $social_media .= l('<i class="fa fa-twitter"></i>', $twitter, $options);
  }
  if ($pinterest != '') {
    $social_media .= l('<i class="fa fa-pinterest"></i>', $pinterest, $options);
  }
  if ($phone != '') {
    $phone = '<i class="fa fa-phone"></i> ' . $phone;
    $phone_render = l($phone, 'tel:'.$phone, $options);
  }
  if ($variables['user']->uid == 0) {
    $links = '<i class="fa fa-user"></i> Login / Register';
  }
  else {
    $links = '<i class="fa fa-user"></i> My Account';
  }
  $links_render = l($links, 'user', $options);
  $variables['social_media'] = $social_media;
  $variables['phone'] = $phone_render;
  $variables['links'] = $links_render;
}


/**
 * Implements hook_form_FORM_ID_alter().
 */
function medicalidfashions_theme_form_search_block_form_alter(&$form, &$form_state) {
  // Place search button before search box.
  $form['actions']['#weight'] = 1;
  $form['search_block_form']['#weight'] = 2;

  // Unset default value, onblur and onfocus values for search box.
  unset($form['search_block_form']['#default_value']);
  unset($form['search_block_form']['#attributes']['onblur']);
  unset($form['search_block_form']['#attributes']['onfocus']);

  // Change search button text to Search.
  $form['actions']['submit']['#value'] = t('Search');

  // Update search button classes.
  $form['actions']['submit']['#attributes']['class'] = array('search-button');

  // Update search form classes.
  $form['#attributes']['class'] = array();
}
