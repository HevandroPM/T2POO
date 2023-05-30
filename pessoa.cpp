#include <iostream>
#include"pessoa.h"
using namespace std;

Endereco::Endereco (string rua, int ncasa, string bairro) {
    this->rua = rua;
    this->n_casa = ncasa;
    this->Bairro = bairro;
}

string Endereco::get_rua() {
    return rua;
}
int Endereco::get_n_casa() {
    return n_casa;
}
string Endereco::get_bairro() {
    return Bairro;
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
    os << "Dinheiro: " << cliente.dinheiro << endl;

    if (cliente.END != nullptr) {
        os << "Rua: " << cliente.END->get_rua() << endl;
        os << "Numero de casa: " << cliente.END->get_n_casa() << endl;
        os << "Bairro: " << cliente.END->get_bairro() << endl;
    }
    return os;
}

Funcionario::Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END) : Pessoa(nome, CPF, sexo, END) {
    this->expediente = expediente;
    this->cargo = cargo;
}

string Funcionario::get_expediente(){
    return this->expediente;
}

void Funcionario::set_expediente(string expediente) {
    this->expediente = expediente;
}
void Funcionario::set_cargo(string cargo) {
    this->cargo = cargo;
}
string Funcionario::get_cargo() {
    return this->cargo;
}

ostream& operator<<(ostream& os, const Funcionario& funcionario) {
    os << "Nome: " << funcionario.nome << endl;
    os << "CPF: " << funcionario.CPF << endl;
    os << "Sexo: " << funcionario.sexo << endl;
    os << "Cargo: " << funcionario.cargo << endl;
    os << "Expediente: " << funcionario.expediente << endl;

    if (funcionario.END != nullptr) {
        os << "Rua: " << funcionario.END->get_rua() << endl;
        os << "Numero de casa: " << funcionario.END->get_n_casa() << endl;
        os << "Bairro: " << funcionario.END->get_bairro() << endl;
    }
    return os;
}