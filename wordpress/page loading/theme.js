/**
 * Handle loading state
 * https://jsfiddle.net/robertc/fjyztnsr/
 */
TWC.handleLoadingState = function () {
    $(window).on('load', function () {
        if ($('body').hasClass('twc-page-loading')) {

            // Remove loading class after page loaded
            $('body').removeClass('twc-page-loading');

            // Add loading class when user leave page
            window.onbeforeunload = on_leaving_page;

            // When a mailto link clicked
            $('a[href*=mailto]').click(function () {
                mailtoClicked = true;
            });
        }
    });
};


/**
 * Add loading class
 * This function placed outside on page loaded
 */
var mailtoClicked = false;

function on_leaving_page() {
    if (!mailtoClicked) {
        jQuery('body').addClass('twc-page-leaving');
    } else {
        mailtoClicked = false;
    }
}