/* VII PARALLAX */
.vii-parallax {height:350px; background-size:cover; background-position:center;}
.vii-parallax-img {height:0!important; visibility:hidden;}

/**
 * Parallax using background image for VC Single Image with class "image-parallax"
 */
TWC.backgroundParallaxVCImage = function () {
    $(".image-parallax.wpb_single_image .vc_single_image-wrapper").each(function () {
        var img = $(this).find("img");
        $(this).append("<div class='vii-parallax' style='background-image: url(" + img.attr("src") + ")'></div>");
        img.addClass('vii-parallax-img');
    });
    $(".vii-parallax").each(function () {
        var _this = $(this);
        $(window).on('load resize', function () {
            if ($(window).width() > 768) {
                var offset = _this.offset().top, wScroll = 0, scroll_window;
                $(window).on("load scroll", function () {
                    scroll_window = $(window).scrollTop();
                    wScroll = (scroll_window - offset) * 0.2;
                    _this.css('background-position', '50% ' + wScroll + 'px');
                });
            } else {
                _this.css('background-position', '');
            }
        });
    });
};