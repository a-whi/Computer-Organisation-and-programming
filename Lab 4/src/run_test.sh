#!/bin/bash
make

# Collatz test cases
python3 run_tests.py "collatz" "35" "$(../outputs/collatz 35)" "35 106 53 160 80 40 20 10 5 16 8 4 2 1" "1"

python3 run_tests.py "collatz" "28" "$(../outputs/collatz 28)" " 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1" "2"

python3 run_tests.py "collatz" "800" "$(../outputs/collatz 800)" "800 400 200 100 50 25 76 38 19 58 29 88 44 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1" "3"

# Component_database test cases
programinput_1="insert Resistor 120 R 69 0.40 
print 
quit"
python3 run_tests.py "component_database" "insert Resistor" "$(echo $programinput_1 | ../outputs/component_database)" "Component: Resistor 120 R, quantity: 69, price: 0.40" "4"

programinput_2="insert Resistor 120 R 69 0.40 
insert Cap 24 k 43 9.99
print 
quit"

python3 run_tests.py "component_database" "insert multiple" "$(echo $programinput_2 | ../outputs/component_database)" "Component: Cap 24 k, quantity: 43, price: 9.99 
Component: Resistor 120 R, quantity: 69, price: 0.40" "5"

programinput_3="insert Resistor 120 R 69 0.40 
insert Cap 24 k 43 9.99
insert LED 4 ii 92 0.25
search Resistor 120 R
remove  Resistor 120 R 69
print 
quit"

python3 run_tests.py "component_database" "insert multiple, then delete" "$(echo $programinput_3 | ../outputs/component_database)" "Component: Resistor 120 R, quantity: 69, price: 0.40 
Component: LED 4 ii, quantity: 92, price: 0.25 
Component: Cap 24 k, quantity: 43, price: 9.99" "6"
