# Adafruit_LCDBackpack_msp430

This is an interface for the Adafruit Character LCD Backpack (https://learn.adafruit.com/i2c-spi-lcd-backpack) when the backpack is in SPI mode. An example of usage is found in main.c.

The code is written for the MSP430fr2433, but can be changed to work with other MSP430s by changing the SPI initialization in adafruit_lcd_backpack_interface.c.


# Notes
During initialization of the LCD and when writing to the LCD, data is sent to the LCD through the backpack in 8-bit chunks:
 - X (don't care value, first bit is not connected)
 - RS (0/1 for sending commands/data)
 - E (must be pulsed while data is stable, see page 52 and figure 25 of HD77480 datasheet)
 - D7 (data bit)
 - D6 (data bit)
 - D5 (data bit)
 - D4 (data bit)
 - LITE (Controls LCD backlight, HIGH for backlight on)
 
The commands used during initialization are found on page 46 of the HD77480 datasheet, while an overview of all available commands can be found on page 24.


# References
 - HD77480 Datasheet: https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
 - Character LCD Backpack Schematic: https://cdn-learn.adafruit.com/assets/assets/000/118/702/original/arduino_compatibles_schem.png?1677078546
 - 74HC595D (used in backpack to output the received SPI data to the LCD): https://toshiba.semicon-storage.com/info/74HC595D_datasheet_en_20161227.pdf?did=36768&prodName=74HC595D
