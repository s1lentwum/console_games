#ifndef __sapi_h
#define __sapi_h

/* sapi.h - це заголовок, який містить загальну сукупність 
			макровизначень (невеличкий API) для гри. */

#define __get(var, mask, offset) 	((var >> offset) & mask)
#define __set(var, mask, offset, x) (var = (var & ~(mask << offset)) | ((x << offset)))
#define __clr(var, mask, offset) 	(var &= ~(mask << offset))
#define __inc(var, offset) 			(var += (1 << offset))
#define __dec(var, offset) 			(var -= (1 << offset))

#endif /* __sapi_h */