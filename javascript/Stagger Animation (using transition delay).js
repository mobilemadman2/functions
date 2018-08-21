/**
 * Stagger Animation (using transition delay)
 * Author: Minh-Phuc Bui
 * @param elements
 * @param delayOffset
 * @param delayStart
 * @param reverse
 */
function staggerAnimation(elements, delayOffset, delayStart, reverse) {
    var delay = delayStart;
    if (reverse) {
        elements = $(elements.get().reverse());
    }
    elements.each(function () {
        $(this).css("transition-delay", delay + "s");
        delay += delayOffset;
    });
}