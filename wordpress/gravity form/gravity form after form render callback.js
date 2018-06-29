/**
 * Gravity form - after form render callback
 * https://stackoverflow.com/questions/29921438/jquery-callback-after-gravity-form-submit
 */
$(document).bind('gform_post_render', function(){
    console.log("Hello!");
});