#ifndef ARQUIVO_H
#define ARQUIVO_H

typedef struct listaCDescritor ListaCDescritor;

void leArquivo(ListaCDescritor *l, int *id);
void salvaArquivo(ListaCDescritor *l);

#endif