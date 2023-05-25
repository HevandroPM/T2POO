#ifndef BANCO_DE_DADOS_FUNCIONARIOS_H
#define BANCO_DE_DADOS_FUNCIONARIOS_H

#include"list.h"
#include"pessoa.h"

class BancoDeDadosFuncionarios
{
private:
    ListaDE<Funcionario> funcionarios;
public:

    void adiciona(Funcionario f);
    bool remove(int ID);
    bool edita(int ID);
    Funcionario pesquisa(int ID);
    void lista();
    int get_tam();

    
};

#endif //BANCO_DE_DADOS_FUNCIONARIOS_H