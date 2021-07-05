#!/bin/bash
make
mkdir outputs

for i in {1..9..1}
    do
    echo "Running $j-$i:"
        time ./dewey tests/test_0${i}.txt outputs/test_0${i}.txt
    done

for i in {10..13..1}
    do
    echo "Running $j-$i:"
        time ./dewey tests/test_${i}.txt outputs/test_${i}.txt
    done

bash ./check_results.sh