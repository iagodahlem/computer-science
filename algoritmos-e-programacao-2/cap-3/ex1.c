// Ler um vetor de 5 posições do tipo inteiro
// calcular e escrever a soma dos elementos

#include <stdio.h>
#include <conio.h>

main() {
       int vet[5], i, soma = 0;
       
       clrscr(); // Limpa tela
       
       gotoxy(10, 8); // Posiciona o cursor na tela, 80 colunas, 25 linhas
       
       printf("Digite 5 valores do tipo inteiro: ");
       
       for (i = 0; i < 5; i++) {
             gotoxy(i*5 + 10, 10);
             scanf("%i", & vet[i]);
             soma += vet[i];
       }
       
       printf("A soma dos elementos %i", soma);
       
       getch();
}
