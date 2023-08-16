/*
* \author: Éder Augusto Penharbel
* \date: February, 2022
* \version: February, 2022
*/

/* 1 - somar dois inteiros                                              - OK
 * 2 - Exibir uma linha cheia de '0'                                    - OK
 * 3 - Fazer uma moldura utilizando os caracteres ASCII
 * 4 - Ler caracteres via teclado e os imprimir na tela (um a um)
 * 5 - mesma coisa que o 4, só que até você mandar ele parar
 * OBS.: 4 e 5 utilizar int 0x16 para leitura de caracter por teclado
*/



# generate 16-bit code
.code16 			   

# Criando variaveis
.data
x: .short 0
y: .short 0


# executable code location
.text 				   

.globl _start

# entry point
_start:				    

    # character to print
    # Coisas declaradas antes de iniciar o loop
    mov $0, %cx
    mov $'0', %al

    # Incrementa 1 na variavel x
    mov $0, x(,1)


loop_start:
    # Compara e da jump ao loop_end
    # compara com 80 para fechar uma linha
    # de '0's da questao 2
    cmp $80, %cx
    jge loop_end

    # Adiciona x ao registrador %al
    add x, %al

    # bios service code to print
    movb $0x0e, %ah
    # bios service (interrupt)
    int $0x10


    inc %cx
    jmp loop_start

loop_end:

    
    # mov to 510th byte from 0 pos
    . = _start + 510	    
    
    # MBR boot signature 
    .byte 0x55		        
    # MBR boot signature 
    .byte 0xaa		        
