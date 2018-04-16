$user = wp_get_current_user();
$allowed_roles = array('editor', 'administrator', 'author');
if( array_intersect($allowed_roles, $user->roles ) ){
	// stuff here for user roles that can edit pages: editors, administrators and author
}