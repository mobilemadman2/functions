/**
 * Footer always at bottom of the page
 */
TWC.footerAlwaysBottom = function () {
    if ($("body").height() < $(window).height()) {
        $(window).on("load resize", function () {
            var minHeight = $(window).height() - ($("header.header").outerHeight() + $("footer").outerHeight());
            $("#primary").css("min-height", minHeight + "px");
        });
    }
};