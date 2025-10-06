<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Functions</h1>
    <?php
       // Scopes: Super Global, Global, Local
       // Super Global: variables created by PHP Engine
       // $_SERVER, $_POST, $_GET, $_SESSION, $_COOKIE
       // $_SERVER : is an assoc. array that contains all information about
       // Http Request Packet and Web Server.
       // REMOTE_ADDR : Ip address of the browser.
       echo "<h3>\$_SERVER super global array</h3>" ;
       echo "<p>Client IP : " , $_SERVER["REMOTE_ADDR"], "</p>" ;
       echo "<p>Server port : " ,  $_SERVER["HTTP_HOST"], "</p>" ;
       echo "<p>User Agent : " , $_SERVER["HTTP_USER_AGENT"], "</p>" ;
       echo "<p>Server : " , $_SERVER["SERVER_SOFTWARE"], "</p>" ;
       echo "<p>Requested File : " , $_SERVER["PHP_SELF"], "</p>" ;
       echo "<p>Requested File : " , $_SERVER["SCRIPT_NAME"], "</p>" ;
       echo "<p>Requested File : " , $_SERVER["SCRIPT_FILENAME"], "</p>" ;
       echo "<p>Requested File : " , basename($_SERVER["PHP_SELF"]), "</p>" ;
       echo "<p>Document Root : " ,  $_SERVER["DOCUMENT_ROOT"], "</p>" ;
       echo "<p>Server Port : " ,  $_SERVER["SERVER_PORT"], "</p>" ;
       echo "<p>Request Method : " , $_SERVER["REQUEST_METHOD"] , "</p>" ;
       echo "<p>Request URI : " , $_SERVER["REQUEST_URI"] , "</p>" ;
       echo "<p>Query String : " ,  $_SERVER["QUERY_STRING"], "</p>" ;          

       function add($n1, $n2) {  
          // PHP Engine creates arguments (local vars.)
          // $n1 = 5 ;
          // $n2 = 4 ;

         $tmp = $n1 + $n2 ; // local variable
         return $tmp ; 

         // PHP Engine deletes all local vars. ($n1, $n2 and $tmp)
       }

       $sum = add(5, 4) ; // sum is a global var.

       echo "<h3>Return a composite from a Function</h3>" ;
       // a function can return composite value. (array or object)
       function ops($n1, $n2) {
        return ["add" => $n1 + $n2, "mul" => $n1 * $n2 ] ;
       }

       var_dump( ops(3, 4)) ;

       echo "<h3>Global Var in Function Body</h3>" ;
       $IP = "139.179.33.2" ; // global variable
       function info() {
           global $IP ; // to access user defined global vars.
           echo "<p>IP : " , $IP, "</p>" ; 
           echo "<p>Port : ", $_SERVER["REMOTE_PORT"] , "</p>" ;
       }
       info() ; 

       // Parameter Passing
       // Pass by value
       echo "<h3>Passing Primitives</h3>" ;
       $x = 5 ;
       function updateV($p) {  // $p = $x ; creates a new copy
         $p = 10 ;
       }
       updateV($x) ;
       echo "<p>By Value : \$x : $x </p>" ;

       // Pass by reference
       function updateR(&$p) {  // $p = &$x ; creates a reference
        $p = 10 ;
      }
      updateR($x) ;
      echo "<p>By Reference : \$x : $x </p>" ;

      // PAY CLOSE ATTENTION TO ARRAYS
      echo "<h3>Passing Arrays</h3>" ;
      $arr = [0 , 1] ; 
      function changeV($n) {  // $n = $arr 
         $n[0] = 100 ;
      }
      changeV($arr) ;
      echo "<p>By Value : [" , join(" , " , $arr) , "]</p>" ;

      // pass by reference
      function changeR(&$n) {  // $n =& $arr 
        $n[0] = 100 ;
     }
     changeR($arr) ;
     echo "<p>By Reference : [" , join(" , " , $arr) , "]</p>" ;

    ?>
</body>
</html>