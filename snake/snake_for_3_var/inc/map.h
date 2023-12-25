#ifndef __map_h
#define __map_h

#define set_map(x, offset) __set(map, 1, offset, x)
#define clr_map(x, offset) __clr(map, 1, offset)

extern unsigned map;

extern void shw_map(void);

#endif /* __map_h */