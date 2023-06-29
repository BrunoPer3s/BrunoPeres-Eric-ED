#include <stdio.h>

#include "arquivo.h"
#include "filme.h"
#include "listaCDescritor.h"
#include "listaDupEncadeada.h"

int main()
{
  int opcao = 0;
  int id = 1;
  int idInput, idInput2;

  ListaCDescritor lista;
  Filme *filme;
  criarLista(&lista);
  leArquivo(&lista, &id);

  do
  {
    printf("\n\n**** Selecione uma opção ****\n\n");

    printf("1- Inserir um novo filme\n");
    printf("2- Alterar os dados de um filme\n");
    printf("3- Remover um Filme\n");
    printf("4- Imprimir lista de filmes\n");
    printf("5- Inserir sequência de um filme\n");
    printf("6- Imprimir seguência de um filme\n");
    printf("7- Remover seguência de um filme\n");
    printf("8- Imprimir filme que antecede um outro\n");
    printf("9- Imprimir filme que sucede um outro\n");
    printf("10- Sair\n");

    printf("\nNúmero da opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      filme = leFilme();
      insereOrdenado(&lista, filme, &id);

      break;

    case 2:
      printf("\nDigite o id do filme: ");
      scanf("%d", &idInput);
      alterarDados(&lista, idInput, &id);

      break;

    case 3:
      printf("\nDigite o id do filme que deseja remover: ");
      scanf("%d", &idInput);
      removerFilme(&lista, idInput);

      break;

    case 4:
      imprimeLista(&lista);

      break;

    case 5:
      printf("\nDigite o id do filme original: ");
      scanf("%d", &idInput);
      if (!verificaSeIdExiste(&lista, idInput))
      {
        printf("\nInsira agora os dados da sequência\n");
        filme = leFilme();
        insereSequencia(&lista, idInput, filme, &id);
        break;
      }
      else
      {
        printf("ID não encontrado!\n");
        break;
      }

    case 6:
      printf("\nDigite o id do filme que deseja saber sua lista de sequencias\n");
      scanf("%d", &idInput);
      imprimeSequencia(&lista, idInput);

      break;

    case 7:
      printf("\nDigite o id do primeiro filme: ");
      scanf("%d", &idInput);

      printf("\nDigite o id da sequencia: ");
      scanf("%d", &idInput2);

      removeSequencia(&lista, idInput, idInput2);

      break;

    case 8:;
      printf("\nDigite o id do respectivo filme: ");
      scanf("%d", &idInput);
      imprimeAntecessor(&lista, idInput);

      break;

    case 9:
      printf("\nDigite o id do respectivo filme: ");
      scanf("%d", &idInput);
      imprimeSucessor(&lista, idInput);

      break;

    case 10:
      printf("Encerrando programa e salvando dados\n");
      salvaArquivo(&lista);
      break;

    default:
      printf("Opcao invalida \n");
    }

  } while (opcao != 10);

  printf("\n***********************Programa encerrado***********************\n");

  return 0;
}