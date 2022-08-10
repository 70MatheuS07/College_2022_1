/**
 * @file ler_linha.c
 * @author Vinicius Mota
 * @brief a função ler_linha lê um tamanho minimo e caso não tenha espaço
 *  dobra de tamanho, isto é começa em 32, vai para 64, então 128, then 256,
 etc. as needed to accommodate the entire linha

 * @version 0.1
 * @date 2022-07-05
 *
 */

#include "prototipos.h"

void LiberaResult(char *result) {
  free(result);
  result = NULL;
}

char *ler_linha(FILE *fp) {

  char linha[TAM_LINHA];
  int qtdCaracteres = 1, num = 1;

  char *result = calloc(TAM_LINHA, sizeof(char));

  while (1) {
    qtdCaracteres = 1;

    if (feof(fp)) {
      LiberaResult(result);
      return NULL;
    }

    // Impede duplicar a ultima linha.
    if (fgets(linha, TAM_LINHA, fp) == NULL) {
      result[0] = '\n';
      result[1] = '\0';
      return result;
    }

    // Conta quantidade de caracteres.
    for (int i = 0; i < TAM_LINHA * num; i++) {
      if (linha[i] == '\0') {
        break;
      }

      if (linha[i] == '\n') {
        linha[i] = '\0';
        break;
      }

      else {
        qtdCaracteres++;
      }
    }

    if (qtdCaracteres < TAM_LINHA) {
      strcat(result, linha);
      break;
    }

    else {
      num++;
      result = realloc(result, sizeof(char) * (TAM_LINHA * num));
      strcat(result, linha);
    }
  }

  return result;
}