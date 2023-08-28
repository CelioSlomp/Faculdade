# generate 16-bit code
.code16 			   

# Criando variaveis
.data
x: .short 0

.text 				   

.globl _start

# entry point
_start:				    


loop:

    mov $0, %ah
    int $0x16

    # Print
    movb $0x0e, %ah
    int $0x10
    jmp loop

loop_fim:

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature
    .byte 0x55		         
    .byte 0xaa		        
