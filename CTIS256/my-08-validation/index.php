<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    $errors = [];
    $isValidTypeNbPerson = fn($nbPerson) => is_numeric($nbPerson);
    $isValidNbPerson = fn($nbPerson) => $nbPerson >= 1 && $nbPerson <= 6;

    $singers = [
        "0" => ["price" => 75, "name" => "Teoman"],
        "1" => ["price" => 35, "name" => "Mor ve Ötesi"],
        "2" => ["price" => 50, "name" => "Feridun Düzağaç"]
    ];

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        extract($_POST);

        if (!$isValidTypeNbPerson($nbPerson))
            $errors[] = 1;
        if (!$isValidNbPerson($nbPerson))
            $errors[] = 2;

        if (!empty($errors))
            $_SERVER["REQUEST_METHOD"] = "GET";
        else
            require_once "./form_output_view.php";
    }

    if ($_SERVER["REQUEST_METHOD"] == "GET") {
        extract($_REQUEST);
        require_once "./form_input_view.php";

        foreach ($errors as $code)
            if ($code === 1)
                echo '<p class="err_msg">Not an integer value</p>';
            else if ($code === 2)
                echo '<p class="err_msg">Not a valid integer [1-6]</p>';
    }
    ?>
</body>

</html>