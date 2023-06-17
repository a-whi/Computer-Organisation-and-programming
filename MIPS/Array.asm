# Code we are converting:
# int main() {
#    int example_array [5];
#    example_array[0]= 3;
#    for(int i=1; i<=5; i++){
#        example_array[i] = example_array[i-1]*2 -4;
#    }
# }


# Create an array 5 elements long 
.data
    example_array: .space 20	# 4*5 = 20 bits of space

.text
.globl main
main:
    la $t1, example_array   # Load base address of the array into $t1
    li $t2, 3               # Load 3 into $t2
    sw $t2, 0($t1)          # Store 3 into example_array[0]
	# To place it in position 2 it would be sw $t2, 4($t1) and 8 for 3 etc ...

    # Initialize loop counter to 1 (i = 1)
    li $t3, 1

while:
    # Compare loop counter with 5
    ble $t3, 4, end         # If i > 4 (i.e., i >= 5), exit the loop

    # Calculate address of example_array[i - 1]
    sll $t4, $t3, 2         # Multiply i by 4 to get byte offset (4*1, 4*2 == 4,8,12...)
    sub $t4, $t4, 4         # Subtract 4 to get address of previous element
    add $t4, $t1, $t4       # Add base address to offset ($t4 == i-1)

    # Load example_array[i - 1] into $t5
    lw $t5, 0($t4)

    # Calculate example_array[i - 1] * 2 - 4
    sll $t6, $t5, 1         # Multiply by 2
    sub $t6, $t6, 4         # Subtract 4

    # Calculate address of example_array[i]
    add $t4, $t4, 4         # Add 4 to get address of current element 'example_array[i]'

    # Store result in example_array[i]
    sw $t6, 0($t4)

    # Increment loop counter
    addi $t3, $t3, 1

    j while

end:
    j end
