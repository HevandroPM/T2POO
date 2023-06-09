#ifndef LIST_H
#define LIST_H

template <typename TIPO> struct ElementoListaDE {
  TIPO dado;
  ElementoListaDE<TIPO> *anterior;
  ElementoListaDE<TIPO> *proximo;
  ElementoListaDE(TIPO d) : dado(d), proximo(nullptr), anterior(nullptr){}
};

template <typename TIPO> ElementoListaDE<TIPO> *novoelementoDE(TIPO dado) {
  ElementoListaDE<TIPO> *novo = new ElementoListaDE<TIPO>(dado);
  return novo;
}

template <typename TIPO> struct ListaDE {
  ElementoListaDE<TIPO> *inicio = nullptr;
  ElementoListaDE<TIPO> *fim = nullptr;

  void insere_fim(TIPO dado) {
    ElementoListaDE<TIPO> *novo = novoelementoDE(dado);
    if (inicio == nullptr) {
      inicio = novo;
      fim = novo;
    } else {
      novo->anterior = fim;
      fim->proximo = novo;
      fim = novo;
    }
  }


  void insere_inicio(TIPO dado) {
    ElementoListaDE<TIPO> *novo = novoelementoDE(dado);
    novo->proximo = inicio;
    inicio = novo;
    if (novo->proximo == nullptr) {
      fim = novo;
    } else {
      novo->proximo->anterior = novo;
    }
  }

  int tamanho() {
    ElementoListaDE<TIPO> *nav = inicio;
    int cont = 0;
    while (nav != nullptr) {
      cont++;
      nav = nav->proximo;
    }
    return cont;
  }

  TIPO retorna_p_indice(int indice) {
    ElementoListaDE<TIPO> *nav = inicio;
    for (int i = 0; i < indice; i++) {
      nav = nav->proximo;
    }
    return nav->dado;
  }

  bool inserir_p_indice(TIPO dado, int indice) {
    ElementoListaDE<TIPO> *novo = novoelementoDE(dado);
    if (indice >= tamanho()) {
      return false;
    } else {
      if (indice == 0) {
        insere_inicio(dado);
      } else if (indice == tamanho() - 1) {
        insere_fim(dado);
      } else {
        ElementoListaDE<TIPO> *nav = inicio;
        for (int i = 0; i < indice; i++) {
          nav = nav->proximo;
        }
        novo->anterior = nav->anterior;
        novo->proximo = nav;
        nav->anterior->proximo = novo;
        nav->anterior = novo;
      }
      return true;
    }
  }

  bool remove_inicio() {
    if (inicio == nullptr) {
      return false;
    } else {
      ElementoListaDE<TIPO> *apagado = inicio;
      inicio = apagado->proximo;
      if (inicio != nullptr) {
        inicio->anterior = nullptr;
        if (inicio->proximo == nullptr) {
          fim = inicio;
        }
      }
      delete apagado;
      return true;
    }
  }

  bool remove_fim() {
    if (fim == nullptr) {
      return false;
    } else {
      ElementoListaDE<TIPO> *apagado = fim;
      fim = apagado->anterior;
      if (fim != nullptr) {
        fim->proximo = nullptr;
        if (fim->anterior == nullptr) {
          inicio = fim;
        }
      }
      delete apagado;
      return true;
    }
  }

  bool remove_pos(int indice) {
    if (indice >= tamanho()) {
      return false;
    } else {
      if (indice == 0) {
        remove_inicio();
      } else if (indice == tamanho() - 1) {
        remove_fim();
      } else {
        ElementoListaDE<TIPO> *navp = inicio;
        ElementoListaDE<TIPO> *p = inicio->proximo;
        ElementoListaDE<TIPO> *navi = inicio->proximo->proximo;
        int i = 0;
        while (i < indice - 1) {
          navi = navi->proximo;
          navp = navp->proximo;
          p = p->proximo;
          i++;
        }
        if (i == indice - 1) {
          if (navi != nullptr && p != nullptr) {
            navi->anterior = p->anterior;
          }
          navp->proximo = p->proximo;
          delete p;
        }
      }
      return true;
    }
  }


};



#endif 