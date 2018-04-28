/************* Trim string by word **************/
    function trimStringByWord(selector, len){
        $(selector).each(function () {
            if($(this).text().length > len){
                var text_ar = $(this).text().split(' ');
                var text_new = '';
                text_ar.forEach(function (value) {
                    if( (text_new+value).length >= len ){return}
                    text_new += value + ' ';
                });
                $(this).text(text_new + '...');
            }
        });
        console.log('Run function trimStringByWord("'+selector+'", '+len+') --- SUCCESSFUL.');
    }
    trimStringByWord('.title-project span', 55);