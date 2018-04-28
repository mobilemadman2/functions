/************* Load more ********************/
    function loadMore(item, button, showItem) {
        if($(item).length > showItem){
            $(item).css('display','none');
            $(item).slice(0, showItem).show();
            $(button).on('click', function (e) {
                // Loading
                $(this).addClass('loading');
                console.log('Ajax loading...');

                // Wait for 1s
                setTimeout(function(){

                    // Loaded
                    $(button).removeClass('loading');

                    e.preventDefault();
                    $(item+":hidden").slice(0, showItem).slideDown();
                    if ($(item+":hidden").length == 0) {
                        $(button).fadeOut('slow');
                    }
                    $('html,body').animate({
                        scrollTop: $(this).offset().top
                    }, 1500);

                }, 1500);


            });
        } else {
            $(button).hide();
        }

    }
    loadMore('.blog-article', '#loadmore', 5);