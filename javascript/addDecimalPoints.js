function addDecimalPoints(str,dot) {
        str=str.replace(/\D/g, '');
        var inputValue = str.replace('.', '').split("").reverse().join(""); //xoa dau cham dang co va reverse
        var newValue = '';
        for (var i = 0; i < inputValue.length; i++) {
            if (i % dot == 0) {
                newValue += '.';
            }
            newValue += inputValue[i];
        }
        str = newValue.split("").reverse().join("");
		str = str.slice(0,str.length-1);//xóa dấu chấm bị dư
		return str;
    }