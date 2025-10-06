<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Basics</title>
</head>
<body>
    <h1>PHP Basic Syntax</h1>
    <?php
      // this is php context
      /*
        PHP : loosely-typed (no type checking), dynamically-typed 
        Variable: all variables start with $ sign, case-sensitive
        Valid: $age, $Total, $_get   Invalid: $1age, $*age
        Variables:
        1. Primitive Types: int, float/double, string, boolean
        2. Composite/Reference Type: Array, Object
      */

      // primitive types
      $age = 25 ;     // (int) age is a variable, 25 : integer literal 
      $cgpa = 3.12 ;  // (float) 3.12 : float literal
      $done = true ; // (bool) true/false: boolean literal
      
      $firstname = "Ali" ;  // double quoted string: string with replacement
      $lastname = 'Gül' ;   // single quoted string: string without replacement

      // composite types
      $colors = ["red", "green", "blue"] ; // array
      $now = new DateTime() ; // object
      
      // output : putting a string into the body/payload part of HTTP Response Packet.
      echo "<p>Fullname is $firstname {$lastname}</p>" ; 
      echo '<p>Fullname is $firstname {$lastname}</p>' ; 
      var_dump($age) ; // only for debugging the value of variables

      // Concatenation: "."
      $salary = 150 ;
      $msg = "<p>Annual Salary is " . $salary * 12 . "\$</p>" ; 
      echo $msg ;

      // Unicode character set: more than 120.000 symbols
      echo "<p>Rocket symbol is \u{1f680} </p>" ;


      // Constants
      const PORT = 80 ;  // define a constant, no $ sign
      const IP = "139.179.34.23" ;
      const MSG = "Web Server is running at " . IP . ":" . PORT ;
      echo "<p>", MSG, "</p>" ; // "<p>MSG</p>" does not work

      // Expressions (construct that returns a VALUE) and Operators
      // Arithmetic, Logical, Relational Expressions
      // Arithmetic Expression: Operators (+,-,*,/,%, **, ++, --)
      // Relational Expression: Operators (>, >= , <, <= , == , !=, ===, !==)
      // Logical Expression: Operators ( &&, ||, !)
      $res = (($age * 3) + 20) / 2 + 5 ** 2 ; // arithmetic exprs.
      $remainingCourse = 0 ;
      $graduate = $cgpa > 2.0 && $remainingCourse === 0 ; // logical expr.

         
      // Ternary Operator : ?:  basically, it is a shorthand notation for if statement
      $color = $cgpa > 2.0 ? "green" : "red" ;

    ?>

</body>
</html>