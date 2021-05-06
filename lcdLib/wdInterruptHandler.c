#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "stateAssembly.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char buzz_count = 0;
  if (++blink_count == 250) {
    state_advance();
    blink_count = 0;
  }

  if(++buzz_count == 125){
    buzzer_state_advance();
    buzz_count = 0;
  }
}
