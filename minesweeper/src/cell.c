#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\inc\cell.h"

mine_t mine[__count];
cell_t cell[__height][__width];

/* ini_cells: инициализирует клетки */
void ini_cells(void) {
	int i, j, k;

	for (i = 0; i < __count; ++i) {
		mine[i] = (mine_t){ rand() % __width, 
			rand() % __height };

		if (cell[mine[i].y][mine[i].x].mined) {
			--i;
			continue;
		}

		cell[mine[i].y][mine[i].x].mined = 1;

		for (j = -1; j <= 1; ++j) {
			if (mine[i].y + j < 0 || mine[i].y + j == __height)
				continue;
			for (k = -1; k <= 1; ++k) {
				if (mine[i].x + k < 0 || mine[i].x + k == __width)
					continue;
				++cell[mine[i].y + j][mine[i].x + k].amount;
			}
		}
	}
}