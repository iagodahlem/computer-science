// PG. 53 - Exercicio 2
// Faça um programa em C que leia um vetor de 20 posições do tipo real.
// Troque a 1a posição com a 11a, a 2a com a 12a, a 3a com a 13a, ..., 10a
// com a 20a. Escreva o vetor modificado.

#include <curses.h>
#include <stdio.h>

void main() {
	initscr();

	int vet[20], i;

	printw("Digite 20 numeros: ");

	for (i = 0; i < 20; i++) {
		scanw("%i", &vet[i]);
	}

	int count = 9;
	for (i = 0; i < 9; i++) {
		int aux = vet[i];
		vet[i] = vet[count];
		vet[count] = aux;
		count++;
	}

	printw("O vetor ficou: \n");
	for (i = 0; i < 20; i++) {
		printw("%i \n", vet[i]);
	}

	refresh();

	getch();

	endwin();
}
