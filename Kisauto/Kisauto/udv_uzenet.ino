/* #include "includes.h"


void   Udvozlo_Uzenet()
{ 
    lcd.setCursor(4,1);
    lcd.print("Hello Edison");
    lcd.setCursor(8,2);
    lcd.print("Klub");
    lcd.setCursor(5,3);
    lcd.print("I        I"); //loading bar szélei.
    lcd.setCursor(6,3);
      lcd.print("#       ");  //loading bar animálása, for ciklus nélkül nagyon csúnya, bocsi.
      delay(200);
      lcd.print("##      ");
      delay(200);
      lcd.print("###     ");
      delay(200);
      lcd.print(" ###    ");
      delay(200);
      lcd.print("  ###   ");
      delay(200);
      lcd.print("   ###  ");
      delay(200);
      lcd.print("    ### ");
      delay(200);
      lcd.print("     ###");
      delay(200);
      lcd.print("      ##");
      delay(200);
      lcd.print("       #");
      delay(200);
      lcd.print("--------");
      delay(200);
  lcd.clear();
    lcd.setCursor(4,1);        //A system rady kiiratása, mosolygós arccal, 3mp-re.
    lcd.print("System Ready");
    lcd.setCursor(6,2);
    lcd.print("^__^");
    delay(2500);
  lcd.clear();
}

*/

#include "includes.h"


void   Udvozlo_Uzenet()
{ 
  
  
    lcd.setCursor(4,1);
    lcd.print("Hello Edison");
    lcd.setCursor(8,2);
    lcd.print("Klub");
    lcd.setCursor(5,3);
    lcd.print("I        I");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("#       ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("##      ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("###     ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print(" ###    ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("  ###   ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("   ###  ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("    ### ");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("     ###");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("      ##");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("       #");
    delay(250);
    lcd.setCursor(6,3);
    lcd.print("        ");
    delay(250);
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("System Ready");
  lcd.setCursor(8,2);
  lcd.print("^__^");
  delay(3000);
  lcd.clear();
}
