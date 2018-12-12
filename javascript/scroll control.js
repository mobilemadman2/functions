/**
 * Scroll control with classes
 */
TWC.scrollingControl = function () {
    var lastPosition = 0,
        scrollAmount = 0,
        topTrigger = 0, // $element.offset().top
        downTrigger = $(".header__banner").outerHeight();

    // Detect scroll direction
    $(window).scroll(function () {
        scrollAmount = $(window).scrollTop();
        if (scrollAmount > lastPosition && scrollAmount > downTrigger) {
            // scroll down
            $body.removeClass('scroll-up');
            $body.addClass('scroll-down');
        } else {
            // scroll up
            $body.addClass('scroll-up');
            $body.removeClass('scroll-down');
        }
        lastPosition = scrollAmount;
    });

    // Detect scroll to top
    $(window).on('load scroll', function () {
        if (scrollAmount > topTrigger) {
            $body.removeClass("scroll-top");
            $body.addClass("scroll-leave-top");
        } else {
            // top touched
            $body.addClass("scroll-top");
            $body.removeClass("scroll-leave-top");
        }
    });
};