#---------------------------------
# Lab 6: Pixel Conversion
#
# Name: <LARA-KIRBY>
#
# --------------------------------
# Below is the expected output.
# 
# Converting pixels to grayscale:
# 0
# 1
# 2
# 34
# 5
# 67
# 89
# Finished.
# -- program is finished running --
#---------------------------------

.data 0x0
  startString:  .asciiz "Converting pixels to grayscale:\n"
  finishString: .asciiz "Finished.\n"
  newline:      .asciiz "\n"
  pixels:       .word   0x00010000, 0x010101, 0x6,      0x3333,
                        0x030c,     0x700853, 0x294999, -1

.text 0x3000

main:
  addi $v0, $0, 4       	# system call code 4 for printing a string
  la   $a0, startString      	# put address of startString in $a0
  syscall               	# print the string



and $t4, $0, $0

loop:
  sll $t5, $t4, 2
  la $t0, pixels
  add $t5, $t5, $t0
  lw $t1, 0($t5)
  addi $s0, $0, -1
  beq $t1, $s0, exit

  
  andi $a2, $t1, 0x000000FF
  srl $t1, $t1, 8
  andi $a1, $t1, 0x000000FF
  srl $t1, $t1, 8
  andi $a3, $t1, 0x0000000FF
  jal rgb_to_gray
  
  add $a3, $0, $v0
  addi $v0, $0, 1
  #la $a3, ($v0)
  
  add $a0, $0, $a3
  syscall 
  addi $v0, $0, 4
  la $a0, newline     	
  syscall 
  
  
  
  addi $t4, $t4, 1
  
  j loop
  
  
 
  
  
 
 #LARA'S CODE ABOVE--------------------------------------------------------

exit:

  
  
  addi $v0, $0, 4            	# system call code 4 for printing a string
  la   $a0, finishString   	# put address of finishString in $a0
  syscall               	# print the string
  
  

  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



#----------------------------------------------------------#

#---- Procedure rgb_to_gray ----#
#
#
#-------------------------------#

rgb_to_gray:      
     
	addi $t2, $0, 3
	add $v0, $a1, $a2
	add $v0, $v0, $a3
	div $v0, $v0, $t2
  	jr $ra                # return to main
