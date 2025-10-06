<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1>PHP Arrays</h1>
    <?php
    // 1. Sequential 
    $nums = [9, 5, 2, 7, 4];

    // convert array to string
    echo "<p>", join(" - ", $nums), "</p>";

    // dynamic
    $nums[] = 8;
    echo "<p>", join(" - ", $nums), "</p>";

    // size of an array
    echo "<p>The length of the array is ", count($nums), "</p>";

    // Traversing an array
    // 1. standard for loop (read/write)
    $sum = 0;
    for ($i = 0; $i < count($nums); $i++) {
        $sum += $nums[$i];
    }
    echo "<p>Sum is $sum</p>";

    // 2. foreach is like for-of in js  (read only access)
    $sum = 0;
    foreach ($nums as $n) {
        $sum += $n;
    }
    echo "<p>Sum is $sum</p>";


    ?>
</body>

</html>