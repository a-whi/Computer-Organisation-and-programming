# Lab 7 Part 3 - Bitwise operations
.text 					                # Start generating instructions 
.globl start 				            # This label should be globally known

# Instructions in the program:
.text
start:
	# Load the address 0x10010000 into register $t0
	la $t0, 0x10010000

	# Load the byte from the address in register $t0 into register $t1
	lb $t1, 0($t0)

	# Set the first two bits to 1
	or $t2, $t1, 0x03 # 3 bits (11)
	# ori will set a bit to 1 if either of the corresponding bits in the operands is 1.

	# Set the next two bits to 0
	and $t3, $t2, 0xF3	#243 bits (11110011)

    # Invert the most significant 4 bits of the value in $t1
    xor $t4, $t3, 0xF0 #11110000

	# Load the address 0x10010005 into register $t6
	la $t5, 0x10010005	

	# Store the modified byte from register $t5 to the address in register $t6
	sb $t4, 0($t5)

infinite_loop:
	j infinite_loop