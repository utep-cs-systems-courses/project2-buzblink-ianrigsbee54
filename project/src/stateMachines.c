#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void countToThree()
{
  static char count = 0;
  
  switch(count){
    
  case 0:
    red_on = 0;
    green_on = 0;
    count = 1;
    break;
    
  case 1:
    red_on = 1;
    green_on = 0;
    count = 2;
    break;
    
  case 2:
    red_on = 0;
    green_on = 1;
    count = 3;
    break;
    
  case 3:
    red_on = 1;
    green_on = 1;
    count = 0;
    break;
  }
}
/*dims lights to 75%*/
void dimLights()
{
  state = 0;
  switch(state){
  case 0:
    red_on = 1;
    green_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 1;
    green_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 0;
    green_on = 0;
    state = 0;
    break
  }
  led_changed = 1;
  led_update();
}
void resetLEDs()
{
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}
void resetCount()
{
  count = 0;
}

