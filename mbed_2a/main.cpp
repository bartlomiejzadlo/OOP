#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"
#include "Keyboard_TS.h"

LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;
Keyboard MyKeyboard;


void DrawRect(uint16_t uiXpos, uint16_t uiYpos, uint16_t uiWidth, uint16_t uiHeight, uint32_t uiFillColor, uint32_t uiBorderColor, uint8_t uiNumber)
{
    char text[16];

    lcd.SetTextColor(uiFillColor);
    lcd.FillRect(uiXpos, uiYpos, uiWidth, uiHeight);
    lcd.SetTextColor(uiBorderColor);
    lcd.DrawRect(uiXpos, uiYpos, uiWidth, uiHeight);
    lcd.SetBackColor(LCD_COLOR_RED);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    sprintf((char*)text, "%d", uiNumber);
    lcd.DisplayStringAt(0, LINE(uiNumber*3.35), (uint8_t *)&text, LEFT_MODE); 

}



int main()
{

    TS_StateTypeDef TS_State;
    uint8_t status;


  
    BSP_LCD_SetFont(&Font24);
  
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"Bartlomiej", CENTER_MODE);
    lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Zadlo", CENTER_MODE);
    lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"MBED_CZ1", CENTER_MODE);
    wait(1);
  
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize()); 
  
    if (status != TS_OK)
    {
      lcd.Clear(LCD_COLOR_RED);
      lcd.SetBackColor(LCD_COLOR_RED);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"INIT FAIL", CENTER_MODE);
    }
    else
    {
      lcd.Clear(LCD_COLOR_GREEN);
      lcd.SetBackColor(LCD_COLOR_GREEN);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"INIT OK", CENTER_MODE);
    }
    
    
    wait(1);
    lcd.Clear(LCD_COLOR_BLACK);
    

   
    while(1)
    {
            ts.GetState(&TS_State);      
            if (TS_State.TouchDetected)
            {
                if(TS_State.X < 80 && TS_State.Y <= 80){
                    
                    DrawRect(0, 0, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 0);

                } else if(TS_State.X < 80 && TS_State.Y <= 160 && TS_State.Y > 80){
                   
                    DrawRect(0, 80, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 1);
                    

                } else if(TS_State.X < 80 && TS_State.Y <= 240 && TS_State.Y > 160){
                   
                    DrawRect(0, 160, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 2);
                   

                } else if(TS_State.X < 80 && TS_State.Y <= 320 && TS_State.Y > 240){
                  
                    DrawRect(0, 240, 80, 80, LCD_COLOR_GREEN, LCD_COLOR_GREEN, 3);

                }
            } 
            else{
                DrawRect(0, 0, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 0);
                DrawRect(0, 80, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 1);
                DrawRect(0, 160, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 2);
                DrawRect(0, 240, 80, 80, LCD_COLOR_BLUE, LCD_COLOR_GREEN, 3); 
            }
    wait(0.1);
    }
}

