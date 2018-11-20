TWC.scrollingControl = function () {
    // Detect scroll direction
    var position = $(window).scrollTop();
    $(window).scroll(function () {
        var scroll = $(window).scrollTop();
        if (scroll > position) {
            // scroll down
            $body.removeClass('scroll-up');
            $body.addClass('scroll-down');
        } else {
            // scroll up
            $body.addClass('scroll-up');
            $body.removeClass('scroll-down');
        }
        position = scroll;
    });

    // Detect scroll to top
    var scrollTrigger = $('.main_header_wrapper').height() / 2;
    $(window).on('load scroll', function () {
        var scrollTop = $(window).scrollTop();
        if (scrollTop > scrollTrigger) {
            $body.removeClass("scroll-top");
        } else {
            // top touched
            $body.addClass("scroll-top");
        }
    });
};