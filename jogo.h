#ifndef JOGO_H
#define JOGO_H

#include <iostream>
using namespace std;
#include "midia.h"

class Jogo : public Midia
{
private:
    string plataforma;

public:
    Jogo(const string &titulo, int ano_Lancamento,const string &categoria, const string &plataforma);
    string getPlataforma() const;
    void setPlataforma(const string &value);
    virtual void imprimir();
};

#endif // JOGO_H