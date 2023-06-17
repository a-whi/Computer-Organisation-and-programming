#!/bin/bash

# compile the program:
cd src
make bee_count
cd ..

executableName="./outputs/bee_count"

# Test 1: bee movie script
programOutput=$($executableName)  # gets the output of the program with the given input
expectedOutput="There were 6 occurances of the word bee in the text"
python3 src/test_bee.py "$programOutput" "$expectedOutput"  # calls the python test script
