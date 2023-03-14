//  Ognen Nikolovski INKI997 - Објаснување 
/* difftime example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
// Библиотеката stdio.h ја користиме за printf() функцијата 
// Библиотеката time.h за функциите и структурите поврзани со времето.
int main ()
{
  time_t now; // Типот time_t се користи за складирање на бројот на секунди од 1 јануари 1970 година.
  struct tm newyear; // Типот struct tm се користи за претставување на време во формат што е почитлив за луѓето со полиња како година, месец, ден, час, минута и секунда.
  double seconds;

  time(&now);  /* get current time; same as: now = time(NULL)  */

  newyear = *localtime(&now); // Со користење на localtime() функцијата, time_t вредноста се конвертира во struct tm објект кој ги содржи информациите за времето во локалниот временски појас.

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;
  /* Во примерот, struct tm објектот за нова година се креира со поставување на часот,
  минутите и секундите на почетокот на денот, на првиот јануари. Исто така, месецот и денот се поставени на 0, што означува прв месец - јануари. */

  seconds = difftime(now,mktime(&newyear));
// Со користење на функцијата mktime(), struct tm објектот за нова година се конвертира во time_t вредност.
// Се користи функцијата difftime() за да се избројат секундите помеѓу моменталното време и почетокот на новата година. Резултатот се прикажува на екран преку printf() функцијата.
  printf ("%.f seconds since new year in the current timezone.\n", seconds);

  return 0;
}