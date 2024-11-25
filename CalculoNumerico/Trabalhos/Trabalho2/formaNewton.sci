// Interpolação pela forma de newton
x = [-2 -1 1 2]';
y = [0 1 -1 0]';
A = 0.5 // Valor que eu quero calcular
X = poly(0,"X"); // variável do polinômio

function coeficientes = coeficientesN(x,y)
    qtdPontos = length(x);
    T = zeros(qtdPontos,qtdPontos);
    T(:,1) = y;
    for j = 2:qtdPontos
        for i = 1:(qtdPontos-j+1)
           T(i,j) = (T(i+1,j-1) - T(i,j-1))/(x(j+i-1) -x(i));
        end
    end
    coeficientes = T(1,:);
endfunction

function [y, pol] = PdeA(A,x,coeficientes)
    y = coeficientes(1);
    pol = 0;
    for i=2:length(coeficientes)
        produto = coeficientes(i);
        varPol = coeficientes(i);
        for j=1:i-1
            produto = produto*(A-x(j));
            varPol = varPol * (X - x(j));
        end
        y = y+ produto;
        pol = pol + varPol;
    end
endfunction
[y,pol] = PdeA(A,x,coeficientesN(x,y));
disp("Ponto:", A);
disp("Polinomio:",pol)
disp("Valor da aproximação do ponto:",y);
