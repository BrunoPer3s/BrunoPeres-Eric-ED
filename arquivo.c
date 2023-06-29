#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"
#include "listaCDescritor.h"
#include "listaDupEncadeada.h"

void leArquivo(ListaCDescritor *l, int *id)

{
  Filme *filme = malloc(sizeof(Filme));
  Filme *filmeSeq = malloc(sizeof(Filme));

  FILE *arq;
  char linha[100];
  arq = fopen("banco.txt", "r");

  if (arq == NULL)
  {
    printf("Erro de alocacao ou Falha no arquivo \n");
  }
  else
  {
    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
      if (strncmp(linha, "|", 1) == 0)
      {
        sscanf(linha, "|%d|%d|%[^\n]", &filmeSeq->id, &filmeSeq->ano, filmeSeq->nome);
        *id = filmeSeq->id;
        insereSequencia(l, filme->id, filmeSeq, id);
      }
      else
      {
        sscanf(linha, "%d\t%[^\t]\t%d", &filme->id, filme->nome, &filme->ano);
        filme->seq = NULL;
        *id = filme->id;
        insereOrdenado(l, filme, id);
      }
    }
    fclose(arq);
  }
  int MaiorId = 0;

  NoFilme *f = l->prim;
  while(f != NULL) {
    ListaDupEncadeada *fSeq = f->info.seq;
    while (fSeq != NULL) {
      if (fSeq->info.id > MaiorId)
      {
        MaiorId = fSeq->info.id;
      }
      fSeq = fSeq->prox;
    }
    if (f->info.id > MaiorId)
    {
      MaiorId = f->info.id;
    }
    f = f->prox;
  }
  MaiorId++;
  (*id) = MaiorId;
}

void salvaArquivo(ListaCDescritor *l, int *id)
{
  FILE *arq;
  arq = fopen("banco.txt", "w");

  if (arq == NULL)
  {
    printf("Erro de alocacao ou Falha no arquivo \n");
  }
  else
  {
    NoFilme *f = l->prim;
    int MaiorId = 0;

    while (f != NULL)
    {
      fprintf(arq, "%d\t%s\t%d\n", f->info.id, f->info.nome, f->info.ano);
      ListaDupEncadeada *fSeq = f->info.seq;
      while (fSeq != NULL)
      {
        fprintf(arq, "|%d|%d|%s\n", fSeq->info.id, fSeq->info.ano, fSeq->info.nome);
        if(fSeq->info.id > MaiorId) {
          MaiorId = fSeq->info.id;
        }
        fSeq = fSeq->prox;
      }
      if(f->info.id > MaiorId) {
        MaiorId = f->info.id;
      }
      f = f->prox;
    }
  *id = MaiorId;
  }
  fclose(arq);
}
