#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco
{
private:
    std::string rua;
    int numero;

public:
    Endereco();
    Endereco(const std::string& rua, int numero);

    std::string getRua() const;
    void setRua(const std::string& rua);

    int getNumero() const;
    void setNumero(int numero);
};

#endif // ENDERECO_H
