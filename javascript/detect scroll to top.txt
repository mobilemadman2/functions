/*** detect scroll to top ***/
function detectScrollToTop(scrollTrigger = 100){
        $(window).on('load scroll', function () {
            var scrollTop = $(window).scrollTop();
            if (scrollTop > scrollTrigger) {
                $('.btn_menu').removeClass('ontop');
            } else {
                $('.btn_menu').addClass('ontop');
            }
        });
    }