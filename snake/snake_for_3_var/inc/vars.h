#ifndef __vars_h
#define __vars_h

#define	  NOP  0 /* пуста інструкція. Використовується блоках if/else */
#define  HPOS  0 /* зміщення до позиції голови змії */
#define  TPOS  5 /* зміщення до позиції хвоста змії */
#define  APOS 10 /* зміщення до позиції яблука */
#define   CNT 15 /* зміщення до лічильника */
#define   LEN 25 /* довжина змії */
#define   RES 20 /* резервуар даних */
#define  CDIR 30 /* зміщення до поточного напрямку змії */

#define PMASK 31 /* position  mask */
#define DMASK  3 /* direction mask */  

/*	vars:	 	 cdir    res	len    cnt   apos   tpos   hpos
				 0 0|000 00|00 000|0 1010|0000 0|00 010|0 1010| */
extern unsigned vars;

/* API */
#define get_hpos() __get(vars, PMASK, HPOS)
#define get_tpos() __get(vars, PMASK, TPOS)
#define get_apos() __get(vars, PMASK, APOS)
#define get_len()  __get(vars, PMASK,  LEN)
#define get_cnt()  __get(vars, PMASK,  CNT)
#define get_res()  __get(vars, PMASK,  RES)
#define get_cdir() __get(vars, DMASK, CDIR)

#define clr_hpos() __clr(vars, PMASK, HPOS)
#define clr_tpos() __clr(vars, PMASK, TPOS)
#define clr_apos() __clr(vars, PMASK, APOS)
#define clr_len()  __clr(vars, PMASK,  LEN)
#define clr_cnt()  __clr(vars, PMASK,  CNT)
#define clr_res()  __clr(vars, PMASK,  RES)
#define clr_cdir() __clr(vars, DMASK, CDIR)

#define set_hpos(x) (((x) > PMASK) ? NOP : __set(vars, PMASK, HPOS, x))
#define set_tpos(x) (((x) > PMASK) ? NOP : __set(vars, PMASK, TPOS, x))
#define set_apos(x) (((x) > PMASK) ? NOP : __set(vars, PMASK, APOS, x))
#define set_cnt(x)  (((x) > PMASK) ? NOP : __set(vars, PMASK,  CNT, x))
#define set_res(x)  (((x) > PMASK) ? NOP : __set(vars, PMASK,  RES, x))
#define set_cdir(x) (((x) > DMASK) ? NOP : __set(vars, DMASK, CDIR, x))

#define inc_hpos() ((get_hpos() < PMASK) ? __inc(vars, HPOS) : clr_hpos())
#define inc_tpos() ((get_tpos() < PMASK) ? __inc(vars, TPOS) : clr_tpos())
#define inc_cnt() ((get_cnt() < PMASK) ? __inc(vars, CNT) : clr_cnt())
#define inc_len() ((get_len() < PMASK) ? __inc(vars, LEN) : clr_len())

#define dec_hpos() ((get_hpos()) ? __dec(vars, HPOS) : NOP)
#define dec_tpos() ((get_tpos()) ? __dec(vars, TPOS) : NOP)
#define dec_cnt() ((get_cnt()) ? __dec(vars, CNT) : NOP)
#define dec_len() ((get_len()) ? __dec(vars, LEN) : NOP)

#endif /* __vars_h */