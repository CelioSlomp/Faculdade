clear

//Método de Newton
//Entrada: f: função, 
//         f': derivada de f
//         x0: aproximação inicial
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y=x^2-5');
deff('ylinha=g(x)','ylinha=2*x');

x0=3;
epsilon=0.01;
x1=x0-f(x0)/g(x0);
iteracoes = 0
erro=abs(f(x1));
matriz = [x0];
while erro > epsilon
    iteracoes = iteracoes + 1;
    x0=x1;
    x1=x0-f(x0)/g(x0);
    erro=abs(f(x1));
    matriz = [matriz; x0];
end
matriz = [matriz; x1];
disp(x1, 'A raiz da função é: ')
disp('Teve um total de ' + string(iteracoes) + ' iteracoes')
disp(matriz)
