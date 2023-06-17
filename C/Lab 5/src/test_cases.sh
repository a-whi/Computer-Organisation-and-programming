#!/bin/bash
make

# Collatz test cases
python3 run_tests.py "simple_bubble_sort" "../data/array.txt" "$(../outputs/simple_bubble_sort ../data/array.txt)" "-23 2 3 5 6 12 23 66 423" "1"

python3 run_tests.py "simple_bubble_sort" "../data/array2.txt" "$(../outputs/simple_bubble_sort ../data/array2.txt)" "1 2 4 4 5 23 34 78 98" "2"

python3 run_tests.py "complex_bubble_sort" "../data/complex_array.txt" "$(../outputs/complex_bubble_sort ../data/complex_array.txt)" "2 6 9 42 
0 5 12 78 
1 57 72 548 " "3"

python3 run_tests.py "complex_bubble_sort" "../data/complex_array2.txt" "$(../outputs/complex_bubble_sort ../data/complex_array2.txt)" "222 222 234 2554 
2 67 1111 3432 
54 432 567 1234 
1 1 2 3 
1 1 1 5 " "4"

#python3 run_tests.py "complex_bubble_sort" "800" "$(../outputs/collatz 800)" "800 400 200 100 50 25 76 38 19 58 29 88 44 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1" "3"

# Component_database test cases
programinput_1="insert Resistor 120 R 69 0.40 
print 
quit"
python3 run_tests.py "binary_search_database" "insert Resistor" "$(echo $programinput_1 | ../outputs/binary_search_database)" "Component: Resistor 120 R, quantity: 69, price: 0.40" "5"

programinput_2="insert Resistor 120 R 69 0.40 
insert Cap 24 k 43 9.99
print 
quit"

python3 run_tests.py "binary_search_database" "insert multiple" "$(echo $programinput_2 | ../outputs/binary_search_database)" "Component: Cap 24 k, quantity: 43, price: 9.99 
Component: Resistor 120 R, quantity: 69, price: 0.40" "6"

programinput_3="insert Resistor 120 R 69 0.40 
insert Cap 24 k 43 9.99
insert LED 4 ii 92 0.25
search Resistor 120 R
remove  Resistor 120 R 69
print 
quit"

python3 run_tests.py "binary_search_database" "insert multiple, then delete" "$(echo $programinput_3 | ../outputs/binary_search_database)" "Component: Resistor 120 R, quantity: 69, price: 0.40 
Component: LED 4 ii, quantity: 92, price: 0.25 
Component: Cap 24 k, quantity: 43, price: 9.99" "7"
