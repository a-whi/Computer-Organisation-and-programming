**LAB 8**

Part 1: Learn how to interact with peripheral devices, specifically the "Digital Lab Sim" seven-segment displays. Two activities:
- 1.1. Modify skeleton code in seven_seg_01.asm to create a rotating pattern on the seven-segment display using memory-mapped output.

- 1.2. Complete skeleton code in seven_seg_02.asm to implement a Modulo-N counter. Display count values on the seven-segment display.

Part 2: In prime_detector.asm, complete the 'is_prime' function that detects if a number is prime. The input is in register $a0, and the 
result should be returned in register $v0.

Part 3: In rec_square.asm, create a recursive function to find the square of a number based on the equation: n^2 = (n-1)^2 + 2(n-1) + 1. 
Input is given in register $a0, and result should be returned in register $v0. Note: on entry, your function must push $ra and $a0 onto 
the stack and pop them when exiting.
