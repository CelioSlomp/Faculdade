// Regra do simpson repetida

a = 8;
b = 13;

m = 20; // subdivisoes
n = m/2

h = (b-a)/m; // o valor do passo

aTMP = a+h; // variavel temporaria 
somaInterna = 0; // soma da parte do 2*(f(xi) ...)
xi = [a;]; // guarda os valores de x
e = exp(1); // carrega o valor de euler

//-------------------------------------
function f = funcao(x) // Funcao normal
    f=3*x*e^(2*x);
endfunction

function f4l = derivFuncao(x) // Derivada dupla
    f4l = (48*x + 96)*e^(2*x);
endfunction
//-------------------------------------

valorI = 1;
somaPares = 0;
somaImpares = 0;

while aTMP < (b)
    if (valorI - floor(valorI / 2) * 2) == 1 then
        somaImpares = somaImpares + funcao(aTMP);
    else
        somaPares = somaPares + funcao(aTMP);
    end

    aTMP = aTMP + h; // Aumenta o valor do x
    xi = [xi, aTMP]; // salva o valor de x
    valorI = valorI+1;
end;

maiorF = abs(derivFuncao(a))
for i = xi
    if maiorF < abs(derivFuncao(i))
        maiorF = abs(derivFuncao(i));
    end
end

disp('valores de x:', xi);
result = (h/3)*(funcao(a) + funcao(b) + 2*somaPares + 4*somaImpares);
disp('Resultado ', result);
erro = (((b-a)^5)/(2880*n^4))*maiorF;
disp('Erro ', erro);
