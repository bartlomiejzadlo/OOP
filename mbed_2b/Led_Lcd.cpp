#include "Led_Lcd.h"


LedLcd::LedLcd(){
    BSP_LCD_SetFont(&Font24);
    Clear(LCD_COLOR_BLACK);

}

void LedLcd::drawBackground(){
    drawRectangle(0, 0, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 0);
    drawRectangle(0, 80, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 1);
    drawRectangle(0, 160, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 2);
    drawRectangle(0, 240, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 3);
}

void LedLcd::drawRectangle(uint16_t uiXpos, uint16_t uiYpos, uint16_t uiWidth, uint16_t uiHeight, uint32_t uiFillColor, uint32_t uiBorderColor, uint8_t uiNumber){
    char text[16];

    SetTextColor(uiFillColor);
    FillRect(uiXpos, uiYpos, uiWidth, uiHeight);
    SetTextColor(uiBorderColor);
    DrawRect(uiXpos, uiYpos, uiWidth, uiHeight);
    SetBackColor(LCD_COLOR_RED);
    SetTextColor(LCD_COLOR_WHITE);
    sprintf((char*)text, "%d", uiNumber);
    DisplayStringAt(0, LINE(uiNumber*3.35), (uint8_t *)&text, LEFT_MODE);

}

void LedLcd::On(unsigned char ucLedIndex){
    switch(ucLedIndex)
    {
        case 0:
            drawBackground();
            drawRectangle(0, 0, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 0);
        break;

        case 1:
            drawBackground();
            drawRectangle(0, 80, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 1);
        break;

        case 2:
            drawBackground();
            drawRectangle(0, 160, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 2);
        break;

        case 3:
            drawBackground();
            drawRectangle(0, 240, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 3);
        break;

        case 4:
            drawBackground();
        break;
    }

}