<?php
session_start();

$conn = mysqli_connect("localhost", "root", "", "student_db");

if(!$conn)
    die("Connection failed: " . mysqli_connect_error());

$message = "";




?>

<!DOCTYPE html>
<html>
<body>
    <p style="color:red;">
        <?php echo $message; ?>
    </p>

    <form method="post">
        Username: <input type="text" name="username" required><br>
        Password: <input type="password" name="password" required><br>
        <input type="submit" name="submit" value="Login">
    </form>
</body>
</html>