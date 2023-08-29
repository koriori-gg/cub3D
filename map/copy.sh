#!/bin/bash

# Directions array
directions=("Not_surrounded_by_walls_2" "Not_surrounded_by_walls_3" "Not_surrounded_by_walls_4" "Not_surrounded_by_walls_5" "Not_surrounded_by_walls_6")

# Loop from 09 to 14
for i in {0..5}
do
    # Using 'expr' to add leading zero to single digit numbers
    num=$(expr $i + 33)
    num=$(printf "%02d" $num)

    cp "valid_01_subject.cub" "invalid_${num}_${directions[$i]}.cub"
done

