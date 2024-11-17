#pragma DEBUG CODE                /* pragma lines can contain C251 command    */
                                  /* line directives                          */
 
#include <reg251s.h>              /* special function register declarations   */
                                  /* for the intended 80251 derivative        */

#include <stdio.h>                /* prototype declarations for I/O functions */


/****************/
/* main program */
/****************/
void main (void)  {               /* execution starts here after stack init   */
#ifndef MCB251


  SCON  = 0x50;                   /* SCON: mode 1, 8-bit UART, enable rcvr    */
  TMOD |= 0x20;                   /* TMOD: timer 1, mode 2, 8-bit reload      */
  TH1   = 0xf3;                   /* TH1:  reload value for 2400 baud         */
  TR1   = 1;                      /* TR1:  timer 1 run                        */
  TI    = 1;                      /* TI:   set TI to send first char of UART  */
#endif

  printf ("Hello World\n");       /* the 'printf' function call               */

  while (1) {                     /* An embedded program does not stop and    */
    ;  /* ... */                  /* never returns.  We've used an endless    */
  }                               /* loop.  You may wish to put in your own   */
}                                 /* code were we've printed the dots (...).  */
