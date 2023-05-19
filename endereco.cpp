#include "endereco.h"

Endereco::Endereco()
{
    rua = "";
    numero = 0;
}

Endereco::Endereco(const std::string& rua, int numero)
{
    this->rua = rua;
    this->numero = numero;
}

std::string Endereco::getRua() const
{
    return rua;
}

void Endereco::setRua(const std::string& rua)
{
    this->rua = rua;
}

int Endereco::getNumero() const
{
    return numero;
}

void Endereco::setNumero(int numero)
{
    this->numero = numero;
}
