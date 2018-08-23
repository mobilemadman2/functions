/**
 * Set equal height on load, resize
 * @param $items
 * @param $breakpoint | remove height if under breakpoint
 */
function set_equal_height($items, breakpoint) {
    $(window).on('load resize', function () {
        if ($(window).width() > breakpoint) {
            // Find max height
            var max_h = 0;
            $items.each(function () {
                max_h = $(this).height() > max_h ? $(this).height() : max_h;
            });
            // Set max height
            $items.each(function () {
                $(this).css('height', max_h + 'px');
            });
        } else {
            // Reset height
            $items.each(function () {
                $(this).css('height', '');
            });
        }

    });
}

set_equal_height($('.home-services .service-box > p'), 1024);