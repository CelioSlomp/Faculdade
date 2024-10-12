clear

//Método de Newton
//Entrada: f: função, 
//         f': derivada de f
//         x0: aproximação inicial
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y=x**10 -1');
deff('ylinha=g(x)','ylinha=10*x**9');

x0=0.5;
epsilon=0.0001;
x1=x0-f(x0)/g(x0);
iteracoes = 0
erro=abs(f(x1));

while erro > epsilon
    iteracoes = iteracoes + 1
    x0=x1;
    x1=x0-f(x0)/g(x0);
    erro=abs(f(x1));
end

disp(x1, 'A raiz da função é: ')
disp('Teve um total de ' + string(iteracoes) + ' iteracoes')

