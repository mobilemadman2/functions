/**
 * Customize body default scroll bar
 * mCustomScrollbar
 * http://manos.malihu.gr/jquery-custom-content-scroller/
 */
TWC.overrideBodyScrollbar = function () {
    $("body").mCustomScrollbar({
        axis: "y",
        scrollbarPosition: "inside",
        theme: "valerie",
        keyboard: {
            enable: true,
            scrollType: "stepless"
        },
        mouseWheel: {scrollAmount: 400},
        callbacks: {
            whileScrolling: function () {
                // Put on scroll functions here since this will deactive default scroll event
                TWC.projectItemAnimation();
            }
        }
    });

    // Destroy
    $(window).on('load resize', function () {
        if($(window).width() <= 768){
            $('body').mCustomScrollbar("destroy");
            $(window).on('scroll', function () {
                TWC.projectItemAnimation();
            });
        }
    });
};