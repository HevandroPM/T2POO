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
        cout<<endl<<nav->dado->get_ID()<<" "<<nav->dado->getTitulo();
        nav = nav->proximo;
    }
    cout<<endl<<"Ha "<<produtos.tamanho()<<" produtos cadastradas no banco de dados."<<endl;
    
}


bool BancoDeDadosMidia::remove(int ID) {
    ElementoListaDE<Midia*> * nav = produtos.inicio;
    int cont = 0;


    while (nav != nullptr)
    {
        if (nav->dado->get_ID() == ID) {
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
        if (nav->dado->get_ID() == ID) {
            return nav->dado;
        } else {
            nav = nav->proximo;
        }
    }
}

bool BancoDeDadosMidia::edita(int ID){
    ElementoListaDE<Midia*> * midia = produtos.inicio;
    string novotitulo;
    string novacategoria;
    string novoduracao;
    string novodiretor;
    int novoano;
    int choice;

    while (midia != nullptr) {
        if (midia->dado->get_ID() == ID) {
            break;
        } else {
            midia = midia->proximo;
        }
    }
    if (midia == nullptr) {
        cout<<"Midia do ID "<<ID<< " não foi encontrada."<<endl;
        return false;
    }
    // diferentes menus para cada tipo de midia
     if (Filme* filme = dynamic_cast<Filme*>(midia->dado)) {
        // menu que pergunta qual atributo o usuario deseja alterar, chamando o get dependendo da opção
        cout<<"Escolha o atributo a ser editado:"<<endl;
        cout<<"1 - Titulo"<<endl;
        cout<<"2 - Categoria"<<endl;
        cout<<"3 - Duracao"<<endl;
        cout<<"4 - Diretor"<<endl;
        cout<<"5 - Ano de lancamento"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Digite o novo titulo:"<<endl;
                cin>>novotitulo;
                filme->setTitulo(novotitulo);
                break;
            case 2:
                cout<<"Digite o novo categoria:"<<endl;
                cin>>novacategoria;
                filme->setCategoria(novacategoria);
                break;
                
            case 3:
                cout<<"Digite o novo duracao:"<<endl;
                cin>>novoduracao;
                filme->setDuracao(novoduracao);
                break;
                
            case 4:
                cout<<"Digite o novo diretor:"<<endl;
                cin>>novodiretor;
                filme->setDiretor(novodiretor);
                break;
                
            case 5:
                cout<<"Digite o novo ano de lancamento:"<<endl;
                cin>>novoano;
                filme->setAnoLancamento(novoano);
                break;
                
            default:
                cout<<"Opcao invalida."<<endl;
                break;
        }

    }
    else if (Jogo* jogo = dynamic_cast<Jogo*>(midia->dado)) {
        cout<<"Escolha o atributo a ser editado:"<<endl;
        cout<<"1 - Titulo"<<endl;
        cout<<"2 - Categoria"<<endl;
        cout<<"3 - Ano de lancamento"<<endl;
        cout<<"4 - Plataforma"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Digite o novo titulo:"<<endl;
                cin>>novotitulo;
                jogo->setTitulo(novotitulo);
                break;
            case 2:
                cout<<"Digite o novo categoria:"<<endl;
                cin>>novacategoria;
                jogo->setCategoria(novacategoria);
                break;
                
            case 3:
                cout<<"Digite o novo ano de lancamento:"<<endl;
                cin>>novoano;
                jogo->setAnoLancamento(novoano);
                break;
                
            case 4:
                cout<<"Digite o novo plataforma:"<<endl;
                cin>>novacategoria;
                jogo->setPlataforma(novacategoria);
                break;
                
            default:
                cout<<"Opcao invalida."<<endl;
                break;
        }
    }
}

int BancoDeDadosMidia::get_tam() {
    return produtos.tamanho();
}