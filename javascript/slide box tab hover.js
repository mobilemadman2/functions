/*************************** ITEM HOVER SLIDE EFFECT ****************************/
    function returnSlideBox(menuSelector, itemClass, activeClass){
        var menu = $(menuSelector);
        var activeItem = menu.children(activeClass);
        var slideBox = $(".slide-box");
        slideBox.css({
            "width":activeItem.children('a').outerWidth() + "px",
            "height":activeItem.children('a').outerHeight() + "px",
            "top":activeItem.position().top + activeItem.children('a').position().top + "px",
            "left":activeItem.position().left + activeItem.children('a').position().left + "px"
        });
    }
    function slideEffect(menuSelector, itemClass, activeClass){
        var menu = $(menuSelector);
        var activeItem = menu.children(activeClass);
        menu.append("<span class='slide-box'></span>");
        var slideBox = $(".slide-box");
        menu.css({'position':'relative'});
        slideBox.css({
            'position':'absolute', 'display':'block', 'z-index':0, 'background':'#96aa3b',
            '-webkit-transition':'all 0.3s ease',
            '-o-transition':'all 0.3s ease',
            'transition':'all 0.3s ease'
        });

        returnSlideBox(menuSelector, itemClass, activeClass);

        menu.children(itemClass).hover(function () {
            slideBox.css({
                "width":$(this).children('a').outerWidth() + "px",
                "height":$(this).children('a').outerHeight() + "px",
                "top":$(this).position().top + $(this).children('a').position().top + "px",
                "left":$(this).position().left + $(this).children('a').position().left + "px"
            });
        }, function () {
            returnSlideBox(menuSelector, itemClass, activeClass);
        });
    }
    slideEffect(".page-template-sidebar .sidebar-section ul", 'li', 'li.active');