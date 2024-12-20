clear

//Método da Bissecção
//Entrada: f: função, 
//         [a,b]: intervalo que contém a raiz
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y=x**2 - 5');
a=2;
b=3;
epsilon=0.01;
x=(a+b)/2;
erro=(b-a);
matriz = [a,b,x,abs(b-a)];
//matriz=['a', 'b', 'x', 'b-a'; a,b,x,erro];
while erro > epsilon
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
    matriz = [matriz; a, b, x, abs(b-a)];
end
disp(matriz)
disp(x, 'A raiz da função é: ')

