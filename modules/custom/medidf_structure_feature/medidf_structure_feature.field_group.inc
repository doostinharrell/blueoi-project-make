<?php
/**
 * @file
 * medidf_structure_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function medidf_structure_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bracelet|node|product|default';
  $field_group->group_name = 'group_bracelet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bracelets';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'field_productref',
      1 => 'field_plate_view',
      2 => 'product:field_inch_pricing',
      3 => 'product:field_fractions_pricing',
      4 => 'product:field_plate_option',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => ' group-bracelet field-group-fieldset',
        'description' => '<strong>Select Your Exact Wrist Size: *</strong><br>
In first box select your wrist size whole number.<br>
In the 2nd box select the fraction (if any).',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bracelet|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bracelet|node|product|form';
  $field_group->group_name = 'group_bracelet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bracelets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bracelet',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_productref',
      2 => 'field_image',
      3 => 'field_category',
      4 => 'field_short_description',
      5 => 'field_similar_color',
      6 => 'field_similar_style',
      7 => 'field_similar_colors',
      8 => 'field_similar_styles',
      9 => 'field_associated_bracelets',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bracelet',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-bracelet field-group-fieldset',
        'description' => 'Enter / select the bracelet information.
',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bracelet|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_engraving|node|plate|default';
  $field_group->group_name = 'group_engraving';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'plate';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Add Engraving',
    'weight' => '7',
    'children' => array(
      0 => 'field_engraveref',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-engraving field-group-hidden',
      ),
    ),
  );
  $export['group_engraving|node|plate|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured|node|product|form';
  $field_group->group_name = 'group_featured';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bracelets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured',
    'weight' => '3',
    'children' => array(
      0 => 'field_featured_large_image',
      1 => 'field_featured_large',
      2 => 'field_featured_medium',
      3 => 'field_featured_medium_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-featured field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_featured|node|product|form'] = $field_group;

  return $export;
}
