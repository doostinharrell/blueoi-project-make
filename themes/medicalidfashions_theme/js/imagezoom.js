(function($) {

  /**
   * Initialize image zoom functionality.
   */
  Drupal.behaviors.imagezoom = {
    attach: function(context, settings) {
      // Create a selector only for the view we wish to alter.
      var view = $('.view-store-catalog-lists', context);
      if (view.length > 0) {
        // The 1st column has image zoom to the right.
        $('.imagezoom-image', context).elevateZoom({
          zoomType: 'window',
          borderSize: '1',
          zoomWindowHeight: '175',
          zoomWindowOffety: -100,
          zoomWindowOffetx: -350
        });
      }
    }
  }

})(jQuery);
