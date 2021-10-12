/*#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#define heartratePin A1
#include "DFRobot_Heartrate.h"
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define DELTAY 2

DFRobot_Heartrate heartrate(DIGITAL_MODE);

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
const static unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  Serial.begin(9600);
  delay(500);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  display.display(); // show splashscreen
  delay(200);
  display.clearDisplay();   // clears the screen and buffer
}


void loop() {
    // text display tests
  
  uint8_t rateValue;
  rateValue = heartrate.getValue(heartratePin);
  rateValue = heartrate.getRate();
  if(rateValue){
    display.println(rateValue);
    display.display();
//    display.clearDisplay();
    Serial.println(rateValue);
  }else{
    
  display.println("Wait until valid value");
  display.display();
  }
  display.clearDisplay();
  delay(20);
}

//
//void getHeart(){
//  
//}*/
