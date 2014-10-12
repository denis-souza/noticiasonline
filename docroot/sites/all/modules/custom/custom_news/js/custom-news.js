(function($) {
	
	// see https://www.drupal.org/node/304258
	Drupal.behaviors.newsHighlight = {
    attach: function(context) {
      $('#banner-fade').bjqs({
        height      : 320,
        width       : 620,
        responsive  : true
      });
    }
  }
})(jQuery);
