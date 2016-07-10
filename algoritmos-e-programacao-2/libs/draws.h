/*
 * DRAW'S LIB
 *
 * By @iagodahlem under MIT license
 */


// Constants Definition
// -------------------------------------

// ASC characters
const int VERTICAL_LINE = 205;
const int HORIZONTAL_LINE = 186;
const int BORDER_TOP_LEFT = 201;
const int BORDER_TOP_RIGHT = 187;
const int BORDER_BOTTOM_LEFT = 200;
const int BORDER_BOTTOM_RIGHT = 188;


// Functions Definition
// -------------------------------------

void drawBorders(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal);

// Private functions
void _drawVerticalLines(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal);
void _drawHorizontalLines(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal);


// Functions
// -------------------------------------

void drawBorders(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal) {
	gotoxy(colunaInicial, linhaInicial); printf("%c", BORDER_TOP_LEFT);
	gotoxy(colunaInicial, linhaFinal); printf("%c", BORDER_BOTTOM_LEFT);
	gotoxy(colunaFinal, linhaInicial); printf("%c", BORDER_TOP_RIGHT);
	gotoxy(colunaFinal, linhaFinal); printf("%c", BORDER_BOTTOM_RIGHT);
	_drawVerticalLines(colunaInicial, colunaFinal, linhaInicial, linhaFinal);
	_drawHorizontalLines(colunaInicial, colunaFinal, linhaInicial, linhaFinal);
}

void _drawVerticalLines(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal) {
	int i;
	for (i = colunaInicial + 1; i < colunaFinal; i++) {
		gotoxy(i, linhaInicial); printf("%c", VERTICAL_LINE);
		gotoxy(i, linhaFinal); printf("%c", VERTICAL_LINE);
	}
}

void _drawHorizontalLines(int colunaInicial, int colunaFinal, int linhaInicial, int linhaFinal) {
	int j;
	for (j = linhaInicial + 1; j < linhaFinal; j++) {
		gotoxy(colunaInicial, j); printf("%c", HORIZONTAL_LINE);
		gotoxy(colunaFinal, j); printf("%c", HORIZONTAL_LINE);
	}
}


// Colors anotation
// -------------------------------------

// COLORS
//
// 0   BLACK
// 1   BLUE
// 2   GREEN
// 3   CYAN
// 4   RED
// 5   MAGENTA
// 6   BROWN
// 7   LIGHTGRAY
// 8   DARKGRAY
// 9   LIGHTBLUE
// 10  LIGHTGREEN
// 11  LIGHTCYAN
// 12  LIGHTRED
// 13  LIGHTMAGENTA
// 14  YELLOW
// 15  WHITE
