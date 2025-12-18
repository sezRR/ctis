<?php

require_once './db.php';
extract($_GET);
extract($_POST);

$todos = $db->query("SELECT * FROM TODO")->fetchAll(PDO::FETCH_ASSOC);

if (isset($op) && isset($id)) {
    $deleteStmt = $db->prepare("delete from todo where id = ?");
    $deleteStmt->execute([$id]);
    header("Location: ./");
}

if (isset($addOne)) {
    if (strlen(trim($addOne)) === 0) {
        header("Location: ./?errMissing=1");
        return;
    }

    $isExists = $db->query("SELECT * FROM TODO WHERE EXISTS (SELECT * FROM TODO WHERE action=$addOne)")->fetch();
    if ($isExists) {
        header("Location: ./?errExists=1");
        return;
    }

    $addStmt = $db->prepare("insert into todo (action) values (?)");
    $addStmt->execute([$addOne]);
    header("Location: ./");
}

if (!isset($errExists)) $errExists = 0;
if (!isset($errMissing)) $errMissing = 0;
if (!isset($showOverlay)) $showOverlay = 0;

?>

<!DOCTYPE html>
<html>

<head>
    <title>MY DB3 SOLUTION</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="style.css" rel="stylesheet" type="text/css" />
</head>

<body>
    <div>
        <div class="header">
            <div class="container">
                <h1 class="header__title">CTIS256 - Midterm #2</h1>
                <h2 class="header__subtitle">by Sezer Tetik</h2>
            </div>
        </div>
        <div class="container">
            <div>
                <a href="./?showOverlay=1" class="big-button <?= count($todos) === 0 ? 'disabled' : '' ?>">What should I do?</a>
            </div>
            <div class="widget">
                <div>
                    <div class="widget-header">
                        <h3 class="widget-header__title">Your Options</h3>
                        <h3 class="widget-header__title"><?= count($todos) ?></h3>
                    </div>
                    <div>
                        <?php if (count($todos) === 0): ?>
                            <p class="widget__message">List is empty</p>
                        <?php else: ?>
                            <?php foreach ($todos as $id => $todo): ?>
                                <div class="option">
                                    <p class="option__text"><?= ($id + 1) . '. ' . $todo["action"] ?></p>
                                    <a href="./?op=delete&id=<?= $todo["id"] ?>" class="button button--link option__trash">&#x1f5d1;</a>
                                </div>
                            <?php endforeach; ?>
                        <?php endif; ?>
                    </div>
                </div>
                <div>
                    <p class="add-option-error">
                        <?= $errExists ? 'It already exists!' : '' ?>
                        <?= $errMissing ? 'Type some value' : '' ?>
                    </p>
                    <form method="POST" class="add-option">
                        <input class="add-option__input" autocomplete="Off" type="text" name="addOne">
                        <button class="button">Add One</button>
                    </form>
                </div>
            </div>
        </div>
    </div>
    <?php if ($showOverlay): ?>
        <div class="overlay">
            <div class="modal">
                <h1 class="modal__title">My Suggestion &#x1f609;</h1>
                <p class="modal__body"><?= $todos[rand(0, count($todos) - 1)]["action"] ?></p>
                <a class="button" href="./">OK</a>
            </div>
        </div>
    <?php endif; ?>
</body>

</html>