#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "..\inc\snake.h"

/* get_dir: получает направление */
int get_dir(void) {
	switch (getch()) {
		case 'w':
			return __up;
		case 'a':
			return __left;
		case 's':
			return __down;
		case 'd':
			return __right;
	}
	return snake->dir;
}

/* chk_collision: проверка коллизии */
int chk_collision(void) {
	int i;
	extern uint32_t len;
	extern struct { uint32_t x, y; } apple;

	if (snake->x == apple.x && 
		snake->y == apple.y) {
		add_snake();
		gen_apple();
	}
	
	for (i = 1; i < len; ++i)
		if (snake->x == snake[i].x && 
			snake->y == snake[i].y)
			return 0;
	return 1;
}

/* run: запуск игры */
int run(void) {
	srand(time(NULL));
	system("cls");
	system("mode con cols=50 lines=18");

	ini_map();
	ini_snake(__width / 2, __height / 2, __left);

	do {
		plc_snake();
		plc_apple();
		shw_map();
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), (COORD){0, 0});
		Sleep(60);
		mov_dir((kbhit()) ? get_dir() : snake->dir);
		mov_snake();
	} while (chk_collision());

	system("cls");
	puts("\t\tGG!");
	system("pause");
	return 0;
}