#ifndef __snake_h
#define __snake_h

#define      UP  0 /* ... */
#define    DOWN  1 /* ... */
#define    LEFT  2 /* ... */
#define   RIGHT  3 /* ... */

#include "..\inc\sapi.h"
#include "..\inc\vars.h"
#include "..\inc\map.h"

/*
	UP:    hpos - 8
	DOWN:  hpos + 8
	LEFT:  hpos - 1
	RIGHT: hpos + 1

	map:
		........
		...$$...
		........

	shape:
		00 00 00 00 00 00 00 00
		00 00 00 00 00 11 10 00
*/

extern unsigned shape;

#define get_hdir() __get(shape, DMASK, (get_len() * 2))
#define get_tdir() __get(shape, DMASK, 0)

#define set_hdir(x) __set(shape, DMASK, (get_len() * 2), x)
#define set_tdir(x) __set(shape, DMASK, 0, x)

extern void rnd_apos(void);
extern void mov_head(void);
extern void mov_tail(void);
extern char mov_snake(void);

#endif /* __snake_h */