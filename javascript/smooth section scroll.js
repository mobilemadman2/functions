/**
 * Smooth section scroll
 * Change default instant move to section with animated scroll to section
 */
TWC.smoothSectionScroll = function(){
    // Select all a tag with href begin with "#"
    $('a[href^="#"]').each(function () {
        var href = $(this).attr('href');

        // If is valid href
        if ($(href).length) {
            $(this).click(function (e) {
                e.preventDefault();

                // Smooth scroll
                $('html,body').animate({
                    scrollTop: $(href).offset().top
                }, 700);
            });
        }
    })
};