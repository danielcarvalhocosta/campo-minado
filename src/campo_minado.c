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

void ajuda(){
  limpar_tela();
  printf("Guia do Jogo\n\n");
  //botar as regras aqui e tals
  printf("Pressione qualquer tecla para voltar ao menu principal\n");
  getchar(); getchar();
}

void menuJogar(){
  casa campo[DIMENSAO_CAMPO][DIMENSAO_CAMPO];
	int opc;
  int jogada;
	limpar_tela();
	printf("Escolha o nivel de dificuldade\n");
	printf("1 - Facil :)\n");
	printf("2 - Dificil :(\n");
	printf("3 - Voltar ao menu principal\n");
	printf("Opcao selecionada: ");
	scanf("%d", &opc);

  switch(opc){
    case 1:
      gerar_campo(*campo, BOMBAS_FACIL);
    break;
    case 2:
      gerar_campo(*campo, BOMBAS_DIFICIL);
    break;
  }


  for(;;){
    limpar_tela();
    printf("Campo Minado\n");
    imprimir_campo(*campo);
    printf("\n\n Digite sua jogada: ");
    scanf("%d", &jogada); //getchar();
    if(verificar_jogada(*campo, jogada) == 1){
      limpar_tela();
      printf("Campo Minado\n");
      imprimir_campo(*campo);
      printf("\n VOCE PERDEU!\n");
      printf("Pressione qualquer tecla para voltar ao menu");
      getchar(); getchar();
      break;
    }
    else{
      verificar_jogada(*campo, jogada);
    }
  }
  //while (!verificar_jogada(*campo, jogada));

}
