#ifndef LISTADUPENCADEADA_H
#define LISTADUPENCADEADA_H

typedef struct filme Filme;
typedef struct listaCDescritor ListaCDescritor;

typedef struct listaDupEncadeada {
  struct filme info;
  struct listaDupEncadeada *prox;
  struct listaDupEncadeada *ant;
} ListaDupEncadeada;

void insereSequencia(ListaCDescritor *l, int idInput, Filme *f, int *id);

void imprimeSequencia(ListaCDescritor *l, int idInput);

void removeSequencia(ListaCDescritor *l, int idInput1, int idInput2);

void imprimeAntecessor(ListaCDescritor *l, int idInput);

void imprimeSucessor(ListaCDescritor *l, int idInput);

#endif
