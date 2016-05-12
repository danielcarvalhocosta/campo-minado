#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

#define DIMENSAO_CAMPO 12
#define BOMBAS_FACIL 20
#define BOMBAS_DIFICIL 50

int main() {
	casa campo[DIMENSAO_CAMPO][DIMENSAO_CAMPO];

  printf("Campo Minado\n\n");

  printf("1 - Jogar\n");
  printf("2 - Ajuda\n");
  printf("3 - Sair\n");

  printf("\nO que deseja fazer? ");
  getchar();

	return 0;
}
