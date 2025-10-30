<?php
include_once "./data.php";
extract($_GET);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="assets/css/materialize.min.css">
    <title>Given Page Design</title>
    <style>
        .error {
            color: red;
            font-size: 24px;
        }
    </style>
</head>

<body>
    <div class="container">
        <div class="row">
            <div class="col s12">
                <table class="striped">
                    <thead>
                        <tr>
                            <th>University</th>
                            <th>Country</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($universities as $university => $attr): ?>
                            <?php
                            $query = http_build_query([
                                "selectedUni" => htmlspecialchars($university)
                            ]);
                            ?>
                            <tr>
                                <td><a href="q.php?<?= $query  ?>"><?= $university ?></a></td>
                                <td><?= $attr["country"] ?></td>
                            </tr>
                        <?php endforeach ?>
                </table>
            </div>
        </div>
        <?php if (isset($selectedUni)): ?>
            <?php
            $universityDetails = $universities[$selectedUni];
            ?>
            <div class="row">
                <div class="col s12">
                    <h5>Erasmus Students at <?= $universityDetails["longname"] ?></h5>

                    <?php if (isset($universityDetails["students"])): ?>
                        <ul class="collection">
                            <?php foreach ($universityDetails["students"] as $students): ?>
                                <li class="collection-item avatar">
                                    <img src="images/<?= $students["img"] ?>" class="circle">
                                    <p><?= $students["name"] ?></p>
                                    <p><?= $students["year"] ?></p>
                                    <p><?= $students["semester"] ?></p>
                                </li>
                            <?php endforeach ?>
                        </ul>
                    <?php else: ?>
                        <span class="error">Student not found</span>
                    <?php endif; ?>
                </div>
            </div>
        <?php endif ?>
    </div>
</body>

</html>