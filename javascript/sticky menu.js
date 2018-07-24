/**
 * Detect scroll direction
 */
var position = $(window).scrollTop();
$(window).scroll(function () {
    var scroll = $(window).scrollTop();
    if (scroll > position) {
        // scroll down
        $('body').removeClass('sticky-show');
    } else {
        // scroll up
        $('body').addClass('sticky-show');
    }
    position = scroll;
});

/**
 * Detect touch to top
 */
function detectScrollToTop() {
    var scrollTrigger;
    $(window).on("load resize", function () {
        scrollTrigger = $(window).width() <= 1170 ? 48 : 60;
    });
    $(window).on('load scroll', function () {
        var scrollTop = $(window).scrollTop();
        if (scrollTop > scrollTrigger) {
            $("body").addClass("sticky-menu");
        } else {
            // top touched
            $("body").removeClass("sticky-menu");
        }
    });
}

detectScrollToTop();