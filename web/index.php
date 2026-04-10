<?php
$host = "localhost";
$dbname = "gaz_ppm_db";
$username = "root";
$password = "";

$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Veritabanı bağlantı hatası: " . $conn->connect_error);
}

$result = $conn->query("SELECT * FROM gas_measurements ORDER BY created_at DESC LIMIT 50");
?>
<!DOCTYPE html>
<html lang="tr">
<head>
    <meta charset="UTF-8">
    <title>Gaz PPM Veri Takip Sistemi</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 30px; background: #f5f5f5; }
        h1 { color: #222; }
        table { border-collapse: collapse; width: 100%; background: white; }
        th, td { border: 1px solid #ddd; padding: 10px; text-align: center; }
        th { background: #222; color: white; }
        .alarm { color: red; font-weight: bold; }
        .safe { color: green; font-weight: bold; }
    </style>
</head>
<body>
    <h1>Gaz PPM Ölçüm ve Veri Takip Sistemi</h1>
    <table>
        <tr>
            <th>ID</th>
            <th>PPM</th>
            <th>Ham Değer</th>
            <th>Alarm</th>
            <th>Zaman</th>
        </tr>
        <?php while($row = $result->fetch_assoc()): ?>
        <tr>
            <td><?php echo $row['id']; ?></td>
            <td><?php echo $row['ppm']; ?></td>
            <td><?php echo $row['raw_value']; ?></td>
            <td class="<?php echo $row['alarm'] ? 'alarm' : 'safe'; ?>">
                <?php echo $row['alarm'] ? 'AKTİF' : 'NORMAL'; ?>
            </td>
            <td><?php echo $row['created_at']; ?></td>
        </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>
<?php $conn->close(); ?>
