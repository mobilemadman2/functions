/**
 * Set equal height on load, resize
 * @param $items
 */
function set_equal_height($items) {
    $(window).on('load resize', function () {
        var max_h = 0;
        // Reset height
        $items.outerHeight('');

        // Find max height
        $items.each(function () {
            max_h = $(this).outerHeight() > max_h ? $(this).outerHeight() : max_h;
        });

        // Set max height
        $items.outerHeight(max_h);
    });
}