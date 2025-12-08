<?php

require_once './db.php';
extract($_GET);

if (!isset($page)) {
    $page = 1;
}

$item_per_page = 3;

$offset = ((int)$page - 1) * $item_per_page;

$products_stmt = $db->prepare("SELECT * FROM PRODUCTS LIMIT :offset, :count");
$products_stmt->bindValue(':offset', (int)$offset, PDO::PARAM_INT);
$products_stmt->bindValue(':count', (int)$item_per_page, PDO::PARAM_INT);

$products_stmt->execute();
$products = $products_stmt->fetchAll(PDO::FETCH_ASSOC);

$product_count = $db->query("SELECT COUNT(*) FROM PRODUCTS")->fetch()[0];
$last_page = ceil($product_count / $item_per_page);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            display: flex;
            flex-direction: column;
            height: 90vh;
            justify-content: center;
            align-items: center;
            gap: 2rem;
        }

        .container {
            display: flex;
            gap: 1rem;

            a {
                display: block;

                &:is(.page) {
                    display: flex;
                    align-items: center;
                    justify-content: center;
                    aspect-ratio: 1;
                    width: 2rem;
                    background-color: lightsalmon;
                    text-decoration: none;
                    color: brown;
                    border-radius: 100%;

                    span {
                        font-size: 1.5em;
                    }
                }

                &:not(.page) {
                    margin: auto 0;
                }
            }

            .card {
                display: flex;
                flex-direction: column;
                gap: 1rem;
                border: 1px solid gray;
                padding: 1rem;

                .stars {
                    display: flex;
                    gap: 0.5rem;
                }
            }

            .disabled {
                pointer-events: none;
                cursor: default;
            }

            a.selected {
                background-color: coral;
                font-weight: bold;
            }
        }
    </style>
</head>

<body>
    <div class="container">
        <a href="./?page=<?= $page - 1 ?>" class="<?= $page - 1 < 1 ? 'disabled' : '' ?>">
            <img src="../assets/icon/prev.png" alt="">
        </a>
        <?php foreach ($products as $id => $product): ?>
            <div class="card">
                <img src="../assets/img/<?= $product["image"] ?>" alt="product image">
                <p><?= $product["title"] ?></p>
                <div class="stars">
                    <?php for ($i = 0; $i < $product["rate"]; $i++): ?>
                        <img src="../assets/icon/full.jpg" alt="filled star">
                    <?php endfor; ?>
                    <?php for ($i = 0; $i < 5 - $product["rate"]; $i++): ?>
                        <img src="../assets/icon/empty.jpg" alt="empty star">
                    <?php endfor; ?>
                </div>
                <span><?= $product["price"] ?> TL</span>
                <button>ADD</button>
            </div>
        <?php endforeach; ?>
        <a href="./?page=<?= $page + 1 ?>" class="<?= $page + 1 > $last_page  ? 'disabled' : '' ?>">
            <img src="../assets/icon/next.png" alt="">
        </a>
    </div>
    <div class="container">
        <?php for ($i = 1; $i <= $last_page; $i++): ?>
            <a href="./?page=<?= $i ?>" class="page <?= (int)$page === $i ? 'selected' : '' ?>">
                <span><?= $i ?></span>
            </a>
        <?php endfor; ?>
    </div>
</body>

</html>