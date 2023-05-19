#ifndef FILME_H
#define FILME_H

#include <iostream>
using namespace std;
#include "midia.h"

class Filme : public Midia
{
private:
    string diretor;
    string duracao;

public:
	Filme();
    Filme(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria, const string &diretor, const string &duracao);
    string getDiretor() const;
    void setDiretor(const string &value);
    string getDuracao() const;
    void setDuracao(const string &value);
    virtual void imprimir();
};

#endif // MIDIA_H