#include <stdio.h>
#include <stdlib.h>

#include "..\inc\snake.h"

unsigned vars, shape;

/* rnd_apos: генерує нову позицію яблука. */
void rnd_apos(void) {
	while (map & (1 << get_apos()))
		set_apos(rand() % 32);
}

/* mov_head: рухає голову. */
void mov_head(void) {
	switch (get_hdir()) {
		case UP:
			set_hpos(get_hpos() - 8);
			break;
		case DOWN:
			set_hpos(get_hpos() + 8);
			break;
		case LEFT:
			dec_hpos();
			break;
		case RIGHT:
			inc_hpos();
			break;
		default:
			break;
	}
}

/* mov_tail: рухає хвіст. */
void mov_tail(void) {
	switch (get_tdir()) {
		case UP:
			set_tpos(get_tpos() - 8);
			break;
		case DOWN:
			set_tpos(get_tpos() + 8);
			break;
		case LEFT:
			dec_tpos();
			break;
		case RIGHT:
			inc_tpos();
			break;
	}
}

/* mov_snake: рухає змію. */
char mov_snake(void) {
	mov_head();

	if ((map & (1 << get_hpos())))
		return 1;

	set_map(1, get_hpos());

	if (get_apos() == get_hpos()) {
		putchar('\a');
		rnd_apos();
		shape <<= 2;
		inc_len();
		set_tdir(get_hdir());
		return 0;
	}

	set_map(0, get_tpos());
	mov_tail();
	return 0;
}