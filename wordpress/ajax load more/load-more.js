jQuery(function ($) {
    $('.load-more-btn').click(function (e) {
        e.preventDefault();
        e.stopPropagation();
        var current = $(this).data("current");
        var post_per_page = $(this).data("post-per-page");
        var post_type = $(this).data("post-type");
        var category = $(this).data("category");

        var this_button = $(this);
        $('body').addClass('twc-ajax-loading');
        $.post(
            ajaxurl,
            {
                'action': 'load_more_action',
                'data': {current_page: current, posts_per_page: post_per_page, post_type: post_type, category: category}
            },
            function (response) {
                $('[data-load-more-container]').append(response);
                if ($("[data-load-more-container] .next-no-post").length > 0) {
                    this_button.parent().hide();
                } else {
                    this_button.data("current", this_button.data("current") + 1);
                }
                TWC.dataLink();
                TWC.blogYearSeparator();
                $('body').removeClass('twc-ajax-loading');
            }
        );
    });
});