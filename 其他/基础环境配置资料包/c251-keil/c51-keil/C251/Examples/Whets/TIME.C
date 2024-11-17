#pragma WARNINGLEVEL (0)

#ifdef __C251__
#include <reg251s.h>
#else
#include <reg51.h>
#endif

/* TIME.C: time Function for DHRYSTONE and WHEATSTONE Benchmarks  */

long timeval;

timerint () interrupt 1 {
  TH0 = -250;             /* 125 Hz at 12 MHz 8051 / 251 */
  timeval++;
}

long time (long *t)  {
  long tval;
  EA   = 0;
  tval = timeval;
#ifdef __C251__
  IE0  = 0x82;
#else
  IE   = 0x82;
#endif
  TR0  = 1;
  return (tval);
}


initserial ()  {
#ifndef MCB251
  SCON = 0x52;    /* SCON */
  TMOD = 0x20;    /* TMOD */
  TCON = 0x69;    /* TCON */
  TH1 =  0xf3;    /* TH1 */
#endif
}

