<?php
include_once "../assets/db.php";
extract($_GET);
$favorites = $favorites ?? "";
$favorites = explode(",", $favorites);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q1</title>
    <link rel="stylesheet" href="../assets/app.css">
</head>

<body>
    <div class="container">
        <div id="fav" class="fav">
            <span>My favorites: </span>
            {
            <?= implode(" ", $favorites) ?>
            }
        </div>
        <a class="btn" href="./q1.php">RESET</a>
        <table>
            <thead>
                <tr>
                    <th>Emoji</th>
                    <th>Id</th>
                    <th>Full Name</th>
                    <th>Favorites</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $implodedFavorites = implode(",", $favorites);
                ?>
                <?php foreach ($people as $id => $attr): ?>
                    <?php
                    $qs = http_build_query([
                        "favorites" => implode(",", [...$favorites, $attr["emoji"]]),
                    ]);
                    $isSelected = in_array($attr["emoji"], $favorites);
                    ?>
                    <tr class="<?= $isSelected ? "selected" : "" ?>">
                        <td class="emoji">
                            <?php if (!$isSelected): ?>
                                <a href="./q1.php?<?= $qs ?>">
                                    <?= $attr["emoji"] ?>
                                </a>
                            <?php else: ?>
                                <span>
                                    <?= $attr["emoji"] ?>
                                </span>
                            <?php endif ?>
                        </td>
                        <td><?= $id ?></td>
                        <td><?= $attr["name"] . " " . $attr["lastname"] ?></td>
                        <td>{ <?= implode(" ", array_map(function ($favId) use ($people) {
                                    return $people[$favId]["emoji"];
                                }, $attr["fav"])) ?> }</td>
                    </tr>
                <?php endforeach ?>
            </tbody>
        </table>
    </div>
</body>

</html>