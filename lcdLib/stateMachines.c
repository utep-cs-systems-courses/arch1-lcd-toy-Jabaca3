#include <msp430.h>
#include "stateMachines.h"
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <abCircle.h>
#include <shape.h>


void buzzer_state_advance(){

}

void state_advance(){
  
  my_shape(COLOR_RED);
   if(switch_state_down_1){
    static char buzz_state= 0; 
    my_shape(COLOR_WHITE);
    offsetX-=10;
    drawString5x7(0,0, "Switch1 LEFT", BLACK, WHITE);
    /*switch(buzz_state){
    case 0: //buzzer_set_period(3822); red_on=0; green_on=1; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=0; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=0; green_on=1; buzz_state=0; break;
    default: buzz_state =0;
    }*/
  }
  else if(switch_state_down_2){
    my_shape(COLOR_WHITE);
    offsetY+=10;
    drawString5x7(0,0, "Switch2 DOWN", BLACK, WHITE);
    static char buzz_state= 0;
    /*switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=0; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=1; green_on=0; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=0; buzz_state=0; break;
    default: buzz_state =0;
    }*/
  }
  else if(switch_state_down_3){
    static char buzz_state= 0;
    my_shape(COLOR_WHITE);
    offsetY-=10;
    drawString5x7(0,0, "Switch3 UP", BLACK, WHITE);
    /*switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=0; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=0; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=0; buzz_state=0; break;
    default: buzz_state =0;
    }*/
  }
  else if(switch_state_down_4){
    static char buzz_state= 0;
    my_shape(COLOR_WHITE);
    offsetX+=10;
    drawString5x7(0,0, "Switch4 RIGHT", BLACK, WHITE);
    /*switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=1; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=1; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=1; buzz_state=0; break;
    default: buzz_state =0;
    }*/
  }
  else {
      buzzer_set_period(0);
      }
  led_changed=1;
  led_update();
  }






