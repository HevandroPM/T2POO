#ifndef BANCO_DE_DADOS_MIDIA_H
#define BANCO_DE_DADOS_MIDIA_H

#include"list.h"
#include"filme.h"
#include"midia.h"
#include"jogo.h"

class BancoDeDadosMidia
{
private:
    ListaDE<Midia*> produtos;
public:

    void adiciona(Midia * m);
    bool remove(int ID);
    bool edita(int ID);
    Midia * pesquisa(int ID);
    void lista();
    int get_tam();
};

#endif // BANCO_DE_DADOS_MIDIA_H