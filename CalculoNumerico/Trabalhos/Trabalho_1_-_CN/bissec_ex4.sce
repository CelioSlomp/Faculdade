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
iteracoes = 0;
while erro > epsilon
    iteracoes = iteracoes + 1;
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
end
disp('A raiz da função é: ' + string(x))
disp('Teve um total de ' + string(iteracoes) + ' iteracoes')

