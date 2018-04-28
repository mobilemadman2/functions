var numeric = [
    ['input1','input2'],
    ['input3','input4']
];
numeric[0][0] == 'input1';
numeric[0][1] == 'input2';
numeric[1][0] == 'input3';
numeric[1][1] == 'input4';

var obj = {
    'row1' : {
        'key1' : 'input1',
        'key2' : 'inpu2'
    },
    'row2' : {
        'key3' : 'input3',
        'key4' : 'input4'
    }
};
obj.row1.key1 == 'input1';
obj.row1.key2 == 'input2';
obj.row2.key1 == 'input3';
obj.row2.key2 == 'input4';

var mixed = {
    'row1' : ['input1', 'inpu2'],
    'row2' : ['input3', 'input4']
};
mixed.row1[0] == 'input1';
mixed.row1[1] == 'input2';
mixed.row2[0] == 'input3';
mixed.row2[1] == 'input4';

http://stackoverflow.com/questions/7545641/javascript-multidimensional-array