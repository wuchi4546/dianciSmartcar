/* FLASH.C - LED Flasher for the Keil MCB251 Evaluation Board */

#include <reg251s.h>                  /* Include 251SB header file */

void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}

void main (void)  {
  unsigned int i;                     /* Delay var */
  unsigned char j;                    /* LED var */

  while (1) {                         /* Loop forever */
    for (j=0x01; j< 0x40; j<<=1)  {   /* Blink LED 0, 1, 2, 3, 4, 5, 6 */
      P1 &= 0x80;                     /* do not change A17 port line   */
      P1 |= j;                        /* Output to LED Port */
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
        wait ();                      /* call wait function */
      }
    }

    for (j=0x40; j> 0x01; j>>=1)  {   /* Blink LED 6, 5, 4, 3, 2, 1 */
      P1 &= 0x80;                     /* do not change A17 port line   */
      P1 |= j;                        /* Output to LED Port */
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
        wait ();                      /* call wait function */
      }
    }
  }
}
