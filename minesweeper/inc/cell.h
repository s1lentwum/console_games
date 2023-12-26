#ifndef __cell_h
#define __cell_h

#define __height 9
#define __width  9
#define __count  10

/* mine_t: структура мины */
typedef struct {
	int x, y;
} mine_t;

/* cell_t: структура клетки */
typedef struct {
	unsigned state   : 1;
	unsigned mined   : 1;
	unsigned marked  : 1;
	unsigned changed : 1;
	unsigned amount  : 4;
} cell_t;

extern mine_t mine[__count];
extern cell_t cell[__height][__width];

extern void ini_cells(void);

#endif /* __cell_h */