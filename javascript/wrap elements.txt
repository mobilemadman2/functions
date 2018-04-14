function wrapFooter(){
        var divs = $(".footer-inner .row-footer-1 #menu-footer li");
        divs.slice(0, 3).wrapAll("<div class='col'></div>");
        divs.slice(3, 5).wrapAll("<div class='col'></div>");
        divs.slice(5, divs.length).wrapAll("<div class='col'></div>");
    }

var divs = $("div > div");
for(var i = 0; i < divs.length; i+=3) {
  divs.slice(i, i+3).wrapAll("<div class='new'></div>");
}