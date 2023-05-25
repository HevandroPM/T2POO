#include<iostream>
#include"banco_de_dados_funcionarios.h"
#include"list.h"
#include"pessoa.h"
#include"midia.h"


void BancoDeDadosFuncionarios::adiciona(Funcionario f) {
    this->funcionarios.insere_fim(f);
}

void BancoDeDadosFuncionarios::lista(){
    ElementoListaDE<Funcionario> * nav = funcionarios.inicio;
    while (nav != nullptr)
    {
        cout<<endl<<nav->dado.get_ID()<<" "<<nav->dado.get_nome();
        nav = nav->proximo;
    }
    cout<<endl<<"Ha "<<funcionarios.tamanho()<<" funcionarios cadastradas no banco de dados."<<endl;
    
}


bool BancoDeDadosFuncionarios::remove(int ID) {
    ElementoListaDE<Funcionario> * nav = funcionarios.inicio;
    int cont = 0;

    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
            funcionarios.remove_pos(cont);
            return true;
        } else {
            cont ++;
        }
        nav = nav->proximo;
    }
    return false;
}

Funcionario BancoDeDadosFuncionarios::pesquisa(int ID) {
    ElementoListaDE<Funcionario> * nav = funcionarios.inicio;
    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
            return nav->dado;
        } else {
            nav = nav->proximo;
        }
    }
}

bool BancoDeDadosFuncionarios::edita(int ID){
    ElementoListaDE<Funcionario> * cliente = funcionarios.inicio;
    while (cliente != nullptr)
    {
        if (cliente->dado.get_ID() == ID) {
            break;
        } else {
            cliente = cliente->proximo;
        }
    }
    if (cliente == nullptr) {
        cout << "Funcionario do ID " << ID << " não foi encontrado." << endl;
        return false;
    }

    // Display the available attributes for editing
    cout << "Escolha o atributo a ser editado:" << endl;
    cout << "1. Nome" << endl;
    cout << "2. CPF" << endl;
    cout << "3. Sexo" << endl;
    cout << "4. Endereço" << endl;
    cout << "5. Expediente" << endl;
    cout << "6. Cargo" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Insira o novo nome: ";
            string novoNome;
            cin>>novoNome;
            cliente->dado.set_nome(novoNome);
            break;
        }
        case 2: {
            cout << "Insira o novo CPF: ";
            long long int novoCPF;
            cin >> novoCPF;
            cliente->dado.set_CPF(novoCPF);
            break;
        }
        case 3: {
            cout << "Insira the novo genero: ";
            string novoGenero;
            cin>>novoGenero;
            cliente->dado.set_sexo(novoGenero);
            break;
        }
        case 4: {
            cout << "Insira o novo endereco:" << endl;
            cout << "Rua: ";
            string novaRua;
            cin>>novaRua;

            cout << "Número da casa: ";
            int novoNcasa;
            cin >> novoNcasa;

            cout << "Bairro: ";
            string novoBairro;
            cin>>novoBairro;

            Endereco* novoEndereco = new Endereco(novaRua, novoNcasa, novoBairro);
            cliente->dado.set_END(novoEndereco);
            break;
        }
        case 5: {
            cout << "Insira o novo expediente: ";
            string expediente;
            cin >> expediente;
            cliente->dado.set_expediente(expediente);
            break;
        }
        case 6: {
            cout << "Insira o novo cargo: ";
            string cargo;
            cin >> cargo;
            cliente->dado.set_expediente(cargo);
            break;
        }
        default:
            cout << "Escolha invalida." << endl;
            return false;
    }

    cout << "Funcionario do ID " << ID << " editado com sucesso." << endl;
    return true;
}

int BancoDeDadosFuncionarios::get_tam() {
    return funcionarios.tamanho();
}