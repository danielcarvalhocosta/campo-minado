#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
  char valor;
  bool aberta;
} casa;

void imprimir_campo(casa *campo, int linhas, int colunas) {
  int i, j;

  for(i = 0; i < linhas; ++i) {
    for(j = 0; j < colunas; ++j) {
      if(campo[i*colunas+j].aberta) {
        printf("[ %c ] ", campo[i*colunas+j].valor);
      } else {
        printf("[%03d] ", i*colunas+j+1);
      }

    }
    printf("\n");
  }
}

void gerar_campo(casa *campo, int tamanho, int bombas) {
  int pos_bombas[bombas];
  int i, j;

  for(i = 0; i < tamanho; ++i) {
    campo[i].valor = '-';
    campo[i].aberta = false;
  }

  srand ( time(NULL) );
  for(i = 0; i < bombas; ++i) {
    int pos = rand()%tamanho;

    while(busca_seq(pos_bombas, pos, i) != -1) {
      pos = rand()%tamanho;
    }
    pos_bombas[i] = pos;

    campo[pos].valor = '*';
  }
}


int busca_seq(int vetor[], int chave, int tamanho) {
  int i;

  for(i = 0; i < tamanho; ++i) {
    if(vetor[i] == chave) {
      return i;
    }
  }

  return -1;
}
