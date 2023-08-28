# generate 16-bit code
.code16 			   

# Criando variaveis
.data
x: .short 0

.text 				   

.globl _start

# entry point
_start:
    jmp loop_start

loop_start:

    # reseta o ah
    mov $0, %ah
    int $0x16

    mov %ah, %bh

    cmpb $'e', %bh
    je loop_x

    # Print
    movb $0x0e, %ah
    int $0x10
    jmp loop_start

loop_x:
    # reseta o ah
    mov $0, %ah
    int $0x16

    mov %ah, %bh

    cmpb $'x', %bh
    je loop_i

    # Print
    movb $0x0e, %ah
    int $0x10
    jmp loop_start

loop_i:
    # reseta o ah
    mov $0, %ah
    int $0x16

    mov %ah, %bh

    cmpb $'i', %bh
    je loop_t

    # Print
    movb $0x0e, %ah
    int $0x10
    jmp loop_start

loop_t:
    # reseta o ah
    mov $0, %ah
    int $0x16

    mov %ah, %bh

    cmpb $'t', %bh
    je loop_fim

    # Print
    movb $0x0e, %ah
    int $0x10
    jmp loop_start

loop_fim:

    # Print
    movb $0x0e, %ah
    int $0x10

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature
    .byte 0x55		         
    .byte 0xaa		        
