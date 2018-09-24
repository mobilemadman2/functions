/**
 * Parallax using background image
 */
function backgroundParallax(el){
    $(window).on('load resize', function () {
        if ($(window).width() > 1025) {
            var offset = 0;
            var wScroll = 0;
            $(window).on("scroll", function () {
                var scroll_window = $(window).scrollTop();
                if (scroll_window > offset) {
                    wScroll = (scroll_window - offset) * 0.65;
                    $(el).css('background-position', '50% ' + (-150 + wScroll) + 'px');
                }
            });
        }
    });
}