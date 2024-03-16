#ifndef LED_LCD_H
#define LED_LCD_H
#include "LCD_DISCO_F429ZI.h"



class LedLcd: public LCD_DISCO_F429ZI
{
    public:
        LedLcd(unsigned char ucColumnSet);
        void On(unsigned char ucLedIndex);
        
    private:
        void drawRectangle(unsigned char ucLedIndex, uint32_t uiFillColor);
        void drawBackground();
        unsigned char ucColumnPosition;
};

#endif
