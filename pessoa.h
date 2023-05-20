#ifndef PESSOA_H
#define PESSOA_H
using namespace std;
class Endereco {
private:
    string rua;
    int n_casa;
    string Bairro;

public:
    Endereco (string rua, int ncasa, string bairro);
};

class Pessoa {
protected:
    string nome;
    long long int CPF;
    string sexo;
    Endereco *END;
    int ID;
    static int cont;

public:
    Pessoa(string nome, long long int CPF, string sexo, Endereco *END);
    string get_nome();

    static int num_pessoas() {
        return cont;
    }
};

class Cliente : public Pessoa {
private:
    float dinheiro;
    //Carrinho compras;

public:
    Cliente(string nome, long long int CPF, string sexo, float dinheiro, Endereco * END);

    /*bool finaliza_compra() {

    }*/
};

Cliente * novo_cliente(string nome, long long int CPF, string sexo, float dinheiro, string rua, int ncasa, string bairro);

class Funcionario : public Pessoa {
private:
    string expediente;
    string cargo;

public:
    Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END);

};

#endif // PESSOA_H
