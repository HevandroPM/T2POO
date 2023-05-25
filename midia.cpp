#include "midia.h"

string Midia::getTitulo() const
{
    return titulo;
}

void Midia::setTitulo(const string &value){
    titulo = value;
}

int Midia::getAnoLancamento() const
{
    return ano_Lancamento;
}

void Midia::setAnoLancamento(const int &value){
    ano_Lancamento = value;
}

string Midia::getCategoria() const
{
    return categoria;
}

void Midia::setCategoria(const string &value){
    categoria = value;
}

void Midia::setDisponivel(const bool &value){
    disponivel = value;
}

bool Midia::getDisponivel(){
    return disponivel;
}

void Midia::imprimir()
{
    cout << "Mídia" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Ano de Lançamento: " << ano_Lancamento << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Disponível: " << (disponivel ? "Sim" : "Não") << endl;
}

Midia::Midia()
{
}

Midia::Midia(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria)
    : titulo(titulo), disponivel(disponivel), id(id), ano_Lancamento(ano_Lancamento), categoria(categoria)
{
}