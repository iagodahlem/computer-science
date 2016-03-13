// Ler um vetor de 10 posições (inteiro)
// encontrar e escrever o menor elemento

#include <stdio.h>
#include <conio2.h>

main() {
       int vet[10], i, menor=1000, pos;
       
       printf(">> Digite 10 inteiros: ");
       
       for (i = 0; i < 10; i++) {
             scanf("%i", &vet[i]);
             
             if (vet[i] < menor) {
                menor = vet[i];
                pos = i;
             }
       }

       printf("O menor numero eh: %i", menor);
       printf("E a posicao eh: %i", pos);
       
       getch();
}
