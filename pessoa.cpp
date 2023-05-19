#include <iostream>
using namespace std;

class Endereco {
private:
    string rua;
    int n_casa;
    string Bairro;

public:
    Endereco (string rua, int ncasa, string bairro) {
        this->rua = rua;
        this->n_casa = ncasa;
        this->Bairro = bairro;
    }
};

class Pessoa {
private:
    string nome;
    long long int CPF;
    string sexo;
    Endereco *END;

public:
    Pessoa(string nome, long long int CPF, string sexo, Endereco *END) {
        this->nome = nome;
        this->CPF = CPF;
        this->sexo = sexo;
        this->END = END;
    }
};

class Cliente : public Pessoa {
private:
    float dinheiro;
    //Carrinho compras;

public:
    Cliente(string nome, long long int CPF, string sexo, float dinheiro, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
        this->dinheiro = dinheiro; 
     
    }

    /*bool finaliza_compra() {

    }*/
};

class Funcionario : public Pessoa {
private:
    string expediente;
    string cargo;

public:
    Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
        this->expediente = expediente;
        this->cargo = cargo;
    }

};