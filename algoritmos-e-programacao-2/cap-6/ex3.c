#include <stdio.h>
#include <conio.h>

struct modelo {
			 char genero;
			 int idade;
			 float peso, altura;
} reg;

FILE *arq;
int teste;

void inserir();
void listar();
void estatisticas();

main() {
			 char op;
			 
			 do {
			   clrscr();
			   gotoxy(5,3); printf("Cadastro de Modelos");
 			   gotoxy(5,6); printf("1 - Inserir");
 			   gotoxy(5,8); printf("2 - Listar");
			   gotoxy(5,10); printf("3 - Dados Estatisticos");
 			   gotoxy(5,12); printf("4 - Sair");
         gotoxy(5,15); printf("Digite a opcao desejada:");
		     gotoxy(30,15); op=getche();
		     
		     switch (op) {
				 				case '1': inserir(); break;
						    case '2': listar(); break;
						    case '3': estatisticas(); break;
					      case '4': 
										 clrscr();
										 gotoxy(5,5);
										 printf("Tecle ENTER para encerrar...");
										 getch();
										 break;
								default: 
										 clrscr();
										 gotoxy(5,5);
										 printf("Opcao invalida...");
										 getch();										 
										 break;
				 }
		     
	 		 } while (op != '4');
			 
}

void inserir() {
		 char resp;
		 arq = fopen("modelos.txt", "ab");
		 if (arq) {
		 		do {
						 		clrscr();
								gotoxy(5,3); printf("Cadastro de Modelo");
								gotoxy(5,6); printf("Genero (F/M)...:");
								gotoxy(5,8); printf("Idade..........:");
          	 		gotoxy(5,10); printf("Peso...........:");				 				 		 		
        		 		gotoxy(5,12); printf("Altura.........:");
				        gotoxy(23,6); scanf("%s", &reg.genero);	
        				gotoxy(23,8); scanf("%i", &reg.idade);	
				        gotoxy(23,10); scanf("%f", &reg.peso);	
        				gotoxy(23,12); scanf("%f", &reg.altura);

       	  			teste = fwrite(&reg, sizeof(struct modelo), 1, arq);
        				if (teste) {
    					      gotoxy(5,15);
 					          printf("Arquivo gravado com sucesso.");
								}
								gotoxy(5,18);
								printf("Continuar gravando? (S/N)");
								resp = getche();
					} while (resp == 's' || resp == 'S');
					fclose(arq);
 		 } else {
		 	 clrscr();
		 	 gotoxy(5,5);
		 	 printf("Arquivo inexistente...");
		 	 getch();
		 }
}

void listar() {
		 int linha = 6;
		 
		 arq = fopen("modelos.txt", "rb");
		 
		 if (arq) {
		 		clrscr();
		 		gotoxy(5,3);
		 		printf("Genero     Idade      Peso     Altura");
		 		rewind(arq);
		 		while (!feof(arq)) {
    	  			teste = fread(&reg, sizeof(struct modelo), 1, arq);
							if (teste) {
								 gotoxy(7,linha); printf("%c", reg.genero);
								 gotoxy(17,linha); printf("%i", reg.idade);
								 gotoxy(27,linha); printf("%.2f", reg.peso);
								 gotoxy(37,linha); printf("%.2f", reg.altura);
								 if (linha < 16) { 
								 		linha++; 
								 } else {
								 			gotoxy(5,18);
								 			printf("Tecle ENTER para rodar os dados...");
								 			getch();
								 			gotoxy(5,6); delline();
  							 			gotoxy(5,16); insline();
								 }
								 linha++;
						  }		
			  }
			  gotoxy(5,22);
			  printf("Relatorio finalizado. Tecle ENTER para retornar ao menu...");
			  getch();
			  fclose(arq);
 		 } else {
 		 	 clrscr();
		 	 gotoxy(5,5);
		 	 printf("Arquivo inexistente...");
		 	 getch();
     }
}

void estatisticas() {
		 arq = fopen("modelos.txt", "rb");
		 int maior = 0;
		 int feminino = 0;
		 int masculino = 0;	
		 int count = 0;
		 float somaPeso = 0;
		 float mediaPeso = 0;
		 float percentualFeminino;
     float percentualMasculino;
		 if (arq) {
		 		rewind(arq);
		 		while (!feof(arq)) {
							teste = fread(&reg, sizeof(struct modelo), 1, arq);
							if (teste) {
								 if (reg.idade > maior) {
								 		maior = reg.idade;
						 		 }
						 		 
						 		 if (reg.genero == 'F' || reg.genero == 'f') {
								 		feminino++;
								 		somaPeso += reg.peso;
						 		 } else {
								 	 if(reg.genero == 'M' || reg.genero == 'm')
								 	    masculino++;
				 	 			 }
				 	 			 
				 	 			 if (reg.genero == 'M' || reg.genero == 'm' && reg.altura > 1.85) {
								 		count++;
				 			   }
						  }
			  }
			  percentualFeminino = (feminino*100)/(feminino+masculino);
			  percentualMasculino = (masculino*100)/(feminino+masculino);
			  mediaPeso = somaPeso/feminino;
			  
			  clrscr();
			  gotoxy(5,3); printf("Dados estatisticos");
			  gotoxy(5,6); printf("Maior idade = %i", maior);
			  gotoxy(5,8); printf("Masculino = %.2f%% - Feminino = %.2f%%", percentualMasculino, percentualFeminino);
 			  gotoxy(5,10); printf("Quantidade homens com mais de 1.85 =  %i", count);
 			  gotoxy(5,12); printf("Peso medio = %.2f", mediaPeso);

				gotoxy(5,22);
			  printf("Relatorio finalizado. Tecle ENTER para retornar ao menu...");
			  getch();
			  fclose(arq);			  
 		 } else {
 		 	 clrscr();
		 	 gotoxy(5,5);
		 	 printf("Arquivo inexistente...");
		 	 getch();
     }
}
