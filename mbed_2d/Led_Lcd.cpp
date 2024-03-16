#include "Led_Lcd.h"


LedLcd::LedLcd(unsigned char ucColumnSet){  
    BSP_LCD_SetFont(&Font24); 
    ucColumnPosition = ucColumnSet;
    Clear(LCD_COLOR_BLACK); 

}

void LedLcd::drawBackground(){
    for( unsigned char ucIterator = 0; ucIterator < 4; ucIterator++ ){
        drawRectangle(ucIterator, LCD_COLOR_BLUE);
    }
}


void LedLcd::drawRectangle(unsigned char ucLedIndex, uint32_t uiFillColor){ 
    char text[2];
    SetTextColor(uiFillColor);
    FillRect(80*ucColumnPosition, ucLedIndex*80, 80, 80);
    SetTextColor(LCD_COLOR_GREEN);
    DrawRect(80*ucColumnPosition, ucLedIndex*80, 80, 80);
    SetBackColor(LCD_COLOR_RED);
    SetTextColor(LCD_COLOR_WHITE);
    sprintf((char*)text, "%d", ucLedIndex);  
    DisplayStringAt(80*ucColumnPosition, LINE(ucLedIndex*3.35), (uint8_t *)&text, LEFT_MODE); 

}


void LedLcd::On(unsigned char ucLedIndex){
   
    drawBackground();
    drawRectangle(ucLedIndex, LCD_COLOR_YELLOW); 
 
}

