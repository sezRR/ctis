<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>q7</title>
</head>

<body>
    <?php
    $numbs = [];
    for ($i = 0; $i < 20; $i++) {
        $numbs[] = rand(0, 10);
    }

    echo 'Original Array: ' . join(' ', $numbs);

    $unique_arr = [];
    foreach ($numbs as $numb) {
        if (!in_array($numb, $unique_arr))
            $unique_arr[] = $numb;
    }

    echo '<br>';

    // sort($unique_arr);
    usort($unique_arr, function ($a, $b) {
        return $a <=> $b;
    });

    echo 'Duplicates Removed: ' . join(' ', $unique_arr);
    ?>
</body>

</html>