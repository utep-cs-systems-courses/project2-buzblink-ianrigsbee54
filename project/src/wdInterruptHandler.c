#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  switch(bttnState){
  case 2:
    if(++blink_count != 187){
      dimLights();
      break;
    }
    blink_count = 0;
  default:
    buzzer_set_period(0);
  }
}
