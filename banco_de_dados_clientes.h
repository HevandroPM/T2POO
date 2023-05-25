#ifndef BANCO_DE_DADOS_CLIENTES_H
#define BANCO_DE_DADOS_CLIENTES_H

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
    Cliente pesquisa(int ID);
    void lista();
    int get_tam();

    
};

#endif // BANCO_DE_DADOS_H
