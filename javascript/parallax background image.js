/**
 * Parallax using background image v2.0
 * @param el
 * @param positionX: background position x | default center
 */
TWC.backgroundParallax = function (el, positionX) {
    $(el).each(function () {
        var _this = $(this);
        if (typeof positionX === "undefined") {
            positionX = "center";
        }
        positionX += " ";
        $(window).on('load resize', function () {
            if ($(window).width() > 768) {
                var offset = _this.offset().top, wScroll = 0, scroll_window;

                // On first load
                scroll_window = $(window).scrollTop();
                wScroll = (scroll_window - offset) * 0.5;
                _this.css('background-position', positionX + wScroll + 'px');

                // On scroll
                $(window).on("scroll", function () {
                    scroll_window = $(window).scrollTop();
                    wScroll = (scroll_window - offset) * 0.5;
                    _this.css('background-position', positionX + wScroll + 'px');
                });
            } else {
                _this.css('background-position', positionX + "center");
            }
        });
    });
};

/**
 * Parallax using background image v1.0
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