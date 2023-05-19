#ifndef PESSOA_H
#define PESSOA_H

#include<iostream>
using namespace std;
#include "endereco.h"

class Pessoa
{
protected:
    string nome;
    int cpf;
    string sexo;
    Endereco endereco;
public:
    Pessoa();
    Pessoa(string nome, int cpf, string sexo,Endereco endereco);
};

#endif // PESSOA_H
