.data
  AA:     .space 400  		# int AA[100]
  BB:     .space 400  		# int BB[100]
  CC:     .space 400  		# int CC[100]
  m:      .space 4   		# m is an int whose value is at most 10
                     		# actual size of the above matrices is mxm
  newline:	.asciiz "\n"

      # You may add more variables here if you need to

.text

main:
	addi	$v0, $0, 5
	syscall 
	add $s0, $0, $v0
	sw $s0, m
	
	mult $s0, $s0
	mflo $t7
	#m^2 in t7
	
	add $a1, $v0, $0 #m is in a1
	
	la $s1, AA
	add $t0, $0, $0
	add $t1, $0, $0
	add $t2, $0, $0
	add $t3, $0, $0
	jal readA
	la $s2, BB
	add $t0, $0, $0
	add $t1, $0, $0
	add $t2, $0, $0
	add $t3, $0, $0
	jal readB 
	la $s3, CC
	#then you go to C multiplication loop
	add $t1, $0, $0
	add $t0, $0, $0
	add $t3, $0, $0
	jal multloop1
	
	add $t0, $0, $0
	add $t1, $0, $0
	add $t2, $0, $0
	add $t3, $0, $0
	add $s1, $0, $0
	
	
	jal exit
	

exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program

	
readA:
	addi $v0, $0, 5
	syscall
	sw $v0, AA($t0)
	
	add $t0, $t0, 4 
	add $t1, $t1, 1
    	slt $t3, $t1, $t7 
    	bne $t3, $0, readA
    	
  
	
	
readB:
	addi $v0, $0, 5
	syscall
	sw $v0, BB($t0)
	
	add $t0, $t0, 4  
	add $t1, $t1, 1
    	slt $t3, $t1, $t7 
    	bne $t3, $0, readB
    	
multloop1:
	add $t1, $0, 0
	slt $t3, $t0, $t7
	bne $t3, $0, multloop2
	jr $ra

multloop2:
	add $t2, $0, $0
	slt $t3, $t1, $a1
	bne $t3, $0, multloop3
	add $t0, $t0, 1
	j multloop1
	

multloop3:
	slt $t3, $t2, $a1
	# do the computation
	#adress to use of AA
	#  $s5 = [$a1*$t0 + $t3]
	mult $a1, $t0
	mflo $s5
	add $s5, $s5, $t3
	sll $s5, $s5, 2
	
	#adress to use of BB
	#  $s6 = [$a1*$t3 + $t2]
	mult $a1, $a3
	mflo $s6
	add $s6, $s6, $t2
	sll $s6, $s6, 2
	
	#adress to use of CC
	#  $s7 = [$a1*$t1 + $t3]
	mult $a1, $t1
	mflo $s7
	add $s7, $s7, $t3
	sll $s7, $s7, 2
	
	#CC[$s7] += AA[$s5]*BB[$s6]
	lw $s0, AA($s5)
	lw $s1, BB($s6)
	mult $s0, $s1
	mflo $s2
	lw $s3, CC($s7)
	
	add $t2, $t2, 1
	bne $t3, $0, multloop3
	add $t1, $t1, 1
	j multloop2
	

	
	#increment i, j, k
	
	add $t3, $t3, 1
	slt $t6, $t3, $a1
	bne $t6, $0, multloop3
	
	add $t1, $t1, 1
	slt $t5, $t1, $a1
	bne $t5, $0, multloop2
	
	
printloop:
	li $v0, 1
	lw $a0, CC($t0)
	syscall	
	
	li $a0, 32
	li $v0, 11
	syscall
	add $t0, $t0, 4
	add $t1, $t1, 1
	
	slt $t2, $t2, $a2
	bne $t2, $0, printloop
	jr $ra
	

	

	
	
#------- If you decide to make other functions, place their code here -------
#
#  You do not have to use helper methods, but you may if you would like to.
#  If you do use them, be sure to do all the proper stack management.
#  For this exercise though, it is easy enough to write all your code
#  within main.
#
#------------ END CODE ---------------
