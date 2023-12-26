#include <stdio.h>
#include <stdint.h>

#include "..\inc\field.h"

#define __mine 207
#define __mark 63
#define __cell 254

uint8_t field[__height][__width];

/* ini_field: инициализирует поле */
void ini_field(void) {
	int i, j;

	for (i = 0; i < __height; ++i)
		for (j = 0; j < __width; ++j) {
			cell[i][j].changed = 1;
			field[i][j] = __cell;
		}
}

/* chg_field: изменяет поле */
void chg_field(void) {
	int i, j;

	for (i = 0; i < __height; ++i)
		for (j = 0; j < __width; ++j) {
			if (cell[i][j].changed)
				continue;

			if (cell[i][j].state)
				field[i][j] = (!cell[i][j].amount) ? '.' :
					'0' + cell[i][j].amount;
			else if (cell[i][j].marked)
				field[i][j] = __mark;
			else 
				field[i][j] = __cell;
			cell[i][j].changed = 1;
		}
}

/* shw_field: отображает поле */
void shw_field(void) {
	int i, j;

	putchar(' ');
	for (i = 1; i <= __height; ++i)
		printf(" %d", i);
	putchar('\n');

	for (i = 0; i < __height; ++i) {
		putchar('A' + i);
		for (j = 0; j < __width; ++j)
			printf(" %c", field[i][j]);
		putchar('\n');
	}
}

/* shw_mines: "отображает" мины. */
void shw_mines(void) {
	int i;

	for (i = 0; i < __count; ++i)
		field[mine[i].y][mine[i].x] = __mine;
}