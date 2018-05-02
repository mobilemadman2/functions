https://github.com/processing/p5.js/wiki/Loading-external-files:-AJAX,-XML,-JSON
$(document).ready(function(){
  $.ajax({
    url: "http://api.openweathermap.org/data/2.5/weather?APPID=YOUR_API_KEY&id=5128581&units=imperial",
    dataType: 'json',
    success: function(data) {
      alert("Temperature is: " + data.main.temp );
    },
    error: function() {
      alert("error");
    }
  });        
});