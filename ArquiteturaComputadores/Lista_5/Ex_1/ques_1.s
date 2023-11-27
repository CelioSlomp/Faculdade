# generate 16-bit code
.code16 			   
.text 				   

.globl _start

_start:				    

    # Print o inicio do programa
    movb $'%' , %al		
    movb $0x0e, %ah	
    int  $0x10

    # Move 0 para o ax e depois para o data segment
    movw $0x0, %ax     
    movw %ax, %ds
    # Por que é movido o 0 ao %ds? Ele é movido por conta das
    # interrupcoes, que são reservadas de 0x00 até 0x3ff
    # as interrupcoes que são liberadas para serem "criadas"
    # são as de 0x80 até 0x3ff.
    # OBS.: cada interrupcao possui 4 bytes, ou seja, ao passar a
    # int 0x80, para poder enderecar precisa ser passado 0x200
    # que é 0x80 * 4

    # move 200 ao %bx
    movw $0x200, %bx

    # valor de _start
    # o 80 é um valor arbitrario, tem que ser igual ao 
    # _start + 0x.. da interrupcao, afinal, é a regiao 
    # reservada para outras int
    movw $0x7c80, (%bx)

    # chama a int 0x80
    int $0x80

    jmp fim

interrupcao:
    # vai até o byte 80, liberado para outras int
    . = _start + 0x80
    # passa a letra F e printa ela
    movb $'F' , %al		
    movb $0x0e, %ah	
    int  $0x10
    iret

fim:
    
    hlt
    jmp fim

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
