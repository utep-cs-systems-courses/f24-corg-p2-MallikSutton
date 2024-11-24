#include <msp430.h>
#include "led.h"

void led_init() {
    P1DIR |= LEDS;     // Set LED pins as output
    P1OUT &= ~LEDS;    // Turn off all LEDs initially
}
