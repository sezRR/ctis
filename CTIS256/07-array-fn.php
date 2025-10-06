<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Required Array Functions</h1>
    <?php
       $nums = [1, 2, 3, 4] ; 
       echo "<p>", join(" , " , $nums), "</p>" ;

       // Array Assignment!!
       echo "<h3>Array Assignment</h3>" ;
       $copy = $nums ;  // creates a copy of the array
       // $copy =& $nums ;  // creates a reference to the array

       shuffle($copy) ; //
       echo "<p>Original : ", join(" , " , $nums), "</p>" ;
       echo "<p>Shuffle  : ", join(" , " , $copy), "</p>" ;

       // Add
       echo "<h3>Adding new item(s)</h3>" ;
       array_unshift($nums, -1, 0) ; 
       array_push($nums, 5, 6) ; 
       echo "<p>", join(" , " , $nums), "</p>" ;
       // Insert
       array_splice($nums, 3, 0, [11, 12]) ;
       echo "<p>", join(" , " , $nums), "</p>" ;

       // Delete
       echo "<h3>Deleting item(s)</h3>" ;
       $first = array_shift($nums) ; // remove the first
       $last = array_pop($nums) ; // remove the last
       echo "<p>", join(" , " , $nums), "</p>" ;
       array_splice($nums, 5, 1) ;
       echo "<p>", join(" , " , $nums), "</p>" ;
       // Replace
       array_splice($nums, 3, 1, [13]) ;
       echo "<p>", join(" , " , $nums), "</p>" ; 

       // Searching
       // Sequential Search for primitive arrays
       echo "<h3>Search an item in sequential primitive array</h3>" ;
       echo in_array(14, $nums) ? "<p>Yes</p>" : "<p>No</p>";

       // Search a key of an assoc array.
       // isset($var) : bool checks the existence of a variable.
       // isset($nums[7])
       echo "<h3>Search key in assoc. array</h3>" ;
       $person = ["name" => "ali", "cgpa" => 3.14] ; 
       echo isset($person["name"]) ? "<p>Yes</p>" : "<p>No</p>";  

       // Sorting
       // sorting a seqential array with primitive values
       echo "<h3>Sorting</h3>" ;
       echo "<h4>Sequential array with primitive values</h4>" ;
       sort($nums) ; 
       echo "<p>", join(" , " , $nums), "</p>" ;
       rsort($nums) ; 
       echo "<p>", join(" , " , $nums), "</p>" ;

       echo "<h4>Assoc. array with primitive values</h4>" ;
       // sorting an assoc. array by keys or values
       $colors = [ "c" => "white", "d" => "black",
                   "a" => "purple", "b" => "yellow"] ;
       var_dump($colors) ; 
       //  by values
       asort($colors) ;  // asc order
       var_dump($colors) ; 
       arsort($colors) ; // desc order
       var_dump($colors) ;

       // by keys
       echo "<h4>Assoc. array with keys</h4>" ;
       ksort($colors) ;  // asc
       var_dump($colors) ;
       krsort($colors) ; // desc
       var_dump($colors) ;

       // sorting mixed array (list of assoc arrays)
       $cars = [
         [ "brand" => "Volvo", "model" => "XC90", "price"=> 10000],
         [ "brand" => "Mazda", "model" => "CX3", "price"=> 8000],
         [ "brand" => "Citroen", "model" => "DS5", "price"=> 9000],
       ] ;

       // sorting mixed array with user defined comparison func.
       echo "<h4>Mixed Array</h4>" ;
       usort($cars, function($a, $b) {
          // comparison function
          // returns positive value : swap occurs
          // <=> : spaceship operator : 
          // a <=> b :  a > b : 1 , a < b : -1, a == b : 0
           return $a["price"] <=> $b["price"]  ; 
       }) ;
       var_dump($cars) ;
    ?>
</body>
</html>