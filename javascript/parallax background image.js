/**
 * Parallax using background image v2.1
 * @param el : element that has background-image
 * @param speed : (0;1] | default 0.5 (optional)
 * @param responsive (optional)
 * @param positionX: background horizontal position | default center (optional)
 */
TWC.backgroundParallax = function (el, speed, responsive, positionX) {
    $(el).each(function () {
        var _this = $(this);
        if (typeof positionX === "undefined") {
            positionX = "center";
        }
        positionX += " ";
        if (typeof speed === "undefined") {
            speed = 0.5;
        }
        if (typeof responsive === "undefined") {
            responsive = 0;
        }
        $(window).on('load resize', function () {
            if ($(window).width() > responsive) {
                var offset = _this.offset().top, wScroll = 0, scroll_window;

                // On first load
                scroll_window = $(window).scrollTop();
                wScroll = (scroll_window - offset) * speed;
                _this.css('background-position', positionX + wScroll + 'px');

                // On scroll
                $(window).on("scroll", function () {
                    scroll_window = $(window).scrollTop();
                    wScroll = (scroll_window - offset) * speed;
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