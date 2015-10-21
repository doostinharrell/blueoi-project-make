<?php

class MedidfOrderLineItem extends CommerceMigrateUbercartLineItem {
  public function __construct($arguments) {
    parent::__construct();
    $this->machineName = $arguments['machine_name'];
    $this->dependencies = array('Order');
    $this->removeFieldMapping('commerce_product');
    $this->addFieldMapping('commerce_product', 'product')
      ->defaultValue(0);

    $this->removeFieldMapping('order_id');
    $this->addFieldMapping('order_id', 'order_id')
         ->sourceMigration('Order');
  }

  public function prepareRow($row) {
    $row->product = 0;
    if (!empty($row->model)) {
      $product = commerce_product_load_by_sku($row->model);
      if (!empty($product)) {
        $row->product = $product->product_id;
      }
    }
  }
}
