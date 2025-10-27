<?php
$calculateVip = fn($price) => isset($isVip) && $isVip ? $price * 2 : $price;
$totalPrice = $calculateVip($singers[$singer]["price"]) * $nbPerson;
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <table>
        <tr>
            <td>Singer:</td>
            <td><?= $singers[$singer]["name"] ?></td>
        </tr>
        <tr>
            <td>VIP :</td>
            <td><?= isset($isVip) ? "YES" : "NO" ?></td>
        </tr>
        <tr>
            <td># of Person :</td>
            <td><?= $nbPerson ?></td>
        </tr>
        <tr>
            <td>Total Price :</td>
            <td><?= $totalPrice ?></td>
        </tr>
    </table>
    <p>
        <?php

        $query = [
            "singer" => $singer,
            "nbPerson" => $nbPerson,
        ];

        if (isset($isVip))
            $query["isVip"] = "on";
        else
            $query["isVip"] = null;

        $stickyQueryString = http_build_query($query);
        ?>
        <a href="./?<?= $stickyQueryString ?>">BACK</a>
    </p>
</body>

</html>