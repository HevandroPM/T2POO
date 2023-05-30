#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
using namespace std;

class Midia
{
private:
    string titulo;
    int ano_Lancamento;
    string categoria;
    int ID;
    static int cont;

public:
    Midia(const string &titulo, int ano_Lancamento,const string &categoria);
    string getTitulo() const;
    void setTitulo(const string &value);
    int getAnoLancamento() const;
    void setAnoLancamento(const int &value);
    string getCategoria() const;
    void setCategoria(const string &value);
    int get_ID();
    virtual void imprimir();

    static int get_cont() {
        return cont;
    }
};

#endif // MIDIA_H