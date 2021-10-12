#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "String.h"
#include "DFRobot_Heartrate.h"
#define heartratePin A1
#define OLED_RESET 4
#define DELTAY 2

  //global variables
  //int test;
  String mood;
  float temp;
  int tempPin = 2;
  char moodTemplate[] = "Your mood is ";

Adafruit_SSD1306 display(OLED_RESET);

DFRobot_Heartrate heartrate(1);

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

//OLED screen setup
void setup() {
  Serial.begin(9600);
  delay(500);
  //Serial.println(sizeof(display));
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  display.display(); // show splashscreen
  delay(200);
  display.clearDisplay();   // clears the screen and buffer
}

//main loop for reading of temp and hr, and printing a mood
void loop() {
  
  //HEART RATE CODE
  uint8_t heartRateValue;
  heartrate.getValue(heartratePin);
  heartRateValue = heartrate.getRate();
  //display the heart rate if a heart rate is read, otherwise wait
  if (heartRateValue) 
  {
    Serial.println(heartRateValue);
    //display.display();
    //Serial.println(heartRateValue);
  }
  else 
  {
    Serial.println("Wait until valid value");
    //display.display();
  }
  display.clearDisplay();
  //delay(1000);

  //TEMPERATURE CODE  
  temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   temp = temp * 5.0 / 1024.0;
   temp = (temp - 0.5) *100;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
   delay(1000); // update sensor reading each one second

  //Mood algorithm
  while ((heartRateValue <= 150 && heartRateValue >= 20) && (temp <= 38 && temp >= 33))
  {
    //Heart rate 20-49
    if ((heartRateValue >= 20 && heartRateValue <= 49) && (temp >= 33 && temp <= 33.9))
    {
      //mood must be saved in a string for later purposes
      //later on the mood will be saved on the phone application
      String mood = "depressed";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 20 && heartRateValue <= 49) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "sad";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 20 && heartRateValue <= 49) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 20 && heartRateValue <= 49) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "worried";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 20 && heartRateValue <= 49) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "sick";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart Rate 50-59
    else if ((heartRateValue >= 50 && heartRateValue <= 59) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "anxious";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 50 && heartRateValue <= 59) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "sad";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 50 && heartRateValue <= 59) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 50 && heartRateValue <= 59) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "worried";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 50 && heartRateValue <= 59) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "surprised";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart rate 60-69
    else if ((heartRateValue >= 60 && heartRateValue <= 69) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "anxious";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 50 && heartRateValue <= 69) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "neutral";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 60 && heartRateValue <= 69) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 60 && heartRateValue <= 69) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "happy";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 60 && heartRateValue <= 69) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "surprised";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart Rate 70-79
    else if ((heartRateValue >= 70 && heartRateValue <= 79) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "tense";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 70 && heartRateValue <= 79) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "neutral";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 70 && heartRateValue <= 79) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 70 && heartRateValue <= 79) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "happy";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 70 && heartRateValue <= 79) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "angry";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart rate 80-89
    else if ((heartRateValue >= 80 && heartRateValue <= 89) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "tense";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 80 && heartRateValue <= 89) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "neutral";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 80 && heartRateValue <= 89) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 80 && heartRateValue <= 89) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "happy";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 80 && heartRateValue <= 89) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "angry";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart Rate 90-99
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "nervous";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "excited";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "upset";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "working out";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    //Heart Rate 100-150
    else if ((heartRateValue >= 100 && heartRateValue <= 150) && (temp >= 33 && temp <= 33.9))
    {
      String mood = "nervous";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 100 && heartRateValue <= 150) && (temp >= 34 && temp <= 34.9))
    {
      String mood = "excited";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 90 && heartRateValue <= 99) && (temp >= 35 && temp <= 35.9))
    {
      String mood = "content";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 100 && heartRateValue <= 150) && (temp >= 36 && temp <= 36.9))
    {
      String mood = "upset";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else if ((heartRateValue >= 100 && heartRateValue <= 150) && (temp >= 37 && temp <= 37.9))
    {
      String mood = "working out";
      Serial.println(moodTemplate);
      Serial.println(mood);
      break;
    }
    else
    {
      Serial.println("error");
      break;
    }
  }

  /*To see if mood is correct or not
  Serial.println("Is your mood correct?");
  Serial.println("1 for yes, 2 for no: ");
  
  serial.read(test);
  if (Serial.available()) 
  {
     test = Serial.read();
     //if mood is wrong, allow user to correct it on the phone
     if ((char)test == '1')
     {
        Serial.println("Please choose your correct mood on your mobile device.");     
     }  
     //if mood is correct, have the phone application suggest a playlist for the user
     //unable to continue here because phone application is not yet completed
     else 
     {
          Serial.println("Here is a suggested playlist based on your mood.");
     }
  }*/
}
