#include <iostream>
#include "list.h"
#include "pessoa.h"
#include "banco_de_dados_clientes.h"
#include"banco_de_dados_funcionarios.h"
#include"banco_de_dados_midia.h"
using namespace std;

class Filme;

class Locadora
{
private:
    string nome;
    string CNPJ;
public:
    BancoDeDadosClientes BDDC;
    BancoDeDadosFuncionarios BDDF;
    BancoDeDadosMidia BDDM;
    Locadora(string nome, string CNPJ);
};

Locadora::Locadora(string nome, string CNPJ)
{
    this->CNPJ = CNPJ;
    this->nome = nome;
}


class Menu
{
private:
    Locadora * loc;
public:
    void main();
    ~Menu();
    void displayMainMenu();
    void displaySecondaryMenu(string optionName);
    void handleMainMenu();
    void handleMainMenu(string optionName);
};


void Menu::displayMainMenu() {
    cout << "\nMenu Principal:" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Funcionarios" << endl;
    cout << "3. Midia" << endl;
    cout << "0. Sair" << endl;
    cout << "Selecione uma opcao: ";
}

void Menu::displaySecondaryMenu(string optionName) {
    cout << "\nMenu " << optionName << ":" << endl;
    cout << "1. Cadastrar" << endl;
    cout << "2. Remover" << endl;
    cout << "3. Listar" << endl;
    cout << "4. Pesquisar" << endl;
    cout << "5. Editar" << endl;
    cout << "0. Voltar" << endl;
    cout << "Selecione uma opcao: ";
}


void Menu::handleMainMenu() {
    int opcaoPrincipal;
    while (true) {
        displayMainMenu();
        cin >> opcaoPrincipal;

        switch (opcaoPrincipal) {
            case 1: {
                handleMainMenu("Clientes");
                break;
            }
            case 2: {
                handleMainMenu("Funcionarios");
                break;
            }
            case 3: {
                handleMainMenu("Midia");
                break;
            }
            case 0: {
                return;
            }
            default: {
                cout << "Opcao invalida!" << endl;
                break;
            }
        }
    }
}

void Menu::handleMainMenu(string optionName) {
    Midia * tempM;
    Cliente * tempC;
    Funcionario * tempF;
    string nome;
    long long int CPF;
    string sexo;
    float dinheiro;
    string rua;
    int ncasa;
    string bairro;
    int opcaoSecundaria, opcaoMidia;
    int ID;
    string expediente;
    string cargo;

    //atributos para instaciar uma classe midia
    string titulo;
    int ano_lancamento;
    string categoria;

    string plataforma;

    string diretor;
    string duracao;
    

    while (true) {
        if (optionName == "Clientes") {
            displaySecondaryMenu(optionName);
            cin >> opcaoSecundaria;

            switch (opcaoSecundaria) {
                case 1: {
                    cout << "Digite o nome do cliente: ";
                    cin>>nome;
                    cout << "Digite o CPF do cliente: ";
                    cin >> CPF;
                    cout << "Digite o sexo do cliente: ";
                    cin>>sexo;
                    cout << "Digite a quantia em dinheiro do cliente: ";
                    cin >> dinheiro;
                    cout << "Digite a rua do endereço do cliente: ";
                    cin>>rua;
                    cout << "Digite o número da casa do endereço do cliente: ";
                    cin >> ncasa;
                    cout << "Digite o bairro do endereço do cliente: ";
                    cin>>bairro;

                    Cliente* novoCliente = novo_cliente(nome, CPF, sexo, dinheiro, rua, ncasa, bairro);
                    loc->BDDC.adiciona(*novoCliente);
                    break;
                }
                case 2: {
                    cout << "Digite o ID do cliente que você quer remover: ";
                    cin>>ID;
                    loc->BDDC.remove(ID);
                    break;
                }
                case 3: {
                    loc->BDDC.lista();
                    break;
                }
                case 4: {
                    cout << "Digite o ID do cliente que você quer pesquisar: ";
                    cin>>ID;
                    tempC = nullptr;
                    tempC = loc->BDDC.pesquisa(ID);
                    if (tempC == nullptr) {
                        cout << "Cliente nao encontrado!" << endl;
                    } else {
                        cout<<*tempC;
                    }
                    break;
                }
                case 5: {
                    cout << "Digite o ID do cliente que você quer editar: ";
                    cin>>ID;
                    loc->BDDC.edita(ID);
                    break;
                }
                case 0: {
                    return;
                }
                default: {
                    cout << "Opcao invalida!" << endl;
                    break;
                }
            }
        }
        if (optionName == "Funcionarios") {
            displaySecondaryMenu(optionName);
            cin >> opcaoSecundaria;

            switch (opcaoSecundaria) {
                case 1: {
                    cout << "Digite o nome do funcionario: ";
                    cin>>nome;
                    cout << "Digite o CPF do funcionario: ";
                    cin >> CPF;
                    cout << "Digite o sexo do funcionario: ";
                    cin>>sexo;
                    cout << "Digite a rua do endereço do funcionario: ";
                    cin>>rua;
                    cout << "Digite o número da casa do endereço do funcionario: ";
                    cin >> ncasa;
                    cout << "Digite o bairro do endereço do funcionario: ";
                    cin>>bairro;
                    cout << "Digite o expediente do funcionario: ";
                    cin >> expediente;
                    cout << "Digite o cargo do funcionario: ";
                    cin >> cargo;

                    Endereco * end = new Endereco(rua, ncasa, bairro);
                    Funcionario novoFuncionario = Funcionario(nome, CPF, sexo, expediente, cargo, end);
                    loc->BDDF.adiciona(novoFuncionario);
                    break;
                }
                case 2: {
                    cout << "Digite o ID do funcionario que você quer remover: ";
                    cin>>ID;
                    loc->BDDF.remove(ID);
                    break;
                }
                case 3: {
                    loc->BDDF.lista();
                    break;
                }
                case 4: {
                    cout << "Digite o ID do funcionario que você quer pesquisar: ";
                    cin>>ID;
                    tempF = nullptr;
                    tempF = loc->BDDF.pesquisa(ID);
                    if (tempF == nullptr) {
                        cout << "Funcionario nao encontrado!" << endl;
                    } else {
                        cout<<*tempF;
                    }
                    break;
                }
                case 5: {
                    cout << "Digite o ID do funcionario que você quer editar: ";
                    cin>>ID;
                    loc->BDDF.edita(ID);
                    break;
                }
                case 0: {
                    return;
                }
                default: {
                    cout << "Opcao invalida!" << endl;
                    break;
                }
            }
        }
        if (optionName == "Midia") { 
            displaySecondaryMenu(optionName);
            cin >> opcaoSecundaria;

            switch (opcaoSecundaria) {
                case 1: { // Adicionando uma midia: o usuario irá escolher se quer adicionar um jogo ou um filme, colocará as informações necessárias para chamar o construtor e depois essa midia será adicionada no banco de dados de midia
                    cout <<"Escolha o tipo da midia.\n1 - Jogo\n2 - Filme"<<endl;
                    cin >> opcaoMidia;
                    if (opcaoMidia == 1) {
                        cout<<"Insira o titulo do jogo: "<<endl;
                        cin>>titulo;
                        cout<<"Insira o ano de lancamento do jogo: "<<endl;
                        cin>>ano_lancamento;
                        cout<<"Insira a categoria do jogo:"<<endl;
                        cin>>categoria;
                        cout<<"Insira a plataformato do jogo: "<<endl;
                        cin>>plataforma;
                        tempM = new Jogo(titulo, ano_lancamento, categoria, plataforma);
                    } else if (opcaoMidia == 2) {
                        cout<<"Insira o titulo do filme: "<<endl;
                        cin>>titulo;
                        cout<<"Insira o ano de lancamento do filme: "<<endl;
                        cin>>ano_lancamento;
                        cout<<"Insira a categoria do filme:"<<endl;
                        cin>>categoria;
                        cout<<"Insira o nome do diretor do filme:"<<endl;
                        cin>>diretor;
                        cout<<"Insira a duracao do filme:"<<endl;
                        cin>>duracao;
                        tempM = new Filme(titulo, ano_lancamento, categoria, diretor, duracao);
                    }

                    loc->BDDM.adiciona(tempM);
                    break;
                }
                case 2: {
                    cout<<"Insira o Id do produto que você deseja deletar: "<<endl;
                    cin>>ID;
                    loc->BDDM.remove(ID);
                    break;
                }
                case 3: {
                    loc->BDDM.lista();
                    break;
                }
                case 4: {
                    cout<<"Insira o Id do produto que você deseja pesquisar:"<<endl;
                    cin>>ID;
                    tempM = nullptr;
                    tempM = loc->BDDM.pesquisa(ID);
                    if (tempM == nullptr) {
                        cout << "Midia nao encontrada!" << endl;
                    } else {
                        tempM->imprimir();
                    }
                    break;
                }
                case 5: {
                    cout<<"Insira o Id do produto que você deseja editar:"<<endl;
                    cin>>ID;
                    loc->BDDM.edita(ID);
                    break;
                }
                case 0: {
                    return;
                }
                default: {
                    
                    break;
                }
            }
        }
    }
}

Menu::~Menu()
{
    cout<<"Obrigado por usar a nossa locadora!";
}

void Menu::main() {
    string nome, CNPJ;
    
    cout<<"Insira o nome da Locadora: ";
    cin>>nome;
    cout<<"Insira o cnpj dela: ";
    cin>>CNPJ;
    loc = new Locadora(nome, CNPJ);

    cout << "Bem-vindo a locadora " <<nome<<"!"<<endl<< endl;

    handleMainMenu();
}


int main()
{
    Menu m;
    m.main();

    return 0;
}
