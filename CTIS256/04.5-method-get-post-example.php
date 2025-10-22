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
            box-sizing: content-box;
            font-size: 20px;
        }

        html {
            font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }

        form {
            padding: 1rem;
            display: flex;
            flex-direction: column;
            gap: 1rem;
            max-width: 192px;

            & div label {
                display: block;
                margin-bottom: 0.5rem;
                font-weight: bold;
            }
        }
    </style>
</head>

<body>
    <?php
    extract($_REQUEST); // $id, $name

    if (!isset($showTemp) || !$showTemp): ?>
        <?php if (isset($id)): ?>
            Id is: <?= $id ?>
        <?php else: ?>
            Id is not found!!
        <?php endif; ?>

        <br><br>

        <?php if (isset($name)): ?>
            Name is: <?= $name ?>
        <?php else: ?>
            Name is not found!!
        <?php endif; ?>

        <?php
        $students = [
            "123" => ["name" => "nese", "cgpa" => 2.4, "surname" => "sahin"],
            "140" => ["name" => "veli", "cgpa" => 3.4, "surname" => "korkmaz"]
        ];
        ?>

        <br><br>

        <?php if (isset($studentId)): ?>
            The student with the id <?= $studentId ?> is:
            <?= implode(', ', $students[$studentId]) ?>
        <?php else: ?>
            Student Id is not found!!
        <?php endif; ?>

        <br><br>

        <a href="/?name=sezer&id=123&studentId=140">Click to see student with the id 140</a>

        <form method="POST" action="">
            <div>
                <label for="id">Enter your id:</label>
                <input type="text" name="id" id="id">
            </div>
            <div>
                <label for="name">Enter your name:</label>
                <input type="text" name="name" id="name">
            </div>
            <input type="hidden" name="showTemp" value="true">
            <button type="submit">Send</button>
        </form>

    <?php else: ?>

        <?php if (isset($id)): ?>
            Your id: <?= $id ?>
        <?php else: ?>
            Id is not found!!
        <?php endif; ?>

        <br><br>

        <?php if (isset($name)): ?>
            Your name is: <?= $name ?>
        <?php else: ?>
            Name is not found!!
        <?php endif; ?>

        <form method="GET" action="">
            <div>
                <label for="id">Enter your id:</label>
                <input type="text" name="id" id="id" value="<?php if (isset($id)) echo $id ?>">
            </div>
            <div>
                <label for="name">Enter your name:</label>
                <input type="text" name="name" id="name" value="<?php if (isset($name)) echo $name ?>">
            </div>
            <input type="hidden" name="showTemp" value="true">
            <button type="submit">Send</button>
        </form>

    <?php endif; ?>
</body>

</html>