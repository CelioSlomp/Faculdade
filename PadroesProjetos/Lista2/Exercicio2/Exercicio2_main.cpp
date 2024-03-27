#include <iostream>
#include "classes.cpp"
#include <vector>

using namespace std;

int main()
{
    Observer *user1 = new Usuario("Usuario1");
    Observer *user2 = new Usuario("Usuario2");
    Observer *user3 = new Usuario("Usuario3");

    Loja *loja = new Loja();
    loja->registerObserver(user1);
    loja->adicionarProduto(new Produto("produto1", 15));
    loja->registerObserver(user2);
    loja->registerObserver(user3);
    loja->adicionarProduto(new Produto("produto2", 30));

    return 0;
}