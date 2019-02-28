/**
 * GSAP Animation with scroll magic
 */
TWC.gsapAnimation = function () {
    /* Letter fly from bottom */
    $(".txt_animation_fly_from_bottom").each(function (i, element) {
        // Split text
        var twcSplitText = new SplitText(element, {type: "words,chars"}),
            $letter = $(twcSplitText.chars);

        // Set animation
        var timeline = new TimelineLite({pause: true});
        timeline.staggerFrom($letter, .8, {
            rotation: "-60deg",
            y: "100%",
            autoAlpha: 0,
            ease: Power3.easeInOut
        }, .03, 0);
        timeline.pause();

        // Set Scroll magic scene
        var controller = new ScrollMagic.Controller(),
            scene = new ScrollMagic.Scene({triggerElement: element})
                .addTo(controller)
                .on("enter", function (e) {
                    timeline.play().timeScale(1);
                });
        // debug mode
        //scene.addIndicators();
    });

    /* Letter fly from top */
    $(".txt_animation_fly_from_top").each(function (i, element) {
        // Split text
        var twcSplitText = new SplitText(element, {type: "words,chars"}),
            $letter = $(twcSplitText.chars);

        // Set animation
        var timeline = new TimelineLite({pause: true});
        timeline.staggerFrom($letter, .8, {
            rotation: "-60deg",
            y: "-100%",
            autoAlpha: 0,
            ease: Power3.easeInOut
        }, .03, 0);
        timeline.pause();

        // Set Scroll magic scene
        var controller = new ScrollMagic.Controller(),
            scene = new ScrollMagic.Scene({triggerElement: element})
                .addTo(controller)
                .on("enter", function (e) {
                    timeline.play().timeScale(1);
                });
        // debug mode
        //scene.addIndicators();
    });

    /* Letter fly from left */
    $(".txt_animation_fly_from_left").each(function (i, element) {
        // Split text
        var twcSplitText = new SplitText(element, {type: "words,chars"}),
            $letter = $(twcSplitText.chars);

        // Set animation
        var timeline = new TimelineLite({pause: true});
        timeline.staggerFrom($letter, .8, {
            rotation: "-60deg",
            x: "-100%",
            autoAlpha: 0,
            ease: Power3.easeInOut
        }, .03, 0);
        timeline.pause();

        // Set Scroll magic scene
        var controller = new ScrollMagic.Controller(),
            scene = new ScrollMagic.Scene({triggerElement: element})
                .addTo(controller)
                .on("enter", function (e) {
                    timeline.play().timeScale(1);
                });
        // debug mode
        //scene.addIndicators();
    });

    /* Letter zoom in */
    $(".txt_animation_zoom_in").each(function (i, element) {
        // Split text
        var twcSplitText = new SplitText(element, {type: "words,chars"}),
            $letter = $(twcSplitText.chars);

        // Set animation
        var timeline = new TimelineLite({pause: true});
        timeline.staggerFrom($letter, .8, {
            scale: "1.7",
            autoAlpha: 0,
            ease: Power3.easeInOut
        }, .03, 0);
        timeline.pause();

        // Set Scroll magic scene
        var controller = new ScrollMagic.Controller(),
            scene = new ScrollMagic.Scene({triggerElement: element})
                .addTo(controller)
                .on("enter", function (e) {
                    timeline.play().timeScale(1);
                });
        // debug mode
        //scene.addIndicators();
    });

    /* Stagger show items */
    $(".twc_stagger_show_items, .slick-track, .list__items, body.blog .posts-highlight__group").each(function (i, element) {
        // Set animation
        var timeline = new TimelineLite({pause: true});
        timeline.staggerFrom($(element).children('div'), .8, {
            autoAlpha: 0,
            ease: Power3.easeInOut
        }, .1, 0);
        timeline.pause();

        // Set Scroll magic scene
        var controller = new ScrollMagic.Controller(),
            scene = new ScrollMagic.Scene({triggerElement: element})
                .addTo(controller)
                .on("enter", function (e) {
                    timeline.play().timeScale(1);
                });
        // debug mode
        //scene.addIndicators();
    });
};