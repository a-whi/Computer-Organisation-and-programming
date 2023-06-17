# Lab 8 Part 2 - Modulo-N Counter

.text 					# Start generating instructions 
.globl start 			# This label should be globally known
	
start:
	li $t0, 0xFFFF0010	# Load memory address of seven segment display
	li $t1, 0x10010000	# Load base memory address of decoder values array
	li $a0, 0x0			# Initialise value to write to display
	li $t4, 0xA		#This will be the N values
		
		
display:
	jal draw_num		# Call the draw_num function using 'jump and link'
	add $a0, $a0, 1		# add 1 to $a0 so it can display the next number
	beq $a0, $t4, start	#if $a0 == N go back to start to the end
	j display
	
	
# Is this needed as I never go to it since it keeps looping
end:
	b end				# End at infinite loop


draw_num:
	add $t2, $t1, $a0	# Calculate address of element in array to access
	lbu $t3, 0($t2)		# Load decoder value byte from memory into $t3
	sb $t3, 0($t0)		# Write decoder value to seven segment display
	jr $ra				# Return from function using 'jump register' and $ra

.data					# Items below this line will be stored in the
						# .data section of memory			
																	
# Store the listed value(s) as 8-bit values at the next available locations
.byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
