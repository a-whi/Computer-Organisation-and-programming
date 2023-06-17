main:
	la $t0, a
	lw $t1, 0($t0)
	la $t0, b
	lw $t2, 0($t0)
	
	srl $t3, $t2, 1		#i = b/2
	
loop:
	blt, $t3, $t1, end	#i >= a
	bge $t2, $t1, b_add	#if b>=a
	j i_adder
	
# if statement
b_add: 
	addi $t2, $t3, 2	#b = i + 2
	sw $t2, 0($t0)		# Store the new b value
	j i_adder
	
#Update I count
i_adder:
	add $t4, $t1, $t1	# 2*a
	sub $t3, $t4, $t2 	#i = 2a - b

	j loop
	
end:
	j end
	