#include "includes.h"

//------------ CUSTOM KARAKTER (teli)
byte customChar[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

// ----------------------------------------------------------------------------------------------------
void Hardware_Init()
{
  // Kimenetek beallitasa
  digitalWrite(RELE1_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE1_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE2_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE2_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE3_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE3_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE4_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE4_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE5_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE5_PIN, OUTPUT);      // rele lab kimenet

  digitalWrite(IRANY_PIN, LOW);    // irany L szint
  pinMode(IRANY_PIN, OUTPUT);      // irany kimenet
  pinMode(TRIG_PIN, OUTPUT); 
  /* A 6-7-8 releket most nem hasznaljuk
  digitalWrite(RELE6_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE6_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE7_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE7_PIN, OUTPUT);      // rele lab kimenet
  digitalWrite(RELE8_PIN, HIGH);   // H szint beallitasa (rele ki)  
  pinMode(RELE8_PIN, OUTPUT);      // rele lab kimenet
  */
  
  // Bemenetek beallitasa
  pinMode(INDEX_B_BEMENET,  INPUT_PULLUP);      // bemenet felhuzo ellenallassal
  pinMode(INDEX_J_BEMENET,  INPUT_PULLUP);      // bemenet felhuzo ellenallassal
  pinMode(SEBVALTO_BEMENET, INPUT_PULLUP);      // bemenet felhuzo ellenallassal
  pinMode(ECHO_PIN, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4, LCD_5x8DOTS);
  // Print a message to the LCD.
  lcd.setRowOffsets(0x00,0x40,0x14,0x54); 
  // create a new custom character
  lcd.createChar(0, customChar);
}

