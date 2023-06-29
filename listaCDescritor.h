#ifndef LISTACDESCRITOR_H
#define LISTACDESCRITOR_H

typedef struct filme Filme;

typedef struct listaCDescritor
{
  int n;
  struct noFilme *prim;
  struct noFilme *ult;
} ListaCDescritor;

typedef struct noFilme
{
  struct filme info;
  struct noFilme *prox;
} NoFilme;

void criarLista(ListaCDescritor *l);

int estaVazia(ListaCDescritor *l);

int verificaSeIdExiste(ListaCDescritor *l, int idInput);

void insereOrdenado(ListaCDescritor *l, Filme *f, int *id);

void alterarDados(ListaCDescritor *l, int idInput, int *id);

void removerFilme(ListaCDescritor *l, int idInput);

void imprimeLista(ListaCDescritor *l);

#endif