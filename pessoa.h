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
    string get_rua();
    int get_n_casa();
    string get_bairro();
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
    Pessoa(string nome, long long int CPF, string sexo, Endereco* END);
    string get_nome();
    void set_nome(string novo_nome);
    long long int get_CPF();
    void set_CPF(long long int novo_CPF);
    string get_sexo();
    void set_sexo(string novo_sexo);
    Endereco* get_END();
    void set_END(Endereco* novo_END);
    int get_ID();

    static int get_cont() {
        return cont;
    }

};

class Cliente : public Pessoa {
private:
    float dinheiro;
    //Carrinho compras;

public:
    Cliente(string nome, long long int CPF, string sexo, float dinheiro, Endereco * END);

    float get_dinheiro();
    void set_dinheiro(float dinheiro);
    friend ostream& operator<<(ostream& os, const Cliente& cliente);
};

Cliente * novo_cliente(string nome, long long int CPF, string sexo, float dinheiro, string rua, int ncasa, string bairro);

class Funcionario : public Pessoa {
private:
    string expediente;
    string cargo;

public:
    Funcionario (string nome, long long int CPF, string sexo, string expediente, string cargo, Endereco * END);
    string get_expediente();
    void set_expediente(string expediente);
    void set_cargo(string cargo);
    string get_cargo();
    friend ostream& operator<<(ostream& os, const Funcionario& funcionario);
};

#endif // PESSOA_H
