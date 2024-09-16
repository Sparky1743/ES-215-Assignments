.data
    string:    .asciiz "Computer Architecture"     # String to search in
    char:      .byte 'A'                  # Character to search for
    notfound:  .asciiz "Character not found.\n"
    found:     .asciiz "Character found at index: "
    newline:   .asciiz "\n"

.text
    .globl main

main:
    la $t0, string            # Load address of the string
    lb $t1, char              # Load the character to find
    li $t2, 0                 # Initialize index

search_loop:
    lb $t3, 0($t0)            # Load current character
    beq $t3, $zero, not_found # End of string
    beq $t3, $t1, found_char  # Character found
    addi $t0, $t0, 1          # Next character
    addi $t2, $t2, 1          # Increment index
    j search_loop             # Continue loop

not_found:
    li $v0, 4                 # Print string
    la $a0, notfound          # Load address
    syscall                   # Print message
    j exit_program            # Exit

found_char:
    li $v0, 4                 # Print string
    la $a0, found             # Load address
    syscall                   # Print message

    li $v0, 1                 # Print integer
    move $a0, $t2             # Load index
    syscall                   # Print index

    li $v0, 4                 # Print newline
    la $a0, newline           # Load address
    syscall                   # Print newline

exit_program:
    li $v0, 10                # Exit syscall
    syscall                   # Exit program


