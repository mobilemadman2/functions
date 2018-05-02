<?php
/**
 * Get monday of week
 * @param null $date
 * @return string
 */
function getStartOfWeekDate($date = null)
{
	if(!isset($date) || empty($date)){
		$date = date("Y-m-d");
	}
	$date = new DateTime($date);

	if ($date->format('N') == 1) {
		// If the date is already a Monday, return it as-is
		$temp = $date;
	} else {
		// Otherwise, return the date of the nearest Monday in the past
		// This includes Sunday in the previous week instead of it being the start of a new week
		$temp = $date->modify('last monday');
	}
	return $temp->format("Y-m-d");
}