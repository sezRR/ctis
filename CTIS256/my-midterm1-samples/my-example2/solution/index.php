<?php
include_once "../assets/data.php";
extract($_GET);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Orders</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: content-box;
        }

        .container {
            display: flex;
            gap: 2rem;
            justify-content: center;
            align-items: center;

            &.col {
                flex-direction: column;
                gap: 1rem;
            }

            &.content {
                margin-top: 1rem;

                & .bold {
                    font-weight: bold;
                }
            }

            &.nav {
                background-color: wheat;
                padding: 1rem;

                & a {
                    text-decoration: none;
                }

                & .selected {
                    text-decoration: underline;
                }
            }
        }

        table {
            width: 580px;
            text-align: center;
            border-collapse: collapse;
        }

        thead {
            margin-bottom: 1rem;
        }

        tr td,
        th {
            padding: 0.5rem;
            border-bottom: 1px solid lightgray;
        }
    </style>
</head>

<body>
    <div class="container nav">
        <a href="./" class="<?= !isset($page) ? "selected" : "" ?>">Home</a>
        <a href="?page=female" class="<?= isset($page) && $page === "female" ? "selected" : "" ?>">Female</a>
        <a href="?page=male" class="<?= isset($page) && $page === "male" ? "selected" : "" ?>">Male</a>
    </div>
    <div class="container col content">
        <?php
        $aggr_orders = [];
        foreach ($users as $email => $attr) {
            $birthDate = DateTime::createFromFormat('d/m/Y', $attr['birthday']);
            $today = new DateTime();
            $age = $today->diff($birthDate)->y;
            $user_orders = array_filter($orders, function ($order) use ($email) {
                return $order["email"] === $email;
            });

            $aggr_orders[] = [
                "name" => $attr["fullname"],
                "gender" => $attr["gender"],
                "phone" => $attr["phone"],
                "age" => $age,
                "orderCount" => count($user_orders),
                "total" => array_sum(array_column($user_orders, "price", null))
            ];
        };

        sort($aggr_orders);
        ?>

        <?php if (!isset($page)): ?>
            <h1>Sezer Tetik</h1>
            <span class="bold">22303222</span>
            <span>Midterm 1</span>
        <?php else: ?>
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Phone</th>
                        <th>Age</th>
                        <th>Order Count</th>
                        <th>Total</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach (
                        array_filter(
                            $aggr_orders,
                            function ($order) use ($page) {
                                return $order["gender"] === $page;
                            }
                        ) as $i => $aggr_order
                    ) : ?>
                        <tr>
                            <td><?= $aggr_order["name"] ?></td>
                            <td><?= $aggr_order["phone"] ?></td>
                            <td><?= $aggr_order["age"] ?></td>
                            <td><?= $aggr_order["orderCount"] ?></td>
                            <td>$ <?= $aggr_order["total"] ?></td>
                        </tr>
                    <?php endforeach ?>
                </tbody>
            </table>
        <?php endif; ?>
    </div>
</body>

</html>