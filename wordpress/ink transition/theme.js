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
                $('#ink-close').trigger('click');

                // Add loading class when user leave page
                window.onbeforeunload = on_leaving_page;

                // When a mailto link clicked
                $('a[href*=mailto]').click(function () {
                    mailtoClicked = true;
                });
            }
        });
    };

    TWC.inkTransitionEffect = function () {
        // cache some jQuery objects
        var modalTrigger = $('#ink-open'),
            modalClose = $('#ink-close'),
            transitionLayer = $('.ink-transition'),
            transitionBackground = transitionLayer.children();

        var frameProportion = 1.78, //png frame aspect ratio
            frames = 25, //number of png frames
            resize = false;

        // set transitionBackground dimentions
        setLayerDimensions();
        $(window).on('resize', function () {
            if (!resize) {
                resize = true;
                (!window.requestAnimationFrame) ? setTimeout(setLayerDimensions, 300) : window.requestAnimationFrame(setLayerDimensions);
            }
        });

        // open modal window
        modalTrigger.on('click', function (event) {
            event.preventDefault();
            transitionLayer.addClass('visible opening');
        });

        // close modal window
        modalClose.on('click', function (event) {
            event.preventDefault();
            transitionLayer.addClass('closing');
            transitionBackground.one('webkitAnimationEnd oanimationend msAnimationEnd animationend', function () {
                transitionLayer.removeClass('closing opening visible');
                transitionBackground.off('webkitAnimationEnd oanimationend msAnimationEnd animationend');
            });
        });

        function setLayerDimensions() {
            var windowWidth = $(window).width(),
                windowHeight = $(window).height(),
                layerHeight, layerWidth;

            if (windowWidth / windowHeight > frameProportion) {
                layerWidth = windowWidth;
                layerHeight = layerWidth / frameProportion;
            } else {
                layerHeight = windowHeight * 1.2;
                layerWidth = layerHeight * frameProportion;
            }

            transitionBackground.css({
                'width': layerWidth * frames + 'px',
                'height': layerHeight + 'px'
            });

            resize = false;
        }
    };

    TWC.loadFunctions = function () {
        TWC.handleLoadingState();
        TWC.inkTransitionEffect();
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
        jQuery('#ink-open').trigger('click');
    } else {
        mailtoClicked = false;
    }
}