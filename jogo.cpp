#include "jogo.h"

string Jogo::getPlataforma() const
{
    return plataforma;
}

void Jogo::setPlataforma(const string &value){
    plataforma = value;
}

void Jogo::imprimir()
{
    cout << "Jogo";
}

void imprimir();

Jogo::Jogo()
{
}

Jogo::Jogo(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria, const string &plataforma)
    : Midia(titulo,disponivel,id,ano_Lancamento,categoria)
{
    this->plataforma = plataforma;
}