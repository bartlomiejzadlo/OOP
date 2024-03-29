#include "KeyboardTsLcd.h"

KeyboardTs* pKeyboard;

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new KeyboardTs(_ucColumn);
    pLed = new LedLcd(_ucColumn);
};


enum KeyboardState KeyboardTsLcd::eRead()
{
    switch(pKeyboard->eRead()) {
            case BUTTON_0:
                pLed->On(0);
                return BUTTON_0;
            case BUTTON_1:
                pLed->On(1);
                return BUTTON_1;
            case BUTTON_2:
                pLed->On(2);
                return BUTTON_2;
            case BUTTON_3:
                pLed->On(3);
                return BUTTON_3;
            default:
                pLed->On(4);
                return RELEASED;
        }
}