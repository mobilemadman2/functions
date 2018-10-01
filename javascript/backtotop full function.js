/**
 * Append back to top button to footer
 */
$("footer").append('<span class="backtotop"></span>');

/**
 * Back to top button
 */
$('.backtotop').on('click', function (e) {
    e.preventDefault();
    $('html,body').animate({
        scrollTop: 0 /* element.offset().top */
    }, 700);
});

/**
 * Detect scroll direction
 */
var position = $(window).scrollTop();
$(window).scroll(function () {
    var scroll = $(window).scrollTop();
    if (scroll > position) {
        // scroll down
        $('.backtotop').removeClass('showing');
    } else {
        // scroll up
        $('.backtotop').addClass('showing');
    }
    position = scroll;
});

/**
 * Detect touch to top
 */
function detectScrollToTop(scrollTrigger = 100){
    $(window).on('load scroll', function () {
        var scrollTop = $(window).scrollTop();
        if (scrollTop > scrollTrigger) {
            // top leave
        } else {
            // top touched
            $('.backtotop').removeClass('showing');
        }
    });
}
detectScrollToTop();

/**
 * Detect touch to bottom
 */
window.onscroll = function(ev) {
    if ((window.innerHeight + window.scrollY) >= document.body.offsetHeight) {
        $('.backtotop').addClass('showing');
    }
};

/**
 * CSS
 */
/*
.backtotop {
    position:fixed; right:10px; bottom:10px; cursor:pointer;
    width:40px; height:40px; background:rgba(253, 152, 32, 1);
    border:2px solid #fff;
    -webkit-transition:all .3s ease;-o-transition:all .3s ease;-moz-transition:all .3s ease;transition:all .3s ease;
    opacity:0; visibility:hidden;
}
.backtotop:before {
    content:"\f106"; font-family:"fontawesome"; font-size:25px; color:#fff;
    position:absolute; top:-4px; left:11px;
}
.backtotop.showing {opacity:.5; visibility:visible;}
.backtotop.showing:hover {opacity:1;}
*/