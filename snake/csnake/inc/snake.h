#ifndef __snake_h
#define __snake_h

#include "map.h"
#include "logic.h"

typedef enum {
	__left = 1, __right, 
	__up, __down
} sdir_t;

typedef struct {
	uint32_t x, y, dir;
} snode_t;

extern snode_t *snake;

extern void gen_apple(void);
extern void plc_apple(void);
extern void ini_snake(uint32_t, uint32_t, sdir_t);
extern void del_snake(void);
extern void add_snake(void);
extern void mov_snake(void);
extern void dmp_snake(void);
extern void mov_dir(sdir_t);

#endif /* __snake_h */