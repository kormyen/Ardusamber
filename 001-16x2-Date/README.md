# Date

This `Arduino` sketch displays YY-MM-DD date format and `Desamber` [date](https://wiki.xxiivv.com/#calendar) on a 16 character by 2 line display.

It includes buttons to set the date. One button adds a year, one adds a month, one adds a day and one subtracks a day.

This experiment was built with an `Arduino Uno`, an `Open Smart I2C / IIC LCD 1602 Display Module` and four `Momentary buttons`. This sketch does not use a `RTC (real-time clock)`, the date is instead set via the buttons.

<img src='https://raw.githubusercontent.com/kormyen/Ardusamber/master/001-16x2-Date/PREVIEW.jpg' width="600"/>

## Guide

### Wiring for LCD

- GND to GND
- VCC to 5V
- SDA to Analog 4
- ​SCL to Analog 5

### Wiring for buttons

- Year button - wire one side to Arduino GND and the other to pin 7.
- Month button - wire one side to Arduino GND and the other to pin 6.
- Day add button - wire one side to Arduino GND and the other to pin 5.
- Day minus button - wire one side to Arduino GND and the other to pin 4.

### Setup

- Connect your Arduino to your PC with a USB cable
- Open and configure the [Arduino IDE](https://www.arduino.cc/en/Main/Software) for your Arduino
- Open the `.ino` sketch that is in this directory
- Upload the sketch to your Arduino

### Usage

- Press the buttons until date is correct
- Enjoy


## Dependencies

The code makes use of the [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) to control the LCD and [TimeLib](https://github.com/PaulStoffregen/Time) for time manipulation.