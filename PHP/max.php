<?php
    $a = array(8, 4, 7, 2);

    $n = count($a);

    $max = PHP_INT_MIN;

    while($n) {
        if($max < $a[$n-1])
            $max = $a[$n-1];
        $n--;
    }

    echo "max: " . $max;
?>