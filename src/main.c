#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

#define DIMENSAO_CAMPO 12
#define BOMBAS_FACIL 20
#define BOMBAS_DIFICIL 50

int main() {
	//casa campo[DIMENSAO_CAMPO][DIMENSAO_CAMPO];
	int opc;
	do{
	limpar_tela();
  	printf("      .--.                               .-..-. _                 .-.      \n"); 
		printf("     : .--'                              : `' ::_;                : :      \n"); 
		printf("     : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--. \n"); 
		printf("     : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :\n"); 
		printf("     `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'\n"); 
		printf("                           : :                                        \n");      
		printf("                           :_;                                    \n"); 
  	printf("1 - Jogar\n");
  	printf("2 - Ajuda\n");
  	printf("3 - Sair\n");
  	printf("\nO que deseja fazer? ");
  	scanf("%d", &opc);

		switch (opc) {
			case 1:
				menuJogar();
			break;
			case 2:
				ajuda();
			break;
		}

	}	while(opc != 3);
	return 0;
}
