**LAB 1**

Part 1: Basic command line navigation

Part 2: Debugging

Part 3: Coding Exercises

3.1 Calculator

- Write a C program that asks the user for three inputs: an integer, an operator, and another integer. The program should perform mathematical operations (multiply, divide, add, subtract, modulus) based on the input operator. Verify your code with provided test cases.
To test the program, use Python and bash scripts. Copy and paste the given Python script test_calculator.py and bash script test_calculator.sh into respective files in your lab1/src directory.
Investigate the following cases: integer division and modulus of various numbers.
Create a floating point version of your calculator by copying the existing code to a new file calculator_float.c and changing integer inputs to floats. Test float division and multiplication with different numbers.

3.1.2 Types

- Write a short report (~100 words) summarizing your findings about arithmetic and variable types in C.

3.2 Dice Game

- Write a C program that simulates a dice game using the rand() function. The game rules are: player wins if the dice sum is 7 or 11, loses if it's 2, 3, or 12. If neither, the game repeats until the sum is either the initial sum (player wins) or 7 (player loses). Winning prizes depend on the rolls.
For each roll, print the sum of the dice. At the end of the game, print the player’s prize and the number of rolls (if won), or a loss message and the total number of rolls (if lost).
Implement this game in a file named dice.c. Use the rand() function for random numbers and srand(time(0)) for true randomness. Include <time.h>.
The task will be marked using stochastic test cases run offline. You can view your code's pass status in the feedback.log file in each lab folder.
