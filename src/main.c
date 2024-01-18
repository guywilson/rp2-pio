#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"
#include "hardware/rtc.h"

#include "pio_rp2040.h"
#include "gpio_def.h"

static void setupLEDPin(void) {
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, false);
}

static void turnOn(void) {
    gpio_put(PICO_DEFAULT_LED_PIN, 1);
}

static void turnOff(void) {
    gpio_put(PICO_DEFAULT_LED_PIN, 0);
}

static void toggleLED(void) {
	static unsigned char state = 0;
	
	if (!state) {
		turnOn();
		state = 1;
	}
	else {
		turnOff();
		state = 0;
	}
}

int main(void) {
    setupLEDPin();

    pioInit();

    while (1) {
        sleep_us(5000);
    }

	return -1;
}
