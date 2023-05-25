#include<iostream>
#include"banco_de_dados_midia.h"
#include"list.h"


void BancoDeDadosMidia::adiciona(Midia * m) {
    this->produtos.insere_fim(m);
}

void BancoDeDadosMidia::lista(){
    ElementoListaDE<Midia*> * nav = produtos.inicio;
    while (nav != nullptr)
    {
        cout<<endl<<nav->dado->getId()<<" "<<nav->dado->getTitulo();
        nav = nav->proximo;
    }
    cout<<endl<<"Ha "<<produtos.tamanho()<<" produtos cadastradas no banco de dados."<<endl;
    
}


bool BancoDeDadosMidia::remove(int ID) {
    ElementoListaDE<Midia*> * nav = produtos.inicio;
    int cont = 0;


    while (nav != nullptr)
    {
        if (nav->dado->getId() == ID) {
            produtos.remove_pos(cont);
            return true;
        } else {
            cont ++;
        }
        nav = nav->proximo;
    }
    return false;
}

Midia * BancoDeDadosMidia::pesquisa(int ID) {
    ElementoListaDE<Midia*> * nav = produtos.inicio;
    while (nav != nullptr)
    {
        if (nav->dado->getId() == ID) {
            return nav->dado;
        } else {
            nav = nav->proximo;
        }
    }
}

bool BancoDeDadosMidia::edita(int ID){
    ElementoListaDE<Midia*> * prod = produtos.inicio;
    while (prod != nullptr)
    {
        if (prod->dado->getId() == ID) {
            break;
        } else {
            prod = prod->proximo;
        }
    }
    if (prod == nullptr) {
        cout << "Midia do ID " << ID << " não foi encontrado." << endl;
        return false;
    }


    cout << "Escolha o tipo de :" << endl; // parei aqui
    cout << "1. Nome" << endl;
    cout << "2. CPF" << endl;
    cout << "3. Sexo" << endl;
    cout << "4. Endereço" << endl;
    cout << "5. Dinheiro" << endl;

    int choice2;
    cin >> choice2;
    switch (choice2)
    {
    case 1:
        /* code */
        break;
    
    case 2:
        /* code */
        break;
    
    default:
        break;
    }

    
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
            prod->dado.set_nome(novoNome);
            break;
        }
        case 2: {
            cout << "Insira o novo CPF: ";
            long long int novoCPF;
            cin >> novoCPF;
            prod->dado.set_CPF(novoCPF);
            break;
        }
        case 3: {
            cout << "Insira the novo genero: ";
            string novoGenero;
            cin>>novoGenero;
            prod->dado.set_sexo(novoGenero);
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
            prod->dado.set_END(novoEndereco);
            break;
        }
        case 5: {
            cout << "Insira a nova quantidade de dinheiro: ";
            float novoDinheiro;
            cin >> novoDinheiro;
            prod->dado.set_dinheiro(novoDinheiro);
            break;
        }
        default:
            cout << "Escolha invalida." << endl;
            return false;
    }

    cout << "Midia do ID " << ID << " editado com sucesso." << endl;
    return true;
}

int BancoDeDadosMidia::get_tam() {
    return produtos.tamanho();
}