/**
 * Sticky header, scrolling status function is required
 */
TWC.stickyHeader = function (el) {
    var $el = $(el), $parent = $el.parent();
    if ($el.length > 0) {
        $el.addClass('sticky-header');

        // add padding to parent
        $window.on('load resize', function () {
            $parent.css('padding-top', $el.outerHeight());
        });
    }
};