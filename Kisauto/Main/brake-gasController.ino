#include "includes.h"


unsigned long int turn_time;
unsigned long int pageChangeTime = 0;

void fek_gaz() {
  //Változók definiálása
  unsigned char percentage;
  unsigned short int actualSpeed, pwm;
  int wheelPercent;

  int distanceFrontMiddle = Sensor(TRIGGER_PIN_FM, ECHO_PIN_FM, 1);
  int distanceBackLeft = Sensor(TRIGGER_PIN_BL, ECHO_PIN_BL, 3);
  int distanceBackMiddle = Sensor(TRIGGER_PIN_BM, ECHO_PIN_BM, 4);
  int distanceBackRight = Sensor(TRIGGER_PIN_BR, ECHO_PIN_BR, 5);

  //Konvertálások
  actualSpeed = readGasPedal;
  if (Mode == 0) {
    percentage = speed_2_percentage(actualSpeed);    //konvertálás percentagere 0-100
  } else {
    percentage = wifiGasPercent;
  }
  wheelPercent = wheel_2_percentage(readWheel);
  pwm = speed_2_pwm(actualSpeed);                  //konvertálás 8 bitre 0-255

  // ha nyomva a fek, nem engedjuk forogni a motort
  if (isBrakePedalON) {
    brakesON;
    WheelBrakeON;
    setPwm(0);
    setWheelSpeed(0);
  }

  if (wheelPercent < 5 || wheelPercent > 95) {
    WheelBrakeON;
    setWheelSpeed(0);
  }

  //Lapozás
  if ((isBrakePedalOFF) && (isGearSwitch) && (millis() - pageChangeTime > PAGE_CHANGE_TIME))
  {
    pageChangeTime = millis();
    switch (page) {
      case 0:
        page = 1;
        lcd.setCursor(0, 2);
        lcd.print("                    ");
        lcd.setCursor(0, 3);
        lcd.print("                    ");
        break;
      case 1:
        page = 0;
        lcd.setCursor(0, 2);
        lcd.print("                    ");
        lcd.setCursor(0, 3);
        lcd.print("                    ");
        break;
    }
  }

  //Irány és sebesség beállítása
  if (Gear == Elore) {
    Forward;
    WheelBrakeOFF;

    if (Mode == 0) {
      setWheelSpeed(0);
    } else {
      wifiWheelSet(wheelPercent);
    }

    if ((2 < distanceFrontMiddle) && (distanceFrontMiddle < 80)) {
      lcd.setCursor(18, 1);
      lcd.print("!");
      brakesON;
      setPwm(0);
      if (canRestart) {
        turn_time = millis();
        canRestart = false;
      }
    } else if (percentage < 2 && canRestart == false) {
      canRestart = true;
      lcd.setCursor(18, 1);
      lcd.print(" ");
    }
    if (isBrakePedalOFF && canRestart == true) {
      brakesOFF;
      
      if (Mode == 0) {
        setPwm(pwm);
      } else {

        setPwm(wifiGasPercent);
        gaz_kijelzes(speed_2_percentage(wifiGasPercent));
      }

    }
  }

  if (Gear == Hatra) {
    Backward;
    WheelBrakeOFF;

    if (Mode == 0) {
      setWheelSpeed(0);
    } else {
      wifiWheelSet(wheelPercent);
    }


    if ((2 < distanceBackMiddle) && (distanceBackMiddle < 80)) {
      lcd.setCursor(18, 1);
      lcd.print("!");
      brakesON;
      setPwm(0);
      if (canRestart) {
        turn_time = millis();
        canRestart = false;
      }
    } else if (percentage < 2 && canRestart == false) {
      canRestart = true;
      lcd.setCursor(18, 1);
      lcd.print(" ");
    }
    if (isBrakePedalOFF && canRestart == true) {
      brakesOFF;

      if (Mode == 0) {
        setPwm(pwm);
      } else {

        setPwm(wifiGasPercent);
        gaz_kijelzes(speed_2_percentage(wifiGasPercent));
      }
    }

  }

  if ((Gear == Park) || (Gear == Ures)) {
    lcd.setCursor(18, 1);
    lcd.print(" ");
    setPwm(0);    //motor letiltva
    WheelBrakeOFF;
  }

  //Fek beállítása
  if ((Gear == Park)) {
    brakesON;
    WheelBrakeON;
  }

  if ((Gear != Park) && isBrakePedalOFF) {
    brakesOFF;
    WheelBrakeOFF;
  }


  /*if (Gear == Sonar) {

    //SHIFTING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    Forward;
    setPwm(pwm);

    if (isBrakePedalOFF) {
      WheelBrakeOFF;
      setWheelSpeed(30);
    }

    if (wheelPercent > 80) {
      Left;
    }
    if (wheelPercent < 20) {
      Right;
    }



    //Sensor(TRIGGER_PIN_BL, ECHO_PIN_BL, 3);
    //Sensor(TRIGGER_PIN_BR, ECHO_PIN_BR, 5);
    //Sensor(TRIGGER_PIN_BM, ECHO_PIN_BM, 4);

      if ((2 < distanceFrontMiddle) && (distanceFrontMiddle < 150)) {
        lcd.setCursor(16, 2);
        lcd.print("R");
        setWheelSpeed(30);
        if (canRestart) {
        turn_time = millis();
        canRestart = false;
        }
      }
      if (isBrakePedalOFF) {
        brakesOFF;
        setPwm(pwm);
      }
      if ((millis()-turn_time > 1000) && !canRestart) {
        setWheelSpeed(0);
        canRestart = true;
        lcd.setCursor(16, 2);
        lcd.print(" ");
      }
    } else {
    //lcd.setCursor(16, 2);
    //lcd.print(" ");
    }*/



  //Fek kijelzése
  lcd.setCursor(7, 1);
  if (isBrakePedalON)
    lcd.print("BRAKE");
  else
    lcd.print("     ");

  //Gaz kijelzése
  if (page == 0) {
    gaz_kijelzes(percentage);
  }

  //Biztonsági Park üzemmód
  park_biztonsagi(percentage);

  //Akku feszultseg kijelzése
  float fesz = readVoltage;
  lcd.setCursor(0, 1);
  lcd.print(fesz);
  lcd.print("V ");
}

void wifiWheelSet(int wheelPercent) {
  //setWHEEL
  if (Mode == 1) {
    lcd.setCursor(14, 2);
    lcd.print(wheelPercent);
    lcd.setCursor(14, 0);
    lcd.print(wifiWheelPercent);
    if (wifiWheelPercent - 1 == wheelPercent || wifiWheelPercent + 1 == wheelPercent || wifiWheelPercent - 2 == wheelPercent || wifiWheelPercent + 2 == wheelPercent) {
      setWheelSpeed(0);
      //Wheel Turner
    } else if (wifiWheelPercent > wheelPercent) {
      lcd.setCursor(0, 2);
      lcd.print("RIGHT");
      Right;
      setWheelSpeed(30);
    } else if (wifiWheelPercent < wheelPercent) {
      lcd.setCursor(0, 2);
      lcd.print("LEFT ");
      Left;
      setWheelSpeed(30);
    }
  }
}

#define PB_TIMEOUT 60000
unsigned long int PB_ido;

void park_biztonsagi(unsigned char percentage) {
  unsigned long int eltelt_ido;

  if ((Gear == Park) || (percentage > 0) || (Mode == 1))                       //ha nyomjuk a gázt vagy Parkban vagyunk
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
