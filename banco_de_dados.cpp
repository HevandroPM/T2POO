#include<iostream>
#include"banco_de_dados.h"
#include"list.h"
#include"pessoa.h"
#include"midia.h"


void BancoDeDados::adiciona(Cliente c) {
    //this->clientes.insere_fim(c);
}

void BancoDeDados::imprime_clientes(){
    ElementoListaDE<Cliente> * nav = clientes.inicio;
    while (nav != nullptr)
    {
        cout<<endl<<nav->dado.get_nome();
    }
    
}