#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"
#include "listaCDescritor.h"
#include "listaDupEncadeada.h"

int tamArquivo()
{
  FILE *file = fopen("bancoLinux.txt", "r");

  if (file == NULL)
    return 0;

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fclose(file);

  return size;
}

void leArquivo(ListaCDescritor *l, int *id)
{
  Filme *filme = malloc(sizeof(Filme));
  Filme *filmeSeq = malloc(sizeof(Filme));
  FILE *arq;
  arq = fopen("bancoLinux.txt", "r");
  if (arq != NULL)
  {
    if (tamArquivo() != 0)
    {
      if (arq == NULL)
      {
        printf("Erro de alocacao ou Falha no arquivo \n");
      }
      else
      {
        char c;
        while (feof(arq) == 0)
        {
          fscanf(arq, "%c", &c);
          fseek(arq, -1, SEEK_CUR);
          if (c == '|')
          {
            fscanf(arq, "|%d|%d|%[^\n]\n", &filmeSeq->id, &filmeSeq->ano, filmeSeq->nome);
            *id = filmeSeq->id;
            insereSequencia(l, filme->id, filmeSeq, id);
          }
          else
          {
            fscanf(arq, "%d\t%[^\t]\t%d\n", &filme->id, filme->nome, &filme->ano);
            filme->seq = NULL;
            *id = filme->id;
            insereOrdenado(l, filme, id);
          }
        }
        fclose(arq);
      }
      int MaiorId = 0;

      NoFilme *f = l->prim;
      while (f != NULL)
      {
        ListaDupEncadeada *fSeq = f->info.seq;
        while (fSeq != NULL)
        {
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
    else
      printf("O arquivo esta vazio, não tem o que inserir\n");
  }
  else
    printf("Não se tem arquivo para obter dados!!!\n -----CONTINUANDO COM O PROGRAMA-----\n");
}

void salvaArquivo(ListaCDescritor *l, int *id)
{
  FILE *arq;
  arq = fopen("bancoLinux.txt", "w");

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
    *id = MaiorId;
  }
  fclose(arq);
}
