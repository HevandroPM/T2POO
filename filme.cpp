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
    cout << "Diretor: " << getDiretor() << endl;
    cout << "Duração: " << getDuracao() << endl;
    cout << "Disponivel: " << ((getDisponivel() == 1)?"SIM":"NAO") << endl;
}

Filme::Filme()
{
}

Filme::Filme(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria, const string &diretor, const string &duracao)
    : Midia(titulo,disponivel,id,ano_Lancamento,categoria)
{
    this->diretor = diretor;
    this->duracao = duracao;
}