<?php
/**
 * @file
 * medidf_structure_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function medidf_structure_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'store_category_pages';
  $context->description = 'This context will be displayed on specific category pages.';
  $context->tag = 'store';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'store_catalog_lists' => 'store_catalog_lists',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-store_catalog_grid-block_1' => array(
          'module' => 'views',
          'delta' => 'store_catalog_grid-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context will be displayed on specific category pages.');
  t('store');
  $export['store_category_pages'] = $context;

  return $export;
}
