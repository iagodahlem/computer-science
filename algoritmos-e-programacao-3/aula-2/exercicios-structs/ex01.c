/**
 * 1 - Faça um programa que armazene em um registro de dados
 * (estrutura composta) os dados de dez funcionários de uma empresa,
 * compostos de:  Nome, Idade, Data de Nascimento
 *
 * Os dados devem ser digitados pelo usuário e armazenados e
 * somente no final exibidos na tela.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int SIZE = 10;

struct Funcionario {
  char nome[50];
  int idade;
  char dataNascimento[10];
};

void main() {
  int i;
  struct Funcionario funcionarios[SIZE];

  for (i = 0; i < SIZE; i++) {
    printf("Digite os dados do funcionario: \n");
    printf("Nome..............: "); scanf("%s", funcionarios[i].nome);
    printf("Idade.............: "); scanf("%i", &funcionarios[i].idade);
    printf("Data de Nascimento: "); scanf("%s", funcionarios[i].dataNascimento);
  }

  for (i = 0; i < SIZE; i++) {
    printf("%s \n", funcionarios[i].nome);
    printf("%i \n", funcionarios[i].idade);
    printf("%s \n", funcionarios[i].dataNascimento);
  }
}
