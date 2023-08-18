/*
* \author: Éder Augusto Penharbel
* \date: February, 2022
* \version: February, 2022
*/


# generate 16-bit code
.code16 			   

.data
x: .short 0
varPrint: .short 0


# executable code location
.text 				   

.globl _start

# entry point
_start:

    mov x, %al
    mov $0x32, %al




    #mov $'0', %al

    #mov $0x32, x
    #mov x, %al

    #mov $0x32, %al

    #add $3, %al
    

    # print %al
    movb $0x0e, %ah
    int $0x10

    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
