#include "prototipos.h"
#include "ufenixcat.h"
#include "ufenixls.h"
#include "ufenixsort.h"
#include "ufenixtail.h"
#include "ufenixuniq.h"

int main(int argc, char *argv[]) {

  int comando = -1;

  while (comando != 0) {

    printf("Escolha a opcao:\n");
    printf("1 - cat\n");
    printf("2 - ls\n");
    printf("3 - tail\n");
    printf("4 - uniq\n");
    printf("5 - sort\n");
    printf("0 - Sair\n");

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