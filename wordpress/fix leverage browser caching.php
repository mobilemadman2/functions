<?php
/*
 * Add lines of code below to .htaccess
 * ref: https://technumero.com/how-to-leverage-browser-caching-wordpress/


# TN - START EXPIRES CACHING #
ExpiresActive On
ExpiresByType text/css "access 1 month"
ExpiresByType text/html "access 1 month"
ExpiresByType image/gif "access 1 year"
ExpiresByType image/png "access 1 year"
ExpiresByType image/jpg "access 1 year"
ExpiresByType image/jpeg "access 1 year"
ExpiresByType image/x-icon "access 1 year"
ExpiresByType application/pdf "access 1 month"
ExpiresByType application/javascript "access 1 month"
ExpiresByType text/x-javascript "access 1 month"
ExpiresByType application/x-shockwave-flash "access 1 month"
ExpiresDefault "access 1 month"
               # TN - END EXPIRES CACHING #

               # TN - BEGIN Cache-Control Headers
               <ifModule mod_headers.c>
<filesMatch "\.(ico|jpe?g|png|gif|swf)$">
            Header set Cache-Control "public"
                                     </filesMatch>
<filesMatch "\.(css)$">
            Header set Cache-Control "public"
                                     </filesMatch>
<filesMatch "\.(js)$">
            Header set Cache-Control "private"
                                     </filesMatch>
<filesMatch "\.(x?html?|php)$">
            Header set Cache-Control "private, must-revalidate"
                                     </filesMatch>
</ifModule>
  # TN - END Cache-Control Headers

  # TN - BEGIN Turn ETags Off
  FileETag None
# TN - END Turn ETags Off


*/