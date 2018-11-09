gsap.makeThemSquare = function (el) {
    $(window).on("load resize", function () {
        $(el).each(function () {
            $(this).height($(this).width());
        });
    });
};