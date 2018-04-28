/***** menu hover *****/
    $(window).on('load resize', function () {
        $('header .menu-item-has-children').hover(function () {
            if( $(window).width() > 960 ) {
                $(this).children('ul.sub-menu').slideDown();
            }
        }, function () {
            if( $(window).width() > 960 ) {
                $(this).children('ul.sub-menu').slideUp();
            }
        });
        if( $(window).width() > 960 ){
            $('header .menu-item-has-children').children('ul.sub-menu').slideUp();
        } else {
            $('header .menu-item-has-children').children('ul.sub-menu').slideDown();
        }
    });