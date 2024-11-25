clear

//Método-de-Newton-para-sistemas-não-lineares
//Entrada: F: função não linear, 
//         JF: matriz jacobiana de F
//         x: solução inicial
//         epsilon: precisão
//Saída: aproximação para a solução do sistema não linear

function y=F(x)
    y(1) = (x(1)-1)^2 + x(2)^2 -4
    y(2) = x(1)^2 + (x(2)-1)^2 -4
endfunction

function y=JF(x)
    y(1,1) = 2*(x(1)-1)
    y(1,2) = 2*x(2)
    y(2,1) = 2*x(1)
    y(2,2) = 2*(x(2)-1)
endfunction

x = [1.5 1.6]'; //solução inicial
epsilon = 0.00001; //tolerância
max_it = 20; //número max iterações
it = 0; //contador das iterações
jacob = JF(x)
disp('Matriz Jacobiana:', jacob)

while( norm(F(x), 'inf') > epsilon & it < max_it )
    disp('Iteração', it)
    disp('Valor de X:', x)
    s = jacob\(-F(x));
    x = x + s;
    it = it +1;
    disp('-------------------------')
end
disp(x, 'A solucao do sistema não linear é: ')
disp(it, 'Quantidade de iterações: ')

