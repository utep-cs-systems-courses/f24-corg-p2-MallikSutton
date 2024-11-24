//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
/**
 * Main loop for a MSP430 program that blinks the LEDs in a silly sequence.
 *
 * Initializes the MSP430, then enters LPM3.  The watchdog timer is configured
 * to periodically wake up the CPU and call watchdog_timer(), which toggles
 * the LEDs.  The program never exits LPM3.
 */
int main(void) {
  configureClocks();
  led_init();
  enableWDTInterrupts();

  or_sr(0x18);
}

int Count=0;
/**
 * Watchdog timer interrupt handler.
 *
 * Called once every watchdog timer period.  Will flip the LEDs every 5 seconds.
 */
void __interrupt_vec(WDT_VECTOR) watchdog_timer(void)
{
  static unsigned int interrupt_count = 0;

  interrupt_count++;

  if (interrupt_count >= 250 * 5) {
    P1OUT ^= LEDS;
    interrupt_count = 0;
  }
}
