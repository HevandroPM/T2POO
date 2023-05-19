template <typename TIPO> struct ElementoListaDE {
  TIPO dado;
  ElementoListaDE<TIPO> *anterior;
  ElementoListaDE<TIPO> *proximo;
  ElementoListaDE(TIPO d) : dado(d), proximo(nullptr), anterior(nullptr){}
};

template <typename TIPO> ElementoListaDE<TIPO> *novoelementoDE(TIPO dado);

template <typename TIPO> struct ListaDE {
  ElementoListaDE<TIPO> *inicio = nullptr;
  ElementoListaDE<TIPO> *fim = nullptr;

  void insere_fim(TIPO dado);

  void insere_inicio(TIPO dado);

  int tamanho();

  TIPO retorna_p_indice(int indice);

  bool inserir_p_indice(TIPO dado, int indice);

  bool remove_inicio();

  bool remove_fim();

  bool remove_pos(int indice);

};