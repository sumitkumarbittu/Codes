<?php
$conn = mysqli_connect("localhost", "root", "", "student_db");

if(!$conn)
    die("Connection Failed: " . mysqli_connect_error());

if(isset($_POST['submit'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $course = $_POST['course'];

    $sql = "INSERT INTO students(name, email, course) VALUES('$name', '$email', '$course')";

    if(mysqli_query($conn, $sql))
        echo "Data inserted Successfully";
    else 
        echo "Error: " . mysqli_error($conn);
}
?>

<!DOCTYPE html>
<html>
<body>
<h2>Enter Student Data</h2>

<form method="post">
    Name: <input type="text" name="name" required><br><br>
    Email: <input type="email" name="email" required><br><br>
    Course: <input type="text" name="course" required><br><br>

    <input type="submit" name="submit" value="Save">

</form>

<hr>

<table border="1" cellpadding="10">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Course</th>
    </tr>
    
    <?php
        $result = mysqli_query($conn, "SELECT * FROM STUDENTS");

        while($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['name'] . "</td>";
            echo "<td>" . $row['email'] . "</td>";
            echo "<td>" . $row['course'] . "</td>";
            echo "</tr>";
        }

        mysqli_close($conn);
    ?>
</table>




</body>
</html>