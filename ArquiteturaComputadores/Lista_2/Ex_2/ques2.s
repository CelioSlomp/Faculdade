# generate 16-bit code
.code16 			   

.text 				   

.globl _start

# entry point
_start:				    

    mov $0, %bx

loop_start:

    mov $0, %bx

    mov $0, %ah
    int $0x16
    
    cmpb $'a', %al
    je loop_end

    pushw %ax

    # print
    movb $0x0e, %ah
    int $0x10

    jmp loop_start

loop_end:

    mov $0, %ax
    popw %ax
    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    .byte 0xaa		        
