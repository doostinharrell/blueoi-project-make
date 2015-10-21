<?php

class MedidfOrder extends CommerceMigrateUbercartOrderMigration {
  public function __construct($arguments) {
    parent::__construct();
    $this->machineName = $arguments['machine_name'];
  }

  function prepare($order, stdClass $row) {
    // Most order statuses (pending, cancelled, completed) are the same
    // between the two systems. However, some are not.
    if ($order->status == 'payment_received') {
      $order->status = 'completed';
    }
  }
}
