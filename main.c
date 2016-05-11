#include <stdio.h>
#include <stdlib.h>
#include "campo_minado.c"

int main() {
	int campo[2][2];

	gerar_campo(*campo, 2, 2);

	imprimir_campo(*campo, 2, 2);

	return 0;
}