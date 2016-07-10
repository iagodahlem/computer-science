#include <stdio.h>
#include <conio.h>

main() {
			 
			 int matriz[4][4] = {0};
			 int i;
			 int l, c;
			 int codigo1, codigo2, resultadoT1, resultadoT2;

			 gotoxy(2, 2);
			 printf("Times");
 			 gotoxy(4, 3);
			 printf("0 - Brasil de Pelotas");
 			 gotoxy(4, 4);
			 printf("1 - Caxias");
 			 gotoxy(4, 5);
			 printf("2 - Gremio");
 			 gotoxy(4, 6);
			 printf("3 - Internacional");
			 
			 for (i = 0; i < 6; i++) {
			 		 gotoxy(2, 10 * i + 2);
			 		 printf("Jogo %i", i + 1);
			 		 
			 		 gotoxy(2, 10 + i * 4);
			 		 printf("Codigo Time 1....: ");
			 		 scanf("%i", & codigo1);
			 		 
			 		 gotoxy(2, 10 + i * 5);
			 		 printf("Codigo Time 2....: ");
			 		 scanf("%i", & codigo2);
 			 		 
 			 		 gotoxy(2, 10 + i * 6);
			 		 printf("Resultado T1.....: ");
			 		 scanf("%i", & resultadoT1);

 			 		 gotoxy(2, 10 + i + 7);
			 		 printf("Resultado T2.....: ");
			 		 scanf("%i", & resultadoT2);

			 		 switch(codigo1) {
	 					  case 0: {
									 matriz[0][0] += resultadoT1;
 									 matriz[0][1] += resultadoT2;
 									 matriz[0][2] += (matriz[0][1] - matriz[0][2]);
							}
							case 1: {
 									 matriz[1][0] += resultadoT1;
 									 matriz[1][1] += resultadoT2;
									 matriz[1][2] += (matriz[1][1] - matriz[1][2]);
							}
							case 2: {
 									 matriz[2][0] += resultadoT1;
 									 matriz[2][1] += resultadoT2;
									 matriz[2][2] += (matriz[2][1] - matriz[2][2]);
							}
							case 3: {
 									 matriz[3][0] += resultadoT1;
 									 matriz[3][1] += resultadoT2;
									 matriz[3][2] += (matriz[3][1] - matriz[3][2]);
							}
 					 }
 					 
 					 switch(codigo2) {
						  case 0: {
									 matriz[0][0] += resultadoT2;
 									 matriz[0][1] += resultadoT1;
 									 matriz[0][2] += (matriz[0][1] - matriz[0][2]);
							}
							case 1: {
 									 matriz[1][0] += resultadoT2;
 									 matriz[1][1] += resultadoT1;
 									 matriz[1][2] += (matriz[1][1] - matriz[1][2]);
							}
							case 2: {
 									 matriz[2][0] += resultadoT2;
 									 matriz[2][1] += resultadoT1;
 									 matriz[2][2] += (matriz[2][1] - matriz[2][2]);
							}
							case 3: {
 									 matriz[3][0] += resultadoT2;
 									 matriz[3][1] += resultadoT1;
 									 matriz[3][2] += (matriz[3][1] - matriz[3][2]);
							}
 					 }
  		 }
  		 
			 gotoxy(2, 30);	 
			 printf("Tabela de Resultados");
			 for (l = 0; l < 4; l++) {
 		 			 gotoxy(4 + l * 2, 30);
			 		 for (c = 0; c < 4; c++) {
					 		 matriz[l][c];
		 		   }
 		 	 }

  		 getch();
			 
}
