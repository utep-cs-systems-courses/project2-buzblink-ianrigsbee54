#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switche.h"

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
  led_init();
  buzzer_init();
  switch_init();
  or_sr(0x18);		/* CPU off, GIE on */
}