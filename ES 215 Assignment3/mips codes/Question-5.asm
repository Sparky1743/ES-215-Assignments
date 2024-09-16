.data
    numbers:      .word 1, 3, 5, 7, 9, 11, 13, 15, 17, 19  # List of 10 numbers
    X:            .word 7   # Number to search for
    output:       .word 0                        
    not_found_msg: .asciiz "Number not found.\n"  
    found_msg:     .asciiz "Number found.\n"       
    iterations_msg: .asciiz "Iterations: "         
    index_msg:     .asciiz "\nIndex: "               

.text
    .globl main

main:
    lw $t0, X              # Load search number
    li $t1, 0              # Index = 0
    li $t2, 10             # Total numbers
    li $t3, 0              # Iterations = 0

search_loop:
    beq $t1, $t2, not_found # If index == total, not found
    lw $t4, numbers($t1)   # Load number
    addi $t3, $t3, 1       # Increment iterations
    beq $t0, $t4, found    # If match, found
    addi $t1, $t1, 4       # Next number
    j search_loop          # Repeat

not_found:
    li $t5, 2              # Number not found
    sw $t5, output         # Store result
    
    li $v0, 4              # Print "Number not found."
    la $a0, not_found_msg  # Load message
    syscall                # Print
    j exit_program         # Exit

found:
    li $t5, 1              # Number found
    sw $t5, output         # Store result
    sw $t3, output + 4     # Store iterations
    srl $t6, $t1, 2        # Calculate index
    sw $t6, output + 8     # Store index

    li $v0, 4              # Print "Number found."
    la $a0, found_msg      # Load message
    syscall                # Print

    li $v0, 4              # Print iterations
    la $a0, iterations_msg # Load message
    syscall                # Print
    li $v0, 1              # Print integer
    lw $a0, output + 4     # Load iterations
    syscall                # Print

    li $v0, 4              # Print index
    la $a0, index_msg      # Load message
    syscall                # Print
    li $v0, 1              # Print integer
    lw $a0, output + 8     # Load index
    syscall                # Print

exit_program:
    li $v0, 10             # Exit
    syscall                # Exit program
