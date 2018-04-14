function responsiveBanner() {
        var body_width = $("body").width();
        $(".banner-wrapper .banner").css({"height":body_width*0.4+"px"});
    }
    responsiveBanner();