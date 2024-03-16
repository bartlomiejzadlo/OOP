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
        unsigned char ucButtonIndex = (y / 80);

        if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80)){
            switch(ucButtonIndex){
                case 0:
                return BUTTON_0;
                break;
                case 1:
                return BUTTON_1;
                break;
                case 2:
                return BUTTON_2;
                break;
                case 3:
                return BUTTON_3;
                break;
            }
        }     
    }
    else{}
}
