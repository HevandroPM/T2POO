#include<iostream>
#include"banco_de_dados.h"
#include"list.h"
#include"pessoa.h"

struct banco_de_dados
{
    ListaDE<Cliente> clientes;
    ListaDE<Funcionario> funcionarios;
};
