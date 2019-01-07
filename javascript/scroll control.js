/**
 * Control scrolling states via classes
 */
TWC.scrollingControl = function () {
    var lastPosition = 0, // should not modify
        scrollAmount = 0, // should not modify
        topTrigger = 0, // px offset from top
        bottomTrigger = 200, // px offset from bottom
        downTrigger = 0, // px
        $body = $("body");

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


    $(window).on('load scroll', function () {
        // Detect scroll to top
        if (scrollAmount > topTrigger) {
            $body.removeClass("scroll-top");
            $body.addClass("scroll-leave-top");
        } else {
            // top touched
            $body.addClass("scroll-top");
            $body.removeClass("scroll-leave-top");
        }

        // Detect scroll to bottom
        if (scrollAmount >= $(document).height() - ($(window).height() + bottomTrigger)) {
            $body.addClass("scroll-bottom");
        } else {
            $body.removeClass("scroll-bottom");
        }
    });
};