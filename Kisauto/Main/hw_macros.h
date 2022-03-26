#include "hardware.h"

//Magyar nyelvű változónevek átírása angolra

//Kimenetek kiosztasa - makrok
#define Forward       digitalWrite(DirectionOfRotation, HIGH)
#define Backward      digitalWrite(DirectionOfRotation, LOW)
#define Left          digitalWrite(DirWheel, HIGH)
#define Right         digitalWrite(DirWheel, LOW)

#define setPwm(x)       analogWrite(PWM_PIN, x)
#define setWheel(y)       analogWrite(PWM_WHEEL, y)

//Relek kiosztasa - makrok
#define indexLeftON        digitalWrite(RELE1_PIN, LOW)
#define indexLeftOFF        digitalWrite(RELE1_PIN, HIGH)

#define indexRightON        digitalWrite(RELE2_PIN, LOW)
#define indexRightOFF        digitalWrite(RELE2_PIN, HIGH)

#define brakesOFF         digitalWrite(RELE3_PIN, LOW)
#define brakesON      digitalWrite(RELE3_PIN, HIGH)

#define RELE_4_LOW   digitalWrite(RELE4_PIN, LOW)
#define RELE_5_HIGH    digitalWrite(RELE4_PIN, HIGH)

#define WheelBrakeOFF      digitalWrite(RELE5_PIN, LOW)
#define WheelBrakeON      digitalWrite(RELE5_PIN, HIGH)


//Analog bementek lekerdezese
#define isBrakePedalON        (analogRead(BrakePedal) > 512)
#define isBrakePedalOFF       (analogRead(BrakePedal) <= 512)
#define readVoltage   (((float)(analogRead(Voltage)) * (1.0 + 6.2/1.2) * 5.0)/1023.0)
#define readGasPedal      (analogRead(gasPotentiometer))

//Digitalis bementek lekerdezese
#define isIndexSwitchLeft        (digitalRead(indexLeft) == 0)
#define isIndexSwitchRight        (digitalRead(indexRight) == 0)
#define isGearSwitch    (digitalRead(GearSwitch) == 0)
