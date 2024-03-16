#ifndef KEYBOARD_TS_H
#define KEYBOARD_TS_H
#include "TS_DISCO_F429ZI.h"




enum KeyboardState{RELASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4, ELSEWHERE};



class Keyboard: public TS_DISCO_F429ZI
{
    public:
        enum KeyboardState eKeyboardRead(void);
        
    private:
        TS_StateTypeDef TS_State;
        TS_DISCO_F429ZI Myts;
};

#endif
