# Lab 8 Part 4 - Recursive Square Program

.text                       # Start generating instructions 
.globl square               # This label should be globally known

start:
    li  $a0, 0x0003         # load argument register $a0 with number to be squared					
    jal square              # call the recursive function to calculate the square
		
infinite:
    b infinite              # wait here when the calculation has finished 
                            # $v0 contains the result

#---------------------------------------------------------------
# square - input parameter $a0 contains number to be squared
#         result returned in register $v0
#---------------------------------------------------------------		
square:
    subi $sp, $sp, 8        # decrement the stack pointer $sp
    sw  $ra, 4($sp)         # push the return address register $ra
    sw  $a0, 0($sp)         # push argument register $a0
    li  $t0, 0x0001         # load $t0 with 1 as part of test for base case
    bne $a0, $t0, notbase   # branch if not the base case
    li $v0, 0x0001          # return base result in $v0
    addi $sp, $sp 8         # recover stack space (Note: did not corrupt registers)
    jr $ra                  # jump to return address in $ra

notbase: 	
	#n^2=(n-1)^2+2(n-1)+1
    #*****************************************
    # your code for the non-base case goes here 
    #*****************************************
    addi $a0, $a0, -1 		# This is (n-1) for the recursive function
    jal square				# This will then square a0
    
    sll $t1, $a0, 1			# 2(n-1), shifting by 1 will double n
    addi $t1, $t1, 1			# Add 1 (2(n-1)+1)
    add $v0, $v0, $t1		# Add (2(n-1)+1) to n^2
    
    lw  $ra, 4($sp)         # pop the return address from stack to register $ra
    lw  $a0, 0($sp)         # pop argument register $a0
    addi $sp, $sp, 8        # increment the stack pointer $sp, as 2 values were poped off it
    
    jr $ra                  # jump to contents of return address register $ra
    
    
    
    

