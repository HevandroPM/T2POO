#include <iostream>
#include"pessoa.h"
using namespace std;

Endereco::Endereco (string rua, int ncasa, string bairro) {
    this->rua = rua;
    this->n_casa = ncasa;
    this->Bairro = bairro;
}

Pessoa::Pessoa(string nome, long long int CPF, string sexo, Endereco *END){
    this->nome = nome;
    this->CPF = CPF;
    this->sexo = sexo;
    this->END = END;
    cont++;
    this->ID = cont;

}

string Pessoa::get_nome() {
    return this->nome;
}

int Pessoa::cont = 0;

Cliente::Cliente(string nome, long long int CPF, string sexo, float dinheiro, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
    this->dinheiro = dinheiro; 
    
}

Cliente * novo_cliente(string nome, long long int CPF, string sexo, float dinheiro, string rua, int ncasa, string bairro) {
    Endereco * end_temp = new Endereco(rua, ncasa, bairro);
    Cliente * cliente_temp = new Cliente(nome, CPF, sexo, dinheiro, end_temp);
    return cliente_temp;
}

Funcionario::Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
    this->expediente = expediente;
    this->cargo = cargo;
}