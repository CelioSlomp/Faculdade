clear

//Método de Jacobi
//Entradas
A = [4 0 1;1 10 3;2 1 4];
b = [6;27;12];
epsilon = 0.01;
xv=[0.97;1.98;2.05];
max_it=10;

n=size(A,1); // número de linhas (número de equações)
for k=1:max_it
    for i=1:n //processo iterativo de Jacobi
        x(i)=(b(i)-(sum(A(i,1:n)*xv(1:n))-A(i,i)*xv(i)))/A(i,i); 
    end
    
    if max(abs(x-xv))<epsilon
        disp(x)
        break
     else
         xv=x;
     end
     
     if k == max_it
         disp(x, 'após o número máximo de iterações chegamos a')
      end
end
