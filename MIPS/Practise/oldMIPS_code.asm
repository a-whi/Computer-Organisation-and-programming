	.data 
	a: .word 0
	b: .word 2
	c: .word 3

	.text
	whileloop:
	#While c > 0
	lw $t2, c
	beq $t2 , $0, end_while
	
	# a = a + b
	lw $t0, a
	lw $t1, b
	add $s0, $t0, $t1
	sw $s0, a
	
	#c = c - 1
	lw $t2, c
	sub $t2, $t2, 1
	sw $t2, c
	
	#jump back
	j whileloop
	
	
	end_while:
	
	lw $a0, a
	addi $v0, $0, 1
	syscall 
	
	# exit
	addi $v0, $0, 10 #exit call code
	syscall #exit
	