#include "includes.h"

#define SEBVALTO_IDO  500

unsigned long int ido=0;

// ----------------------------------------------------------------------------------------------------
void sebvalto()
{
  // Sebesseg valtas Park-Hatra-Ures-Elore sorrendben
  if ((FEK_NYOMVA) && (SEBVALTO_GOMB_BENYOMVA) && (millis()-ido > SEBVALTO_IDO))
  {
    ido = millis();
    switch (Sebvalto)
    {
      case Park:  Sebvalto = Hatra; 
        break;
      case Ures:  Sebvalto = Elore; 
        break;
      case Elore: Sebvalto = Park; 
        break;
      case Hatra: Sebvalto = Ures; 
        break;
    }
  }


  // Sebvalto allapot kijelzese LCDn
  lcd.setCursor(8,0);
  
  switch (Sebvalto)
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
