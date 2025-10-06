<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q4</title>
</head>

<body>
    <?php
    $sum = 0;
    echo "[";
    for ($i = 0; $i < 10; $i++) {
        $generated = rand(1, 10);
        $sum += $generated;
        echo " $generated ";
    }
    echo "]<br>";

    echo "Sum: $sum<br>";

    $avg = $sum / 10;
    echo "Avg: $avg";
    ?>
</body>

</html>