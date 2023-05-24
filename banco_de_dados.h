#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include"list.h"
#include"pessoa.h"
#include"midia.h"

class BancoDeDadosClientes
{
private:
    ListaDE<Cliente> clientes;
public:

    void adiciona(Cliente c);
    bool remove(int ID);
    bool edita(int ID);
    void pesquisa(int ID);
    void lista();

    
};

#endif // BANCO_DE_DADOS_H
