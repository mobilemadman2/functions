/**
 * Draw curved path
 * This algorithm using starting and ending point to determine the svg height
 * Then draw same height curves by deviding svg height with entered curved points
 */
VI.drawPath = function () {
    var $wrapper = $(".vi-path-wrapper");
    if (!$wrapper.length) return;

    var $begin = $wrapper.find(".vi-path-begin"),
        $end = $wrapper.find(".vi-path-end"),
        $data = $wrapper.find(".vi-curved-path-data");

    $wrapper.prepend("<svg class='vi-svg-wrapper' width='100%' height='100%'><path d=''/></svg>");

    var $svg = $(".vi-svg-wrapper"),
        $path = $svg.find("path"),
        curveCount = $data.attr("data-curved-points"),
        startFrom = $data.attr("data-start-from"),
        step, d;

    $(window).on("load resize", function () {
        // d="M200 0 Q 350 50, 200 100 T 200 250"
        // https://www.w3schools.com/graphics/tryit.asp?filename=trysvg_path
        step = ($svg.height() - $end.height()) / curveCount;

        // starting point
        d = "M" + $svg.width() / 2 + " " + $begin.height() / 2 + " ";

        for (var i = 1; i <= curveCount - 1; i++) {
            var coordinate = "";
            if (i === 1) {
                Q1x = -350;
                if (startFrom === "from_right") {
                    Q1x = $svg.width() + 350;
                }

                Q1y = step / 2 + $begin.height();
                Q2x = $svg.width() / 2;
                Q2y = step + $begin.height();
                coordinate = "Q " + Q1x + " " + Q1y + ", " + Q2x + " " + Q2y;
            } else {
                Tx = $svg.width() / 2;
                Ty = step * i;
                coordinate = "T " + Tx + " " + Ty;
            }
            d += coordinate + " ";
        }

        // ending point
        d += "T " + $svg.width() / 2 + " " + ($svg.height() - $end.height() * 0.9);

        // add path data
        $path.attr("d", d);
    });
};