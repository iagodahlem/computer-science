#include <stdio.h>
#include <conio.h>

main() {

			 int v[12];
			 int i, j, l, aux = 0;
			 int count;
			 int exibir;
			 int linha = 6;
			 
			 clrscr();
			 gotoxy(5, 2);
			 
			 printf("Digite 12 valores: ");

			 for (i = 0; i < 12; i++) {
 		 			 gotoxy(i*4 + 5, 4);
			 		 scanf("%i", & v[i]);
 		 	 }

 		 	 for (i = 0; i < 12; i++) {
			 		 count = 0;
			 		 exibir = 1;
			 	 	 for (j = 0; j < 12; j++) {
					 		 if (v[i] == v[j]) {
							 		if (j >= i) {
						 		     count++;
					        } else {
										exibir = 0;
									}
								}
 		 	 		 }
 		 	 		 if (exibir == 1) {
					 		gotoxy(5, linha++);
							printf("N: %i - Vezes: %i", v[i], count);	
		 			 }
 		 	 }
			 
			 getche();
			 
}
