#include "Keyboard_Ts.h"

KeyboardTs::KeyboardTs(unsigned char ucColumnSet){
    Init(240,320);  
    ucColumnPosition = ucColumnSet;
}


enum KeyboardState KeyboardTs::eRead(void){

    GetState(&TS_State);
    uint16_t x = TS_State.X;
    uint16_t y = TS_State.Y;

    if (TS_State.TouchDetected)
    {
        if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80)  && y <= 80){                 
            return BUTTON_0;
        } 

        else if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80) && y <= 160 && y > 80){               
            return BUTTON_1;       
        } 

        else if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80) && y <= 240 && y > 160){            
            return BUTTON_2;
        } 

        else if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80) && y > 240){             
            return BUTTON_3;
        }
    }
    else{}
}
