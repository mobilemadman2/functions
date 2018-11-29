/**
 * Keep ratio of image base on its width
 * @param $el : element object
 * @param x : x ratio
 * @param y : y ratio
 */
TWC.keepRatioBaseOnWidth = function ($el, x, y) {
    if ($el.length) {
        var w = 0, h = 0;
        $(window).on('load resize', function () {
            w = $el.width();
            h = y * w / x;
            $el.addClass("twc-ratio-kept");
            $el.height(h);
        });
    }
};