# Write a MIPS assembly language program that:
# computes the following equation where A, B and C are 32-bit signed integers. 
# The addresses of A, B and C are loaded into registers $a0, $a1, and $a2, respectively.
# 4*(A - B) - C

# Your program should call a function equation_confirmation (which you must write) that:

# takes the values in registers $a0-$a2 as input arguments, 
# computes the equation above and 
# checks whether the result is equal to the value of B*2. 
# If the computed result is equal to B*2, $v0 should be loaded with a value of 5. Else, $v0 should be loaded with a value of 0. The program should then end in an infinite loop. 
# Note that you are only allowed to use instructions that have been listed in the MIPS reference sheet provided in the 'Instructions' section of this exam.

main:
	lw $a0, A
	lw $a1, B
	lw $a2, C
	
	jal equation_confirmation
	
	j end
	
equation_confirmation:
	add $t0, $a1, $a1	#b*2
	sub $t1, $a0, $a1 	#A-B
	sll $t1, $t1, 2	#t1 *4
	sub $t1, $t1, $a2 	#t1 -C
	
	beq $t0, $t1, equal
	li $v0, 0	#V0 = 0
	jr $ra	#return
	
equal:
	li $v0, 5
	jr $ra	#return
	
end:
	j end

