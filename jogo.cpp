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
    cout << "Jogo"<<endl;
    cout << "Título: " << getTitulo() << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Disponivel: " << ((getDisponivel() == 1)?"SIM":"NAO") << endl; 
}

Jogo::Jogo()
{
}

Jogo::Jogo(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria, const string &plataforma)
    : Midia(titulo,disponivel,id,ano_Lancamento,categoria)
{
    this->plataforma = plataforma;
}