<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        * {
            padding: 0;
            margin: 0;
            box-sizing: border-box;
        }

        html {
            font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }

        body {
            display: flex;
            flex-direction: column;
            gap: 1rem;
            align-items: center;
            justify-content: center;
            height: 100vh;
        }

        table {
            padding: 0.25rem;
            border-radius: 0.5rem;

            th {
                padding: 0.15rem;
                text-align: start;
            }

            td {
                padding: 0.45rem;
            }

            tr {
                &:nth-child(even) {
                    background-color: lightblue;
                }

                &:nth-child(odd) {
                    background-color: lightcyan;
                }
            }

            thead {
                tr:first-child {
                    background-color: lightskyblue;
                }
            }
        }
    </style>
</head>

<body>
    <?php
    require_once './world_db.php';

    extract($_GET);
    $items_per_page = 10;
    $page = isset($page) ? $page : 1;
    $start_offset = ($page - 1) * $items_per_page;
    ?>

    <table>
        <thead>
            <tr>
                <th scope="col">No</th>
                <th scope="col">Country</th>
                <th scope="col">Area</th>
                <th scope="col">Population</th>
                <th scope="col">Capital</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach (array_slice($countries, $start_offset, $items_per_page) as $i => $country): ?>
                <tr>
                    <td><?= htmlspecialchars($start_offset + $i + 1) ?></td>
                    <td><a href="/my-05-htt-get/cities.php?code=<?= $country["code"] ?>&page=<?= $page ?>"><?= htmlspecialchars($country["name"]) ?></a></td>
                    <td><?= htmlspecialchars($country["area"]) ?></td>
                    <td><?= htmlspecialchars($country["population"]) ?></td>
                    <td><?= htmlspecialchars(isset($cities[$country["capital"]]["name"]) ? $cities[$country["capital"]]["name"] : '') ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    <div>
        [
        <?php
        foreach (range(0, count($countries) / 10) as $i) {
            $page = $i + 1;
            echo "<a class='' href='/my-05-htt-get/?page=$page'>$page</a> ";
        }
        ?>
        ]
    </div>
</body>

</html>