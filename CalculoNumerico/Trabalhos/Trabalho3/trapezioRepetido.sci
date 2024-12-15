// Regra do trapezio repetido

a = 8;
b = 13;

n = 20; // subdivisoes

h = (b-a)/n; // o valor do passo

aTMP = a+h; // variavel temporaria 
somaInterna = 0; // soma da parte do 2*(f(xi) ...)
xi = [a]; // guarda os valores de x
e = exp(1); // carrega o valor de euler

//-------------------------------------
function f = funcao(x) // Funcao normal
    f=3*x*e^(2*x);
endfunction

function fll = derivFuncao(x) // Derivada dupla
    fll = (12*x + 12)*e^(2*x);
endfunction
//-------------------------------------

while aTMP < (b)
    somaInterna = somaInterna + funcao(aTMP); // soma a parte do 2*
    aTMP = aTMP + h; // Aumenta o valor do x
    xi = [xi, aTMP]; // salva o valor de x
end;

maiorF = abs(derivFuncao(a))
for i = xi
    if maiorF < abs(derivFuncao(i))
        maiorF = abs(derivFuncao(i));
    end
end

disp('valores de x:', xi);
result = ((h/2)*(funcao(a) + funcao(b) + 2*somaInterna));
disp('Resultado ', result);
erro = (((b-a)^3)/(12*n^2))*maiorF;
disp('Erro ', erro);
