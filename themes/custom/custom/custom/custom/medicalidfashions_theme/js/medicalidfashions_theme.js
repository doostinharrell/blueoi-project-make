(function ($, Drupal) {

  Drupal.behaviors.medicalidfashions_theme = {
    attach: function(context, settings) {
      // Get your Yeti started.
      $('.view-store-catalog-grid .views-field-name', context).matchHeight();
      $('.view-store-catalog-lists .views-row', context).matchHeight();
      $('.view-plate-images .views-row', context).matchHeight();
      $('table').tableit();
    }
  };

})(jQuery, Drupal);
