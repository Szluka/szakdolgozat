#include "includes.h"

void indexing()
{
  #define PERIODUSIDO     1000    //1 masodperc periodusido
  unsigned char be;
  unsigned long int ido;

  ido =  millis();

  if (ido % PERIODUSIDO < PERIODUSIDO/2)
    be =1;
  else
    be =0;

  //Jobb index beállítása
  lcd.setCursor(18,0);
  if (isIndexSwitchRight)
  {
    Right;
    lcd.setCursor(0,2);
    lcd.print("RIGHT");
    if(be)
    {
      indexRightON;
      lcd.setCursor(18,0);
      lcd.print("->");
    }
    else
    {
      indexRightOFF;
      lcd.setCursor(18,0);
      lcd.print("  ");
    }
  }
  else
  {
    indexRightOFF;
    lcd.setCursor(18,0);
    lcd.print("  ");
  }

   //Bal index beállítása
  lcd.setCursor(0,0);
  if (isIndexSwitchLeft)
  {
    Left;
    lcd.setCursor(0,2);
    lcd.print("LEFT ");
    if(be)
    {
      indexLeftON;
      lcd.setCursor(0,0);
      lcd.print("<-");
    }
    else
    {
      indexLeftOFF;
      lcd.setCursor(0,0);
      lcd.print("  ");
    }
  }
  else
  {
    indexLeftOFF;
    lcd.setCursor(0,0);
    lcd.print("  ");
  }
  
}
