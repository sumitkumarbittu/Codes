<?php
$conn = mysqli_connect("localhost", "root", "", "student_db");

if(!$conn)
    die("Connection Failed: " . mysqli_connect_error());

if(isset($_GET['delete'])) {
    $id = $_GET['delete'];

    $sql = "DELETE FROM students WHERE id = $id";

    if(mysqli_query($conn, $sql))
        echo "Record Deleted Successfully";
    else
        echo "Error Deleting Record: " . mysqli_error($conn);
}

if(isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $course = $_POST['course'];

    $sql = "UPDATE students SET name='$name', email='$email', course='$course' WHERE id='$id'";

    if(mysqli_query($conn, $sql))
        echo "Record Updated Successfully";
    else
        echo "Record Update Error: " . mysqli_error($conn);
}

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
<h1>Student Data</h1>

<table border="1" cellpadding="10">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Course</th>
        <th>Action</th>
    </tr>
    
    <?php
        $result = mysqli_query($conn, "SELECT * FROM students");

        while($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['name'] . "</td>";
            echo "<td>" . $row['email'] . "</td>";
            echo "<td>" . $row['course'] . "</td>";
            echo "<td>
                    <a href='change.php?edit=" . $row['id'] . "'>Edit</a> |
                    <a href = ' change.php?delete=" . $row['id'] . " ' onclick='return confirm(\"Are u sure?\")'>Delete</a>
                </td>";
            echo "</tr>";
        }
    ?>
</table>

<br><hr><br>

<?php
if(isset($_GET['edit'])) {
    $id = $_GET['edit'];

    $result = mysqli_query($conn, "SELECT * FROM students WHERE id=$id");

    $row = mysqli_fetch_assoc($result);
}
?>


<h2>Update Student Record</h2>

<form method="post">
    <input type="hidden" name="id" value="<?php echo $row['id']; ?>"><br><br>

    Name: <input type="text" name="name" value="<?php echo $row['name']; ?>" required><br><br>
    Email: <input type="email" name="email" value="<?php echo $row['email']; ?>" required><br><br>
    Course: <input type="text" name="course" value="<?php echo $row['course']; ?>" required><br><br>

    <input type="submit" name="update" value="Update">

</form>

    <?php mysqli_close($conn); ?>

</body>
</html>