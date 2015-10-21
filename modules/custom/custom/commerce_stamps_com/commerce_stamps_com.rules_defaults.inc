<?php

function commerce_stamps_com_rules_configuration() {
  $configs = array();
  $rule = '{ "rules_send_tracking_information_to_order_owner_stamps_com_" : {
    "LABEL" : "Send Tracking Information To Order Owner (Stamps.com)",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "stamps.com" ],
    "REQUIRES" : [ "rules", "commerce_stamps_com", "entity" ],
    "ON" : [ "commerce_order_update" ],
    "IF" : [
      { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "completed" } },
      { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "completed" } },
      { "commerce_stamps_com_order_has_tracking_numbers" : { "order" : [ "commerce-order" ] } }
    ],
    "DO" : [
      { "commerce_stamps_com_order_get_tracking_numbers" : {
          "USING" : { "order" : [ "commerce-order" ] },
          "PROVIDE" : { "tracking_numbers" : { "tracking_numbers" : "Tracking Numbers" } }
        }
      },
      { "mail" : {
          "to" : [ "commerce-order:mail" ],
          "subject" : "[site:name] order [commerce-order:order-number] has shipped",
          "message" : "Your order has shipped. Here are the USPS tracking numbers to track your order shipment(s):\r\n\r\n[commerce-order:commerce_stamps_com_tracking_numbers]\r\n\r\n",
          "from" : [ "site:mail" ],
          "language" : [ "" ]
        }
      }
    ]
  }
}';

  $configs['commerce_stamps_com_email_tracking_numbers'] = rules_import($rule);

  return $configs;
}
