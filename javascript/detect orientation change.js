/**
 * Detect orientation change
 * https://davidwalsh.name/orientation-change
 */
function detect_screen_orientation() {
    // get orientation onload
    var orientation = screen.orientation.type; // portrait-primary & landscape-primary
    $("body").addClass(orientation);

    // add event listener
    window.addEventListener("orientationchange", function () {
        // remove current orientation class
        $("body").toggleClass(orientation);

        // get new orientation
        orientation = screen.orientation.type;

        // add new orientation
        $("body").toggleClass(orientation);
    }, false);
}