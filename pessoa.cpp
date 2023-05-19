#include "pessoa.h"

Pessoa::Pessoa()
{

}

Pessoa::Pessoa(string nome, int cpf, string sexo,Endereco endereco)
{
    this->nome = nome;
    this->cpf = cpf;
    this->sexo = sexo;
    this->endereco = endereco;
}