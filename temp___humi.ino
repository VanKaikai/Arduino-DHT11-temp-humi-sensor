#include <SimpleDHT.h>
#include <Wire.h> 
#include <LCD.h> 
#include <LiquidCrystal_I2C.h>
const int pinDHT = 2;
SimpleDHT11 dht11;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack 
void setup() { // activate LCD module 
  lcd.begin (16,2); // for 16 x 2 LCD module 
  lcd.setBacklightPin(3,POSITIVE); 
  lcd.setBacklight(HIGH); 
} 
void loop() { 
  byte temp;
  byte humi;                                                                                                                                                                                                                                                                    
  dht11.read(pinDHT, &temp, &humi, NULL);
  lcd.home (); // set cursor to 0,0 
  lcd.print(temp); lcd.print(" C");
  lcd.setCursor (0,1); // go to start of 2nd line 
  lcd.print(humi); lcd.print(" %"); 
  
}
