#ifndef __logic_h
#define __logic_h

#include "field.h"

extern void open(int, int);
extern void mark(int, int);
extern void unmark(int, int);
extern int check(void);
extern void minesweeper(void);

#endif /* __logic_h */