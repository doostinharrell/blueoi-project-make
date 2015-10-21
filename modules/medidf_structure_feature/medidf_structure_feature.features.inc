<?php
/**
 * @file
 * medidf_structure_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function medidf_structure_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function medidf_structure_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function medidf_structure_feature_image_default_styles() {
  $styles = array();

  // Exported image style: catalog_term_image.
  $styles['catalog_term_image'] = array(
    'label' => 'catalog_term_image',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 238,
          'height' => 238,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function medidf_structure_feature_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('Use this content type to add a banner image to the home page .'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'bracelets' => array(
      'name' => t('Bracelets'),
      'base' => 'node_content',
      'description' => t('Bracelets with options of plates, engraving and donation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'engraving' => array(
      'name' => t('Engraving'),
      'base' => 'node_content',
      'description' => t('Custom line item for engraving plates.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'plate' => array(
      'name' => t('Plate'),
      'base' => 'node_content',
      'description' => t('Plates with engraving.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Products other than bracelets, plates or engraving.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function medidf_structure_feature_weight_features_default_settings() {
  $settings = array();

  $settings['banner'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
