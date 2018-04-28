function setSliderFullWidthAccommodation(){
        var window_w = $(window).width();
        var slider = $(".single-accommodation .gallery-single-wrap");
        if(window_w > 767){
            var pos_left = slider[0].getBoundingClientRect().left;
            var expect_w = window_w - pos_left - 50;
            slider.css({width:expect_w + "px"});
        } else {
            slider.css({width:""});
        }
    }
    setSliderFullWidthAccommodation();