/* Edison Klub 2016
 *  PAL Workgroup (Patrik-Andris-Laci)
 *  
 *  Kicsikocsi vezerlo program Arduino Uno R3 
 */

// include the library code:
#include "includes.h"


typedef enum 
{  Park, Ures, Elore, Hatra }
Sebvalto_allapot;

// Globalis valtozok 
LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);  // LCD inicializalasa
Sebvalto_allapot Sebvalto = Park;       // sebvalto aktualis allapota

//-----------------------------------------------------------------------------------------------------
byte teli[8] = 
{
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};
// ----------------------------------------------------------------------------------------------------
void setup() {
  Hardware_Init();    // a hardware beallitasa
  Udvozlo_Uzenet();
  lcd.createChar(0, teli);
}


// ----------------------------------------------------------------------------------------------------
void loop() {
  index();
  fek_gaz();
  sebvalto();
//  Sensor();
//  teszteles();
}


unsigned char sebesseg2Szazalek(unsigned short poti)
{
  signed short int szazalek;
  szazalek = map(poti, GAZ_ALAPJARAT, GAZ_FULL, 0, 100);

  if (szazalek < 0)
    szazalek=0;

  if (szazalek > 100)
    szazalek=100;

  return (unsigned char)szazalek;
}


// ----------------------------------------------------------------------------------------------------
unsigned short int sebesseg2pwm(unsigned short poti)
{
  signed short int pwm;
  signed char valto;
  valto = 1;
  pwm = map(poti, GAZ_ALAPJARAT, GAZ_FULL, 0, 255);
  //pwm = pwm/2;
  if (pwm < 0) pwm = 0;
 if (valto = 1) {
  if (pwm < 0) pwm = 0;
  if (pwm > 180) pwm = 180;
  }
  return (unsigned short int)pwm;
  return (unsigned char)valto;
}



