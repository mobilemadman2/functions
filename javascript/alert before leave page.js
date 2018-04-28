//jQuery
$(window).bind('beforeunload', function(){
  return 'Are you sure you want to leave?';
});
//javascript
window.onbeforeunload = function(){
  return 'Are you sure you want to leave?';
};

note: the returned string is just use for meaning, it doesn't show on browser.
So, you can return anything and you have to return something.