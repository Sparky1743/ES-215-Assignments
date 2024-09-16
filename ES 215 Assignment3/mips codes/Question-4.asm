.data
    num1:    .word 18 # First number
    num2:    .word 21 # Second number
    result:  .word 0     
    newline: .asciiz "\n" 

.text
    .globl main



main:
    lw $t0, num1             # Load num1 into $t0
    lw $t1, num2             # Load num2 into $t1
    li $t2, 0                # Initialize $t2 (result) to 0
    li $t3, 0                # Initialize $t3 (counter) to 0

mul_loop:
    beq $t1, $t3, end        # If counter == num2, end loop
    add $t2, $t2, $t0        # Add num1 to result
    addi $t3, $t3, 1         # Increment counter
    j mul_loop                   # Jump back to loop

end:
    sw $t2, result           # Store the result in memory




# Print the result
    li $v0, 1              
    move $a0, $t2         
    syscall         

    li $v0, 4            
    la $a0, newline       
    syscall               

    li $v0, 10            
    syscall