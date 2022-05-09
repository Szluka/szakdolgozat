/* Edison Klub 2016
    PAL Workgroup (Patrik-Andris-Laci)

    Kicsikocsi vezerlo program Arduino Uno R3
*/

/* Edison Klub 2022
    Szluka András szakdolgozat

    Elektromos gokart vezerlo program Arduino MEGA 2560
*/

#include "includes.h"

//Üzemmódok
typedef enum {
  Park, Ures, Elore, Hatra
} Gears;

//Globalis valtozok
//LCD inicializálása
#include <LiquidCrystal.h>
LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

Gears Gear = Park;
bool canRestart = true;
bool wifiBoot = false;
int page = 0;
int wifiWheelPercent = 50;
int wifiGasPercent = 0;
short int Mode = 0;

//ESP8622 - Wifi Module START


#define BLYNK_TEMPLATE_ID "TMPL82plWXxf"
#define BLYNK_DEVICE_NAME "arduino"
#define BLYNK_AUTH_TOKEN "YiEul3kzxRmWeM5bYI5hHlk6o5TmtkTA"

#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Bandeer";  //Aurorparancsnoksag //TP-LINK_Szluka
char pass[] = "asd54321";        //KalozCsizma2     //XpAndras11

#define EspSerial Serial2

#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

void myTimerEvent()
{
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup() {
  // Debug console
  Serial.begin(19200);

  Hardware_Init();
  //Welcome_message();

  lcd.setCursor(5, 1);
  lcd.print("Connecting");

  if (isGearSwitch) {
  wifiBoot = true;
    
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  timer.setInterval(1000L, myTimerEvent);

  WheelBrakeOFF;
  }

  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("PARK ");
}

void loop() {
  if (wifiBoot) {
  Blynk.run();
  timer.run();
  }

  indexing();
  fek_gaz();
  sebvalto();

  //teszteles();
}

BLYNK_WRITE(V0)
{
  if (Mode == 1) {
    lcd.setCursor(8, 0);
    switch (param.asInt())
    {
      case 0:
        Gear = Elore;
        lcd.print("ELORE");
        break;
      case 1:
        Gear = Hatra;
        lcd.print("HATRA");
        break;
    }
  }
}

BLYNK_WRITE(V7)
{
  if (Mode == 1) {
    wifiWheelPercent = param.asInt();
  }
}

BLYNK_WRITE(V8)
{
  if (Mode == 1) {
    wifiGasPercent = param.asInt();
  }
}

BLYNK_WRITE(V9)
{
  lcd.setCursor(3, 0);
  switch (param.asInt())
  {
    case 0:
      Mode = 0;
      lcd.print("MAN");
      break;
    case 1:
      Mode = 1;
      lcd.print("REM");
      break;
  }
}

unsigned char speed_2_percentage(unsigned short potentiometer) {
  signed short int percentage;
  percentage = map(potentiometer, gasPotentiometerMIN, gasPotentiometerMAX, 0, 100);

  if (percentage < 0)
    percentage = 0;

  if (percentage > 100)
    percentage = 100;

  return (unsigned char) percentage;
}

int wheel_2_percentage(unsigned short potentiometer) {
  int percentage;
  percentage = map(potentiometer, wheelPotentiometerMIN, wheelPotentiometerMAX, 0, 100);

  if (percentage < 0)
    percentage = 0;

  if (percentage > 100)
    percentage = 100;

  return percentage;
}

unsigned short int speed_2_pwm(unsigned short potentiometer) {
  signed short int pwm;
  pwm = map(potentiometer, gasPotentiometerMIN, gasPotentiometerMAX, 0, 255);
  if (pwm < 0) pwm = 0;
  if (pwm > 255) pwm = 255;
  return (unsigned short int) pwm;
}
