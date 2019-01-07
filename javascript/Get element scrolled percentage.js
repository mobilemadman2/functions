/**
 * Get element's scrolled percentage, run this function in your $(window).scroll event
 * https://teamtreehouse.com/community/get-the-current-percentage-of-scroll-in-an-elementnot-the-document
 * @param $el
 * @returns {number}
 */
TWC.elementScrolledPercentage = function ($el) {
    var viewportHeight = $(window).height(),
        viewportTop = $(window).scrollTop(),
        viewportBottom = viewportTop + viewportHeight,
        elementHeight = $el.outerHeight(),
        elementTop = $el.offset().top,
        percentage = (viewportBottom - elementTop) / (viewportHeight + elementHeight);

    return percentage;
};