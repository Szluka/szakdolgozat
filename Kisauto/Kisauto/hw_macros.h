#include "hardware.h"

// Ebben a fileban vannak a hardware hozzaferest biztosito makrok
// Ezek hasznalhatok a program egyszeru megirasahoz


// Kimenetek kiosztasa - makrok 
#define IRANY_ELORE       digitalWrite(IRANY_PIN, HIGH)
#define IRANY_HATRA       digitalWrite(IRANY_PIN, LOW)

#define PWM_BEALLITASA(x) analogWrite(PWM_PIN, x)

// Relek kiosztasa - makrok 
#define INDEX_B_BE        digitalWrite(RELE1_PIN, LOW)
#define INDEX_B_KI        digitalWrite(RELE1_PIN, HIGH)

#define INDEX_J_BE        digitalWrite(RELE2_PIN, LOW)
#define INDEX_J_KI        digitalWrite(RELE2_PIN, HIGH)

#define FEK_OLDAS         digitalWrite(RELE3_PIN, LOW)
#define FEK_ROGZITES      digitalWrite(RELE3_PIN, HIGH)

#define TOLATOLAMPA_BE    digitalWrite(RELE4_PIN, LOW)
#define TOLATOLAMPA_KI    digitalWrite(RELE4_PIN, HIGH)

#define FEKLAMPA_BE      digitalWrite(RELE5_PIN, LOW)
#define FEKLAMPA_KI      digitalWrite(RELE5_PIN, HIGH)


// Analog bementek lekerdezese
#define FEK_NYOMVA        (analogRead(FEK_KAPCSOLO) > 512)
#define AKKU_FESZ_ERTEK   (((float)(analogRead(AKKU_FESZ)) * (1.0 + 6.2/1.2) * 5.0)/1023.0)
#define GAZ_ALLAS   	  (analogRead(SEBESSEG_POTI))

// Digitalis bementek lekerdezese
#define INDEX_BE_BALRA		(digitalRead(INDEX_B_BEMENET) == 0)
#define INDEX_BE_JOBBRA		(digitalRead(INDEX_J_BEMENET) == 0)
#define SEBVALTO_GOMB_BENYOMVA	(digitalRead(SEBVALTO_BEMENET) == 0)

