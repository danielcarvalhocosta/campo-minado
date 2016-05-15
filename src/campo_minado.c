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

void imprimir_logo() {
  printf("      .--.                               .-..-. _                 .-.      \n");
  printf("     : .--'                              : `' ::_;                : :      \n");
  printf("     : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--. \n");
  printf("     : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :\n");
  printf("     `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'\n");
  printf("                           : :                                             \n");
  printf("                           :_;                                             \n\n\n");
}

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
  Retorno:
    Um inteiro representando a quantidade de bombas ao redor
*/
int verificar_vizinhos(casa *campo, int jogada) {
  int i, j, bombas = 0;

  if(campo[(jogada-1) - 12].valor == '*') ++bombas;
  if(campo[jogada - 12].valor == '*') ++bombas;
  if(campo[(jogada+1) - 12].valor == '*') ++bombas;
  if(campo[jogada - 1].valor == '*') ++bombas;
  if(campo[jogada + 1].valor == '*') ++bombas;
  if(campo[(jogada-1) + 12].valor == '*') ++bombas;
  if(campo[jogada + 12].valor == '*') ++bombas;
  if(campo[(jogada+1) + 12].valor == '*') ++bombas;

  return bombas;
}

/*
  Retornos:
    -1 - Perdeu
    (0 .. 6) - Quantidade de bombas ao redor
*/
int verificar_jogada(casa *campo, int jogada) {
  if(campo[jogada].aberta) {
    return 0;
  } else {
    if(campo[jogada].valor == '*') {
      campo[jogada].aberta = true;
      return -1;
    } else {
      campo[jogada].aberta = true;

      return verificar_vizinhos(campo, jogada);
    }
  }
}

void ajuda(){
  limpar_tela();
  imprimir_logo();

  printf("Guia do Jogo\n\n");
  printf("\n");
  printf("\n");
  printf("1-Ao prossionar jogar voce ira escolhe uma entre as duas modalidades\n");
  printf("\n");
  printf("2-Selecionada a modalidade ira aparecer uma matriz representando o campo\n");
  printf("\n");
  printf("3-Selecione a posiçao de seu interece e espere o resultado\n");
  printf("\n");
  printf("4-Caso seja [ - ] representa que nao tem bomba e voce podera escolher outra\n");
  printf("posiçao\n");
  printf("\n");
  printf("5-Caso seja [ * ] representa que vc encontrou uma boba e automatiamente perdeu\n");
  printf("o jogo\n");
  printf("\n");
  printf("6-Ao final do jogo voce podera jogar novamente ou sair do jogo\n");
  printf("\n");
  printf("Pressione qualquer tecla para voltar ao menu principal\n");
  printf("\n");


  getchar(); getchar();
}

int jogar(){
  casa campo[DIMENSAO_CAMPO][DIMENSAO_CAMPO];

  for(;;) {
    int opc, jogada;

    limpar_tela();
    imprimir_logo();

    printf("Escolha o nivel de dificuldade\n\n");
    printf("1 - Facil (20 Bombas)\n");
    printf("2 - Dificil (50 Bombas) \n");
    printf("3 - Voltar ao menu principal\n");
    printf("\nOpcao selecionada: ");
    scanf("%d", &opc);

    switch(opc){
      case 1:
        gerar_campo(*campo, BOMBAS_FACIL);
      break;
      case 2:
        gerar_campo(*campo, BOMBAS_DIFICIL);
      break;
      case 3:
        return 0;
      break;
      default:
        printf("Opção inválida!\n");
      break;
    }

    int jogada_info = 0;

    for(;;){
      limpar_tela();
      imprimir_logo();

      imprimir_campo(*campo);

      printf("\n Bombas próximas da última jogada: %d\n", jogada_info);
      printf("\n\n Digite sua jogada: ");
      scanf("%d", &jogada);

      jogada_info = verificar_jogada(*campo, jogada-1);
      if(jogada_info == -1){
        limpar_tela();
        imprimir_logo();

        imprimir_campo(*campo);
        printf("\n VOCE PERDEU!\n");
        printf("Pressione qualquer tecla para voltar ao menu");
        getchar(); getchar();
        break;
      }
    }
  }
}
