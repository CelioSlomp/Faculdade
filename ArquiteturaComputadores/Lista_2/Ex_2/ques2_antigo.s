# generate 16-bit code
.code16 			   

.text 				   

.globl _start

# entry point
_start:				    

    mov $0, %cx
    mov $0, %bh

loop_start:

    # mov $0, %bx

    mov $0, %ah
    int $0x16
    
    # print
    movb $0x0e, %ah
    int $0x10


    cmpb $'a', %al
    je fim
    

    # mov $0, %edx
    mov $1, %dx
    inc %cx

    sub $0x30, %ax
    push %ax


    jmp loop_start

fim:
    cmp $0, %cx
    je loop_end
    
    dec %cx
    
    # mov $0, %bl
    popw %bx

    mov %bx, %ax

    imul $10, %dx

    jmp fim

loop_end:

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    .byte 0xaa		        
