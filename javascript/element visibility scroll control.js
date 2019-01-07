/**
 * Control element's visibility relative ro viewport via classes
 * https://teamtreehouse.com/community/get-the-current-percentage-of-scroll-in-an-elementnot-the-document
 */
TWC.visibilityControl = function ($el) {
    $el.each(function () {
        var _this = $(this);
        $(window).on("scroll", function () {
            var viewportHeight = $(window).height(),
                viewportTop = $(window).scrollTop(),
                viewportBottom = viewportTop + viewportHeight,
                elementHeight = _this.outerHeight(),
                elementTop = _this.offset().top,
                percentage = (viewportBottom - elementTop) / (viewportHeight + elementHeight);

            if (percentage < 0.02) {
                _this.addClass('vis-ctrl-incoming');
                _this.removeClass('vis-ctrl-inview');
                _this.removeClass('vis-ctrl-outview');
            } else if (percentage >= 0.02 && percentage <= 1) {
                _this.addClass('vis-ctrl-inview');
                _this.removeClass('vis-ctrl-outview');
                _this.removeClass('vis-ctrl-incoming');
            } else if (percentage > 1) {
                _this.addClass('vis-ctrl-outview');
                _this.removeClass('vis-ctrl-inview');
                _this.removeClass('vis-ctrl-incoming');
            }
        });
    });

};