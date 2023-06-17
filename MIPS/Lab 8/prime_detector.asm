# Lab 8 Part 3 - Prime Number detector

.text                       # Start generating instructions 
.globl is_prime             # This label should be globally known

start:
    li  $a0, 0x0017         # load argument register $a0 with number to be test
    jal is_prime            # call the recursive function to test if prime
		
infinite:
    b infinite              # wait here when the calculation has finished 
                            # $v0 contains the result

#---------------------------------------------------------------
# is_prime - input parameter $a0 contains number to test
#   result returned in register $v0 (1 if prime, 0 if not prime)
#---------------------------------------------------------------		
is_prime:	
	li $t0, 2		# Make $t0 = 2
	
	# Immediatly check if the number is 1 or 2
	blt $a0, $t0, prime 	#if a0 < 2 go to prime
	beq $a0, $t0, not_prime #if a0 == 2 then go not_prime
	
div_loop:
	div $a0, $t0 	# basically a0/t0
	mfhi $t2		# store a0%t0 in t2
	beq $t2, 0x0, not_prime #if $t2 == 0 it is not a prime number
	add $t0, $t0, 1			# add 1 to $t0
	bne $t0, $a0, div_loop	#if $t2 != $a0 keep looping
	
# Both of these just set the $v0 value
prime:
	li $v0, 1
	jr $ra
	
not_prime:
	li $v0, 0
	jr $ra
	
	
	
	
	
	