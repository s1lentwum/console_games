#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\inc\logic.h"

int mark_cnt;

/* endscr: конец игры */
void endscr(void) {
	system("cls");
	shw_mines();
	shw_field();
	printf("\nyour score: %d/%d\n", check(), __count);
	system("pause");
	exit(1);
}

/* open: открывает клетку */
void open(int x, int y) {
	int i, j;

	if (cell[y][x].state)
		return;

	cell[y][x].state = 1;
	cell[y][x].changed = 0;

	if (cell[y][x].mined)
		endscr();

	if (!cell[y][x].amount) {
		for (i = -1; i <= 1; ++i) {
			if (y + i < 0 || y + i == __height)
				continue;

			for (j = -1; j <= 1; ++j) {
				if (x + j < 0 || x + j == __width)
					continue;
				open(x + j, y + i);
			}
		}
	}
}

/* mark: помечает клетку */
void mark(int x, int y) {
	if (cell[y][x].marked || cell[y][x].state)
		return;

	cell[y][x].marked = 1;
	cell[y][x].changed = 0;
	--mark_cnt;
}

/* check: подсчитывает очки */
int check(void) {
	int i, j;

	for (i = j = 0; i < __count; ++i)
		if (cell[mine[i].y][mine[i].x].marked &&
			cell[mine[i].y][mine[i].x].mined)
			++j;
	return j;
}

/* unmark: убирает метку с клетки */
void unmark(int x, int y) {
	if (!cell[y][x].marked || cell[y][x].state)
		return;
	cell[y][x].marked = 0;
	cell[y][x].changed = 0;
	++mark_cnt;
}

/* dmp_cell: отображение состояния клетки */
void dmp_cell(int x, int y) {
	printf("=== cell dump ===\n");
	printf("x: %d, y: %d\n", x, y);
	printf("state: %s\n", (cell[y][x].state) ? "opened" : "closed");
	printf("mined: %s\n", (cell[y][x].mined) ? "yes" : "no");
	printf("marked: %s\n", (cell[y][x].marked) ? "yes" : "no");
	printf("showed: %s\n", (cell[y][x].changed) ? "yes" : "no");
	printf("amount: %d\n\n", cell[y][x].amount);
}


/* minesweeper: цикл игры */
void minesweeper(void) {
	char x, y, c;
	mark_cnt = __count;

	srand(time(NULL));
	ini_field();
	ini_cells();

	while (mark_cnt) {
		printf("marks left: %d\n\n", mark_cnt);
		shw_field();
		printf("\n>> ");

		scanf("%c%c%d", &c, &y, &x);
		fflush(stdin);

		switch (c) {
			case 'q':
				open(x - 1, y - 'a');
				break;
			case 'w':
				mark(x - 1, y - 'a');
				break;
			case 'e':
				unmark(x - 1, y - 'a');
				break;
		}
		chg_field();
		system("cls");
		dmp_cell(x - 1, y - 'a');
	}
	endscr();
}