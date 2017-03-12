/**
 * 2 - Faça um programa que declara uma matriz 3x3 de inteiros na
 * função principal. Depois o programa passa a matriz por referência a
 * uma função que irá ler dados para esta matriz. Depois a função
 * principal irá mostrar os dados da matriz.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int SIZE = 3;

void read(int *arr);

void main() {
  int arr[SIZE][SIZE];

  read(arr);
}

funcinario[].nome

void read(int *arr) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("Digite o valor da matriz \n");
      scanf("%i", &arr[i][j]);
    }
  }
}
