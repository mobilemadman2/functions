function custom_tabs_gallery() {
        $('.gallery-inner .item-gallery').each(function (e) {
            var name_id = $(this).attr('id');
            $(this).find('.slider-for').addClass(name_id);
            $(this).find('.slider-nav').addClass(name_id);

            $('.item-gallery .slider-for.'+name_id).slick({
                slidesToShow: 1,
                slidesToScroll: 1,
                arrows: true,
                fade: true,
                centerMode: true,
                asNavFor: '.item-gallery .slider-nav.'+name_id
            });
            $('.item-gallery .slider-nav.'+name_id).slick({
                slidesToShow: 5,
                slidesToScroll: 1,
                asNavFor: '.item-gallery .slider-for.'+name_id,
                dots: false,
                centerMode: true,
                focusOnSelect: true,
                centerPadding:"0px",
                /*infinite: false,*/
                responsive: [
                    {
                        breakpoint: 940,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1
                        }
                    },
                    {
                        breakpoint: 680,
                        settings: {
                            slidesToShow: 2,
                            slidesToScroll: 1,
                            vertical: false
                        }
                    }
                ]
            });
        });
    }

    custom_tabs_gallery();