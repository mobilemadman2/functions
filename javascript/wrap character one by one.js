/*append span to every character*/
    $('.content-item-blog .title-blog').each(function (index) {
        var character = $(this).text().split(" ");
        $this = $(this);
        $this.empty();
        $.each(character, function (i, el) {
            $this.append("<span>" + el + "</span>" + " ");
        });
    });