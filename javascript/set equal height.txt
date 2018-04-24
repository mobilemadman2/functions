/**
* Set equal height on load, resize
* @param $items
*/
function set_equal_height($items){
    $(window).on('load resize', function () {
        var max_h = 0;
            $items.each(function () {
                max_h = $(this).height() > max_h ? $(this).height() : max_h;
            });
            $items.each(function () {
                $(this).css('height', max_h+'px');
            });
        });
    }
    set_equal_height($('.woocommerce li.product .woocommerce-loop-product__title'));