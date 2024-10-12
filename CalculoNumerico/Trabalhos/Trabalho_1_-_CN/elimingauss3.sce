clear

//Eliminação Gaussiana 3 (pode ter pivô nulo)
//Entradas
A = [5 2 1; -1 4 2; 2 -3 10];
b = [-12; 20; 3];

//Matriz aumentada
Ab = [A b];

//Triangularizar a matriz
n=size(Ab,1); // quantidade de linhas (quantidade de equações)
for k = 1 : n-1
    // Troca linhas se o pivô for nulo
    if Ab(k,k)==0 // Verifica se o pivô é nulo
        for j=k+1:n // Procura nas próximas linhas um pivô não nulo e faz a troca
            if Ab(j,k)~=0 
                Ab([j k],:)=Ab([k j],:) // Troca das linhas
                break
             end
         end 
    end
    //Fim da troca de linhas
           
    for i = k+1 : n
        mik = Ab(i,k)/Ab(k,k); // multiplicador
        Ab(i,k)=0;
        Ab(i,k+1:n+1) = Ab(i,k+1:n+1) - mik*Ab(k,k+1:n+1); // operação elementar entre as linhas
     end 
end
disp(Ab, 'A matriz triangularizada é: ')

//Resolve sistema triangular superior
a = Ab(:, 1:n); //resgata a matriz A escalonada
b = Ab(:, n+1); //resgata o vetor b dos termos independentes

x(n)=b(n)/a(n,n);
for i = n-1:-1:1
    x(i)=(b(i)-a(i,i+1:n)*x(i+1:n))/a(i,i);
end

disp(x, 'A solução do sistema é:')

