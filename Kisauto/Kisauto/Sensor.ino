#include "includes.h"

unsigned long int timer=0;
//--------------------------------------------------------------------------------------------------
void Sensor() {
#define Jelhossz 10 //Az ultrahang kibocsájtása ms-ben (1s = 1000ms)
#define HCM      20 //A határérték cm-ben
long duration;
long tav;
  digitalWrite(TRIG_PIN, HIGH);
 timer = millis();
 if (millis() >= timer + Jelhossz)
 {
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
tav = duration/58.2;
if (tav <= HCM) 
  {
    FEK_ROGZITES;
  }
 else 
  {
    FEK_OLDAS;
  }
 }
}
