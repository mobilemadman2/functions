/****** APPEND INNER WRAPPER FOR SHADOW STYLE *****/
    function appendInnerWrapper(selector, wrapperClass){
        /*NOT WORK if this element has wrapperClass already*/
        $(selector).each(function () {
            if(!$(this).find(wrapperClass).length) {
                $(this).wrapInner("<div class='" + wrapperClass + "'></div>");
            }
        });
    }