#include "filme.h"

string Filme::getDiretor() const
{
    return diretor;
}

void Filme::setDiretor(const string &value){
    diretor = value;
}

string Filme::getDuracao() const
{
    return duracao;
}

void Filme::setDuracao(const string &value){
    duracao = value;
}

void Filme::imprimir()
{
    cout << "Filme" << endl;
    cout << "Título: " << getTitulo() << endl;
    cout<< "Ano de lançamento: "<<getAnoLancamento() << endl;
    cout<< "Categorio: "<<getCategoria() << endl;
    cout << "Diretor: " << getDiretor() << endl;
    cout << "Duração: " << getDuracao() << endl;
}

Filme::Filme(const string &titulo, int ano_Lancamento,const string &categoria, const string &diretor, const string &duracao)
    : Midia(titulo,ano_Lancamento,categoria)
{
    this->diretor = diretor;
    this->duracao = duracao;
}