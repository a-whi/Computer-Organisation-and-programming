#converting code

#int N = 64
#for (int i=0; i<N; i++){
# 	A[i] = i; }

# assume base address of array A is stored in $a0
main:
	li $t0, 64 # N = 64
	li $t1, 0 	# i = 0
	
loop:
	beq $t0, $t1, end	# i == N break
	
	sll $t2, $t1, 2 # i*4 to get address
	
	add $t2, $a0, $t2 #add address + position
	
	sw $t1, 0($t2) #store i in address $t2
	addi $t1, $t1, 1	#add 1 to i 
	j loop	#jump to loop
	
end:
	j end
	
	
#if (i ==j && i ==k)
#	i++
#else
#	j--
#j = i + k

#Assume $t0 = i, $t1 = j, $t2 = k)


main:
	bne $t0, $t1, else	#if i!=j
	bne $t0, $t2, else	#if i!=k
	addi $t0, $t0, 1 #i++
	j end
	
else:
	sub $t1, $t1, 1 # j--


end:
	add $t1, $t0, $t2 # j = i+k
	
	
#void swap(int v[], int k){
#	int temp;
#	temp = v[k]
#	v[k] = v[k+1]
#	v[k+1] = temp
#}

#assume $a0 = base address of array v, and $a1 = k

main:
    sll $t0, $a1, 2       # calculate k * 4 (offset for v[k])
    add $t1, $a0, $t0     # calculate address of v[k]

    lw $t2, 0($t1)        # load v[k] into $t2 (temp)

    addi $t3, $t0, 4      # calculate k * 4 + 4 (offset for v[k + 1])
    add $t4, $a0, $t3     # calculate address of v[k + 1]

    lw $t5, 0($t4)        # load v[k + 1] into $t5

    sw $t5, 0($t1)        # store v[k + 1] into v[k]
    sw $t2, 0($t4)        # store temp into v[k + 1]

	
	














