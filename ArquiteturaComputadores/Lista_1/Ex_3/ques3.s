# generate 16-bit code
.code16 			   

.text 				   

.globl _start

# entry point
_start:				    

    # character to print
    # Coisas declaradas antes de iniciar o loop
    mov $0, %cx
    mov $0, %bx
    mov $'0', %al

    # caractere em branco: 0x20
    # ╚: 0xda, ═: 0xc4, ║: 0xba, 
    # ╝: 0xd9, ╗: 0xbf, ╔: 0xc9

    movb $0xda, %al
    movb $0xe, %ah
    int $0x10

    jmp prim_linha

completa_linha:
    # funcao criada para completar uma linha com 
    # qualquer caracter 
    cmp $78, %cx
    jge loop_linhas2

    movb $0x20, %al
    
    # printa na tela
    movb $0xe, %ah
    int $0x10

    inc %cx
    jmp completa_linha

prim_linha:
    # Compara para ter os 80 caracteres
    cmp $78, %cx
    jge loop_end1

    # Adiciona x ao registrador %al
    #add hor, %al

    movb $0xc4, %al

    # bios service code to print
    movb $0x0e, %ah
    # bios service (interrupt)
    int $0x10

    inc %cx
    jmp prim_linha

loop_linhas:
    mov $0, %cx

    cmp $20, %bx
    jge ultima_linha
    
    movb $0xba, %al

    movb $0xe, %ah
    int $0x10

    jmp completa_linha

loop_linhas2:
    movb $0xba, %al

    movb $0xe, %ah
    int $0x10

    inc %bx
    jmp loop_linhas

loop_end1:
    mov $0, %cx
    movb $0xbf, %al
    movb $0xe, %ah
    int $0x10
    jmp loop_linhas

completa_linha2: 
    cmp $78, %cx
    jge loop_end_ult_linha

    movb $0xc4, %al
    
    # printa na tela
    movb $0xe, %ah
    int $0x10

    inc %cx
    jmp completa_linha2

ultima_linha:
    mov $0, %cx
    movb $0xd8, %al
    movb $0xe, %ah
    int $0x10
    jmp completa_linha2
    # ╝: 0xd9, ╗: 0xbf, ╔: 0xc9

loop_end_ult_linha:
    movb $0xd9, %al
    movb $0xe, %ah
    int $0x10



    # mov to 510th byte5 from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        