#ifndef LED_LCD_H
#define LED_LCD_H
#include "LCD_DISCO_F429ZI.h"



class LedLcd: public LCD_DISCO_F429ZI
{
    public:
        LedLcd(unsigned char ucColumnSet);
        void On(unsigned char ucLedIndex);
        
    private:
        void drawRectangle(uint16_t uiXpos, uint16_t uiYpos, uint16_t uiWidth, uint16_t uiHeight, uint32_t uiFillColor, uint32_t uiBorderColor, uint8_t uiNumber);
        void drawBackground();
        unsigned char ucColumnPosition;
};

#endif
