#include <stdio.h>
#include <conio.h>

main() {

			 char palavra[80];
			 char palavraInvertida[80] = {'inicio'};
			 int i;
			 
       gotoxy(2, 2);
  	   printf(">> Digite uma palavra (fim para sair): ");
       scanf("%s", palavra);

			 while (strcmp(palavra, "fim")) {

				 int tamanhoPalavra = strlen(palavra);
				 char letraAuxiliar;
				 for (i = 0; i < tamanhoPalavra; i++) {
				 		 letraAuxiliar = palavra[tamanhoPalavra - 1];
				 		 palavraInvertida[i] = letraAuxiliar;
				  	 tamanhoPalavra--;
	 		 	 }

				 gotoxy(2, 6);
	       printf("Palavra original: %s", palavra);
				 gotoxy(2, 8);
	       printf("Palavra invertida: %s", palavraInvertida);

				 gotoxy(2, 10);
	       if (strcmp(palavra, palavraInvertida) == 0) {
				 		printf("A palavra eh palindroma.");
		 		 } else {
				 		printf("A palavra NAO eh palindroma.");
				 }
				 
				 getch();
				 clrscr();
         gotoxy(2, 2);
	  	   printf(">> Digite uma palavra (fim para sair): ");
         scanf("%s", palavra);
       }

}
