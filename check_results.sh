#!/bin/bash

for i in {1..9..1}
    do
    file_content1=$(head -1 outputs/test_0${i}.txt)
    file_content2=$(head -1 solutions/test_0${i}.txt)
    echo -n $file_content
    if [[ $file_content1 = $file_content2 ]]; then
        echo "Costo ${i} coincide"
    else
        echo "Costo ${i} no coincide [ERROR]"
    fi        
    done

for i in {10..13..1}
    do
    file_content1=$(head -1 outputs/test_${i}.txt)
    file_content2=$(head -1 solutions/test_${i}.txt)
    echo -n $file_content
    if [[ $file_content1 = $file_content2 ]]; then
        echo "Costo ${i} coincide"
    else
        echo "Costo ${i} no coincide [ERROR]"
    fi     
    done