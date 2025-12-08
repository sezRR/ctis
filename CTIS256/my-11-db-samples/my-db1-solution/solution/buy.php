<?php

require_once './db.php';
extract($_GET);

$buy_stmt = $db->prepare("UPDATE MOTORBIKES SET STATUS = 1 WHERE ID = ?");
$buy_stmt->execute([$id]);



header("Location: index.php");
