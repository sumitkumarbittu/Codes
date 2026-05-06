<!DOCTYPE html>
<html>
<body>

<form method="post">
    Enter Text:<br><br>
    <textarea name="text" rows="5" cols="40" required></textarea>
    <br><br>
    <input type="submit" name="submit" value="Save Text">
</form>


<?php
$file = "data.txt";

if(isset($_POST['submit'])) {
    $text = $_POST['text'];

    $fp = fopen($file, "a");
    fwrite($fp, $text . "\n");
    fclose($fp);

    echo "Text inserted Successfully.<br><br>";
}

if(file_exists($file)) {
    echo "<h3>File from Text: </h3>";

    $content = file_get_contents($file);

    echo nl2br($content);
}

?>

</body>
</html>