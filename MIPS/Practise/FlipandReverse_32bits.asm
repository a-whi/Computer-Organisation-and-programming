# reversing all bits in a 32 bit sequence

main:
	li $a0, 0x00000001
	li $a1, 0x0
	li $t0, 32
	
loop:
    # Shift $a0 to the right by 1 (this extracts the least significant bit)
    srl $t1, $a0, 1

    # Shift $a1 to the left by 1 (this makes room for the new bit)
    sll $a1, $a1, 1

    # Isolate the least significant bit of $a0
    andi $t2, $a0, 0x1

    # Insert the extracted bit into $a1
    or $a1, $a1, $t2

    # Update $a0 with the right-shifted value (which removes the bit we just processed)
    move $a0, $t1

    # Decrement the counter
    addi $t0, $t0, -1

    # If the counter is not zero, go back to the start of the loop
    beq $t1, $zero, end
    
    j loop

# When the counter reaches zero, we've processed all the bits
# Now, $a1 contains the bit-reversed value of the original input

end:
	j end