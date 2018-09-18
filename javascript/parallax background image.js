/**
 * Parallax using background image
 */
if ($(window).width() > 1025) {
    var offset = 0;
    var wScroll = 0;
    $(window).on("scroll", function () {
        var scroll_window = $(window).scrollTop();
        if (scroll_window > offset) {
            wScroll = (scroll_window - offset) * 0.65;
            $(element).css('background-position', '50% ' + (-150 + wScroll) + 'px');
        }
    });
}