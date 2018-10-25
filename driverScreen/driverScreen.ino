#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

//given variables
int Wheel1RPM;
int Wheel2RPM;
int InverterDCVoltage;
int InverterDCCurrent;
int inverterMotorTemp;
int BrakeBiasPosReport;
//calculated variables
int WheelRPM;
int speed;
string speedBoxColor;
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    Serial.println("RA8875 start");

    /* Initialise the display using 'RA8875_480x272' or 'RA8875_800x480' */
    if (!tft.begin(RA8875_800x480)) {
      Serial.println("RA8875 Not Found!");
      while (1);
    }

    Serial.println("Found RA8875");

    tft.displayOn(true);
    tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
    tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
    tft.PWM1out(255);

    // With hardware accelleration this is instant
    //RPM display
    tft.fillScreen(RA8875_WHITE);
    tft.setCursor(300,10);
    tft.textColor(RA8875_WHITE);
  //  tft.textWrite(WheelRPM);
    tft.setCursor(320,10);
    tft.textColor(RA8875_RED);
    tft.textWrite("RPM");

    //Speed display

    tft.drawRect(250,20,350,400);
    tft.fillRect(251,21,349,399,speedBoxColor);
    tft.textEnlarge(5);
    tft.textWrite("MPH");
  //  tft.textWrite(speed);

    //Voltage display
    tft.textEnlarge(4);
    tft.setCursor(10,20);
    tft.textWrite("V:");
  //  tft.textWrite(InverterDCVoltage);

    //current display
    tft.textEnlarge(4);
    tft.setCursor(10,30);
    tft.textWrite("A:");
  //  tft.textWrite(InverterDCCurrent);

    //Temperature diplay
    tft.textEnlarge(4);
    tft.setCursor(700,20);
    tft.textWrite("T:");
  //  tft.textWrite(inverterMotorTemp);

    //Brake Bias display
    tft.textEnlarge(4);
    tft.setCursor(700,30);
    tft.textWrite("BB:");
  //  tft.textWrite(BrakeBiasPosReport);
  }


void loop() {
  //RPM live display
  tft.setCursor(300,10);
  tft.textColor(RA8875_WHITE);
  tft.textWrite(WheelRPM);

  //Speed live display
  if (speed>50){
    speedBoxColor="RA8875_RED";
  }
  else
  speedBoxColor="RA8875_WHITE";
   // if else mechanism to change color of the speed display box when speed crosses threshold value
   tft.fillRect(251,21,349,399,speedBoxColor);
   tft.textEnlarge(5);
   tft.textWrite(speed);

   //set text size for all side display
   tft.textEnlarge(4);

   //Voltage live display
   tft.setCursor(10,20);
   tft.textWrite(InverterDCVoltage);

   //current live display
   tft.setCursor(10,30);
   tft.textWrite(InverterDCCurrent);

   //Temperature live display
   tft.setCursor(700,20);
   tft.textWrite(inverterMotorTemp);

   //brake Bias live display
   tft.setCursor(700,30);
   tft.textWrite(BrakeBiasPosReport);
}
