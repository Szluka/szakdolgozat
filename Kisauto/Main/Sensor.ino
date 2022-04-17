#include "includes.h"

//#define SENSOR_TIMEOUT 500
//unsigned long int Sensor_ido;

int Sensor(int trigger, int echo, int pos) {
  unsigned int uS = 0;
  unsigned long int eltelt_ido;

  NewPing sonar(trigger, echo, MAX_DISTANCE);

  /*eltelt_ido = millis() - Sensor_ido;
    if (eltelt_ido > SENSOR_TIMEOUT) {*/
  uS = sonar.ping();

  signed int cm = uS / US_ROUNDTRIP_CM;

  if (page == 1) {
    switch (pos)
    {
      case 0:
        lcd.setCursor(0, 2);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
      case 1:
        lcd.setCursor(7, 2);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
      case 2:
        lcd.setCursor(14, 2);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
      case 3:
        lcd.setCursor(0, 3);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
      case 4:
        lcd.setCursor(7, 3);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
      case 5:
        lcd.setCursor(14, 3);
        lcd.print(cm);
        lcd.print("cm  ");
        break;
    }
  }

  return cm;
  //}
}
