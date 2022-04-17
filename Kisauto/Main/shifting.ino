#include "includes.h"

#define SEBVALTO_IDO  500

unsigned long int ido = 0;


void sebvalto()
{
  //Sebesseg valtas Park-Hatra-Ures-Elore sorrendben
  if ((isBrakePedalON) && (isGearSwitch) && (millis() - ido > SEBVALTO_IDO))
  {
    ido = millis();
    switch (Gear)
    {
      case Park:
        Gear = Elore;
        break;
      case Elore:
        Gear = Ures;
        break;
      case Ures:
        Gear = Hatra;
        break;
      case Hatra: 
        Gear = Park;
        break;
    }
  }


  //Gear allapot kijelzése LCDn
  lcd.setCursor(8, 0);

  switch (Gear)
  {
    case Park:  lcd.print("PARK ");
      break;
    case Ures:  lcd.print("URES ");
      break;
    case Elore: lcd.print("ELORE");
      break;
    case Hatra: lcd.print("HATRA");
      break;
  }
}
