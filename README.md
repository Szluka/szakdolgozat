# szakdolgozat

## 3.0.0 ##
  - A gokartra felkerült 4 HR-SR05-ös szonár, amelyek folyamatos méréssel biztosítják, hogy ne ütközhessen. 80 cm-en belül autómatikus vékezi a mozgásban lévő járművet.
  - Az ESP8266-os Wifi modul is bekötésre került, mely kapcsolatot biztosít egy megadott hálózattal. Jelenleg a biztonság miatt csak az én telefonommal kommunikál, és ennek hiányában nem is bootol be az autó. A Blynk Iot alkamlmazás segítségével válthatunk "MANUAL", azaz kézi, és "REMOTE" avagy távoli vezérlések között. MANUAL üzemmódban az autó csak a fizikai inputokat veszi figyelembe, ezzel megőrízve az eredeti funkcionalitását. Távoli vezérlés során lehetőségünk van kezelni a kormányt, a gázpedált, valamint két üzemmód közül választhatunk, ezek az ELŐRE és HÁTRA. A kormányszög leolvasása érdekében, egy potméterről olvassa le az Arduino Mega, hogy éppen merre is van eltekerve a kormány, és ennek segítségével tudja irányítani. Az üzemmódváltó gomb egyszeri lenyomása "lapoz" a kijelzőn, így nem csak a gázállást láthatjuk az alsó két sorban, hanem a szonárok által mért távolságokat is.

## 2.1.0 ##
  A HR-SR05-ös szonár ideiglenesen helyet foglal az autó orrán, és ELŐRE menetben 50 cm belül megállítja az autót, és addig nem engedi az újabb gáz adást, amíg az akadály meg nem szűnik, vagy üzemmód váltlás történik.

## 2.0.0 ##
  A kód teljes logikai felüldefiniálása, változó- és függvénynevek angol nyelvre való átírása, használaton kívüli funkciók megszűntetése

## 1.0.0 ##
  A 2017 szeptemberi verzió
