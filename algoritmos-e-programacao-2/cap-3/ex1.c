// Ler um vetor de 5 posições do tipo inteiro
// calcular e escrever a soma dos elementos

#include <curses.h>
#include <stdio.h>

int main() {

	int vet[5], i, soma = 0;

	printw("Digite 5 valores do tipo inteiro: ");

	for (i = 0; i < 5; i++) {
		scanw("%i", & vet[i]);
		soma += vet[i];
	}

	printw("A soma dos elementos é %i", soma);

}
