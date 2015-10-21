<?php
/**
 * @file
 * medidf_structure_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function medidf_structure_feature_default_rules_configuration() {
  $items = array();
  $items['rules_order_contains_a_plate_without_an_engraving'] = entity_import('rules_config', '{ "rules_order_contains_a_plate_without_an_engraving" : {
      "LABEL" : "Order contains a plate without an engraving or bracelet",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "DO" : [
        { "drupal_message" : {
            "message" : "You must purchase an engraving to purchase a plate. \\u003C?php print l(\\u0027Purchase an engraving\\u0027, \\u0027node\\/262\\u0027); ?\\u003E",
            "type" : "warning",
            "repeat" : 0
          }
        },
        { "data_set" : { "data" : [ "commerce-order:field-order-validity" ], "value" : 0 } }
      ]
    }
  }');
  $items['rules_order_contains_an_engraving'] = entity_import('rules_config', '{ "rules_order_contains_an_engraving" : {
      "LABEL" : "Order contains an engraving",
      "PLUGIN" : "or",
      "OWNER" : "rules",
      "TAGS" : [ "Order", "Restrictions" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "OR" : []
    }
  }');
  $items['rules_order_contains_engraving_without_a_plate'] = entity_import('rules_config', '{ "rules_order_contains_engraving_without_a_plate" : {
      "LABEL" : "Order contains engraving without a plate",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Order", "Restrictions" ],
      "REQUIRES" : [ "rules", "medidf_rules" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "IF" : [
        { "component_rules_order_contains_an_engraving" : { "commerce_order" : [ "commerce_order" ] } },
        { "NOT order_contains_product_type" : { "commerce_order" : [ "commerce_order" ], "type" : "plates" } },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "You must purchase a plate to purchase an engraving. \\u003C?php print l(\\u0027Purchase a plate\\u0027, \\u0027node\\/280\\u0027); ?\\u003E",
            "type" : "warning",
            "repeat" : 0
          }
        },
        { "data_set" : { "data" : [ "commerce-order:field-order-validity" ], "value" : 0 } }
      ]
    }
  }');
  $items['rules_order_restrictions'] = entity_import('rules_config', '{ "rules_order_restrictions" : {
      "LABEL" : "Order restrictions",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "value" : "checkout_checkout"
          }
        },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "checkout_checkout" } },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-order:field-order-validity" ], "value" : 1 } },
        { "component_rules_set_order_to_invalid_when_it_engravings_and_plates_don_t_m" : { "commerce_order" : [ "commerce_order" ] } },
        { "component_rules_redirect_invalid_order_to_store" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  $items['rules_redirect_invalid_order_to_store'] = entity_import('rules_config', '{ "rules_redirect_invalid_order_to_store" : {
      "LABEL" : "Redirect invalid order to store",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Order", "Restrictions" ],
      "REQUIRES" : [ "rules", "commerce_order" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } },
        { "data_is" : { "data" : [ "commerce-order:field-order-validity" ], "value" : 0 } }
      ],
      "DO" : [
        { "commerce_order_update_state" : { "commerce_order" : [ "commerce_order" ], "order_state" : "cart" } },
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "cart" } },
        { "entity_save" : { "data" : [ "commerce-order" ], "immediate" : 1 } },
        { "drupal_message" : {
            "message" : "Please meet all of the requirements listed above before attempting to complete checkout.",
            "type" : "warning",
            "repeat" : 0
          }
        },
        { "redirect" : { "url" : "store\\/categories" } }
      ]
    }
  }');
  $items['rules_set_order_to_invalid_when_it_engravings_and_plates_don_t_m'] = entity_import('rules_config', '{ "rules_set_order_to_invalid_when_it_engravings_and_plates_don_t_m" : {
      "LABEL" : "Set order to invalid when it engravings and plates don\\u0027t match",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "rules", "medidf_rules" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "IF" : [
        { "commerce_order_is_cart" : { "commerce_order" : [ "commerce-order" ] } },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } },
        { "NOT order_contains_equal_plates_and_engravings" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-order:field-order-validity" ], "value" : 0 } },
        { "entity_save" : { "data" : [ "commerce-order" ], "immediate" : 1 } },
        { "drupal_message" : {
            "message" : "You must purchase an equal number of plates and engravings. Please make sure your order contains 1 engraving for every 1 plate in the cart.",
            "type" : "error",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
