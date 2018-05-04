<?php
/**
 * Get first/last date of week/month/year
 *
 * @param $type
 * @param $position
 * @param null $date
 *
 * @return bool|mixed
 */
function get_first_last_day( $type, $position, $date = null ) {
	// If not set $date get today
	if ( ! isset( $date ) || empty( $date ) ) {
		$date = TODAY;
	}
	$date   = new DateTime( $date );
	$result = array(
		'first' => '',
		'last'  => ''
	);
	switch ( $type ) {
		case "week":
			if ( $date->format( 'N' ) == 1 ) {
				// If the date is already a Monday, return it as-is
				$result['first'] = $date->format( "Y-m-d" );
			} else {
				// Otherwise, return the date of the nearest Monday in the past
				// This includes Sunday in the previous week instead of it being the start of a new week
				$temp            = $date->modify( 'last monday' );
				$result['first'] = $temp->format( "Y-m-d" );
			}
			$result['last'] = TODAY;
			break;
		case "month":
			$result = array(
				'first' => date( 'Y-m-01', strtotime( $date->format( "Y-m-d" ) ) ),
				'last'  => date( 'Y-m-t', strtotime( $date->format( "Y-m-d" ) ) )
			);
			break;
		case "year":
			$result = array(
				'first' => date( 'Y-01-01', strtotime( $date->format( "Y-m-d" ) ) ),
				'last'  => date( 'Y-12-t', strtotime( $date->format( "Y-m-d" ) ) )
			);
			break;
		default:
			return false;
	}

	return $result[ $position ];
}