<?php

// https://stackoverflow.com/questions/3207749/i-have-2-dates-in-php-how-can-i-run-a-foreach-loop-to-go-through-all-of-those-d?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

$begin = new DateTime( "2015-07-03" );
$end   = new DateTime( "2015-07-09" );

for($i = $begin; $i <= $end; $i->modify('+1 day')){
	echo $i->format("Y-m-d");
}

// If you dont need the last date just remove = from the condition.