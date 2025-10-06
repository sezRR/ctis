<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>HTTP Response</title>
        <style>
            p { font-size : <?= rand(12,48) ?>px ; }
        </style>
        <script>
            alert(<?= rand(1,100) ?>)
        </script>
    </head>
    <body>
        <h1>Introduction to PHP</h1>
        <p>Random Number : <?php echo rand(0,100) ?></p>
    </body>
</html>
