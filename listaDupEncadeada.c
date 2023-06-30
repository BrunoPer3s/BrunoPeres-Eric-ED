#include <stdio.h>
#include <stdlib.h>

#include "filme.h"
#include "listaCDescritor.h"

typedef struct listaDupEncadeada {
  struct filme info;
  struct listaDupEncadeada *prox;
  struct listaDupEncadeada *ant;
} ListaDupEncadeada;

void insereSequencia(ListaCDescritor *l, int idInput, Filme *f, int *id) {
  if (!estaVazia(l)) {
    NoFilme *p;

    for (p = l->prim; (p != NULL) && (p->info.id != idInput); p = p->prox)
      ;

    if (p == NULL) {
      printf("\nO primeiro filme nao foi encontrado para adicionar a sequencia\n");
      free(f);
    } else if (p->info.id == idInput) {
      f->seq = NULL;

      f->id = *id;
      (*id)++;

      printf("O id unico gerado para %s eh: %d\n", f->nome, f->id);

      ListaDupEncadeada *seq = malloc(sizeof(ListaDupEncadeada));
      seq->info = *f;
      seq->prox = NULL;

      if (p->info.seq == NULL) {
        p->info.seq = seq;
        seq->ant = NULL;
      }

      else {
        ListaDupEncadeada *p_seq;

        for (p_seq = p->info.seq; p_seq->prox != NULL; p_seq = p_seq->prox)
          ;

        p_seq->prox = seq;
        seq->ant = p_seq;
      }
    }
    l->n++;
  } else {
    printf("\nA lista esta vazia\n");
  }
}

void imprimeSequencia(ListaCDescritor *l, int idInput) {
  if (!estaVazia(l)) {

    NoFilme *p;
    ListaDupEncadeada *p_seq;

    for (p = l->prim; (p != NULL) && (p->info.id != idInput); p = p->prox)
      ;

    if (p == NULL) {
      printf("\nNao foi encontrado um filme com o id informado\n");
    } else if (p->info.id == idInput) {

      if (p->info.seq == NULL) {
        printf("\nO filme indicado nao tem sequencias\n");
      } else {
        printf("\nSequencia(s) de %s:\n", p->info.nome);

        for (p_seq = p->info.seq; p_seq != NULL; p_seq = p_seq->prox) {
          imprimeFilme(&(p_seq->info));
          printf("\n");
        }
      }
    }
  } else {
    printf("\nLista Vazia!\n");
  }
}

void removeSequencia(ListaCDescritor *l, int idInput1, int idInput2) {
  if (!estaVazia(l)) {
    NoFilme *p;

    for (p = l->prim; (p != NULL) && (p->info.id != idInput1); p = p->prox)
      ;

    if (p == NULL) {
      printf("\nO primeiro filme não foi encontrado para remover a sequência\n");
      return;
    }

    else if (p->info.id == idInput1) {
      ListaDupEncadeada *p_seq;

      for (p_seq = p->info.seq; (p_seq != NULL) && (p_seq->info.id != idInput2); p_seq = p_seq->prox)
        ;

      if (p_seq == NULL) {
        printf("\nNão foi encontrada nenhuma sequência com o id informado\n");
        return;
      }

      if (p_seq->info.id == idInput2) {
        if (p_seq->prox == NULL && p_seq->ant == NULL) {
          p->info.seq = NULL;
        }

        else if (p_seq->ant == NULL) {
          p->info.seq = p_seq->prox;
          p_seq->prox->ant = NULL;
        }

        else if (p_seq->prox == NULL) {
          p_seq->ant->prox = NULL;
        }

        else {
          p_seq->ant->prox = p_seq->prox;
          p_seq->prox->ant = p_seq->ant;
        }

        l->n--;
        free(p_seq);
      }
    }
  } else {
    printf("\nLista Vazia!\n");
    return;
  }
}

void imprimeAntecessor(ListaCDescritor *l, int idInput) {
  if (!estaVazia(l)) {
    NoFilme *p;
    ListaDupEncadeada *p_seq;

    for (p = l->prim; p != NULL; p = p->prox) {
      if (p->info.id == idInput) {
        printf("\nO filme em questao nao tem antecessor\n");

        return;
      }

      for (p_seq = p->info.seq; p_seq != NULL; p_seq = p_seq->prox) {
        if (p_seq->info.id == idInput) {

          if (p_seq->ant == NULL) {

            printf("\nAntecessor:\n");
            imprimeFilme(&(p->info));
            printf("\n");
          } else {
            printf("\nAntecessor:\n");
            imprimeFilme(&(p_seq->ant->info));
            printf("\n");
          }

          return;
        }
      }
    }

    printf("\nO id informado nao foi encontrado em lugar nenhum\n");
  } else {
    printf("\nA lista esta vazia\n");
  }
}

void imprimeSucessor(ListaCDescritor *l, int idInput) {
  if (!estaVazia(l)) {
    NoFilme *p;
    ListaDupEncadeada *p_seq;

    for (p = l->prim; p != NULL; p = p->prox) {

      if (p->info.id == idInput) {

        if (p->info.seq != NULL) {
          printf("\nSucessor:\n");
          imprimeFilme(&(p->info.seq->info));
          printf("\n");
        } else {
          printf("\nO filme em questao nao tem sucessor\n");
        }

        return;
      }

      for (p_seq = p->info.seq; p_seq != NULL; p_seq = p_seq->prox) {

        if (p_seq->info.id == idInput) {

          if (p_seq->prox != NULL) {
            printf("\nSucessor:\n");
            imprimeFilme(&(p_seq->prox->info));
            printf("\n");
          } else {
            printf("\nO filme em questao nao tem sucessor\n");
          }

          return;
        }
      }
    }

    printf("\nO id informado nao foi encontrado em lugar nenhum\n");
  } else {
    printf("\nA lista esta vazia\n");
  }
}
