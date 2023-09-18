# generate 16-bit code
.code16 			   

.text 				   

.globl _start

# entry point
_start:
    # mov $0x1000, %ax
    # mov %ax, %ss
    # mov $0xffff, %sp

    # configurado memoria
    movw $0x1000, %ax
    movw %ax, %ds
    movw $0xf00, %bx

    # Imprimir %
    mov $'%', %al
    movb $0xe, %ah
    int $0x10
    
    mov $0xff08, %sp
    mov $0, %cl

leitura_teclado:

    # Leitura teclado
    mov $0, %ah
    int $0x16
    
    # compara enter para fim do loop
    cmpb $0xd, %al
    je loop_end

    # print
    movb $0xe, %ah
    int $0x10

    # Remove o resto do ax para sobrar apenas a letra
    mov $0, %ah

    movw $0xf00, %bx
    # soma o contador com o bx para poder alterar
    # o lugar da memoria em que e armazenada
    add %cx, %bx
    movw %ax, (%bx)

    inc %cl
    jmp leitura_teclado

loop_end:
    # incrementa contador e anula ultimo byte
    inc %cl
    movw $0xf00, %bx
    add %cx, %bx
    movw %ax, (%bx)


    # Printa na tela % pra simbolizar que acabou o programa
    mov $'%', %al
    movb $0xe, %ah
    int $0x10

    hlt
    jmp loop_end

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    .byte 0xaa		        
