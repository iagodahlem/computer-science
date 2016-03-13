// float %f
// int %i
// char %c || %s

// Ler um vetor de 15 posições do tipo char, contar quantas vezes a letra "a" aparece no vetor

#include <stdio.h>
#include <conio.h>

main() {
       char vet[15];
       int sum = 0, i;
       
       printf(">> Digite caracteres.");
       
       for (i = 0; i < 15; i++) {
           gotoxy(i*5 + 2, 3);
           scanf("%s", &vet[i]);
           if ("%s", vet[i] == 'a') {
              sum++;
           }
       }
       
       printf("A letra a aparece %i vezes.", sum);
       
       getch();
}
