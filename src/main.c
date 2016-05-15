#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

int main() {
	int opc;
	do {
    limpar_tela();
    imprimir_logo();

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
				ajuda();
			break;
		}

	}	while(opc != 3);
	return 0;
}
