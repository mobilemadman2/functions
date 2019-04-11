/**
 * Add slide down button for sub menu
 * There are two types of click event, please read code to make decision
 */
TWC.mobileMenuSlideDown = function (el) {
    var $items = $(el); // items have sub menu
    $items.each(function () {
        $(this).addClass('menu-item-slidedown');
        $(this).append('<span class="btn-mobile-slidedown"></span>');
    });

    // click event
    var $btn = $('.btn-mobile-slidedown');
    $btn.click(function () {
        $(this).prev().slideToggle(); // toggle slide ul.sub-menu tag
        $(this).toggleClass('close');
    });
    $btn.trigger('click');

    // click event (only open one at once, should have from 2 sub menus)
    /*var $btn = $('.btn-mobile-slidedown');
    $btn.click(function () {
        // close the others
        var $opening = $('.btn-mobile-slidedown:not(.close)');
        if ($opening.is($(this))) {
            return;
        }
        $opening.prev().slideUp();
        $opening.addClass('close');

        // open this
        $(this).prev().slideDown();
        $(this).removeClass('close');
    });*/

    // trigger close all but first one
    /*$btn.prev().slideUp();
    $btn.addClass('close');
    $btn.first().trigger('click');*/
};

/**
 * CSS

 /* MOBILE MENU > Slide down */
.menu-item-slidedown {position:relative;}
.btn-mobile-slidedown {
    position:absolute; right:-12px; top:-4px; z-index:1; text-align:center;
    width:30px; height:30px; line-height:30px; border-radius:50%; cursor:pointer;
    -webkit-transition:all .3s ease;-o-transition:all .3s ease;transition:all .3s ease;
}
.btn-mobile-slidedown:hover {background:#261c5c; color:#fff;}
.btn-mobile-slidedown:after {
    content:'\f0d7'; font-family: 'Font Awesome 5 Free'; font-weight:600; display:block;
    -webkit-transition:all .3s ease;-o-transition:all .3s ease;transition:all .3s ease;
    -webkit-transform:rotate(180deg);-ms-transform:rotate(180deg);transform:rotate(180deg);
}
.btn-mobile-slidedown.close:after {transform:none;}
 */