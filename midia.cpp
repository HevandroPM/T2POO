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
void Midia::imprimir()
{
    cout << "Mídia" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Ano de Lançamento: " << ano_Lancamento << endl;
    cout << "Categoria: " << categoria << endl;
}

int Midia::get_ID() {
    return ID;
}

Midia::Midia(const string &titulo, int ano_Lancamento,const string &categoria)
    : titulo(titulo), ano_Lancamento(ano_Lancamento), categoria(categoria)
{
    cont++;
    this->ID = cont;
}

int Midia::cont = 0;