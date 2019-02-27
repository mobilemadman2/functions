/**
 * MOBILE MENU
 * Works with original WP menu structure, regardless how many levels
 * @param $container: closest parent of the first menu level
 */
TWC.mobileMenu = function ($container) {
    // trigger button
    $('.btn-hamburger').on('click', function () {
        $body.toggleClass('menu-open');
    });

    $container.addClass('twc-mobile-menu');
    var $mainMenu = $container.find("ul.menu");

    function assignId($menu, level) {
        if (typeof level === 'undefined') {
            level = 2;
        }

        $menu.children("li").each(function (i) {
            var $this_li = $(this),
                id = 'lv' + level + '-item' + i,
                $subMenu = $this_li.children("ul");

            // if item has sub menu
            if ($subMenu.length > 0) {
                // set data
                $this_li.addClass('twcmm__has-child');
                $this_li.append('<span class="twcmm__button twcmm__open"></span>');
                $this_li.attr('data-id', id);
                $subMenu.attr('data-child-of', id);

                // recursion
                assignId($subMenu, level + 1);
                $subMenu.addClass('twcmm__submenu');
                $subMenu.detach().appendTo($container);
                $subMenu.prepend('<li class="twcmm__li"><span class="twcmm__button twcmm__close">' + $this_li.children('a').text() + '</span></li>');

                // open event
                $('.twcmm__button.twcmm__open').click(function () {
                    var id = $(this).parent().attr('data-id');

                    // hide this ul
                    $(this).parent().parent().removeClass('twcmm__active');

                    // show active ul
                    $('.twcmm__submenu[data-child-of="' + id + '"]').addClass('twcmm__active');
                });

                // close event
                $('.twcmm__button.twcmm__close').click(function () {
                    var id = $(this).parent().parent().attr('data-child-of');

                    // hide this ul
                    $(this).parent().parent().removeClass('twcmm__active');

                    // show active ul
                    $('.twcmm__has-child[data-id="' + id + '"]').parent().addClass('twcmm__active');
                });
            }
        });
    }

    assignId($mainMenu);
    $mainMenu.addClass('twcmm__active');
};