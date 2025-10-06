<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>Assoc. Array/Hashmap</h1>
    <?php
       // creating an assoc. array
       $person = [
          "name" => "ahmet",
          "id" => 1234,
          "cgpa" => 3.14
       ] ;
       echo "<p>Id of the person is {$person["id"]}</p>" ;
       $person["age"] = 24 ; 
       var_dump($person) ;

       // Traversing (visiting) items
       foreach( $person as $k => $v) {
         echo "<p>Key: $k ==>  Value: $v</p>" ;
       }

       // Mixed Array
       $cars = [
          ["brand" => "Volvo", "model" => "XC90", "price" => 100000],
          ["brand" => "Mazda", "model" => "CX3", "price" => 60000],
          ["brand" => "Citroen", "model" => "DS5", "price" => 80000],
       ] ;

       echo "<p>First car's model is {$cars[0]["model"]}</p>" ;

       // Rendering a mixed array into an HTML table in a general way
       echo "<table>" ;
       // First Row, Header Row
       echo "<tr>" ;
         foreach( $cars[0] as $k => $v) {
            echo "<th>$k</th>" ;
         }
       echo "</tr>" ;

       // list of all records or objects
       foreach( $cars as $car) {
         echo "<tr>" ;
         foreach( $car as $v) {
            echo "<td>$v</td>" ;
         }
         echo "</tr>" ;
       }
       
       echo "</table>" ;
       
      

    ?>
</body>
</html>