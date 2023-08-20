/*
* \author: Éder Augusto Penharbel
* \date: February, 2022
* \version: February, 2022
*/


# generate 16-bit code
.code16 			   

.data
varMult:    .short 0
valorCalc:  .short 0
valorPrint: .short 0
contador:   .short 0
zeroMold:   .short 0

# executable code location
.text 				   

.globl _start

# entry point
_start:

    mov $1, %dx

    # adicionando '0' na moldura
    mov $0x30, zeroMold

    # adiciona 65535 a variavel que
    # sera printada na tela
    mov $0xffff, valorPrint

    # Como ela tem 5 digitos, passara
    # por um for para os 5 digitos
    mov $5, %cx

    # As bases de cada digito
    mov $10000, valorCalc

    jmp laco_inicial

laco_inicial:

    cmp $0, %cx
    jle final

    # zera o NumMenorVar
    mov $0, %dx

    # Diminui 1 do contador
    dec %cx




    # mov $0x32, x
    #   mov x, %al

    mov valorCalc, %cl
    # mov $10, %al
    # idiv %cl, %al
    # idiv $10
    movb $0x0e, %ah
    int $0x10
    # Dividir por 10 aqui
    # -----------------------
    # -----------------------
    # -----------------------

    jmp laco_inicial

NumMenorVar:
    cmp $10, %dx
    jge laco_inicial

    mov $0, %bx

    mov %dx, varMult
    mov varMult, %dx
    mov varMult, %bx

    # imul x , y  => x pode ser qualquer coisa e o y
    # precisa ser um registrador obrigatoriamente.
    # Multiplica o valor do x pelo y e o armazena
    # dentro de y.
    imul valorCalc, %bx
    
    cmp valorPrint, %dl
    jg eoValor

    inc %dx
    jmp NumMenorVar

eoValor:
    
    dec %dx
    mov %dx, varMult

    # reseta a moldura
    # mov $'0', zeroMold
    mov $'0', %al
    add varMult, %al

    jmp laco_inicial


final:

    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
