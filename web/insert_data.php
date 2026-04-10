<?php
$host = "localhost";
$dbname = "gaz_ppm_db";
$username = "root";
$password = "";

$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Veritabanı bağlantı hatası: " . $conn->connect_error);
}

$ppm = isset($_POST['ppm']) ? $_POST['ppm'] : null;
$raw_value = isset($_POST['raw_value']) ? $_POST['raw_value'] : null;
$alarm = isset($_POST['alarm']) ? $_POST['alarm'] : 0;

if ($ppm === null || $raw_value === null) {
    die("Eksik veri");
}

$stmt = $conn->prepare("INSERT INTO gas_measurements (ppm, raw_value, alarm) VALUES (?, ?, ?)");
$stmt->bind_param("dii", $ppm, $raw_value, $alarm);

if ($stmt->execute()) {
    echo "Kayıt başarılı";
} else {
    echo "Kayıt hatası";
}

$stmt->close();
$conn->close();
?>
