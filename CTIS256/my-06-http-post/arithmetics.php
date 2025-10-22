<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Output : Arithmetic</title>
</head>

<body>
    <h1>Arithmetics</h1>
    <span>Operation: <?= isset($opAdd) ? 'Addition' : 'Subtraction' ?></span>
    <span>n1: <?= $number1 ?></span>
    <span>n2: <?= $number2 ?></span>
    <?php if (isset($opAdd)) : ?>
        <span>Result: <?= $number1 + $number2 ?></span>
    <?php else : ?>
        <span>Result: <?= $number1 - $number2 ?></span>
    <?php endif; ?>
    <a href="/my-06-http-post/index.php">Go back to main</a>
</body>

</html>