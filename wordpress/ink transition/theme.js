TWC = {};
jQuery(document).ready(function ($) {
    /**
     * Handle loading state
     */
    TWC.handleLoadingState = function () {
        $(window).on('load', function () {
            if ($('body').hasClass('twc-page-loading')) {

                // Remove loading class after page loaded
                $('body').removeClass('twc-page-loading');
                $('body').addClass('twc-page-loaded');
                $('.modal-close').trigger('click');

                // Add loading class when user leave page
                window.onbeforeunload = on_leaving_page;

                // When a mailto link clicked
                $('a[href*=mailto]').click(function () {
                    mailtoClicked = true;
                });
            }
        });
    };

    TWC.loadFunctions = function () {
        TWC.handleLoadingState();
    };

    TWC.loadFunctions();
});

/**
 * Add loading class
 * This function placed outside on page loaded
 */
var mailtoClicked = false;

function on_leaving_page() {
    if (!mailtoClicked) {
        jQuery('body').addClass('twc-page-leaving');
        jQuery('body').removeClass('twc-page-loaded');
        jQuery('.modal-open').trigger('click');
    } else {
        mailtoClicked = false;
    }
}