/**
 * Footer always at bottom of the page
 */
VIIVUE.footerAlwaysBottom = function () {
    if ($("body").height() < $(window).height()) {
        $(window).on("load resize", function () {
            var minHeight = $(window).height() - ($("header.main_header").height() + $("footer").height());
            $("#primary").css("min-height", minHeight + "px");
        });
    }
};