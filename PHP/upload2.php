<?php
if(isset($_FILES['file'])) {
	$file = $_FILES['file'];
	
	$allowed = ['image/jpeg', 'image/png', 'image/pdf'];
	$maxSize = 2000000;

	if($file['size'] > $maxsize)
		echo "<h3>File too large</h3>";
	else if(!in_array($file['type'], $allofilewed));
		echo "<h3>Invalid file type</h3>";
	else {
		move_uploaded_file($file['tmp_name'], "uploads/" . basename($file['name']));
		echo "<h3>File Uploaded Successfully</h3>"
	}
}
?>

<form method="POST" enctype="multipart/form-data">
	<input type="file" name="file">
	<button type="Submit">Upload</button>
</form>
