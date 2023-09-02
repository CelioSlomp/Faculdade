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

    # Print
    movb $0x0e, %ah
    int $0x10

    cmpb $'e', %al
    je loop_x

    jmp loop_start

loop_x:
    # reseta o ah
    mov $0, %ah
    int $0x16

    # Print
    movb $0x0e, %ah
    int $0x10

    cmpb $'x', %al
    je loop_i

    jmp loop_start

loop_i:
    # reseta o ah
    mov $0, %ah
    int $0x16

    # Print
    movb $0x0e, %ah
    int $0x10

    cmpb $'i', %al
    je loop_t

    jmp loop_start

loop_t:
    # reseta o ah
    mov $0, %ah
    int $0x16

    # Print
    movb $0x0e, %ah
    int $0x10

    cmpb $'t', %al
    je loop_fim

    jmp loop_start

loop_fim:

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature
    .byte 0x55		         
    .byte 0xaa		        
