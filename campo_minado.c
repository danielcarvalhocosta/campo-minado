#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_campo(char *campo, int linhas, int colunas) {
  int i, j;

  for(i = 0; i < linhas; ++i) {
    for(j = 0; j < colunas; ++j) {
      printf("[%03d] ", (i*colunas+j)+1);
    }
    printf("\n");
  }
}

void gerar_campo(char *campo, int tamanho, int bombas) {
  int i, j;

  for(i = 0; i < tamanho; ++i) {
    campo[i] = '-';
  }

  srand( (unsigned)time(NULL) );
  for(i = 0; i < bombas; ++i) {
    int pos = rand()%tamanho;
    campo[pos] = '*';
  } 
}
