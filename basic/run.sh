#!/bin/bash
set -e
g++ ac.cpp -o ac.exe
g++ wa.cpp -o wa.exe

for((i=0;;i++))
do
    echo "$i"
    python3 gen.py > input
    ./ac.exe < input > ac.out
    ./wa.exe < input > wa.out
    diff ac.out wa.out || break
done