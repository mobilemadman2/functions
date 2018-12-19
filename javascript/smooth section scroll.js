/**
 * Smoothly scroll to section (support "https:domain.com/#target", "#target")
 * @param $el | required
 * @param offset | 0px by default
 * @param speed | 700ms by default
 * @param callbackBeforeAnimate
 * @param callbackAfterAnimation
 */
Viivue.smoothSectionScroll = function ($el, offset, speed, callbackBeforeAnimate, callbackAfterAnimation) {
    // Validation
    offset = typeof offset === "undefined" ? 0 : offset;
    speed = typeof speed === "undefined" ? 700 : speed;

    // Select all a tag with href has "#"
    $el.each(function () {
        var target = $(this).attr("href");

        // Remove #target from url if any
        var url = window.location.href;
        if (url.indexOf("#") > -1) {
            url = url.substring(0, target.indexOf("#"));
        }

        // If target has current page link, remove url to get valid target
        target = target.indexOf(url) > -1 ? target.substring(target.indexOf("#"), target.length) : target;

        // Valid target is started with "#" && exist in current page
        if (target[0] === "#" && $(target).length) {
            $(this).attr("data-scroll-target", target);
            $(this).attr("data-scroll-offset", offset);
            $(this).click(function (e) {
                e.preventDefault();

                if (typeof callbackAfterAnimation !== "undefined") {
                    callbackBeforeAnimate();
                }

                // Smooth scroll
                $('html,body').animate({
                    scrollTop: $(target).offset().top - offset
                }, speed);

                if (typeof callbackAfterAnimation !== "undefined") {
                    callbackAfterAnimation();
                }
            });
        }
    });
};