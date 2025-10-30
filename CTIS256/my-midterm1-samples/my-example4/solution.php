<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dynamic Headers</title>
    <script src="scripts/jquery-3.7.1.min.js"></script>
    <style>
        h1,
        h2,
        h3,
        h4,
        h5,
        h6 {
            cursor: pointer;
            transition: color 0.3s, transform 0.2s;
            margin: 10px 0;
        }

        h1:hover,
        h2:hover,
        h3:hover,
        h4:hover,
        h5:hover,
        h6:hover {
            color: blue
        }

        #output {
            margin-top: 20px;
            font-weight: bold;
            font-size: 18px;
        }
    </style>
</head>

<body>

    <?php

    $toGenerate = rand(1, 20);
    for ($i = 1; $i <= $toGenerate; $i++) {
        $randHeading = rand(1, 6);
        $text = "Header $i with space";
        echo "<h$randHeading onclick='headerClicked(this, \"$randHeading\", \"$text\")'>Header $i (H$randHeading)</h$randHeading>";
    }

    ?>

    <div id="output">Click on a header to see its tag.</div>

    <script>
        function headerClicked(selectedElement, selectedLevel, selectedText) {
            const tag = $(selectedElement).prop("tagName");
            $("#output").text("You clicked: " + tag + ",  Level: " + selectedLevel + " Text: " + selectedText);
        }
    </script>

</body>

</html>