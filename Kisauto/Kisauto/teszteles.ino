#include "includes.h"	// a szukseges fileok betoltese


// Tesztelo rutin, kiirja a kijelzore az osszes bemenet erteket
// -------------------------------------------------------------

void teszteles()
{
  unsigned short int speed=0;
  
  lcd.setCursor(5,0);
  lcd.print("TESZT UZEM");

  // Analog Sebesseg kijelzese
  lcd.setCursor(4,1);
  speed = GAZ_ALLAS;
  lcd.print("SEB=");
  lcd.print(speed);
  lcd.print("  ");
  lcd.print(sebesseg2Szazalek(speed));
  lcd.print("%  ");

  // index jobb
  lcd.setCursor(18,0);
  if (INDEX_BE_JOBBRA)
    lcd.print("->");
  else 
    lcd.print("  ");
 
  // index bal
  lcd.setCursor(0,0);
  if (INDEX_BE_BALRA)
    lcd.print("<-");
  else 
    lcd.print("  ");

  // Akku feszultseg kijelzese
  float fesz = AKKU_FESZ_ERTEK;
  lcd.setCursor(4,2);
  lcd.print("AKKU: ");
  lcd.print(fesz);
  lcd.print("V ");
 
  // Fek kijelzese
  lcd.setCursor(0,3);
  if (FEK_NYOMVA)
    lcd.print("FEK");
  else
    lcd.print("   ");

  // Sebvalto nyomogomb
  lcd.setCursor(16,3);
  if (SEBVALTO_GOMB_BENYOMVA)
    lcd.print("SEBV");
  else
    lcd.print("    ");
  
}
