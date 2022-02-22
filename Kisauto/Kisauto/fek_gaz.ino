#include "includes.h"


// ----------------------------------------------------------------------------------------------------
void fek_gaz()
{
//Változók definiálása
  unsigned char szazalek;
  unsigned short int speed,pwm;
  unsigned long int bizti_ido;
  unsigned long int autovalto;
  unsigned char valto;
  unsigned char rogzito; //Ez jegyzi, hogy átléptük-e a ~70%-ot
//--------------------------------------------------------------------------
//Értékek
 #define VALTO_IDO 1000
 #define BIZTI_IDO 250
//Konvertálások
  speed = GAZ_ALLAS;
  szazalek = sebesseg2Szazalek(speed);    // konvertalas szazalekra 0-100
  pwm = sebesseg2pwm(speed);              // konvertalas 8 bitre 0-255
//--------------------------------------------------------------------------
  //Az újra induláshoz fél percet várni kell
      if ((millis() - bizti_ido > BIZTI_IDO) && (pwm < 25))
      {
        FEK_OLDAS;
        FEKLAMPA_KI;
      }
    if (FEK_NYOMVA)   // ha nyomva a fek, nem engedjuk forogni a motort
  {
   pwm = 0;
   // feklampa es PWM beallitasa
    if (pwm <= 10)
    {
    FEKLAMPA_BE;
    FEK_ROGZITES;
      bizti_ido =  millis();
    }
  }
//Kettesre Váltás szükségének vizsgálata  
 
  if ((rogzito == 0) && (pwm > 180)) {
    rogzito = 1;
   autovalto = millis();
                                     }
  //Váltó idő hozzáadása 
   if ((millis() - autovalto > VALTO_IDO) && (pwm > 180) && (rogzito == 1)) {
   valto = 2;
   pwm = pwm;
                                                          }
  //Kettes fokozat
  if (valto == 2) {
   if (pwm < 0) pwm = 0;
   if (pwm > 255) pwm = 255;
                  }
  //Egyes fokozat
  if (pwm < 180) {
  valto = 1;
  pwm = pwm/2;
  rogzito = 0;
  autovalto = millis();
                 }
//-----------------------------------------------------------------------------------------------------------------------
  // Irany es sebesseg beallitasa
  if (Sebvalto == Elore)
  {
	  IRANY_ELORE;
    PWM_BEALLITASA(pwm);
    TOLATOLAMPA_KI;
  }
  
  if (Sebvalto == Hatra)
  {
	  IRANY_HATRA;
    PWM_BEALLITASA(pwm);
    TOLATOLAMPA_BE;
  }

  if ((Sebvalto == Park) || (Sebvalto == Ures))
  {
    PWM_BEALLITASA(0);    // motor letiltva
    TOLATOLAMPA_KI;
  }

  // Fek beallitasa
  if ((Sebvalto == Park) || FEK_NYOMVA)
    FEK_ROGZITES;
  else
    FEK_OLDAS;

  // Fek kijelzese
  lcd.setCursor(8,1);
  if (FEK_NYOMVA)
    lcd.print("FEK");
  else
    lcd.print("   ");
 
  // Valto kijelzese
  if (valto == 1) {
    lcd.setCursor(16,0);
  lcd.print("1");
  }
  else { 
   lcd.setCursor(16,0);
  lcd.print("2");
  }
    
  // Gaz kijelzese
  gaz_kijelzes(szazalek); 
   
  // Biztonsági Park üzemmód
  park_biztonsagi(szazalek);

 // Akku feszultseg kijelzese
  float fesz = AKKU_FESZ_ERTEK;
  lcd.setCursor(0,1);
  lcd.print(fesz);
  lcd.print("V ");
}
 
 
#define PB_TIMEOUT 30000                                         // Ennyi gáz inaktivitás után visszaállunk Parkba
unsigned long int PB_ido;                                        // Időbélyeg a gázpedál figyelésére

void park_biztonsagi(unsigned char szazalek)
{
  unsigned long int eltelt_ido;

  if ((Sebvalto == Park) || (szazalek>0))                       // ha nyomjuk a gázt vagy Parkban vagyunk
    PB_ido=millis();                                            // lementjük az időbélyeget

  eltelt_ido=millis()-PB_ido;                                   // Meghatarozzuk az eltelt idot
                                                                // Az utolso gazlenyomas ota
  if (eltelt_ido>PB_TIMEOUT)                                    // Ha ez nagyobb 
    Sebvalto=Park;                                              // Parkba kapcsol
}


// Gaz kijelzese
void gaz_kijelzes(unsigned char szazalek) //elvileg sikerült átírni a gazkijelző csíkot
{/*
<<<<<<< HEAD
    lcd.setCursor(7,2);
    lcd.print(szazalek);
    lcd.print("%  ");
    lcd.setCursor(0,3);
    for(int v=0;v<=100;v=v+5)
    {
      if(v < szazalek)
      
      lcd.print("#");
      else
      lcd.print(" ");
     
    }
//======= */
  unsigned char  v;
  
  lcd.setCursor(8,2);
  lcd.print(szazalek);
  lcd.print("%  ");
  
  lcd.setCursor(0,3);
  for(v=5;v<=100;v=v+5)
  {
   if (v<=szazalek)
   lcd.write((uint8_t)255);   // tele karakter
   else
   lcd.print(" ") ;
  }
//>>>>>>> 41b6b66fd67227e0bb1270f075f0278db292c275
}

