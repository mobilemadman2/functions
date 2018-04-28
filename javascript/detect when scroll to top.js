/**
     * Detect when scroll to top
     */
    var scrollTrigger = 100, // px
        backToTop = function () {
            var scrollTop = $(window).scrollTop();
            if (scrollTop > scrollTrigger) {
                $('.main_header').addClass('show');
                $('.backtotop').addClass('show');
            } else {
                $('.main_header').removeClass('show');
                $('.backtotop').removeClass('show');
            }
        };
    backToTop();
    $(window).on('scroll', function () {
        backToTop();
    });