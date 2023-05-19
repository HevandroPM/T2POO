#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
using namespace std;

class Midia
{
private:
    string titulo;
    bool disponivel;
    int id;
    int ano_Lancamento;
    string categoria;

public:
		Midia();
    Midia(const string &titulo, bool disponivel, int id, int ano_Lancamento,const string &categoria);

    string getTitulo() const;
    void setTitulo(const string &value);
    int getAnoLancamento() const;
    void setAnoLancamento(const int &value);
    string getCodigo() const;
    void setCodigo(const string &value);
    string getCategoria() const;
    void setCategoria(const string &value);
    void setDisponivel(const bool &disponivel);
    bool getDisponivel();
    virtual void imprimir();
};

#endif // MIDIA_H