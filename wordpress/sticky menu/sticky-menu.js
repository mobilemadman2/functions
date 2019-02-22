/**
 * Sticky menu, Scrolling Control function is required
 */
TWC.stickyMenu = function ($el) {
    // validate element
    if ($el.length > 0) {
        var $parent = $el.parent();
        $el.addClass('sticky-menu');

        // add padding to parent
        $window.on('load resize', function () {
            $parent.css('padding-top', $el.outerHeight());
        });
    }
};