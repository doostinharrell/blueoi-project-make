<?php
/**
 * @file
 * medidf_page_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function medidf_page_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit__bracelets';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Bracelets',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'bracelets',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'bracelets' => 'bracelets',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '51a0b334-f608-44be-a1aa-01d84983df3c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3a52905d-1b43-412c-a395-3ca5832b7788';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3a52905d-1b43-412c-a395-3ca5832b7788';
    $display->content['new-3a52905d-1b43-412c-a395-3ca5832b7788'] = $pane;
    $display->panels['middle'][0] = 'new-3a52905d-1b43-412c-a395-3ca5832b7788';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit__bracelets'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__bracelets';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Bracelets',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Product Reference',
        'keyword' => 'commerce_product',
        'name' => 'entity_from_field:field_productref-node-commerce_product',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'bracelets',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'bracelets' => 'bracelets',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'medidf_bracelet';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'above_left' => NULL,
      'above_right' => NULL,
      'below_left' => NULL,
      'below_right' => NULL,
      'bottom' => NULL,
      'medidf_top' => NULL,
      'm_top' => NULL,
      'm_mid_left' => NULL,
      'm_mid_right' => NULL,
      'm_btm' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fb5149c9-3eee-4594-bcd2-50b365cfb4fb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-88f6f915-95b9-4980-bf9a-c0516843f318';
    $pane->panel = 'm_btm';
    $pane->type = 'views';
    $pane->subtype = 'associated_bracelets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '88f6f915-95b9-4980-bf9a-c0516843f318';
    $display->content['new-88f6f915-95b9-4980-bf9a-c0516843f318'] = $pane;
    $display->panels['m_btm'][0] = 'new-88f6f915-95b9-4980-bf9a-c0516843f318';
    $pane = new stdClass();
    $pane->pid = 'new-eac4f06d-95ff-4b9d-9c49-2cf70c22db51';
    $pane->panel = 'm_mid_left';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:product:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eac4f06d-95ff-4b9d-9c49-2cf70c22db51';
    $display->content['new-eac4f06d-95ff-4b9d-9c49-2cf70c22db51'] = $pane;
    $display->panels['m_mid_left'][0] = 'new-eac4f06d-95ff-4b9d-9c49-2cf70c22db51';
    $pane = new stdClass();
    $pane->pid = 'new-dede4274-563a-4369-8d6c-71a617de680b';
    $pane->panel = 'm_mid_left';
    $pane->type = 'views';
    $pane->subtype = 'product_pinterest_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dede4274-563a-4369-8d6c-71a617de680b';
    $display->content['new-dede4274-563a-4369-8d6c-71a617de680b'] = $pane;
    $display->panels['m_mid_left'][1] = 'new-dede4274-563a-4369-8d6c-71a617de680b';
    $pane = new stdClass();
    $pane->pid = 'new-13d0551a-cfb1-4d5a-9a9f-ffc45065c620';
    $pane->panel = 'm_mid_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '13d0551a-cfb1-4d5a-9a9f-ffc45065c620';
    $display->content['new-13d0551a-cfb1-4d5a-9a9f-ffc45065c620'] = $pane;
    $display->panels['m_mid_left'][2] = 'new-13d0551a-cfb1-4d5a-9a9f-ffc45065c620';
    $pane = new stdClass();
    $pane->pid = 'new-815ece87-ebe0-4430-84d1-14e4a92f49e3';
    $pane->panel = 'm_mid_left';
    $pane->type = 'views';
    $pane->subtype = 'plate_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '24',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_3',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '815ece87-ebe0-4430-84d1-14e4a92f49e3';
    $display->content['new-815ece87-ebe0-4430-84d1-14e4a92f49e3'] = $pane;
    $display->panels['m_mid_left'][3] = 'new-815ece87-ebe0-4430-84d1-14e4a92f49e3';
    $pane = new stdClass();
    $pane->pid = 'new-406ac202-e5ec-4ecb-b68e-e0325d357447';
    $pane->panel = 'm_mid_right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h4>Select Your Exact Wrist Size:</h4><div>In 1st box select wrist size whole number.</div><div>In 2nd box select the fraction.</div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '406ac202-e5ec-4ecb-b68e-e0325d357447';
    $display->content['new-406ac202-e5ec-4ecb-b68e-e0325d357447'] = $pane;
    $display->panels['m_mid_right'][0] = 'new-406ac202-e5ec-4ecb-b68e-e0325d357447';
    $pane = new stdClass();
    $pane->pid = 'new-b7555561-3563-4789-acda-de7b299527c7';
    $pane->panel = 'm_mid_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_productref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'commerce_cart_add_to_cart_form',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'show_quantity' => 1,
        'default_quantity' => '1',
        'combine' => 1,
        'show_single_product_attributes' => 0,
        'line_item_type' => 'product',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b7555561-3563-4789-acda-de7b299527c7';
    $display->content['new-b7555561-3563-4789-acda-de7b299527c7'] = $pane;
    $display->panels['m_mid_right'][1] = 'new-b7555561-3563-4789-acda-de7b299527c7';
    $pane = new stdClass();
    $pane->pid = 'new-34655808-e7d6-4017-bf75-564278701d8d';
    $pane->panel = 'm_mid_right';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:product:field_inch_pricing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '34655808-e7d6-4017-bf75-564278701d8d';
    $display->content['new-34655808-e7d6-4017-bf75-564278701d8d'] = $pane;
    $display->panels['m_mid_right'][2] = 'new-34655808-e7d6-4017-bf75-564278701d8d';
    $pane = new stdClass();
    $pane->pid = 'new-26e05bfd-0e84-4686-a058-c699432f8c9a';
    $pane->panel = 'm_mid_right';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:product:field_fractions_pricing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '26e05bfd-0e84-4686-a058-c699432f8c9a';
    $display->content['new-26e05bfd-0e84-4686-a058-c699432f8c9a'] = $pane;
    $display->panels['m_mid_right'][3] = 'new-26e05bfd-0e84-4686-a058-c699432f8c9a';
    $pane = new stdClass();
    $pane->pid = 'new-7dc13b61-9fc8-4eb3-bfc3-e3edbf715506';
    $pane->panel = 'm_mid_right';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'node:product:field_free_plate_and_engraving';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '7dc13b61-9fc8-4eb3-bfc3-e3edbf715506';
    $display->content['new-7dc13b61-9fc8-4eb3-bfc3-e3edbf715506'] = $pane;
    $display->panels['m_mid_right'][4] = 'new-7dc13b61-9fc8-4eb3-bfc3-e3edbf715506';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__bracelets'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__default';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0074cd8a-05a2-47c9-8e96-7a68c7a340e1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6c35d6a6-3276-4a57-94c8-691e5b298c1b';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6c35d6a6-3276-4a57-94c8-691e5b298c1b';
    $display->content['new-6c35d6a6-3276-4a57-94c8-691e5b298c1b'] = $pane;
    $display->panels['middle'][0] = 'new-6c35d6a6-3276-4a57-94c8-691e5b298c1b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6c35d6a6-3276-4a57-94c8-691e5b298c1b';
  $handler->conf['display'] = $display;
  $export['node_view__default'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__catalog';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Catalog',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'catalog',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'catalog' => 'catalog',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6e67569a-199f-4750-b958-644b6b3f77e0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-187e14af-8bfc-42cd-a587-46c0f3c42d3a';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'store_catalog_grid';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '187e14af-8bfc-42cd-a587-46c0f3c42d3a';
    $display->content['new-187e14af-8bfc-42cd-a587-46c0f3c42d3a'] = $pane;
    $display->panels['middle'][0] = 'new-187e14af-8bfc-42cd-a587-46c0f3c42d3a';
    $pane = new stdClass();
    $pane->pid = 'new-81be2ca7-9ed6-455a-8529-e87e537c2af6';
    $pane->panel = 'middle';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'taxonomy_term:description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '81be2ca7-9ed6-455a-8529-e87e537c2af6';
    $display->content['new-81be2ca7-9ed6-455a-8529-e87e537c2af6'] = $pane;
    $display->panels['middle'][1] = 'new-81be2ca7-9ed6-455a-8529-e87e537c2af6';
    $pane = new stdClass();
    $pane->pid = 'new-41857cc9-2540-4e87-851f-26072549c232';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'store_catalog_lists';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '51',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '%term:tid',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '41857cc9-2540-4e87-851f-26072549c232';
    $display->content['new-41857cc9-2540-4e87-851f-26072549c232'] = $pane;
    $display->panels['middle'][2] = 'new-41857cc9-2540-4e87-851f-26072549c232';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-81be2ca7-9ed6-455a-8529-e87e537c2af6';
  $handler->conf['display'] = $display;
  $export['term_view__catalog'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function medidf_page_layout_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = '';
  $page->path = 'home-page';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_page__panel_context_7569b2b9-1284-4708-9146-ef36c360abc4';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'foundation_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '17b01912-945a-41fc-805c-ce6c25954809';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-af7db72c-7194-4d26-9ceb-6c5ec2841b96';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h1 style="text-align: center;">Custom sized <span class="label">fashionable</span> medical ID bracelets.</h1><p style="text-align: center;">Over 500 designer medical ID bracelets for all medical conditions...handcrafted in the USA. See our exclusive WaterWear Bracelets&reg; from stylish Stainless Steel to Precious Metals...or step up to high fashion Beaded Bracelets.&nbsp;</p><p style="text-align: center;"><img src="../sites/all/themes/medicalidfashions_theme/images/home-static-banner.jpg" /></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af7db72c-7194-4d26-9ceb-6c5ec2841b96';
    $display->content['new-af7db72c-7194-4d26-9ceb-6c5ec2841b96'] = $pane;
    $display->panels['middle'][0] = 'new-af7db72c-7194-4d26-9ceb-6c5ec2841b96';
    $pane = new stdClass();
    $pane->pid = 'new-148ebd45-b20b-470f-a2d0-1314dc411188';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'store_catalog_grid';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '148ebd45-b20b-470f-a2d0-1314dc411188';
    $display->content['new-148ebd45-b20b-470f-a2d0-1314dc411188'] = $pane;
    $display->panels['middle'][1] = 'new-148ebd45-b20b-470f-a2d0-1314dc411188';
    $pane = new stdClass();
    $pane->pid = 'new-868a5995-6cd1-41dd-aa29-9397f93b40d5';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'store_catalog_lists';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '12',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '868a5995-6cd1-41dd-aa29-9397f93b40d5';
    $display->content['new-868a5995-6cd1-41dd-aa29-9397f93b40d5'] = $pane;
    $display->panels['middle'][2] = 'new-868a5995-6cd1-41dd-aa29-9397f93b40d5';
    $pane = new stdClass();
    $pane->pid = 'new-16a416b0-1e6b-4867-b586-2d4a7ea24d11';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Illness Logos',
      'title' => '',
      'body' => '<div class="row"><div class="columns large-2"><a href="http://shopdiabetes.org/Medical-ID.aspx?loc=header" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/ada.jpg" /></a></div><div class="columns large-2"><a href="https://www.aakp.org/" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/aakp.jpg" /></a></div><div class="columns large-2" style="border-left: 1px solid red"><a href="http://healthcare.utah.edu/huntsmancancerinstitute/" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/hcf.jpg" /></a></div><div class="columns large-2"><a href="http://www.womenheart.org/" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/wh.jpg" /></a></div><div class="columns large-2"><a href="https://www.cff.org/" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/cff.jpg" /></a></div><div class="columns large-2"><a href="http://www.epilepsy.com/" target="_blank"><img src="../sites/all/themes/medicalidfashions_theme/images/illness-logos/ef.jpg" /></a></div></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '16a416b0-1e6b-4867-b586-2d4a7ea24d11';
    $display->content['new-16a416b0-1e6b-4867-b586-2d4a7ea24d11'] = $pane;
    $display->panels['middle'][3] = 'new-16a416b0-1e6b-4867-b586-2d4a7ea24d11';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  return $pages;

}
