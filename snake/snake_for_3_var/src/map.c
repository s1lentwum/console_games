#include <stdio.h>
#include <stdlib.h>

#include "..\inc\snake.h"

unsigned map;

/* shw_map: відображає мапу. */
void shw_map(void) {
	system("cls");
	clr_cnt();

	do {
		if (!(get_cnt() % 8))
			putchar('\n');
		putchar(((get_cnt() == get_apos()) ? '@' : 
			((map & (1 << get_cnt())) ? '$' : 
				'.')));
		inc_cnt();
	} while (get_cnt());

	putchar('\n');
}