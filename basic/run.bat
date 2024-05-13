@echo off
g++ ac.cpp -o ac.exe -std=c++20
g++ wa.cpp -o wa.exe -std=c++20

:loop
   echo %%x
   python gen.py > input
   ac.exe < input > ac.out
   wa.exe < input > wa.out
   fc ac.out wa.out 
if not errorlevel 1 goto loop