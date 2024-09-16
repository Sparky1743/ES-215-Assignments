.data
numbers: .word 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 
average: .word 0 
msg:    .asciiz "The average is: " 

.text
.globl main

main:
    # Initialize variables
    li $t0, 0         # sum = 0
    li $t1, 15        # count = 15 (number of elements)
    li $t2, 0         # i = 0 (loop counter)
    la $t3, numbers   # array_address = address of numbers array

loop:
    beq $t2, $t1, done  # if i == count then break
    lw $t4, 0($t3)      # number = numbers[array_address]
    add $t0, $t0, $t4   # sum += number
    addi $t3, $t3, 4    # array_address += 4 (move to next element)
    addi $t2, $t2, 1    # i += 1
    j loop              # jump to start of loop

done:
    li $t5, 15          # divisor = 15
    div $t0, $t5        # quotient = sum / divisor
    mflo $t6            # average = quotient
    sw $t6, average     # store average in memory



# Print the message
    li $v0, 4          
    la $a0, msg        
    syscall            

    # Print the average
    li $v0, 1          
    lw $a0, average    
    syscall           

    # Exit the program
    li $v0, 10         
    syscall          