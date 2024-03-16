#ifndef KEYBOARD_TS_LCD
#define KEYBOARD_TS_LCD
#include "Led_Lcd.h"
#include "Keyboard_Ts.h"

class KeyboardTsLcd
{
    public:
        enum KeyboardState eRead();
        KeyboardTsLcd(unsigned char);
    private:
        KeyboardTs* pKeyboard;  
        LedLcd* pLed; 
};

#endif
