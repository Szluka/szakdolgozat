#include "includes.h"

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define SENSOR_TIMEOUT 500
unsigned long int Sensor_ido;

int Sensor() {
    unsigned int uS = 0;
    unsigned long int eltelt_ido;

    /*eltelt_ido = millis() - Sensor_ido;
    if (eltelt_ido > SENSOR_TIMEOUT) {*/
    uS = sonar.ping();

    signed int cm = uS / US_ROUNDTRIP_CM;
    lcd.setCursor(14, 1);
    lcd.print(cm);
    lcd.print("cm  ");
    return cm;
    //}
}
