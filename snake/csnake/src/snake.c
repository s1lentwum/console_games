#include <stdio.h>
#include <stdlib.h>

#include "..\inc\snake.h"

#define __snode(x, y, d) (snode_t) { x, y, d }

snode_t *snake;
uint32_t len, cap;
struct { uint32_t x, y; } apple;

/* gen_apple: генерит рандом координаты яблока */
void gen_apple(void) {
	apple.x = rand() % (__width - 1);
	apple.y = rand() % (__height - 1);

	if (map[apple.y][apple.x] == __snake)
		gen_apple();
}

/* plc_apple: размещает яблоко */
void plc_apple(void) {
	map[apple.y][apple.x] = __apple;
}

/* ini_snake: инициализация змеи */
void ini_snake(uint32_t x, uint32_t y, sdir_t dir) {
	cap = sizeof(snode_t) * 2;
	snake = (snode_t *) malloc(cap);

	if (!snake)
		fprintf(stderr, "<warn>: uninitialized!\n");
	snake[len++] = __snode(x, y, dir);
	gen_apple();
}

/* del_snake: освобождает змею. */
void del_snake(void) {
	free(snake);
	snake = NULL;
}

/* add_snake: удлиняет змею */
void add_snake(void) {
	if (len * sizeof(snode_t) >= cap) {
		cap *= 2;
		snake = (snode_t *) realloc(snake, cap);
	}

	if (!snake)
		fprintf(stderr, "<warn>: uninitialized!\n");
	snake[len] = snake[len - 1];
	switch (snake[len].dir) {
		case __left:
			snake[len].dir = __right;
			++snake[len].x;
			break;
		case __right:
			snake[len].dir = __left;
			--snake[len].x;
			break;
		case __up:
			snake[len].dir = __down;
			++snake[len].y;
			break;
		case __down:
			snake[len].dir = __up;
			--snake[len].y;
			break;
	}
	++len;
}

/* mov_snake: двигает змею относительно направления */
void mov_snake(void) {
	int i;

	for (i = 0; i < len; ++i) {
		map[snake[i].y][snake[i].x] = __space;
		switch (snake[i].dir) {
			case __left:
				snake[i].x = (!snake[i].x) ? 
					__width - 2 : snake[i].x - 1;
				break;
			case __right:
				snake[i].x = (snake[i].x == __width - 2) ? 
					0 : snake[i].x + 1;
				break;
			case __up:
				snake[i].y = (!snake[i].y) ? 
					__height - 1 : snake[i].y - 1;
				break;
			case __down:
				snake[i].y = (snake[i].y == __height - 1) ? 
					0 : snake[i].y + 1;
				break;
		}
	}
}

/* dmp_snake: */
void dmp_snake(void) {
	printf("x:%.2d   y:%.2d   dir:%.2d\n", snake->x, snake->y, snake->dir);
	printf("cap:%.4dB  len:%.4d\n", cap, len);
}

/* mov_dir: смещает направления */
void mov_dir(sdir_t dir) {
	int i;

	if (len > 1)
		switch (dir) {
			case __left:
				if (snake->dir == __right)
					dir = snake->dir;
				break;
			case __right:
				if (snake->dir == __left)
					dir = snake->dir;
				break;
			case __up:
				if (snake->dir == __down)
					dir = snake->dir;
				break;
			case __down:
				if (snake->dir == __up)
					dir = snake->dir;
				break;
		}

	for (i = len - 1; i >= 1; --i)
		snake[i].dir = snake[i - 1].dir;
	snake->dir = dir;
}