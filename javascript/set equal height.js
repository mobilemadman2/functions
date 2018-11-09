/**
 * Set equal height on load, resize
 * @param $items
 */
TWC.setEqualHeight = function (el) {
    var max_h, $items = $(el);
    $(window).on('load resize', function () {
        max_h = 0;
        $items.outerHeight('');
        $items.each(function () {
            max_h = $(this).outerHeight() > max_h ? $(this).outerHeight() : max_h;
        });
        $items.outerHeight(max_h);
    });
};