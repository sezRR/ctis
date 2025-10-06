<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q3</title>
</head>

<body>
    <?php
    $prev = 0;
    $curr = 1;
    for ($i = 1; $i <= 10; $i++) {
        echo "$i. $prev<br>";
        $temp = $curr;
        $curr += $prev;
        $prev = $temp;
    }
    ?>
</body>

</html>