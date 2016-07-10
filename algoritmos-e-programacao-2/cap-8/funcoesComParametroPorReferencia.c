#include <stdio.h>
#include "conio.c"

int isVowel(char letter);

main() {

	char letterToTest;
	int isLetterVowel;

	clrscr();
	gotoxy(10, 10); printf("Letra: "); scanf("%c", &letterToTest);
	isLetterVowel = isVowel(letterToTest);

	gotoxy(10,14);

	if (isLetterVowel == 1) {
		printf("A letra eh vogal!");
	} else {
		if (isLetterVowel == 0) {
			printf("A letra eh consoante!");
		} else {
			printf("Nao eh letra!");
		}
	}

	getch();

}

int isVowel(char letter) {
	if ((letter >= 65 && letter <= 90) ||(letter >= 97 && letter <= 122)) {
		if (letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' || letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || letter == 'U' || letter == 'u') {
			return 1;
		} else {
			return 0;
		}
	}
}
