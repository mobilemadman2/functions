/**
 * Keep element's square
 * @param el
 */
TWC.keepSquare = function (el) {
    $(window).on("load resize", function () {
        $(el).each(function () {
            $(this).height($(this).width());
        });
    });
};