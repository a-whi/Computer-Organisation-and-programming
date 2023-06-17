# Lab 8 Part 1 - Rotating Seven Segment Display

.text					# Start generating instructions 
.globl start			# This label should be globally known

	
start:
	li $t0, 0xFFFF0010	# Load memory address of seven segment display
	li $t1, 0x1			# Initialise value to write to display (0x1 is 1 in hex)
	li $t2, 0x40		# 0x40 is the number after 5 shifts (0x40 is 64 in hex)
		
repeat:
	sb $t1, 0($t0)		# Write the value 0x1 to seven segment display
	sll $t1, $t1, 1		# Shift left logical by 1
	beq $t1, $t2, start	#if $t1 == 0x40 go back to start to reset $t1
	b repeat			# Branch to repeat label
