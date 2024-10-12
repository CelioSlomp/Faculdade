clear

//Método da Bissecção
//Entrada: f: função, 
//         [a,b]: intervalo que contém a raiz
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y=4*cos(x)-exp(x)');
a=0.5;
b=1;
epsilon=0.01;
x=(a+b)/2;
erro=(b-a);
while erro > epsilon
    disp('Valor de x: '+ string(x))
    disp('Erro: ' + string(erro))
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
end
disp(x, 'A raiz da função é: ')

