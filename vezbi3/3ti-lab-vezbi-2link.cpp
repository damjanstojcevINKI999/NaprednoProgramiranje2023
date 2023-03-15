#include <stdio.h> /* puts, printf */
#include <time.h> /* time_t, struct tm, time, localtime */

// Damjan Stojcev INKI999


int main ()
{
time_t rawtime; // Deklarira promenliva koja prima tocno vreme(rawtime)
struct tm * timeinfo; // deklarira pointer za stuktura za skladiranje na vremeto

// go zema tocno sega vreneto i go pretvora vo localno vreme vo nashata zona
time (&rawtime); //tocno vreme vo sekundi
timeinfo = localtime (&rawtime); // Go konvertira tocnoto vremeto spored nasata zona

// Pecati tocno veme i data
printf ("Current local time and date: %s", asctime(timeinfo)); // asctime() Konvertira string vo formatot "Den Mesec Data Vreme"

return 0;
}