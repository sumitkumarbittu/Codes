<!DOCTYPE html>
<html>
<body>
<h2>File Upload Program</h2>

<form method="post" enctype="multipart/form-data">
    Select File: <input type="file" name="myfile"><br><br>
    <input type="submit" name="submit" value="upload file">
</form>

<?php
if(isset($_POST['submit'])) {
    $fileName = $_FILES['myfile']['name'];
    $fileTmpName = $_FILES['myfile']['tmp_name'];
    $fileSize = $_FILES['myfile']['size'];
    $fileType = $_FILES['myfile']['type'];
    $fileError = $_FILES['myfile']['error'];

    $uploadFolder = "files/";

    $allowed_types = array("image/png", "image/jpeg", "application/pdf");

    $maxSize = 2*1024*1024;

    if(!$fileError) {
        if(in_array($fileType, $allowed_types)) {
            if($fileSize <= $maxSize) {
                $destination = $uploadFolder . basename($fileName);

                if(move_uploaded_file($fileTmpName, $destination)) {
                    echo "File Moved Successfully!";
                } else echo "File Moved Failed";
            } else echo "File size is too much";
        } else echo "Invalid file type";
    } else echo "Invalid file selected";
} 

?>

</body>
</html>