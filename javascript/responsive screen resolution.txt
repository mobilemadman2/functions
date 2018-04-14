/* responsive for modal column */
//BOOTSTRAP SIZE: xs < 768px | sm >= 768px | md >= 992px | lg >=1200px
function scr_reso(){
	var scr;
	if($(window).innerWidth()<768){ return scr = "xs";}
	else 
	if($(window).innerWidth()>=768 && $(window).innerWidth()<992) { return scr = "sm";}
	else
	if($(window).innerWidth()>=992 && $(window).innerWidth()<1200) { return scr = "md";}
	else { return scr = "lg";}
}
$(window).resize(function(e) {
    if(scr_reso()=='lg'){

	} else {

	}
});

// scr_reso()

/* CSS selector */
$(".bmp-content").css({"padding":"0 1vw","font-size":"20px"});
$(".bmp-inside-container h1").css("font-size","40px");