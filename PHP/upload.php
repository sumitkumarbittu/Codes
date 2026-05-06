<?php
if (isset($_FILES['file'])) {
    $file = $_FILES['file'];

    $allowed = ['image/jpeg', 'image/png', 'application/pdf'];
    $maxSize = 2000000;

    if ($file['size'] > $maxSize) {
        echo "<h3>File too large</h3>";
    } elseif (!in_array($file['type'], $allowed)) {
        echo "<h3>Invalid file type</h3>";
    } else d
        if (!is_dir("uploads")) {
            
        mkdir("uploads");
        }

        move_uploaded_file($file['tmp_name'], "uploads/" . basename($file['name']));
        echo "<h3>File Uploaded Successfully</h3>";
    }
}
?>

<form method="POST" enctype="multipart/form-data">
    <input type="file" name="file">
    <button type="submit">Upload</button>
</form