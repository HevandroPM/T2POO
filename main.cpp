#include <iostream>
#include "list.h"
#include "pessoa.h"
using namespace std;

class Filme;


class Cliente;


class Funcionario;


class Estoque
{
private:
    ListaDE<Filme> filmes;
public:
};

class Locadora
{
private:
    string nome;
    string CNPJ;
    ListaDE<Cliente> clientes;
    ListaDE<Funcionario> funcionarios;
    Estoque estoque;
public:
    Locadora(string nome, string CNPJ);
};

Locadora::Locadora(string nome, string CNPJ)
{
    this->CNPJ = CNPJ;
    this->nome = nome;
}

class Menu
{
private:
public:
    void main();
    ~Menu();
};

Menu::~Menu()
{
    cout<<"Obrigado por usar a nossa locadora!";
}

void Menu::main() {
    Locadora * loc;
    string nome, CNPJ;
    cout<<"Insira o nome da Locadora: ";
    cin>>nome;
    cout<<"Insira o cnpj dela: ";
    cin>>CNPJ;
    loc = new Locadora(nome, CNPJ);

    cout << "Bem-vindo a locadora " <<nome<<"!"<<endl<< endl;
}


int main(int argc, char const *argv[])
{
    Menu m;
    m.main();
    return 0;
}
