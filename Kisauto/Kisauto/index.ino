#include "includes.h"


// Index mukodteto kod
// ----------------------------------------------------------------------------------------------------
void index()
{
  #define PERIODUSIDO     1000    // 1 masodperc periodusido
  unsigned char be;
  unsigned long int ido;

  ido =  millis();

  if (ido % PERIODUSIDO < PERIODUSIDO/2)
    be =1;
  else
    be =0;

  // Jobb index beallitasa
  lcd.setCursor(18,0);
  if (INDEX_BE_JOBBRA)
  {
    if(be)
    {
      INDEX_J_BE;
      lcd.print("->");
    }
    else
    {
      INDEX_J_KI;
      lcd.print("  ");
    }
  }
  else
  {
    INDEX_J_KI;
    lcd.print("  ");
  }

   // Bal index beallitasa
  lcd.setCursor(0,0);
  if (INDEX_BE_BALRA)
  {
    if(be)
    {
      INDEX_B_BE;
      lcd.print("<-");
    }
    else
    {
      INDEX_B_KI;
      lcd.print("  ");
    }
  }
  else
  {
    INDEX_B_KI;
    lcd.print("  ");
  }
  
}
