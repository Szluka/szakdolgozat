#include "includes.h"

void fek_gaz() {
//Változók definiálása
    unsigned char percentage;
    unsigned short int actualSpeed, pwm;
    int distanceFrontMiddle = Sensor();
    unsigned long int turn_time;

    //Konvertálások
    actualSpeed = readGasPedal;
    percentage = speed_2_percentage(actualSpeed);    //konvertálás percentagere 0-100
    pwm = speed_2_pwm(actualSpeed);                  //konvertálás 8 bitre 0-255

    // ha nyomva a fek, nem engedjuk forogni a motort
    if (isBrakePedalON) {
        brakesON;
        WheelBrakeON;
        setPwm(0);
        setWheel(0);
    }

//Irány és sebesség beállítása
    if (Gear == Elore) {
        Forward;
        setPwm(pwm);
    }

    if (Gear == Hatra) {
        Backward;
        setPwm(pwm);
    }

    if ((Gear == Park) || (Gear == Ures)) {
        setPwm(0);    //motor letiltva
    }

    //Fek beállítása
    if ((Gear == Park)) {
        brakesON;
    }

    if ((Gear != Park) && isBrakePedalOFF) {
        brakesOFF;
    }


    if (Gear == SelfD) {
        Forward;
        WheelBrakeOFF;
        /*
        if ((2 < distanceFrontMiddle) && (distanceFrontMiddle < 150)) {
            lcd.setCursor(16, 2);
            lcd.print("R");
            setWheel(30);
            if (restarter) {
            turn_time = millis();
            restarter = false;
            }
        }
        if (isBrakePedalOFF) {
            brakesOFF;
            setPwm(pwm);
        }
        if ((millis()-turn_time > 1000) && !restarter) {
            setWheel(0);
            restarter = true;
            lcd.setCursor(16, 2);
            lcd.print(" ");
        }*/
    } else {
      WheelBrakeOFF;
      setWheel(0);
      //lcd.setCursor(16, 2);
      //lcd.print(" ");
    }

    

    //Fek kijelzése
    lcd.setCursor(7, 1);
    if (isBrakePedalON)
        lcd.print("BRAKE");
    else
        lcd.print("     ");

    //Gaz kijelzése
    gaz_kijelzes(percentage);

    //Biztonsági Park üzemmód
    park_biztonsagi(percentage);

    //Akku feszultseg kijelzése
    float fesz = readVoltage;
    lcd.setCursor(0, 1);
    lcd.print(fesz);
    lcd.print("V ");
}

#define PB_TIMEOUT 60000
unsigned long int PB_ido;

void park_biztonsagi(unsigned char percentage) {
    unsigned long int eltelt_ido;

    if ((Gear == Park) || (percentage > 0))                       //ha nyomjuk a gázt vagy Parkban vagyunk
        PB_ido = millis();                                        //lementjük az időbélyeget

    eltelt_ido = millis() - PB_ido;                               //Meghatarozzuk az eltelt idot

    if (eltelt_ido > PB_TIMEOUT)                                  //Ha ez nagyobb
        Gear = Park;                                              //Parkba kapcsol
}


//Gaz kijelzése
void gaz_kijelzes(unsigned char percentage) {
    unsigned char v;

    lcd.setCursor(8, 2);
    lcd.print(percentage);
    lcd.print("%  ");

    lcd.setCursor(0, 3);
    for (v = 5; v <= 100; v = v + 5) {
        if (v <= percentage)
            lcd.write((uint8_t) 255);
        else
            lcd.print(" ");
    }
}
