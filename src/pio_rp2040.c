#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "pio_rp2040.h"
#include "gpio_def.h"

#include "wave.pio.h"

static int          dacSM;

void pioInit() {
    uint            dacOffset = 0;
    uint            p = DAC_PIN_D0;

    // gpio_set_function(DAC_SYNC_PIN, GPIO_FUNC_SIO);
    // gpio_set_dir(DAC_SYNC_PIN, false);
    // gpio_pull_down(DAC_SYNC_PIN);

    pio_add_program_at_offset(pio0, &wave_program, dacOffset);

    dacSM = pio_claim_unused_sm(pio0, true);

    pio_sm_config dacConfig = wave_program_get_default_config(dacOffset);

    sm_config_set_set_pins(&dacConfig, DAC_PIN_D0, 5);

    pio_sm_set_consecutive_pindirs(pio0, dacSM, DAC_PIN_D0, 5, true);

    while (p <= DAC_PIN_D13) {
        pio_gpio_init(pio0, p++);
    }

    pio_sm_init(pio0, dacSM, dacOffset, &dacConfig);
    pio_sm_set_enabled(pio0, dacSM, true);
}

void pioEnable(void) {
    pio_sm_set_enabled(pio0, dacSM, true);
}

void pioDisable(void) {
    pio_sm_set_enabled(pio0, dacSM, false);
}

int pioGetSM(void) {
    return dacSM;
}