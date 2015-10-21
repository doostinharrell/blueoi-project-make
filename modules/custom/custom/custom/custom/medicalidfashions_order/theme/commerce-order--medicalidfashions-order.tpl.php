
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <table class="medicalidfashions-customer-information">
      <thead>
        <tr>
          <th>Ship to:</th>
          <th>Bill to:</th>
        </tr>
      </thead>
      <tfoot>
        <tr>
          <td colspan="2">
            <?php if ($content['order_source']) : ?>
            <div class="order-source"><span class="label">Order Source:</span> <?php print $content['order_source']; ?></div>
            <?php endif; ?>
            <div class="order-number"><span class="label">Order Number:</span> <?php print $content['order_number']; ?></div>
            <div class="order-email"><span class="label">Order Email:</span> <?php print $content['customer_email']; ?></div>
            <div class="customer-id"><span class="label">Customer ID:</span> <?php print $content['customer_id']; ?></div>
            <div class="customer-phone"><span class="label">Customer Phone:</span> <?php print $content['customer_phone']; ?></div>
            <div class="payments-list"><span class="label">Payments:</span></div>
            <?php foreach ($content['payments'] as $payment) : ?>
              <div class="payment-method"><span class="label">&nbsp;</span><?php print $payment; ?></div>
            <?php endforeach; ?>
          </td>
        </tr>
      </tfoot>
      <tbody>
        <tr>
          <td>
            <?php if (isset($content['commerce_customer_shipping'])): ?>
              <?php print render($content['commerce_customer_shipping']); ?>
            <?php endif; ?>
          </td>
          <td>
            <?php if (isset($content['commerce_customer_billing'])): ?>
              <?php print render($content['commerce_customer_billing']); ?>
            <?php endif;?>
          </td>
        </tr>
      </tbody>
    </table>
      <?php
        // Render the elements assigned to the left column.
        print render($content['commerce_line_items']);
        print render($content['commerce_order_total']);
        if (isset($content['commerce_message_messages_order_view'])) {
          print render($content['commerce_message_messages_order_view']);
        }
        // Render all additional, unknown elements.
        print render($content['field_order_source']);
        print render($content['field_order_validity']);
        print render($content['field_order_donation']);
        print render($content['field_order_comments']);
        print render($content['field_store_comments']);
        print render($content);
      ?>
  </div>
</div>
