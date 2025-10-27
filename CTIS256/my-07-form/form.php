<?php
extract($_REQUEST);
$preCities = ["Ankara", "Istanbul", "Izmir"];
$preLanguages = ["C", "JS", "Java"];
$preFruits = ["Cherry", "Banana", "Apple"];
$preStatuses = ["Undergrad", "MSc", "PhD"];
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>07 - Form</title>
    <style>
        .result-container {
            margin-top: 1rem;
            display: flex;
            flex-direction: column;
            gap: 0.5rem;
        }
    </style>
</head>

<body>
    <h1>Web Form App</h1>
    <form method="post">
        <table>
            <tr>
                <td>
                    <label for="name">Name:</label>
                </td>
                <td>
                    <input type="text" name="name" id="name" value="<?= htmlspecialchars($name ?? '') ?>">
                </td>
            </tr>
            <tr>
                <td>
                    <label for="password">Password:</label>
                </td>
                <td>
                    <input type="password" name="password" id="password" value="<?= htmlspecialchars($password ?? '') ?>">
                </td>
            </tr>
            <tr>
                <td>
                    <span>Languages:</span>
                </td>
                <td>
                    <?php foreach ($preLanguages as $language): ?>
                        <?php
                        $lowerLanguage = strtolower($language);
                        ?>
                        <input
                            type="checkbox"
                            name="<?= $lowerLanguage ?>"
                            id="<?= $lowerLanguage ?>"
                            <?= isset($$lowerLanguage) ? "checked" : '' ?>>
                        <label for="<?= $lowerLanguage ?>"><?= $language ?></label>
                    <?php endforeach ?>
                </td>
            </tr>
            <tr>
                <td>
                    <span>Fruits:</span>
                </td>
                <td>
                    <?php foreach ($preFruits as $fruit): ?>
                        <input
                            type="checkbox"
                            name="fruits[]"
                            id="<?= strtolower($fruit) ?>"
                            value="<?= $fruit ?>"
                            <?= isset($fruits) && in_array($fruit, $fruits) ? "checked" : '' ?>>
                        <label for="cherry"><?= $fruit ?></label>
                    <?php endforeach ?>
                </td>
            </tr>
            <tr>
                <td>
                    <label for="status">Status:</label>
                </td>
                <td>
                    <?php foreach ($preStatuses as $preStatus): ?>
                        <?php
                        $lowerPreStatus = strtolower($preStatus);
                        ?>

                        <input
                            type="radio"
                            name="status"
                            id="<?= $lowerPreStatus ?>"
                            value="<?= $preStatus ?>"
                            <?= isset($status) && $status === $preStatus ? "checked" : '' ?>>
                        <label for="undergrad"><?= $preStatus ?></label>
                    <?php endforeach ?>
                </td>
            </tr>
            <tr>
                <td>
                    <label for="cities">Cities:</label>
                </td>
                <td>
                    <select name="cities" id="cities">
                        <?php foreach ($preCities as $city): ?>
                            <option
                                value="<?= $city ?>"
                                <?= isset($cities) && $cities === $city ? "selected" : '' ?>><?= $city ?></option>
                        <?php endforeach ?>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    <label for="message">Message:</label>
                </td>
                <td>
                    <textarea name="message" id="message" rows="6" cols="30"><?= $message ?? '' ?></textarea>
                </td>
            </tr>
            <tr>
                <td>
                    <input type="submit" value="Send" name="send">
                </td>
            </tr>
        </table>
    </form>

    <?php
    extract($_POST)
    ?>

    <?php if (isset($send)): ?>
        <div class="result-container">
            <span>Username is: <?= $name ?> </span>
            <span>Password is: <?= $password ?> </span>
            <span>Fruits are: <?= isset($fruits) ? join(', ', $fruits) : "None" ?> </span>
            <span>C Language: <?= isset($c) ? "YES" : "NO" ?> </span>
            <span>JS Language: <?= isset($js) ? "YES" : "NO" ?> </span>
            <span>Java Language: <?= isset($java) ? "YES" : "NO" ?> </span>
            <span>Status: <?= $status ?? "No status specified" ?> </span>
            <span>Cities: <?= ucfirst($cities) ?> </span>
            <span>Message: <?= isset($message) && strlen(trim($message)) !== 0 ? $message : "No Message" ?> </span>

            <a href="./form.php">Back to Form</a>
        </div>
    <?php endif ?>
</body>

</html>