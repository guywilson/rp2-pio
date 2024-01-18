#include <stdint.h>

#ifndef __INCL_PIO_RP2040
#define __INCL_PIO_RP2040

void        pioInit(void);
void        pioEnable(void);
void        pioDisable(void);
int         pioGetSM(void);

#endif
