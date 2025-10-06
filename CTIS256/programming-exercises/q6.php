<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q6</title>
</head>

<body>
    <?php
    $even = [];
    $odd = [];
    $numbs = [];
    for ($i = 0; $i < 20; $i++) {
        $numb = rand(1, 20);
        $numbs[] = $numb;
        if ($numb % 2 === 0) {
            $even[] = $numb;
        } else {
            $odd[] = $numb;
        }
    }

    echo "Original Array: " . join(' ', $numbs) . '<br>';
    echo 'Odd-Even Formation: ' . join(' ', $odd) . join(' ', $even);
    ?>
</body>

</html>