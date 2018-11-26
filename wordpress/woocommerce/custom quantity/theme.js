/**
 * Custom quantity control
 */
TWC.customQuantity = function () {
    var $btn = $('.custom-quantity a'),
        $input = $('.custom-quantity input'),
        newVal;
    $btn.click(function () {
        newVal = parseInt($input.val());
        // if up
        if ($(this).hasClass('increase')) {
            newVal += 1;
        }
        // if down
        if ($(this).hasClass('decrease') && newVal > 1) {
            newVal -= 1;
        }
        $input.val(newVal);
        $input.focus();
        $input.keydown();
    });
};