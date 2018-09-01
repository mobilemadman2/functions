/**
 * Disable scrollify with breakpoint
 * @type {boolean}
 */
var is_disabled = false;
$(window).on("resize load", function(){
    if($(window).width() <= 1024){
        $.scrollify.disable();
        is_disabled = true;
    } else {
        if(is_disabled){
            $.scrollify.enable();
            is_disabled = false;
        }
    }
});