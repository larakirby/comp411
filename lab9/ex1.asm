.data 
	n: .space 4
	currentlevel: .space 4
	pattern: .space 84                    #20 spaces...maybe we can make this mutable with '0' and '1'? 
						#this only needs to be 20 spaces bc it's null terminated ascii space
	newline: .asciiz "\n" 			#null terminator needed?
	zero: .asciiz "0"
	one: .asciiz "1"
	nullterminator: .asciiz ""
	
.globl main
.globl makepatterns
.text
main:
	li $v0, 5
	syscall
	sw $v0, n
	sw $0, currentlevel
	la $t0, nullterminator
	sll $t1, $v0, 2
	sw $t0, pattern($t1)
	#la $a2, pattern #stores the adress of pattern in a2
	la $s0, zero
	la $s1, one
	
	lw $a1, n
	lw $a2, currentlevel
	lw $a3, pattern
	
	jal makepatterns

exit:
	li $v0, 10 #yee haw baby B)
	syscall
	
makepatterns:
	 addi $sp, $sp, -4
         sw $ra, 0($sp)
         addi $sp, $sp, -4
         sw $a2, 0($sp)
         addi $sp, $sp, -4
         sw $a3, 0($sp)
         
         beq $a1, $a2, if
         j else

if:
	add $t2, $0, $0
	j printer
        
else:        
	sll $t0, $a2, 2
        #want to store 0 in patterns[currentlevel] = patterns[$a1]
        sw $s0, pattern($t0)
        
        addiu $a2, $a2, 1
        
        jal makepatterns
        
        #need to maintain stack here.....................
        lw $ra, 8($sp)
        lw $a2, 4($sp)
        lw $a3, 0($sp)
        # end unsure stack maintenance between code......
        
        sll $t0, $a2, 2
        sw $s1, pattern($t0)
        addiu $a2, $a2, 1
        jal makepatterns
        j end
                
  

        
printer: 
	slt $t5, $t2, $a2
	beq $t5, $0, newl
	sll $t3, $t2, 2
	addi $v0, $0, 4
	lw $a0, pattern($t3)
	syscall
	addi $t2, $t2, 1
	j printer
	
newl:
	addi $v0, $0, 4
	la $a0, newline
	syscall
	j end

 end:      
        lw $ra, 8($sp)
        lw $a2, 4($sp)
        lw $a3, 0($sp)
        
        addi $sp, $sp, 12
        
        jr $ra
        

