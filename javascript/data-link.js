/**
 * Direct on click
 */
function data_link() {
    $('[data-link]').css('cursor','pointer');
    $('[data-link]').on('click', function (e) {
        var url = $(this).attr('data-link');
        if (url != null) {
            window.location.href = url;
        }
    });
}