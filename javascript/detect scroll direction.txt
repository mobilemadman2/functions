/**
     * Detect scroll direction
     */
    var position = $(window).scrollTop();
    $(window).scroll(function () {
        var scroll = $(window).scrollTop();
        if (scroll > position) {
            // scrolling downwards, only here for dev purposes
            console.log('moving DOWN the page');
        } else {
            // scrolling upwards
            console.log('moving UP the page');
        }
        position = scroll;
    });