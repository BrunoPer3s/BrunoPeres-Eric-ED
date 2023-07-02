#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct listaDupEncadeada;

typedef struct filme {
  int id;
  int ano;
  char nome[MAX];
  struct listaDupEncadeada *seq;
} Filme;

Filme *leFilme() {
  Filme *filme = malloc(sizeof(Filme));

  if (filme != NULL) {
    printf("\nCADASTRO DE FILME: \n\n");

    printf("Insira o nome do filme: ");
    scanf(" %[^\n]", filme->nome);

    printf("Insira o ano em que o filme foi lançado: ");
    scanf(" %d", &filme->ano);

    filme->seq = NULL;

    return filme;
  } else {
    printf("Erro de Alocação \n");
    exit(1);
  }
}

void alterarNome(Filme *f) {
  char novoNome[MAX];
  printf("\nInsira o novo nome: ");
  scanf(" %[^\n]", novoNome);

  strcpy((*f).nome, novoNome);
}

void alterarAno(Filme *f) {
  int novoAno;
  printf("Insira o novo ano: ");
  scanf(" %d", &novoAno);

  (*f).ano = novoAno;
}

int retornaAno(Filme *f) {
  return f->ano;
}

void imprimeFilme(Filme *f) {
  if (f != NULL) {
    printf("id: %d | %s | %d", f->id, f->nome, f->ano);
  } else {
    printf("\nErro ao imprimir filme\n");
  }
}