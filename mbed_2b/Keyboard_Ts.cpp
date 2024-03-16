#include "Keyboard_Ts.h"


KeyboardTs::KeyboardTs(){
    Init(Led.GetXSize(), Led.GetYSize()); 

}

enum KeyboardState KeyboardTs::eRead(void){

    GetState(&TS_State);
    if (TS_State.TouchDetected)
    {
        if(TS_State.X < 80 && TS_State.Y <= 80){
                    
            return BUTTON_0;

        } 
        else if(TS_State.X < 80 && TS_State.Y <= 160 && TS_State.Y > 80){
                   
            return BUTTON_1;
                    

        } 
        else if(TS_State.X < 80 && TS_State.Y <= 240 && TS_State.Y > 160){
                   
            return BUTTON_2;
        } 

        else if(TS_State.X < 80 && TS_State.Y <= 320 && TS_State.Y > 240){
                  
            return BUTTON_3;
        }
    }
    else{}
}
