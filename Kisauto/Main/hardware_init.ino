#include "includes.h"

void Hardware_Init() {

    //OUTPUTS - Kimenetek beállítása

    digitalWrite(RELE1_PIN, HIGH);
    pinMode(RELE1_PIN, OUTPUT);

    digitalWrite(RELE2_PIN, HIGH);
    pinMode(RELE2_PIN, OUTPUT);

    digitalWrite(RELE3_PIN, HIGH);
    pinMode(RELE3_PIN, OUTPUT);

    digitalWrite(RELE4_PIN, HIGH);
    pinMode(RELE4_PIN, OUTPUT);

    digitalWrite(RELE5_PIN, HIGH);
    pinMode(RELE5_PIN, OUTPUT);

    //irany meghatározása
    digitalWrite(DirectionOfRotation, LOW);

    //irany beállítása kimenetnek
    pinMode(DirectionOfRotation, OUTPUT);

    /* A 6-7-8 releket most nem hasznaljuk
    digitalWrite(RELE6_PIN, HIGH);
    pinMode(RELE6_PIN, OUTPUT);
    digitalWrite(RELE7_PIN, HIGH);
    pinMode(RELE7_PIN, OUTPUT);
    digitalWrite(RELE8_PIN, HIGH);
    pinMode(RELE8_PIN, OUTPUT);
    */

    //INPUTS - Bemenetek beállítása


    //Bal index kapcsolás felhuzo ellenallassal
    pinMode(indexLeft, INPUT_PULLUP);

    //Jobb index kapcsolás felhuzo ellenallassal
    pinMode(indexRight, INPUT_PULLUP);

    //Váltógomb felhuzo ellenallassal
    pinMode(GearSwitch, INPUT_PULLUP);

    /* LCD kijelző konfigurálása */
    lcd.begin(20, 4, LCD_5x8DOTS);
    lcd.setRowOffsets(0x00, 0x40, 0x14, 0x54);
}
