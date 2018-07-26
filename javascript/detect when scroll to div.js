/**
 * Check if element is visible after scrolling
 * https://stackoverflow.com/questions/487073/check-if-element-is-visible-after-scrolling
 * @constructor
 */
function Utils() {
}

Utils.prototype = {
    constructor: Utils,
    isElementInView: function (element, fullyInView) {
        var pageTop = $(window).scrollTop();
        var pageBottom = pageTop + $(window).height();
        var elementTop = $(element).offset().top;
        var elementBottom = elementTop + $(element).height();

        if (fullyInView === true) {
            return ((pageTop < elementTop) && (pageBottom > elementBottom));
        } else {
            return ((elementTop <= pageBottom) && (elementBottom >= pageTop));
        }
    }
};

var Utils = new Utils();
$(window).on("load scroll", function () {
    var isElementInView = Utils.isElementInView($('section.drl-main-stats'), false);

    if (isElementInView) {
        console.log('in view');
    } else {
        console.log('out of view');
    }
});