// Banco de dados de jogos: listar e adicionar jogos
// Campos de cada jogo: ID, nome, gênero e preço

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOGOS 100

struct jogo{
  int id;
  char nome[50];
  char genero[30];
  float preco;
};

void mostrarMenu();
void listarJogos(struct jogo jogos[], int total);
int adicionarJogo(struct jogo jogos[], int total);

int main() {
  system("chcp 65001 > nul");

  struct jogo jogos[MAX_JOGOS];
  int total = 0;
  char opcao;

  jogos[0].id = 1;
  strcpy(jogos[0].nome, "The Witcher 3");
  strcpy(jogos[0].genero, "RPG");
  jogos[0].preco = 79.90;

  jogos[1].id = 2;
  strcpy(jogos[1].nome, "Minecraft");
  strcpy(jogos[1].genero, "Sandbox");
  jogos[1].preco = 99.90;

  jogos[2].id = 3;
  strcpy(jogos[2].nome, "Hollow Knight");
  strcpy(jogos[2].genero, "Metroidvania");
  jogos[2].preco = 46.99;

  total = 3;

  do {
    mostrarMenu();
    scanf(" %c", &opcao);

    switch (opcao)
    {
      case '1':
        listarJogos(jogos, total);
        break;

      case '2':
        total = adicionarJogo(jogos, total);
        break;

      case '0':
        printf("\nEncerrando o programa.\n");
        break;

      default:
        printf("\nOpção inválida, digite 1, 2 ou 0.\n");
        break;
    }
  } while (opcao != '0');

  return 0;
}

void mostrarMenu() {
  printf("\n====== BANCO DE DADOS DE JOGOS ======\n");
  printf("1 - Listar todos os jogos\n");
  printf("2 - Adicionar jogo\n");
  printf("0 - Sair\n");
  printf("Escolha uma opção: ");
}

void listarJogos(struct jogo jogos[], int total) {
  int i;

  printf("\n====== JOGOS CADASTRADOS ======\n");

  if (total == 0) {
    printf("Nenhum jogo cadastrado.\n");
  }

  for (i = 0; i < total; i++) {
    printf("ID      : %d\n", jogos[i].id);
    printf("Nome    : %s\n", jogos[i].nome);
    printf("Gênero  : %s\n", jogos[i].genero);
    printf("Preço   : R$ %.2f\n", jogos[i].preco);
    printf("-------------------------------\n");
  }
}

int adicionarJogo(struct jogo jogos[], int total) {
  float preco = 0;

  printf("\n====== ADICIONAR JOGO ======\n");

  if (total >= MAX_JOGOS) {
    printf("O banco de dados está cheio.\n");
    return total;
  }

  printf("Nome do jogo: ");
  scanf(" %49[^\n]", jogos[total].nome);

  printf("Gênero do jogo: ");
  scanf(" %29[^\n]", jogos[total].genero);

  printf("Preço do jogo (use ponto, exemplo 59.90): R$ ");
  scanf("%f", &preco);
  while (preco < 0) {
    printf("O preço não pode ser negativo, digite novamente: R$ ");
    scanf("%f", &preco);
  }
  jogos[total].preco = preco;

  jogos[total].id = total + 1;

  printf("Jogo '%s' adicionado com o ID %d.\n", jogos[total].nome, jogos[total].id);

  return total + 1;
}