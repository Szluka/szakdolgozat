#include "includes.h"	//a szukseges fileok betoltese


//Tesztelo rutin, kiirja a kijelzore az osszes bemenet erteket
//-------------------------------------------------------------

void teszteles()
{
  unsigned short int speed=0;
  
  lcd.setCursor(5,0);
  lcd.print("TESZT UZEM");

  //Analog Sebesseg kijelzése
  lcd.setCursor(4,1);
  speed = readGasPedal;
  lcd.print("SEB=");
  lcd.print(speed);
  lcd.print("  ");
  lcd.print(speed_2_percentage(speed));
  lcd.print("%  ");

  //index jobb
  lcd.setCursor(18,0);
  if (isIndexSwitchRight)
    lcd.print("->");
  else 
    lcd.print("  ");
 
  //index bal
  lcd.setCursor(0,0);
  if (isIndexSwitchLeft)
    lcd.print("<-");
  else 
    lcd.print("  ");

  //Akku feszultseg kijelzése
  float fesz = readVoltage;
  lcd.setCursor(4,2);
  lcd.print("AKKU: ");
  lcd.print(fesz);
  lcd.print("V ");
 
  //Fek kijelzése
  lcd.setCursor(0,3);
  if (isBrakePedalON)
    lcd.print("FEK");
  else
    lcd.print("   ");

  //Gear nyomogomb
  lcd.setCursor(16,3);
  if (isGearSwitch)
    lcd.print("SEBV");
  else
    lcd.print("    ");
  
}
