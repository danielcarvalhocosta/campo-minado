#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DIMENSAO_CAMPO 12
#define BOMBAS_FACIL 20
#define BOMBAS_DIFICIL 50

typedef struct {
  char valor;
  bool aberta;
} casa;

void imprimir_campo(casa *campo) {
  int i, j;

  for(i = 0; i < DIMENSAO_CAMPO; ++i) {
    for(j = 0; j < DIMENSAO_CAMPO; ++j) {
      if(campo[i*DIMENSAO_CAMPO+j].aberta) {
        printf("[ %c ] ", campo[i*DIMENSAO_CAMPO+j].valor);
      } else {
        printf("[%03d] ", i*DIMENSAO_CAMPO+j+1);
      }

    }
    printf("\n");
  }
}

void gerar_campo(casa *campo, int bombas) {
  int pos_bombas[bombas];
  int tamanho = DIMENSAO_CAMPO * DIMENSAO_CAMPO;
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

/*
  Retornos:
    1 - Perdeu
    0 - Jogo continua
*/
int verificar_jogada(casa *campo, int jogada) {
  if(campo[jogada].aberta) {
    return 0;
  } else {
    if(campo[jogada].valor == '*') {
      campo[jogada].aberta = true;
      return 1;
    } else {
      // TODO Implementar abertura de vizinhos vazios
      campo[jogada].aberta = true;
      return 0;
    }
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

void limpar_tela() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}