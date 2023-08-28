# generate 16-bit code
.code16 			   

# Criando variaveis
.data
x: .short 0

.text 				   

.globl _start

# entry point
_start:				    

    # move 0x30 ao %al
    mov $'0', %al

    # soma 4 ao %al
    add $4, %al

    # Print
    movb $0x0e, %ah
    int $0x10

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature
    .byte 0x55		         
    .byte 0xaa		        
