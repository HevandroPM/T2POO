#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include"list.h"
#include"pessoa.h"
#include"midia.h"

class BancoDeDados
{
private:
    ListaDE<Cliente> clientes;
    ListaDE<Funcionario> funcionarios;
    ListaDE<Midia> produtos;
public:

    void adiciona(Cliente c);
    void imprime_clientes();
};


#endif // PESSOA_H
