/**
 * 1 - Faça um programa em C que declara e lê um vetor [10] local, de
 * inteiros na função principal. A seguir, o programa principal passa o
 * endereço do vetor a uma função. Essa função irá inverter a ordem
 * dos dados desse array. No final o programa principal irá mostrar o
 * array com a nova ordem dos elementos.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int SIZE = 10;

void orderDesc(int *arr);

void main() {
  int i, arr[SIZE];

  for (i = 0; i < SIZE; i++) {
    printf("Digite um valor: ");
    scanf("%i", &arr[i]);
  }

  orderDesc(arr);

  for (i = 0; i < SIZE; i++) {
    printf("%i \n", arr[i]);
  }
}

void orderDesc(int *arr) {
  int i = SIZE, j = 0, aux;

  while (i > j) {
    i--;
    aux = arr[j];
    arr[j] = arr[i];
    arr[i] = aux;
    j++;
  }
}
