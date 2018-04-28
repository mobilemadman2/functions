<div id="links">
</div>

<script>
var strLinks = '';

for (var i = 1; i <= 55; i++) {
    strLinks += '<a href="'+ i +'.html"><img src="images/'+ i +'.jpg" width="119" height="121" alt="" /></a>';
}

document.getElementById("links").innerHTML = strLinks;
</script>

//nen dat script duoi tag can loop