.data
	prompt: .asciiz "Enter number to find its factorial: "
	result: .ascii "\nThe factorial of the number is: "
	number: .word  0
	answer: .word  0

.text
	.globl main
	main:
		#print prompt and read int from user
		li $v0, 4
		la $a0, prompt
		syscall
		
		li $v0, 5
		syscall
		
		sw $v0, number
		
		#put the number read into the arg register $a0
		#call factorial
		#put answer in "answer"
		lw $a0, number
		jal factorial
		sw $v0, answer
		
		#print message and then display result
		li $v0, 4
		la $a0, result
		syscall
		
		li $v0, 1
		lw $a0, answer
		syscall
		
		#tell the OS this is the end of program
		li $v0, 10 #syscall for exiting program
		syscall
		
#------------------------factorial function---------------------------------		

.globl factorial
factorial:
	addiu $sp, $sp, -8
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	
	#base case
	li $v0, 1
	beq $a0, $0, factorialFinished
	
	add $s0, $a0, $0
	sub $a0, $a0, 1
	jal factorial
	
	#the magic happens uwu --> recursion happens here when recursion unwinds
	mul $v0, $s0, $v0
	
	factorialFinished:
		lw $ra, ($sp) #restore $ra, $s0, $sp value from stack C:
		lw $s0, 4($sp) 
		addiu $sp, $sp, 8
		jr $ra 