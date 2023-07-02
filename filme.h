#ifndef FILME_H
#define FILME_H

#define MAX 50

struct listaDupEncadeada;

typedef struct filme {
  int id;
  int ano;
  char nome[MAX];
  struct listaDupEncadeada *seq;
} Filme;

Filme *leFilme();
void alterarNome(Filme *f);
void alterarAno(Filme *f);
int retornaAno(Filme *f);
void imprimeFilme(Filme *f);

#endif