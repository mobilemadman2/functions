/**
 * CSS
 */
footer.fixed-footer {
    position:fixed; bottom:0; left:0; right:0; z-index:1;
}

/**
 * JS
 */
TWC.fixedFooter = function () {
    $(window).on('load resize', function () {
        $("#primary").css("margin-bottom", $("footer").outerHeight() + "px");
    });
};