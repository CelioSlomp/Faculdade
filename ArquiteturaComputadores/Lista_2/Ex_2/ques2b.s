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
    # Usando cl para contador do numero de digitos
    mov $0, %cl
    mov $0xff08, %sp

leitura_teclado:

    # Leitura teclado
    mov $0, %ah
    int $0x16
    
    # compara enter para fim do loop
    cmpb $0xd, %al
    je leitura_teclado_end

    # print
    movb $0xe, %ah
    int $0x10

    # Transformando ASCII para binario
    sub $0x30, %al
    # empilhando valor binario
    mov $0, %ah
    push %ax

    inc %cl
    jmp leitura_teclado

leitura_teclado_end:
    # res = 0
    movw $0xf00, %bx
    movw $0x0 , (%bx)
    # pot = 1
    movw $0xf02, %bx
    movw $0x1 , (%bx)

loop_conversao:    
    cmp $0, %cl
    je loop_end
    
    # Pegar digito
    pop %ax

    # Pegar o valor da potencia
    movw $0xf02, %bx
    movw (%bx), %dx

    # Multiplicar digito pela potencia
    mul %dx

    # Carrega res
    movw $0xf00, %bx
    movw (%bx), %dx

    # res = res + (pot * digito)
    add %dx, %ax

    # salvar res na memoria
    movw $0xf00, %bx
    movw %ax, (%bx)

    # calcular potencia
    movw $0xf02, %bx
    movw (%bx), %ax

    # multiplica a potencia por 10
    movw $10, %dx
    mul %dx

    # Joga a nova potencia na memoria
    movw $0xf02, %bx
    movw %ax, (%bx)

    # decrementa cl para o loop
    dec %cl
    jmp loop_conversao

loop_end:
    
    # Printa na tela % pra simbolizar que acabou o programa
    mov $'%', %al
    movb $0xe, %ah
    int $0x10

    # Joga o resultado no registrador dx
    movw $0xf00, %bx
    movw (%bx), %dx


    hlt
    jmp loop_end

    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    .byte 0xaa		        
