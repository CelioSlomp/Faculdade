# generate 16-bit code
.code16 			   

# executable code location
.text 				   

.globl _start

# entry point
_start:				    

    # character to print
    # Coisas declaradas antes de iniciar o loop
    mov $0x34, %al

    # Incrementa 1 na variavel x
    mov $0x36, %al

    movb $0x0e, %ah
    int $0x10

    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
