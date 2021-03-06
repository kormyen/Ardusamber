/*
 * This Arduino sketch displays YY-MM-DD date format and Desamber date format on a 16 character by 2 line display.
 * It includes buttons to set the date. One button adds a year, one adds a month, one adds a day and one subtracks a day.
 * Desamber is a time format created by Devine Lu Linvega. More information about Desamber here: https://wiki.xxiivv.com/#clock
 */

#include "Ardusamber.h"
#include "MilitaryTime.h"
#include "Bun.h"
#include "TimeLib.h"
#include "LiquidCrystal_I2C.h"

Ardusamber _dTime;
MilitaryTime _mTime;
LiquidCrystal_I2C _lcd(0x20,16,2); // Set the LCD address to 0x20 for a 16 chars and 2 line display

Bun buttonYear(7);
Bun buttonMonth(6);
Bun buttonDay(5);
Bun buttonDayMinus(4);

void setup()
{
  setTime(5, 20, 00, 1, 6, 2018);
  
  _lcd.init();
  _lcd.backlight();
  _lcd.home();
  _lcd.clear();
}

void loop()
{
  if(buttonYear.isPressed()) 
  {
    setTime(hour(),minute(),second(),day(),month(),year()+1);
  }
  if(buttonMonth.isPressed()) 
  {
    setTime(hour(),minute(),second(),day(),month()+1,year());
  }
  if(buttonDay.isPressed()) 
  {
    setTime(hour(),minute(),second(),day()+1,month(),year());
  }
  if(buttonDayMinus.isPressed()) 
  {
    setTime(hour(),minute(),second(),day()-1,month(),year());
  }

  _dTime.update();

  writeToScreen(_mTime.getFormattedDate(), 4, 0);
  writeToScreen(_dTime.getFormattedDate(), 7, 1);
  
  delay(100);
}

void writeToScreen(String value, int posX, int posY)
{
  _lcd.setCursor(posX, posY);
  _lcd.print(value);
}
