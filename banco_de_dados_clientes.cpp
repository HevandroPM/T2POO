#include<iostream>
#include"banco_de_dados_clientes.h"
#include"list.h"
#include"pessoa.h"
#include"midia.h"


void BancoDeDadosClientes::adiciona(Cliente c) {
    this->clientes.insere_fim(c);
}

void BancoDeDadosClientes::lista(){
    ElementoListaDE<Cliente> * nav = clientes.inicio;
    while (nav != nullptr)
    {
        cout<<endl<<nav->dado.get_ID()<<" "<<nav->dado.get_nome();
        nav = nav->proximo;
    }
    cout<<endl<<"Ha "<<clientes.tamanho()<<" clientes cadastradas no banco de dados."<<endl;
    
}


bool BancoDeDadosClientes::remove(int ID) {
    ElementoListaDE<Cliente> * nav = clientes.inicio;
    int cont = 0;


    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
            clientes.remove_pos(cont);
            return true;
        } else {
            cont ++;
        }
        nav = nav->proximo;
    }
    return false;
}

Cliente * BancoDeDadosClientes::pesquisa(int ID) {
    ElementoListaDE<Cliente> * nav = clientes.inicio;
    Cliente * result;
    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
            result = &nav->dado;
            return result;
        } else {
            nav = nav->proximo;
        }
    }
}

bool BancoDeDadosClientes::edita(int ID){
    ElementoListaDE<Cliente> * cliente = clientes.inicio;
    while (cliente != nullptr)
    {
        if (cliente->dado.get_ID() == ID) {
            break;
        } else {
            cliente = cliente->proximo;
        }
    }
    if (cliente == nullptr) {
        cout << "Cliente do ID " << ID << " não foi encontrado." << endl;
        return false;
    }

    // Display the available attributes for editing
    cout << "Escolha o atributo a ser editado:" << endl;
    cout << "1. Nome" << endl;
    cout << "2. CPF" << endl;
    cout << "3. Sexo" << endl;
    cout << "4. Endereço" << endl;
    cout << "5. Dinheiro" << endl;

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
            cout << "Insira a nova quantidade de dinheiro: ";
            float novoDinheiro;
            cin >> novoDinheiro;
            cliente->dado.set_dinheiro(novoDinheiro);
            break;
        }
        default:
            cout << "Escolha invalida." << endl;
            return false;
    }

    cout << "Cliente do ID " << ID << " editado com sucesso." << endl;
    return true;
}

int BancoDeDadosClientes::get_tam() {
    return clientes.tamanho();
}