#ifndef __map_h
#define __map_h

#include <stdint.h>

#define __height 15
#define __width  50

#define __snake '%'
#define __space '.'
#define __apple '$'

extern uint8_t map[__height][__width];

extern void ini_map(void);
extern void shw_map(void);
extern void plc_snake(void);

#endif /* __map_h */