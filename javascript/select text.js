function SelectText(element) {
    var doc = document
        , text = doc.getElementById(element)
        , range, selection
    ;    
    if (doc.body.createTextRange) {
        range = document.body.createTextRange();
        range.moveToElementText(text);
        range.select();
    } else if (window.getSelection) {
        selection = window.getSelection();        
        range = document.createRange();
        range.selectNodeContents(text);
        selection.removeAllRanges();
        selection.addRange(range);
    }
}

document.onclick = function(e) {    
    if (e.target.className === 'click') {
        SelectText('selectme');
    }
};
<div id="selectme"><p>Some text goes here!</p><p>Moar text!</p></div>
<p class="click">Click me!</p>