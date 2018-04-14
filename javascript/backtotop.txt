/********* Back to top button *********/
    $('.backtotop').on('click', function (e) {
        e.preventDefault();
        $('html,body').animate({
            scrollTop: 0 /* element.offset().top */
        }, 700);
    });