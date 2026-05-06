<?php
    $n = 100;

    echo "Original Value" . $n . "<br>";
    echo "Original " . gettype($n) . "<br><br>";

    settype($n, "integer");

    echo "Convert Value" . $n . "<br>";
    echo "Convert " . gettype($n) . "<br><br>";

    settype($n, "double");

    echo "Convert Value" . $n . "<br>";
    echo "Convert " . gettype($n) . "<br><br>";
?>