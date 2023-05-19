#include <iostream>
#include "pessoa.h"
using namespace std;
#include "jogo.h"

int main(int argc, char const *argv[])
{
    Jogo j1("CS:GO",1,27,2012,"FPS","PC,Linux,MacX");
    j1.imprimir();
    return 0;
}
