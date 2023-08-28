# generate 16-bit code
.code16 			   

.text 				   

.globl _start

# entry point
_start:				    

    # Coisas declaradas antes de iniciar o loop
    mov $0, %cx
    mov $'0', %al

loop_start:
    # Compara e da jump ao loop_end
    # compara com 80 para fechar uma linha
    # de '0's da questao 2
    cmp $80, %cx
    jge loop_end

    # print '0'
    movb $0x0e, %ah
    int $0x10

    inc %cx
    jmp loop_start

loop_end:

    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    .byte 0xaa		        
