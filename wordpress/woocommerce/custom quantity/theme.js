/**
 * Custom quantity control
 */
TWC.customQuantity = function () {
    var $btn = $('.custom-quantity a'), newVal, id, $input;

    $btn.click(function () {
        id = $(this).attr('data-id');
        $input = $('.custom-quantity input#' + id);
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