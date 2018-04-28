/*** detect when element on the view ***/
    function onTheView(element){
        var ele = $(element);
        $(window).scroll(function() {
            var hT = ele.offset().top,
                hH = ele.outerHeight(),
                wH = $(window).height(),
                wS = $(this).scrollTop();
            if (wS > (hT+hH-wH)){
                console.log('H1 on the view!');
                $('#blog-loadmore').trigger('click');
            }
        });
    }
    onTheView('#blog-loadmore');