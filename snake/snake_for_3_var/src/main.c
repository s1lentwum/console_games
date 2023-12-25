#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "..\inc\snake.h"

void ini_game(void);
void mem_dmp(void);

int main(void) {
	srand(time(NULL));

restart:
	ini_game();
mainloop:
	shw_map();
	mem_dmp();

	switch (getch()) {
		case 'w':
			set_hdir(UP);
			break;
		case 'a':
			set_hdir(LEFT);
			break;
		case 's':
			set_hdir(DOWN);
			break;
		case 'd':
			set_hdir(RIGHT);
			break;
		case 'm': default:
			goto menu;
	}

	if (mov_snake() || get_len() == 0x10)
		goto menu;
	shape >>= 2;
	goto mainloop;
	

menu:
	system("cls");
	printf("\nYour score: %d/16\n", get_len());
	printf("Press \'q\'/\'r\' to quit/restart ... ");

	if (getch() == 'r') 
		goto restart;
	return EXIT_SUCCESS;
}

/* ini_game: ініціалізує гру. */
void ini_game(void) {
	vars = map = 0;
	set_hpos(20);
	set_tpos(20);
	set_apos(10);
	set_map(1, get_hpos());
}

/* mem_dmp: відображає пам'ять. */
void mem_dmp(void) {
	printf("\n-- memory dump --");
	printf("\nhpos: %.2x\n", get_hpos());
	printf("tpos: %.2x\n", get_tpos());
	printf("apos: %.2x\n", get_apos());
	printf(" cnt: %.2x\n", get_cnt());
	printf(" len: %.2x\n", get_len());
	printf(" res: %.2x\n", get_res());
	printf("hdir: %.2x\n", get_hdir());
	printf("tdir: %.2x\n", get_tdir());
}