<?php
extract($_GET);

require_once './db.php';
$stmt1 = $db->prepare("SELECT * FROM MOTORBIKES WHERE ID = ?");
$stmt1->execute([$id]);
$motorbike = $stmt1->fetch(PDO::FETCH_ASSOC);

$stmt2 = $db->prepare("SELECT * FROM MOTORBIKE_PHOTO WHERE BIKE_ID = ?");
$stmt2->execute([$id]);
$motorbike_photos = $stmt2->fetchAll(PDO::FETCH_ASSOC);

if (!isset($selectedPhoto)) {
    $selectedPhoto = 0;
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .selected {
            border: 10px solid blue;
        }
    </style>
</head>

<body>
    <h1><?= $motorbike["title"] ?></h1>
    <img src="../assets/images/<?= $motorbike_photos[$selectedPhoto]["path"] ?>" alt="motorbike">
    <p><?= $motorbike["price"] ?> TL</p>
    <p>BRAND: <?= $motorbike["brand"] ?></p>
    <p>MODEL: <?= $motorbike["model"] ?></p>
    <p>YEAR: <?= $motorbike["year"] ?></p>
    <p>KM: <?= $motorbike["km"] ?></p>
    <p>COLOR: <?= $motorbike["color"] ?></p>
    <p>ENGINE: <?= $motorbike["engine"] ?></p>
    <a href="./">BACK</a>
    <?php if ($motorbike["status"] === '0'): ?>
        <a href="./buy.php?id=<?= $motorbike["id"] ?>">BUY</a>
    <?php endif; ?>
    <div>
        <?php foreach (range(0, count($motorbike_photos) - 1) as $i): ?>
            <?php
            $query = http_build_query([
                "id" => $id,
                "selectedPhoto" => $i
            ])
            ?>
            <a href="./details.php?<?= $query ?>">
                <img class="<?= (int)$selectedPhoto === $i ? 'selected' : ' ' ?>" src="../assets/images/<?= $motorbike_photos[$i]["path"] ?>" alt="motorbike">
            </a>
        <?php endforeach; ?>
    </div>
</body>

</html>