#include <iostream>
#include"pessoa.h"
using namespace std;

Endereco::Endereco (string rua, int ncasa, string bairro) {
    this->rua = rua;
    this->n_casa = ncasa;
    this->Bairro = bairro;
}

ostream& operator<<(ostream& os, const Endereco& endereco) {
    os << "Rua: " << endereco.rua << ", Número: " << endereco.n_casa << ", Bairro: " << endereco.Bairro;
    return os;
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
    return nome;
}

void Pessoa::set_nome(string novo_nome) {
    nome = novo_nome;
}

// Getter and Setter for 'CPF'
long long int Pessoa::get_CPF() {
    return CPF;
}

void Pessoa::set_CPF(long long int novo_CPF) {
    CPF = novo_CPF;
}

// Getter and Setter for 'sexo'
string Pessoa::get_sexo() {
    return sexo;
}

void Pessoa::set_sexo(string novo_sexo) {
    sexo = novo_sexo;
}

// Getter and Setter for 'END'
Endereco* Pessoa::get_END() {
    return END;
}

void Pessoa::set_END(Endereco* novo_END) {
    END = novo_END;
}

// Getter for 'ID'
int Pessoa::get_ID() {
    return ID;
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

float Cliente::get_dinheiro(){
    return this->dinheiro;
}
void Cliente::set_dinheiro(float dinheiro) {
    this->dinheiro = dinheiro;
}

ostream& operator<<(ostream& os, const Cliente& cliente) {
    os << "Nome: " << cliente.nome << endl;
    os << "CPF: " << cliente.CPF << endl;
    os << "Sexo: " << cliente.sexo << endl;
    os << "Endereço: " << *(cliente.END) << endl;
    os << "Dinheiro: " << cliente.dinheiro << endl;
    return os;
}

Funcionario::Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
    this->expediente = expediente;
    this->cargo = cargo;
}