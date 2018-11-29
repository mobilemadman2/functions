TWC.readMoreElement = function () {
    var $begin = $('.read-more-begin'),
        $end = $('.read-more-end');

    // Wrap content to be hidden
    $begin.nextUntil($end).wrapAll("<section class='read-more-wrapper'></section>");

    // Hide content
    var $content = $('.read-more-wrapper');
    $content.slideUp();

    // Add events to button
    var $button = $end.find('.read-more-button');
    $button.click(function (e) {
        e.preventDefault();
        $content.slideDown();
        $button.hide();
        $end.addClass('active');
    });
};