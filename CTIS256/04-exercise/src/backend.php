<?php

   require "db.php" ;

   // backend prepares "out" array to be processed by frontend
   $out = [] ;
   $now = new DateTime() ; // current date
   foreach( $courses as $cid => $cdata) {
     $course = [ "code" => $cid, "name" => $cdata["name"], "roster" => []] ;
     // sequentially search the registered students
     foreach( $register as $reg) {
        if ( $reg["course_id"] === $cid) {
            // filter out student ids taking course $cid
            $std = getStudent($reg["std_id"]) ; // convert id to std data
            $std["age"] = getAge($std["bday"]) ; // calculate age
            array_push($course["roster"], $std) ; 
        }
     }
      array_push($out, $course) ;
    }

   function getAge($bday) {
     global $now ; // I want to use $now
     // convert string date format to DateTime object format.
     $bday = DateTime::createFromFormat("d-m-Y", $bday) ;
     $days = $now->diff($bday)->days ; // total number of days
     return round($days/365, 1) ; 
   }
   // unit test getAge
   // var_dump( getAge("23-02-2000")) ; 

   function getStudent($id) {
      // sequential search for student by id
      global $students ; 
      foreach( $students as $std) {
        if ( $std["id"] === $id) return $std ;
      }
   }
   // unit test getStudent
   // var_dump( getStudent(20142645)) ;
