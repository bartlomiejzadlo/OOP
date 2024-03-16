#ifndef KEYBOARD_TS_H
#define KEYBOARD_TS_H
#include "TS_DISCO_F429ZI.h"

enum KeyboardState{RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3, ELSEWHERE};

class KeyboardTs: private TS_DISCO_F429ZI
{
    public:
        KeyboardTs(unsigned char ucColumnSet);
        enum KeyboardState eRead(void);
        
    private:
        TS_StateTypeDef TS_State;
        unsigned char ucColumnPosition;
};

#endif
