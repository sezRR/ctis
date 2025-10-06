<?php
   // "report.php" is the entry point.
   // Normally, backend.php and frontend.php are inaccessible from the browser.
   require_once "./src/backend.php" ;   //  --> $out  (global variable created by backend)

   // render:
   require_once "./src/frontend.php" ;  // <--  $out 