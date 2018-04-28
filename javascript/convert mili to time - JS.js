var time = new Date();
time = time.getTime();
time = milisecToMinSec(time);
//=> min:sec
function milisecToMinSec(time){
	var t = new Date(time);
	var m = t.getMinutes();
	var s = t.getSeconds();
	return t = m+':'+s;	
}