/**
 * jQuery animated number counter from zero to value
 * https://stackoverflow.com/questions/23006516/jquery-animated-number-counter-from-zero-to-value
 */

$('.stat-inner .stat-num').each(function () {
    var $this = $(this);
    jQuery({Counter: 0}).animate({Counter: $this.text()}, {
        duration: 2000,
        easing: 'swing',
        step: function () {
            $this.text(Math.ceil(this.Counter));
        }
    });
});