/**
 * Set equal height on load, resize
 * @param $items
 * @param $breakpoint | remove height if under breakpoint
 */
function set_equal_height($items, breakpoint) {
    $(window).on('load resize', function () {
        var max_h = 0;
        if ($(window).width() > breakpoint) {
            // Reset height
            $items.each(function () {
                $(this).css('height', '');
            });

            // Find max height
            $items.each(function () {
                max_h = $(this).height() > max_h ? $(this).height() : max_h;
            });
            // Set max height
            max_h += "px";
        } else {
            // Reset height
            max_h = "";
        }
        $items.each(function () {
            $(this).css('height', max_h);
        });

    });
}