/* Edison Klub 2016
 *  PAL Workgroup (Patrik-Andris-Laci)
 *  
 *  Kicsikocsi vezerlo program Arduino Uno R3 
 */

/* Edison Klub 2022
 *  Szluka András szakdolgozat
 *  
 *  Ekeltromos gokart vezerlo program Arduino MEGA 2560 
 */

#include "includes.h"

//Üzemmódok
typedef enum {
    Park, Ures, Elore, Hatra
} Gears;

//Globalis valtozok
//LCD inicializálása
LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
Gears Gear = Park;


void setup() {
    Hardware_Init();
    Welcome_message();
}

void loop() {
    indexing();
    fek_gaz();
    sebvalto();
    Sensor();
// teszteles();
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

unsigned short int speed_2_pwm(unsigned short potentiometer) {
    signed short int pwm;
    pwm = map(potentiometer, gasPotentiometerMIN, gasPotentiometerMAX, 0, 255);
    if (pwm < 0) pwm = 0;
    if (pwm > 255) pwm = 255;
    return (unsigned short int) pwm;
}
