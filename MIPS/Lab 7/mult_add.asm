# Copyright Monash University 2023
# Lab 7 Part 2 - Multiplication via successive addition


.text                   # Start generating instructions
.globl main             # Makes the label main globally known


.text                   # Instructions in the program:
start:
# setting $t0 = 2 and $t1 = 3:
	addi    $t0, $0, 2
	addi    $t1, $0, 3

# main program:
main:
	# if $t1 <= 0 go to the infinite loop
	ble $t1, $0, infinite
	
	# add t0 to s0
	add $s0, $s0, $t0
	
	# t1 - 1
	sub $t1, $t1, 1
		
	# loop again
	j main
	
	
infinite:
   	j infinite 

