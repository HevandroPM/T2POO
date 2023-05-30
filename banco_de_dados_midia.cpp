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

bool BancoDeDadosMidia::edita(int ID){}

int BancoDeDadosMidia::get_tam() {
    return produtos.tamanho();
}