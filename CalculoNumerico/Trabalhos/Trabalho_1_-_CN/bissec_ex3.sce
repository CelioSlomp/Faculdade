clear

//Método da Bissecção
//Entrada: f: função, 
//         [a,b]: intervalo que contém a raiz
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y= x**3 + 4*x**2 -10');
//deff('y=f(x)','y=x**2-2');
//deff('y=f(x)','y=(x/2)**2 - sin(x)');

a=1;
b=2;
epsilon=0.0001;
x=(a+b)/2;
erro=(b-a);
while f(x) < epsilon
    disp('Valor de x: '+ string(x))
    disp('f(x): ' + string(f(x)))
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
end
disp(x, 'A raiz da função é: ')

