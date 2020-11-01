#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count != 250) {
    switch(bttnState){
    case 1:
      countToThree();
      break;
    case 2:
      dimLights();
      break;
    case 3:
      buzzer_set_period(0);
      resetLEDs();
      resetCount();
      break;
    case 4:
      annoyEars();
      break;
    }
  }
  blink_count = 0;
}
