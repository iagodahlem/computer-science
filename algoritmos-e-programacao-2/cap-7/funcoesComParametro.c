#include <stdio.h>
#include <conio.h>
#include "draws.h"
#include "dates.h"

main() {

	int day, month, year, isDateValid;

	do {
		clrscr();
		gotoxy(10, 10);
		printf("Exemplo");
		drawBorders(5, 75, 8, 18);

		gotoxy(10, 12); printf("Dia: "); scanf("%i", &day);
		gotoxy(10, 13); printf("Mes: "); scanf("%i", &month);
		gotoxy(10, 14); printf("Ano: "); scanf("%i", &year);

		isDateValid = validDate(day, month, year);

		gotoxy(10, 16);
		if (isDateValid == 1) {
			printf("Data VALIDA! => %i/%i/%i", day, month, year);
		} else {
			printf("Data INVALIDA! => %i/%i/%i", day, month, year);
		}

		getch();
	} while (isDateValid! = 1);

}
