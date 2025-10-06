<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Class Roster</title>
   <style>
         table { width: 500px; margin: 20px auto; border-collapse: collapse;}
         .course { background: #bbb;}
         .title { font-weight: bold; font-style: italic;}
         h1, h5 { text-align: center;}
         .title td { border-bottom: 4px double black;}
         td, th {padding: 3px;}
   </style>
</head>
<body>
   <?php require "header.php" ?>
   
   <table>
   <?php foreach( $out as $course) : ?>
          <tr class="course">
              <th colspan="4"><?= $course["code"] . " : " . $course["name"] ?> </th>
          </tr>
          <tr class='title'>
              <td>Name</td>
              <td>Surname</td>
              <td>Age</td>
              <td>CGPA</td>
          </tr>
          <?php foreach( $course["roster"] as $std) : ?>
              <tr>
                <td><?= $std["name"] ?></td>
                <td><?= $std["surname"] ?></td>
                <td><?= $std["age"] ?></td>
                <td><?= $std["cgpa"] ?></td>
              </tr>
          <?php endforeach ?>
   <?php endforeach ?>
   </table>
</body>
</html>
  