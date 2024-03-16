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
        enum KeyboardState eButton[4] = {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

        if(x >= ucColumnPosition*80 && x <= 80 +(ucColumnPosition*80)){                   
            return eButton[ucButtonIndex];
        }     
    }
    else{}
}
