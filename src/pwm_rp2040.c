#include <stdint.h>
#include <pico/stdlib.h>

#include "hardware/pwm.h"

#include "gpio_def.h"
#include "pwm_rp2040.h"

//#define PWM_PHASE_CORRECT

#define SYSTEM_CLOCK_FREQUENCY                  125000000

#define MAX_PWM_FREQUENCY                       62500000.0f
#define MIN_PWM_FREQUENCY                       7.5f

static int calculateParameters(pwm_config * pPWMConfig, float frequency) {
    // float           actualFrequency;

    if (frequency > 2000.0) {
        pPWMConfig->div = 1;
    }
    else if (frequency >= 200.0) {
        pPWMConfig->div = 10;
    }
    else if (frequency >= 20.0) {
        pPWMConfig->div = 100;
    }
    else if (frequency >= 10.0) {
        pPWMConfig->div = 200;
    }
    else if (frequency >= ((float)MIN_PWM_FREQUENCY * (float)SYSTEM_CLOCK_FREQUENCY / (float)SYSTEM_CLOCK_FREQUENCY)) {
        pPWMConfig->div = 255;
    }
    else {
        return -1;
    }

    /*
    ** PWM_Freq = SYSTEM_CLOCK_FREQUENCY / ((TOP + 1) * (DIV + (DIV_FRAC/16)))
    */
    pPWMConfig->top = (SYSTEM_CLOCK_FREQUENCY / frequency / pPWMConfig->div) - 1;
        
    // actualFrequency = (SYSTEM_CLOCK_FREQUENCY) / ((pPWMConfig->top + 1) * pPWMConfig->div);

#ifdef PWM_PHASE_CORRECT
    pPWMConfig->top = pPWMConfig->top >> 1;
#endif

    return 0; 
}

uint pwmClockInit(uint gpio) {
    uint            slice;

    gpio_set_function(gpio, GPIO_FUNC_PWM);

    slice = pwm_gpio_to_slice_num(gpio);

    return slice;
}

int pwmClockSetFrequency(uint slice, float frequency) {
    pwm_config      config = pwm_get_default_config();

    calculateParameters(&config, frequency);

#ifdef PWM_PHASE_CORRECT
    pwm_set_phase_correct(slice, true);
#endif

    pwm_config_set_clkdiv_int(&config, config.div);
    pwm_config_set_wrap(&config, config.top);

    pwm_init(slice, &config, false);

    pwm_set_chan_level(slice, PWM_CHAN_B, config.top >> 1);    
    pwm_set_chan_level(slice, PWM_CHAN_A, config.top >> 1);    

    return 0;
}

void pwmClockStart(uint slice) {
    pwm_set_enabled(slice, true);
}

void pwmClockStop(uint slice) {
    pwm_set_enabled(slice, false);
}
