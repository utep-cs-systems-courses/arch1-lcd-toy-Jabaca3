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

static int offsetX =25;
static int offsetY =50;

void my_shape(u_int color){
  fillRectangle(offsetX+1, offsetY+15, 50, 20, color);
  fillRectangle(offsetX+15, offsetY+1, 20, 50, color);
  
  // Left Arrow
  int offsetXTL= offsetX;     // X Triangle Left
  int offsetYTL= offsetY*2-1; // Y Triangle Left

  // Right Arrow
  int offsetXTR= offsetX*3;   // X Triangle Right
  int offsetYTR= offsetY; // Y Triangle Right
  
  for(int r=0; r<25; r++){
    for(int c=0; c<=r; c++){
      
      // Left Arrow
      drawPixel(offsetX-c, offsetY+r, color);
      drawPixel(offsetXTL-c, offsetYTL-r, color);

      // Right Arrow
      drawPixel(offsetXTR+c, offsetYTL-r, color);
      drawPixel(offsetXTR+c, offsetYTR+r, color);
    }
  }
}

void buzzer_state_advance(){

}

void state_advance(){
  
  my_shape(COLOR_RED);
   if(switch_state_down_1){
    static char buzz_state= 0; 
    //clearScreen(COLOR_WHITE);
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
    clearScreen(WHITE);
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
    offsetY-=10;
    clearScreen(WHITE);
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
    clearScreen(WHITE);
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






