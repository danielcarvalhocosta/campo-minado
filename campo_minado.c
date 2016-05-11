#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_campo(int *campo, int linhas, int colunas) {
  int i, j;

  for(j = 0; j < colunas+1; ++j) {
    if(j == 0) printf("  ");
    else printf("%d ", j);
  }
  printf("\n");

  for(i = 0; i < linhas; ++i) {
    printf("%d ", i+1);
    for(j = 0; j < colunas; ++j) {
      printf("%d ", campo[i*colunas+j]);
    }
    printf("\n");
  }
}

void gerar_campo(int *campo, int linhas, int colunas) {
  int i, j;

  srand( (unsigned)time(NULL) );
  for(i = 0; i < linhas; ++i) {
    for(j = 0; j < colunas; ++j) {
      campo[i*colunas+j] = rand()%7;
    }
  } 
}