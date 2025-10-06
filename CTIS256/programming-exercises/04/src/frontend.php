<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>04 - Exercise</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: content-box;
            font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }

        #app {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            width: 620px;
            margin: 0 auto;
        }

        #content {
            padding: 1rem;
            display: flex;
            flex-direction: column;
            gap: 2rem;
            justify-content: center;
            align-items: center;
        }

        .course-header {
            background-color: wheat;
            text-align: center;
            width: 100%;
            padding: .5rem 1rem;
            border-radius: 1rem;

            & span {
                font-weight: bold;
                font-size: 1.25rem;
                color: orangered;
            }
        }
    </style>
</head>

<body>
    <div id="app">
        <?php require_once 'header.php' ?>
        <?php require_once 'backend.php' ?>
        <div id="content">
            <?php foreach ($course_details as $course) : ?>
                <div class="course-header">
                    <span><?= $course["code"] ?>: <?= $course["name"] ?></span>
                </div>
                <div class="course-students">
                    <table>
                        <thead>
                            <tr>
                                <td>Id</td>
                                <td>Name</td>
                                <td>Surname</td>
                                <td>CGPA</td>
                                <td>Birth Date</td>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach ($course["registered_students"] as $student) : ?>
                                <tr>
                                    <td><?= $student["id"] ?></td>
                                    <td><?= $student["name"] ?></td>
                                    <td><?= $student["surname"] ?></td>
                                    <td><?= $student["cgpa"] ?></td>
                                    <td><?= $student["bday"] ?></td>
                                </tr>
                            <?php endforeach ?>
                        </tbody>
                    </table>
                </div>
            <?php endforeach ?>
        </div>
    </div>
</body>

</html>