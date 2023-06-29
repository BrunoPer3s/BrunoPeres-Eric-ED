#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"
#include "listaDupEncadeada.h"

typedef struct listaCDescritor
{
  int n;
  struct noFilme *prim, *ult;
} ListaCDescritor;

typedef struct noFilme
{
  struct filme info;
  struct noFilme *prox;
} NoFilme;

void criarLista(ListaCDescritor *l)
{
  l->n = 0;
  l->prim = NULL;
  l->ult = NULL;
}

int estaVazia(ListaCDescritor *l)
{
  return (l->n == 0);
}

int verificaSeIdExiste(ListaCDescritor *l, int idInput)
{
  NoFilme *p;

  for (p = l->prim; (p != NULL) && (p->info.id != idInput); p = p->prox)
    ;

  return (p == NULL);
}

void insereOrdenado(ListaCDescritor *l, Filme *f, int *id)
{

  NoFilme *novoFilme = (NoFilme *)malloc(sizeof(NoFilme));

  f->id = *id;
  (*id)++;
  novoFilme->info = *f;

  printf("ID: %d - %s\n\n", f->id, f->nome);

  if (estaVazia(l))
  {

    novoFilme->info = *f;

    novoFilme->prox = NULL;

    l->ult = novoFilme;
    l->prim = novoFilme;
    l->n++;

    return;
  }

  if (strcmp(novoFilme->info.nome, l->prim->info.nome) < 0)
  {

    novoFilme->info = *f;

    novoFilme->prox = l->prim;
    l->prim = novoFilme;
    l->n++;

    return;
  }

  else
  {
    NoFilme *p = l->prim, *ant;

    while (p != NULL && strcmp(novoFilme->info.nome, p->info.nome) >= 0)
    {
      ant = p;
      p = p->prox;
    }

    if (p == NULL)
    {
      novoFilme->prox = NULL;
      ant->prox = novoFilme;
      l->ult = novoFilme;
      l->n++;

      return;
    }

    else
    {
      novoFilme->prox = p;
      ant->prox = novoFilme;
      l->n++;
    }
  }
}

void alterarDados(ListaCDescritor *l, int idInput, int *id)
{
  if (!estaVazia(l))
  {
    NoFilme *p, *ant = NULL;
    (*id)++;

    for (p = l->prim; (p != NULL) && (p->info.id != idInput); p = p->prox)
    {
      ant = p;
    }

    if (p == NULL)
    {
      printf("\nId não encontrado\n");
    }
    else if (p->info.id == idInput)
    {
      Filme *f;
      f = &(p->info);

      printf("\nO filme encontrado foi: ");
      imprimeFilme(f);
      printf("\n");

      alterarNome(f);
      alterarAno(f);

      if (ant == NULL)
      {
        l->prim = p->prox;
      }
      else
      {
        ant->prox = p->prox;
      }

      l->n--;
      insereOrdenado(l, f, id);
    }
  }
  else
  {
    printf("\nLista Vazia!\n");
  }
}

void imprimeLista(ListaCDescritor *l)
{

  NoFilme *f;
  ListaDupEncadeada *lDup;

  if (!estaVazia(l))
  {
    printf("\n- Impressão da Lista -\n\n");
    for (f = l->prim; f != NULL; f = f->prox)
    {
      imprimeFilme(&(f->info));

      for (lDup = f->info.seq; lDup != NULL; lDup = lDup->prox)
      {
        printf("   --->   ");
        imprimeFilme(&(lDup->info));
      }

      printf("\n");
    }
  }
  else
  {
    printf("\nLista Vazia!\n");
  }
}

void removerFilme(ListaCDescritor *l, int idInput)
{
  NoFilme *ant = NULL;
  NoFilme *p;

  for (p = l->prim; (p != NULL) && (p->info.id != idInput); p = p->prox)
  {
    ant = p;
  }

  if (p == NULL)
  {
    printf("\nElemento não encontrado!\n");
  }
  else
  {

    if (p->info.seq != NULL)
    {
      ListaDupEncadeada *p1_seq, *p2_seq;

      for (p1_seq = p->info.seq; p2_seq != NULL; p1_seq = p2_seq)
      {
        p2_seq = p1_seq->prox;
        l->n--;
        free(p1_seq);
      }
      //(*id)--;
    }

    if (ant == NULL)
    {
      l->prim = p->prox;

      if (l->prim == NULL)
      {
        l->ult = NULL;
      }
    }

    else if (p->prox == NULL)
    {
      ant->prox = NULL;
      l->ult = ant;
    }

    else
    {
      ant->prox = p->prox;
    }

    free(p);
    l->n--;
    //(*id)++;
  }
}