<?php
require_once 'db.php';

function dump($label, $value)
{
    echo "<pre><strong>$label</strong>\n";
    var_dump($value);
    echo "</pre>";
}

$course_details = [];
foreach ($courses as $course_code => $attr) {
    $registered_student_raw = array_filter(
        $register,
        fn($attr) => $attr["course_id"] === $course_code
    );

    $registered_student_ids = array_column($registered_student_raw, 'std_id');

    $students_by_id = array_column($students, null, 'id');

    $course = [
        "code" => $course_code,
        "name" => $attr["name"],
        "registered_students" => array_map(
            fn($id) => $students_by_id[$id],
            $registered_student_ids
        )
    ];

    array_push($course_details, $course);
}
