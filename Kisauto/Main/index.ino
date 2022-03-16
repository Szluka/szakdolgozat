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
    if(be)
    {
      indexRightON;
      lcd.print("->");
    }
    else
    {
      indexRightOFF;
      lcd.print("  ");
    }
  }
  else
  {
    indexRightOFF;
    lcd.print("  ");
  }

   //Bal index beállítása
  lcd.setCursor(0,0);
  if (isIndexSwitchLeft)
  {
    if(be)
    {
      indexLeftON;
      lcd.print("<-");
    }
    else
    {
      indexLeftOFF;
      lcd.print("  ");
    }
  }
  else
  {
    indexLeftOFF;
    lcd.print("  ");
  }
  
}
