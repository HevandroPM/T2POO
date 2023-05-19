#include <iostream>
#include "pessoa.h"
using namespace std;
#include "jogo.h"
#include "filme.h"
int main(int argc, char const *argv[])
{
    /*
    Jogo j1("CS:GO",1,27,2012,"FPS","PC,Linux,MacX");
    j1.imprimir();
    cout << endl;
    Filme f1("Brasil",0,23,2002,"Documentario","Mark Zukenberg","120 Minutos");
    f1.imprimir();*/

    Midia * testeJogo = new Jogo("CS:GO",1,27,2012,"FPS","PC,Linux,MacX");
    Midia * testeFilme = new Filme("Brasil",0,23,2002,"Documentario","Mark Zukenberg","120 Minutos");

    testeJogo->imprimir();
    cout<<endl;
    testeFilme->imprimir();
    return 0;
}
