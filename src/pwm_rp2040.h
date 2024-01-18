#include <stdint.h>
#include <pico/stdlib.h>

#ifndef __INCL_PWM_RP2040
#define __INCL_PWM_RP2040

uint    pwmClockInit(uint gpio);
int     pwmClockSetFrequency(uint slice, float frequency);
void    pwmClockStart(uint slice);
void    pwmClockStop(uint slice);

#endif
