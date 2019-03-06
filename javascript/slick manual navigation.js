/**
 * Manually control slick navigation
 * used with complex thumbnail layout
 * @type {jQuery|HTMLElement}
 */
var $albumMain = $('.vi-album-main'), $albumNav = $('.vi-album-thumb');
$albumMain.slick({
    slidesToShow: 1,
    slidesToScroll: 1,
    arrows: true,
    dots: false,
    fade: true,
    infinite: false,
});
$albumNav.slick({
    slidesToShow: 4,
    slidesToScroll: 1,
    dots: false,
    arrows: true,
    infinite: false,
    focusOnSelect: true,
    rows: 2
});

// Navigation click
var $thumbItem = $('.vi-album-thumb__item');
$thumbItem.click(function () {
    $thumbItem.removeClass('active');
    $(this).addClass('active');

    var index = $(this).attr('data-index');
    $albumMain.slick('slickGoTo', index);
});

// Main image change
var lastSlideIndex = 0;
$albumMain.on('afterChange', function (event, slick, direction) {
    var index = $albumMain.slick('slickCurrentSlide');
    $thumbItem.removeClass('active');
    $thumbItem.eq(index).addClass('active');

    console.log("last: " + lastSlideIndex + " index: " + index);
    if (lastSlideIndex < index && index % 2 === 0) {
        $albumNav.slick('slickNext');
    }
    if (lastSlideIndex > index && index % 2 === 1) {
        $albumNav.slick('slickPrev');
    }
    lastSlideIndex = index;
});