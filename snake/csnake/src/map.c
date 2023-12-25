#include <stdio.h>

#include "..\inc\snake.h"

#define __snake '%'
#define __space '.'
#define __apple '$'

uint8_t map[__height][__width];

/* ini_map: инициализация карты */
void ini_map(void) {
	int i, j;

	for (i = 0; i < __height; ++i) {
		for (j = 0; j < __width - 1; ++j)
			map[i][j] = __space;
		map[i][__width - 1] = '\0';
	}
}

/* shw_map: отображение карты */
void shw_map(void) {
	int i;

	dmp_snake();
	for (i = 0; i < __height; ++i)
		printf("%s\n", map[i]);
}

/* plc_snake: отображение змеи */
void plc_snake(void) {
	int i;
	extern uint32_t len;

	for (i = 0; i < len; ++i)
		map[snake[i].y][snake[i].x] = __snake;
}