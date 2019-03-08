/**
 * Add slide down button for sub menu
 */
VI.menuSlideDownButton = function () {
    var $items = $('#menu ul.menu > li.menu-item-has-children');
    $items.each(function () {
        $(this).append('<span class="vi-menu-slidedown"></span>');
    });

    // click event
    /*
    var $btn = $('.vi-menu-slidedown');
    $btn.click(function () {
        $(this).prev().slideToggle();
        $(this).toggleClass('close');
    });
    $btn.trigger('click);
    */

    // click event (always open one at once)
    var $btn = $('.vi-menu-slidedown');
    $btn.click(function () {
        // close the others
        var $opening = $('.vi-menu-slidedown:not(.close)');
        if ($opening.is($(this))) {
            return;
        }
        $opening.prev().slideUp();
        $opening.addClass('close');

        // open this
        $(this).prev().slideDown();
        $(this).removeClass('close');
    });

    // trigger close all but first one
    $btn.prev().slideUp();
    $btn.addClass('close');
    $btn.first().trigger('click');
};

/**
 * CSS

 .vi-menu-slidedown {
    position:absolute; right:5px; top:4px; z-index:1; text-align:center;
    width:30px; height:30px; line-height:30px; border-radius:50%; cursor:pointer;
    -webkit-transition:all .3s ease;-o-transition:all .3s ease;transition:all .3s ease;
}
 .vi-menu-slidedown:hover {background:#fff; color:#2e445f;}
 .vi-menu-slidedown:after {
    content:'\f106'; font-family:'fontawesome'; display:block;
    -webkit-transition:all .3s ease;-o-transition:all .3s ease;transition:all .3s ease;
}
 .vi-menu-slidedown.active:after {-webkit-transform:rotate(180deg);-ms-transform:rotate(180deg);transform:rotate(180deg);}
 */