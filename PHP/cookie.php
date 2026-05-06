<!DOCTYPE html>
<html>
<body>

<?php
session_start();

echo "Last Visited On: " . $_COOKIE['dnt'] . "<br><br>";

setcookie("dnt", date("d-m-Y h:i:s"), time() + 10*86400);

if(isset($_SESSION['session_count']))
    $_SESSION['session_count']++;
else
    $_SESSION['session_count'] = 1;

echo "Session Count: " . $_SESSION['session_count'];

?>

</body>
</html>