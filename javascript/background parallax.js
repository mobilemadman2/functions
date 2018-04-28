/**************** CROSS-BROWSER BACKGROUND PARALLAX ******************/
    /*
    * backgroundParallax(selector, scrollRatio)
    * selector: element that contain background-image to parallax
    * scrollRatio: parallax speed, should be in range from 0.1 to 1
    * Note: using this with another js library could cause confict error,
    * in that case, just remove the add css script and add it manually.
    */
    /*
    .background-parallax {
        height:415px; position:relative; overflow:hidden;
        background-image:unset!important;
    }
    .background-parallax img {
        position:absolute; top:0; left:50%; z-index:-1;
        -webkit-transform:translateX(-50%);-ms-transform:translateX(-50%);transform:translateX(-50%);
        display:block; width:auto; max-width: unset;
    }
    */
    function backgroundParallax(selector, scrollRatio){
        $(selector).addClass("background-parallax");
        $(".background-parallax").each(function () {
            /** CSS: remove this block if you've already apply those styles above to your css file **/
            $(this).css({
                'position':'relative',
                'overflow':'hidden',
                'background-image':'unset!important'
            });
            $(this).children('img').css({
                'position':'absolute', 'top':'0', 'left':'50%',
                '-webkit-transform':'translateX(-50%)', '-ms-transform':'translateX(-50%)', 'transform':'translateX(-50%)',
                'display':'block', 'width':'auto', 'max-width':'unset'
            });
            /** end CSS **/

            var scroll = $(window).scrollTop() * scrollRatio;
            var img = $(this).children("img");
            img.css({ "top": -1 * scroll + "px" });

            while( img.width() < $(window).width() ){
                img.css({"height":img.height() * 1.001 + "px"});
            }
        });
    }
    $(window).on("load resize scroll",function(){
        backgroundParallax(".banner-wrapper .page-banner", 0.3);
    });