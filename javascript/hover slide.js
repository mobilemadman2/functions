/*hover for sidebar*/
    function slideHover(selector){
        var selector = $(selector);
        /*add hover slide*/
        if(!selector.find(".hover-slide").length){selector.append("<span class='hover-slide'></span>");}

        var hoverSlide = selector.children(".hover-slide");
        var childItem = selector.children("li.active");
        hoverSlide.css({
            "width":childItem.width()+"px",
            "height":childItem.height()+"px"
        });

        var positionTop = 0;
        selector.children("li").mouseover(function () {
            console.log($(this).position().top+"px");
            hoverSlide.css({"top":$(this).position().top+"px"});
        });
        selector.mouseout(function () {
            hoverSlide.css({"top":childItem.position().top+"px"});
        });
        /*$("p").hover(function(){
            $(this).css("background-color", "yellow");
            }, function(){
            $(this).css("background-color", "pink");
        });*/
        /*get which item is hovered*/
        /*var itemCount = 0;
        childItem.each(function () {
            console.log("position: "+ $(this));
        });*/
        /*$(selector).mousemove(function (event) {
            $("span").text(event.pageX + ", " + event.pageY);
            console.log("mouse: "+event.pageX + ", " + event.pageY);
        });
        $(selector).mouseout(function (event) {

        });*/
    }
    slideHover("ul.menu-sidebar");