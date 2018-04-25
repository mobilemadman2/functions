/**
     * Break items into column
     * @param num_of_col - int - number of columns you need
     * @param $items - object - list of items
     * 1 2 3 4 5 6 => col[1, 2] col[3, 4] col[5, 6]
     */
    function columnize(num_of_col, $items){
        var length = $items.length;
        var items_per_col = Math.ceil( length/num_of_col );
        for(var i=0; i<length; i+=items_per_col){
            $items.slice(i, i+items_per_col).wrapAll("<div class='social-feed-col'></div>");
        }
    }
    columnize(3, $('#cff .cff-item'));