#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

#define DIMENSAO_CAMPO 12
#define BOMBAS_FACIL 20
#define BOMBAS_DIFICIL 50

void jogar(){
	int opc;
	system("cls"); //limpa a tela
	printf("Escolha o nivel de dificuldade\n");
	printf("1 - Facil :)\n");
	printf("2 - Dificil :(\n");
	printf("3 - Voltar ao menu principal\n");
	printf("Opcao selecionada: ");
	scanf("%d", &opc);
	//if(opc == 3) break;
}

int main() {
	casa campo[DIMENSAO_CAMPO][DIMENSAO_CAMPO];
	int opc;
	do{
		system("cls"); //limpa a tela
  	printf("Campo Minado\n\n");
  	printf("1 - Jogar\n");
  	printf("2 - Ajuda\n");
  	printf("3 - Sair\n");
  	printf("\nO que deseja fazer? ");
  	scanf("%d", &opc);

		switch (opc) {
			case 1:
				jogar();
			break;
			case 2:
			break;
		}

	}	while(opc != 3);
	return 0;
}
