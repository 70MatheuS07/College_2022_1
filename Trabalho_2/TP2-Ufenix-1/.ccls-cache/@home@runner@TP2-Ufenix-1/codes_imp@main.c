#include "prototipos.h"
#include "ufenixcat.h"
#include "ufenixls.h"
#include "ufenixsort.h"
#include "ufenixtail.h"
#include "ufenixuniq.h"

int main(int argc, char *argv[]) {

  int comando = -1;
  char opcao[TAM_INICIAL];
  char argumento[TAM_INICIAL];

  while (strcmp(opcao, "sair") == 0) {

    printf("Digite o nome da opcao desejada:\n");
    printf("- cat\n");
    printf("- ls\n");
    printf("- tail\n");
    printf("- uniq\n");
    printf("- sort\n");
    printf("- sair\n\n");

    printf("ufenix$ ");
    scanf("%s ", opcao);

    if (strcmp(opcao, "cat") == 0) {

      mainUfenix_cat(argc, argv);

    }

    else if (strcmp(opcao, "ls") == 0) {

    }

    else if (strcmp(opcao, "tail") == 0) {

    }

    else if (strcmp(opcao, "uniq") == 0) {
    }

    else {
      printf("Operacao invalida, tente novamente\n\n");
      scanf("%*[^\n]");
      scanf("%*[\n]");
    }
  }

  while (comando != 0) {

    printf("Digite o nome da opcao desejada:\n");
    printf("1 - cat\n");
    printf("2 - ls\n");
    printf("3 - tail\n");
    printf("4 - uniq\n");
    printf("5 - sort\n");
    printf("0 - sair\n\n");

    scanf("%d", &comando);

    switch (comando) {

    case 0:
      printf("Voce saiu do programa\n");
      break;

    case 1:
      mainUfenix_cat(argc, argv);
      break;

    case 2:
      mainUfenix_ls(argc, argv);
      break;

    case 3:
      mainUfenix_sort(argc, argv);
      break;

    case 4:
      mainUfenix_tail(argc, argv);
      break;

    case 5:
      mainUfenix_uniq(argc, argv);
      break;

    default:
      printf("Numero invalido, tente novamente\n\n");
    }
  }

  return 0;
}