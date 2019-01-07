/**
 * Reveal svg using clip
 */
$(window).on('scroll', function () {
    var $svg = $('svg'),
        clipY = VI.elementScrolledPercentage($svg) * $svg.height();
    $svg.css("clip", "rect(0px, " + $svg.width() + "px, " + clipY + "px, 0px)");
});

/**
 * Get element's scrolled percentage
 * https://teamtreehouse.com/community/get-the-current-percentage-of-scroll-in-an-elementnot-the-document
 */
VI.elementScrolledPercentage = function ($el) {
    var viewportHeight = $(window).height(),
        viewportTop = $(window).scrollTop(),
        viewportBottom = viewportTop + viewportHeight,
        elementHeight = $el.outerHeight(),
        elementTop = $el.offset().top,
        percentage = (viewportBottom - elementTop) / (viewportHeight + elementHeight);

    return percentage;
};