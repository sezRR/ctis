<?php

require_once './db.php';
$motorbikes = $db->query("SELECT * FROM MOTORBIKES")->fetchAll(PDO::FETCH_ASSOC);
$pattern = '/^[A-Z]{2}[0-9]{3}-[0-9]{2}$/';
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <table>
        <thead>
            <tr>
                <td></td>
                <td>Brand</td>
                <td>Model</td>
                <td>Title</td>
                <td>Price</td>
                <td>Discount</td>
                <td>Status</td>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($motorbikes as $id => $motorbike): ?>
                <tr>
                    <td><a href="./details.php?id=<?= $motorbike["id"] ?>">
                            <img src="../assets/images/<?= $motorbike['profile'] ?> ?>" alt="motorbike">
                        </a></td>
                    <td><?= $motorbike["brand"] ?></td>
                    <td><?= $motorbike["model"] ?></td>
                    <td><?= $motorbike["title"] ?></td>
                    <td><?= $motorbike["price"] ?></td>
                    <td><?= preg_match('/^[A-Z]{2}[0-9]{3}-[0-9]{2}$/', $motorbike["coupon"]) === 1 ? "YES" : "NO" ?></td>
                    <td><?= $motorbike["status"] === '0' ? "On Sale" : "SOLD" ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>

</html>