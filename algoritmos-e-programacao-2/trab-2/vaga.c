#include <stdio.h>
#include <conio.h>

struct modelo {
	int codigo, idade;
	char nome[255];
	char genero;
	float nota;
} candidato;

FILE *arq;
int teste;

void cadastrar();
void editar();
void listar();
void estatisticas();

main() {

	char op;

	do {
		clrscr();
		gotoxy(5,3); printf("========== Menu de Opcoes ===========");
		gotoxy(5,6); printf("1 - Cadastro de dados dos candidatos");
		gotoxy(5,8); printf("2 - Edicao de dados dos candidatos");
		gotoxy(5,10); printf("3 - Relatorio");
		gotoxy(5,12); printf("4 - Dados Estatisticos");
		gotoxy(5,14); printf("5 - Sair");
		gotoxy(5,17); printf("Digite a opcao desejada:");
		gotoxy(30,17); op = getche();

		switch (op) {
			case '1': cadastrar(); break;
			case '2': editar(); break;
			case '3': listar(); break;
			case '4': estatisticas(); break;
			case '5':
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

	} while (op != '5');

}

void cadastrar() {
	char resp;
	arq = fopen("candidatos.txt", "ab");

	if (arq) {
		do {
			clrscr();
			gotoxy(5,3); printf("Cadastro de Candidato");
			gotoxy(5,6); printf("Codigo.........:");
			gotoxy(5,8); printf("Nome...........:");
			gotoxy(5,10); printf("Idade..........:");
			gotoxy(5,12); printf("Genero.........:");
			gotoxy(5,14); printf("Nota...........:");

			gotoxy(23,6); scanf("%i", &candidato.codigo);
			gotoxy(23,8); scanf("%s", &candidato.nome);	
			gotoxy(23,10); scanf("%i", &candidato.idade);
			gotoxy(23,12); scanf("%s", &candidato.genero);
			gotoxy(23,14); scanf("%f", &candidato.nota);

			teste = fwrite(&candidato, sizeof(struct modelo), 1, arq);
			if (teste) {
				gotoxy(5,17); printf("Arquivo gravado com sucesso.");
			}

			gotoxy(5,20); printf("Continuar gravando? (S/N)");
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

void editar() {
	int codigoPesquisa;
	int achei, apontador;
	char resp='S';

	arq = fopen("candidatos.txt", "rb+");

	if (arq) {
		while (resp == 'S' || resp == 's') {
			achei = 0;
			clrscr();
			gotoxy(5,3); printf("Digite o Codigo do candidato a ser editado:");
			gotoxy(49,3); scanf("%i", &codigoPesquisa);

			rewind(arq);
			apontador = 0;
			while (!feof(arq) && achei == 0) {
				teste = fread(&candidato, sizeof(struct modelo), 1, arq);
				apontador++;

				if (teste) {
					if (candidato.codigo == codigoPesquisa) {
						gotoxy(5,5); printf("=== Dados atuais ===");
						gotoxy(5,7); printf("Nome...........: %s", candidato.nome);
						gotoxy(5,8); printf("Idade..........: %i", candidato.idade);
						gotoxy(5,9); printf("Genero.........: %c", candidato.genero);
						gotoxy(5,10); printf("Nota...........: %.2f", candidato.nota);

						gotoxy(5,13); printf("=== Novos dados ===");
						gotoxy(5,15); printf("Nome...........:");
						gotoxy(5,16); printf("Idade..........:");
						gotoxy(5,17); printf("Genero.........:");
						gotoxy(5,18); printf("Nota...........:");
						achei = 1;

						gotoxy(22,15); scanf("%s", &candidato.nome);
						gotoxy(22,16); scanf("%i", &candidato.idade);	
						gotoxy(22,17); scanf("%s", &candidato.genero);
						gotoxy(22,18); scanf("%f", &candidato.nota);

						gotoxy(5,20); printf("Confirma a edicao? S/N");
						gotoxy(28,20); resp=getche();

						if (resp == 'S' || resp == 's') {
							apontador--;
							fseek(arq, apontador * sizeof(struct modelo), SEEK_SET);
							teste=fwrite(&candidato, sizeof(struct modelo), 1, arq);

							if (teste) {
								gotoxy(5,22); printf("Registro editado com sucesso!");
							}
						}
					}
				}
			}

			if (achei == 0) {
				gotoxy(5, 12); printf("Registro nao encontrado!");
			}
			gotoxy(5,24); printf("Deseja continuar? S/N");
			gotoxy(27, 24); resp=getche();
		}
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
	int totalCandidatos = 0;

	arq = fopen("candidatos.txt", "rb");

	if (arq) {
		clrscr();
		gotoxy(5,3);
		printf("Codigo         Nome");

		rewind(arq);
		while (!feof(arq)) {
			teste = fread(&candidato, sizeof(struct modelo), 1, arq);
			if (teste) {
				totalCandidatos++;
			}
		}

		rewind(arq);
		while (!feof(arq)) {

			teste = fread(&candidato, sizeof(struct modelo), 1, arq);

			if (teste) {
				gotoxy(7,linha); printf("%i", candidato.codigo);
				gotoxy(17,linha); printf("%s", candidato.nome);

				if (linha < 16) {
					linha++;
				} else {
					gotoxy(5,18); printf("Tecle ENTER para rodar os dados...");
					getch();
					gotoxy(5,6); delline();
					gotoxy(5,16); insline();
				}
				linha++;
			}
		}

		gotoxy(5,20); printf("Total de Candidatos: %i", totalCandidatos);
		gotoxy(5,22); printf("Relatorio finalizado. Tecle ENTER para retornar ao menu...");
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
	arq = fopen("candidatos.txt", "rb");

	int totalCandidatos = 0;
	int candidatosEntre18e20 = 0;
	int masculino = 0;
	int feminino = 0;
	int candidatosAcimaMediaGeral = 0;

	float percentualEntre18e20;
	float percentualMasculino;
	float percentualFeminino;
	float notaGeral = 0;
	float mediaGeral;

	if (arq) {
		rewind(arq);
		while (!feof(arq)) {
			teste = fread(&candidato, sizeof(struct modelo), 1, arq);

			if (teste) {
				totalCandidatos++;
				notaGeral += candidato.nota;

				if (candidato.idade >= 18 && candidato.idade <= 20) {
					candidatosEntre18e20++;
				}

				if (candidato.genero == 'M' || candidato.genero == 'm') {
					masculino++;
				} else if (candidato.genero == 'F' || candidato.genero == 'f') {
					feminino++;
				}
			}
	  	}

	  	percentualEntre18e20 = (candidatosEntre18e20*100)/(totalCandidatos);
		percentualMasculino = (masculino*100)/(totalCandidatos);
		percentualFeminino = (feminino*100)/(totalCandidatos);
		mediaGeral = notaGeral / totalCandidatos;

	  	rewind(arq);
		while (!feof(arq)) {
			teste = fread(&candidato, sizeof(struct modelo), 1, arq);

			if (teste) {
				if (candidato.nota > mediaGeral) {
					candidatosAcimaMediaGeral++;
				}
			}
	  	}

		clrscr();
		gotoxy(5,3); printf("Dados Estatisticos");
		gotoxy(5,6); printf("Total de Candidatos = %i", totalCandidatos);
		gotoxy(5,8); printf("Percentual de Candidatos entre 18 e 20 anos = %.2f%%", percentualEntre18e20);
		gotoxy(5,10); printf("Percentual de Homens = %.2f%%", percentualMasculino);
		gotoxy(5,12); printf("Percentual de Mulheres = %.2f%%", percentualFeminino);
		gotoxy(5,14); printf("Media Geral = %.2f", mediaGeral);
		gotoxy(5,16); printf("Total de Candidatos acima da Media Geral = %i", candidatosAcimaMediaGeral);

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
