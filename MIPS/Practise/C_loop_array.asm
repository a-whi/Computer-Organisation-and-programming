#for (int i = 0; i < size; i++){
#	if (array[i] > i){
#		array[i] = 0;
#		}
#	else{
#		array[i] = i;
#		}
#	}

.data
	array: .space 12
	
.text
	la $t0, array	# address of array
	addi $t1, $zero, 0 # i = 0
	addi $s0, $zero, 3 #array size = 3
	
loop:
	beq $t1, $s0, end	# if i == array size
	sll $t2, $t1, 2 	# i * 4 shift left twice
	add $t3, $t0, $t2	#Find address of element, add the offset and address
	lw $t4, 0($t3)	#load the value
	blt $t4, $t1, else	# if array[i] < i go to else
	sw $zero, 0($t3)	#make array[i] = 0
	
	add $t1, $t1, 1	# Add 1 to i
	
else:
	sw $t1, 0($t3)	#make array[i] = i
	add $t1, $t1, 1	# Add 1 to i
	j loop
	
end:
	j end