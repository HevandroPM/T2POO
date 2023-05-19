#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include<iostream>
using namespace std;
#include "pessoa.h"

class Funcionario : public Pessoa
{
private:
    string expediente;
    string cargo;
public:
    Funcionario();
    Funcionario(string nome, int cpf, string sexo,Endereco endereco, string expediente, string cargo):Pessoa(nome,cpf,sexo,endereco){
        this->expediente=expediente;
        this->cargo=cargo;
    };
};

bool add_func();
void remove_Func();
void remove_Cliente();
bool add_Prod(Produto p);
bool add_Servico (Servico s);

#endif // FUNCIONARIO_H
