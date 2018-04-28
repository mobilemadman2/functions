/******* swap element's order ********/   
 function swapElement(selector){
        var element = $(selector);
        if($(window).outerWidth() <= 570){
            element.insertAfter(element.next());
        } else {
            element.insertBefore(element.prev());
        }
    }
$(window).on("load resize",function(){
        swapElement(".list-tour-circle .list-tours-wrapper");
    });