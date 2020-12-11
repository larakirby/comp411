.data 0x0
#	prompt: .asciiz "Enter two integers (for n and k) separated by space:\n"
	newline: .asciiz "\n"
	
.text 0x3000
.globl main

main:
	ori     $sp, $0, 0x3000     # Initialize stack pointer to the top word below .text
                                # The first value on stack will actually go at 0x2ffc
                                #   because $sp is decremented first.
	addi    $fp, $sp, -4        # Set $fp to the start of main's stack frame
    
    
#	li $v0, 4           #print the prompt :)
#	la  $a0, prompt
 #   	syscall
    
    	li      $v0,5         
    	syscall
    
    	beq $v0, $0, exit_from_main  #zero input read--> exits prog
    
    	add $s0, $v0, $0
    	li $v0,5           
    	syscall
    	add $a0, $s0, $0   #put the read numbersinto argument registers
    	addi $a1, $v0, 0
    	jal NchooseK

end_of_main:  
	addi $s0, $v0, 0  
    	addi $a0, $s0, 0  
   	li $v0, 1    #put one in return     
    	syscall
   	li $v0, 4          
   	la $a0, newline 
   	syscall
   	j main #return to main to continue the loop
   	 
 exit_from_main:
 	li $v0, 10
 	syscall #yeet


 NchooseK:
         slt $s0, $a0, $a1         
         bne $s0, $0, end_NchooseKv1	 #goes & returns 0 & comes back to return adress
         beq $a0, $a1, end_NchooseKv2 #returns one
         beq $a1, $0, end_NchooseKv2  

         sw $fp, -4($sp) #maintain stack & saved vars by kind of jumping up each time with sp
         addi $fp, $sp, 0
         addi $sp, $sp, -12
         sw $ra, 4($sp)
         sw $a0, 0($sp)
         addi $sp, $sp, -4
         sw $s1, 0($sp)
         addi $a0, $a0, -1
         
         jal NchooseK

         add $s1, $v0, $0  #stack maintenance stuff :^)
         addi $sp, $sp, -4
         sw $a1, 0($sp)
         addi $sp, $sp, -4
         sw $ra, 0($sp) 
         addi $a1, $a1, -1

         jal NchooseK

         add $v0, $s1, $v0
         lw $ra, 0($sp)
         addi $sp, $sp, 4
         lw $a1, 0($sp)
         addi $sp, $sp, 4
         
         lw $s1, 0($sp)
         addi $sp, $sp, 4
         lw $a0, 0($sp)
         addi $sp, $sp, 4
         lw $ra, 0($sp)
         addi $sp, $sp, 4
         lw  $fp, 0($sp)
         addi $sp, $sp, 4
         j NchooseKfinish

end_NchooseKv1:   
	addi $v0, $0, 0       #returns 0
        j  NchooseKfinish

end_NchooseKv2:   
	addi $v0, $0, 1    #returns 1

NchooseKfinish:    jr $ra        









