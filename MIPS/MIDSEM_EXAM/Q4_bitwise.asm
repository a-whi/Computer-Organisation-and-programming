

start: li $t0, 0xB1	# 11 in binary
  #Your code goes here
  
  # to make 0x10070000
  sll $t1, $t0, 24	#11000000
  
  # Make 0x00070000 ($t2)
  or $t2, $t0, $t0
  sll $t2, $t2, 24	# 10000
  
  
  # Combine the 2 
  or $t2, $t1, $t2
  

lb $t1, 0($t2)
  #Your code goes here
  # Now we make 0x10010110, same as ablove
  # first make 10110
  sll
  
  # Combine the values to make the address 
  or $t2, $t, $t2
  
sb $t1, 0($t2)