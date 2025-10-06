<?php

/* Q1 Arrays */
$students = [
    ["id" => 20142645, "name" => "Meltem", "surname" => "Yılmaz", "cgpa" => 3.03, "bday" => "03-11-2004"],
    ["id" => 20132446, "name" => "Ahmet", "surname" => "Okur", "cgpa" => 2.13, "bday" => "23-09-2003"],
    ["id" => 20142743, "name" => "Cem", "surname" => "Tuncel", "cgpa" => 3.72, "bday" => "13-01-2003"],
    ["id" => 20152849, "name" => "Sercan", "surname" => "Tuncay", "cgpa" => 3.43, "bday" => "12-10-2004"],
    ["id" => 20142040, "name" => "Hakan", "surname" => "Genç", "cgpa" => 1.94, "bday" => "01-09-2004"],
    ["id" => 20132840, "name" => "Seçkin", "surname" => "Şafak", "cgpa" => 1.88, "bday" => "30-08-2002"],
    ["id" => 20132447, "name" => "Nihan", "surname" => "Akbıyık", "cgpa" => 2.01, "bday" => "25-06-2004"],
    ["id" => 20142377, "name" => "Özge", "surname" => "Bulman", "cgpa" => 1.91, "bday" => "21-02-2003"],
    ["id" => 20152354, "name" => "Tunç", "surname" => "Küçük", "cgpa" => 3.57, "bday" => "14-11-2005"],
    ["id" => 20142333, "name" => "Mehmet", "surname" => "Ada", "cgpa" => 3.07, "bday" => "13-10-2001"],
];

$courses = [
    "CTIS151" => ["name" => "Introduction to Programming", "credit" => 5],
    "CTIS152" => ["name" => "Data Structure and Algorithms", "credit" => 5],
    "CTIS255" => ["name" => "Frontend Web Technologies", "credit" => 3],
    "CTIS256" => ["name" => "Introduction to Backend Development", "credit" => 3],
];

$register = [
    ["std_id" => 20142645, "course_id" => "CTIS151"],
    ["std_id" => 20142645, "course_id" => "CTIS255"],
    ["std_id" => 20142333, "course_id" => "CTIS151"],
    ["std_id" => 20142333, "course_id" => "CTIS152"],
    ["std_id" => 20142333, "course_id" => "CTIS255"],
    ["std_id" => 20132447, "course_id" => "CTIS255"],
    ["std_id" => 20132447, "course_id" => "CTIS256"],
    ["std_id" => 20132446, "course_id" => "CTIS152"],
    ["std_id" => 20132446, "course_id" => "CTIS256"],
    ["std_id" => 20142743, "course_id" => "CTIS151"],
    ["std_id" => 20142743, "course_id" => "CTIS152"],
    ["std_id" => 20152849, "course_id" => "CTIS151"],
    ["std_id" => 20152849, "course_id" => "CTIS256"],
    ["std_id" => 20132840, "course_id" => "CTIS256"],
    ["std_id" => 20142377, "course_id" => "CTIS151"],
    ["std_id" => 20142377, "course_id" => "CTIS255"],
    ["std_id" => 20152354, "course_id" => "CTIS255"],
    ["std_id" => 20142040, "course_id" => "CTIS151"],
    ["std_id" => 20142040, "course_id" => "CTIS255"],
];
