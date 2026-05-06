<!DOCTYPE html>
<html>
<body>

<form method="post">
    previous reading: <input type="number" name="previous"><br><br>
    present reading: <input type="number" name="present"><br><br>
    <input type="submit" name="submit" value="calculate bill">
</form>

<?php
    if(isset($_POST['submit'])) {
        $previous = $_POST['previous'];
        $present = $_POST['present'];

        if($present < $previous) {
            echo "Present reading must be greater than Previous Reading";
        } else {
            $unit = $present - $previous;

            if($unit < 100)
                $rate = 3;
            else if($unit <= 200)
                $rate = 4;
            else if($unit <= 300)
                $rate = 5;
            else
                $rate = 6;

            $bill = $rate * $unit;

            echo $unit . "<br>" . $rate . "<br>" . $bill . "<br>";
        }
    }
?>

</body>
</html>