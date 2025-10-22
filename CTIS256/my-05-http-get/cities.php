<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    require_once './world_db.php';

    extract($_GET);

    $lookup_countries = array_column($countries, null, "code");
    $lookup_cities = array_filter($cities, function ($city) use ($code) {
        return $city["code"] === $code;
    })
    ?>

    <h1>Cities in <?= $lookup_countries[$code]["name"] ?></h1>

    <table>
        <thead>
            <tr>
                <th>City</th>
                <th>Population</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($lookup_cities as $city): ?>
                <tr>
                    <td><?= $city["name"] ?></td>
                    <td><?= $city["population"] ?></td>
                </tr>
            <?php endforeach ?>
        </tbody>
    </table>

    <a href="/my-05-htt-get/index.php?page=<?= isset($page) && !empty($_GET['id']) ? $page : 1 ?>">Go Back to Main</a>
</body>

</html>