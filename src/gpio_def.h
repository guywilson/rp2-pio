#include "pico/stdlib.h"

#ifndef __INCL_GPIO_DEF
#define __INCL_GPIO_DEF

#define I2C0_SDA_ALT_PIN			16
#define I2C0_SLK_ALT_PIN			17

#define I2C1_SDA_ALT_PIN			14
#define I2C1_SLK_ALT_PIN			15

#define DAC_CLK_PIN                 14
#define DAC_SYNC_PIN                15

#define QUAD_INPUT1_CHANA           18
#define QUAD_INPUT1_CHANB           19
#define QUAD_INPUT2_CHANA           20
#define QUAD_INPUT2_CHANB           21

#define SQUARE_WAVE_OUT_PIN         22

#define DEBUG_ENABLE_PIN            28

#define DAC_PIN_D0                   0      // LSB
#define DAC_PIN_D1                   1
#define DAC_PIN_D2                   2
#define DAC_PIN_D3                   3
#define DAC_PIN_D4                   4
#define DAC_PIN_D5                   5
#define DAC_PIN_D6                   6
#define DAC_PIN_D7                   7
#define DAC_PIN_D8                   8
#define DAC_PIN_D9                   9
#define DAC_PIN_D10                 10
#define DAC_PIN_D11                 11
#define DAC_PIN_D12                 12
#define DAC_PIN_D13                 13      // MSB

#define DAC_BUS_MASK               ((1 << DAC_PIN_D13)  |   \
                                    (1 << DAC_PIN_D12)  |   \
                                    (1 << DAC_PIN_D11)  |   \
                                    (1 << DAC_PIN_D10)  |   \
                                    (1 << DAC_PIN_D9)   |   \
                                    (1 << DAC_PIN_D8)   |   \
                                    (1 << DAC_PIN_D7)   |   \
                                    (1 << DAC_PIN_D6)   |   \
                                    (1 << DAC_PIN_D5)   |   \
                                    (1 << DAC_PIN_D4)   |   \
                                    (1 << DAC_PIN_D3)   |   \
                                    (1 << DAC_PIN_D2)   |   \
                                    (1 << DAC_PIN_D1)   |   \
                                    (1 << DAC_PIN_D0))

#define ONBAORD_LED_PIN             PICO_DEFAULT_LED_PIN

#endif
