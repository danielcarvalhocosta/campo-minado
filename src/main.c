#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

int main() {
	char opc;

  do {
    limpar_tela();
    imprimir_logo();

  	printf("1 - Jogar\n");
  	printf("2 - Ajuda\n");
  	printf("3 - Sair\n");
  	printf("\nO que deseja fazer? ");
  	scanf("%c", &opc);

		switch (opc) {
			case '1':
				jogar();
			break;
			case '2':
				ajuda();
			break;
      case '3':
        return 0;
      break;
      default:
        printf("Opção Inválida!\n");
      break;
		}

	}	while(opc != '3');
	return 0;
}
