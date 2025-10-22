<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Input : Web Form</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: content-box;
        }

        body {
            display: flex;
            gap: 1.25rem;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            margin-top: 2rem;
        }

        .submit-container {
            display: flex;
            gap: 1rem;
            align-items: center;
            justify-content: center;
            margin-top: 1rem;

            & button {
                width: 4rem;
            }
        }
    </style>
</head>

<body>
    <?php
    extract($_POST);

    if (isset($number1) && isset($number2) && (isset($opAdd) || isset($opSubtract))) {
        require_once './arithmetics.php';
    } else {
        require_once './form.php';
    }
    ?>
</body>

</html>