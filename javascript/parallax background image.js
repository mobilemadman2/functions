/**
 * Parallax using background image
 */
TWC.backgroundParallax = function (el, scrollRatio, backgroundSize) {
    // set default value
    scrollRatio = typeof scrollRatio !== 'undefined' ? scrollRatio : 0.1;
    backgroundSize = typeof backgroundSize !== 'undefined' ? backgroundSize : '120%';

    $(el).each(function () {
        var _this = $(this);

        // set background size
        _this.css('background-size', backgroundSize);

        // process
        $(window).on('load resize', function () {
            var offset = _this.offset().top, wScroll = 0, scroll_window;

            // set background position on scroll
            $(window).on("scroll", function () {
                scroll_window = $(window).scrollTop();
                wScroll = (scroll_window - offset) * scrollRatio;
                _this.css('background-position', '50% ' + wScroll + 'px');
            });
        });
    });
};