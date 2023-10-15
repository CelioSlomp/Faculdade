# generate 16-bit code
.code16 			   
.text 				   

.globl _start

# entry point
_start:				    

    # character to print
    movb $'x' , %al		
    # bios service code to print
    movb $0x0e, %ah	
    # bios service (interrupt) 
    int  $0x10		  

    call func_teste

    jmp fim

func_teste:

    movb $'x' , %al		
    # bios service code to print
    movb $0x0e, %ah	
    # bios service (interrupt) 
    int  $0x10
    ret

aa:
    movb $'b' , %al		
    # bios service code to print
    movb $0x0e, %ah	
    # bios service (interrupt) 
    int  $0x10

fim:
    movb $'z' , %al		
    # bios service code to print
    movb $0x0e, %ah	
    # bios service (interrupt) 
    int  $0x10

    hlt
    jmp fim
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
