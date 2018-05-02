// https://css-tricks.com/snippets/jquery/get-x-y-mouse-coordinates/

$("#demo-box").click(function(e) {

    var offset = $(this).offset();
    var relativeX = (e.pageX - offset.left);
    var relativeY = (e.pageY - offset.top);

    alert("X: " + relativeX + "  Y: " + relativeY);

});