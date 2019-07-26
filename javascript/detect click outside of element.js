$(document).click(function (event) {
    var $target = $(event.target);
    if (!$target.closest('.header__block').length) {
        $html.removeClass('menu-open');
    }
});