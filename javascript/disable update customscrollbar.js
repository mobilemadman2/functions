/**
 * http://manos.malihu.gr/repository/custom-scrollbar/demo/examples/disable_destroy_example.html
 */

TWC.overrideBodyScrollbar = function () {
    var $body = $('body');
    $(window).on('load resize', function () {
        if ($(window).width() <= 768) {
            $body.mCustomScrollbar("destroy");
        } else {
            $body.mCustomScrollbar();
        }
    });
};