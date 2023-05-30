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
    cout<< "Ano de lançamento: " << getAnoLancamento() << endl;
    cout<<"Categoria: " << getCategoria() << endl;
    cout << "Plataforma: " << plataforma << endl;
}


Jogo::Jogo(const string &titulo, int ano_Lancamento,const string &categoria, const string &plataforma)
    : Midia(titulo,ano_Lancamento,categoria)
{
    this->plataforma = plataforma;
}