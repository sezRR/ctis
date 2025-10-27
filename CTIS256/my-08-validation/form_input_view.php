<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        table {
            border-collapse: collapse;
            margin: 40px auto;
        }

        td {
            border: 1px solid #CCC;
            padding: 10px;
        }

        .err_msg {
            color: red;
            font-style: italic;
            text-align: center;
        }

        .red {
            background-color: #FDD;
        }
    </style>
</head>

<body>
    <form action="" method="post">
        <table>
            <tr>
                <td>Singer/Band : </td>
                <td>
                    <select name="singer">
                        <?php foreach ($singers as $singerId => $attr): ?>
                            <option
                                value="<?= $singerId ?>"
                                <?= isset($singer) && $singerId == "$singer" ? "selected" : "" ?>>
                                <?= $attr["name"] ?>
                            </option>
                        <?php endforeach ?>
                    </select>
                </td>
            </tr>
            <tr>
                <td>VIP : </td>
                <td>
                    <input type="checkbox" name="isVip" <?= isset($isVip) ? "checked" : "" ?>>
                </td>
            </tr>
            <tr class="<?= !empty($errors) ? 'red' : '' ?>">
                <td>Amount : </td>
                <td>
                    <input type="text" name="nbPerson" value="<?= isset($nbPerson) ? htmlspecialchars($nbPerson) : '' ?>">
                </td>
            </tr>
            <tr>
                <td colspan="2">
                    <button type="submit">BUY</button>
                </td>
            </tr>
        </table>
    </form>
</body>

</html>