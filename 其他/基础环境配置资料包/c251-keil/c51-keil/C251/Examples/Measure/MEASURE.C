/******************************************************************************/
/*                                                                            */
/*      MEASURE.C:  Remote Measurement Recorder using the C251 COMPILER       */
/*                                                                            */
/******************************************************************************/

#if __C251__ >= 200                                               
#define CONST  const   /* for C251 Version 2: place constants into const area */
#define NEAR   near    /* for C251 Version 2: near variables into near space  */
#else
#define CONST  code    /* for C251 Version 1: place constants into code space */
#define NEAR   xdata   /* for C251 Version 1: near variables into xdata space */
#endif


char CONST menu[] = 
   "\n"
   "+*********** REMOTE MEASUREMENT RECORDER using C251 ***********+\n"
   "| This program is a simple Measurement Recorder. It is based   |\n"
   "| on the 80251A1 CPU and records the state of Port1 and Port3  |\n"
   "| and the voltage on the four analog inputs AN0 through AN3.   |\n"
   "+ command -+ syntax -----+ function ---------------------------+\n"
   "| Read     | R [n]       | read <n> recorded measurements      |\n"
   "| Display  | D           | display current measurement values  |\n"
   "| Time     | T hh:mm:ss  | set time                            |\n"
   "| Interval | I mm:ss.ttt | set interval time                   |\n"
   "| Clear    | C           | clear measurement records           |\n"
   "| Quit     | Q           | quit measurement recording          |\n"
   "| Start    | S           | start measurement recording         |\n"
   "+----------+-------------+-------------------------------------+\n";

#include <stdio.h>                       /* standard I/O .h-file              */
#include <stdlib.h>                      /* standard library .h-file          */
#ifdef c251a1
#include <reg251a1.h>                    /* special function register 80251A1 */
#else
#include <reg251s.h>                     /* special function register 80251SB */
#endif
#include <ctype.h>                       /* character functions               */

struct clock {                           /* structure of the clock record     */
  unsigned char    hour;                 /* hour                              */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milliseconds                      */
};

struct mrec  {                           /* structure for measurement records */
  struct   clock   time;                 /* time of measurement               */
  unsigned char   port1;                 /* state of port 1                   */
  unsigned char   port3;                 /* state of port 3                   */
#ifdef c251a1
  unsigned char  analog [4];             /* voltage on analog Pins AN0 .. AN3 */
#endif
};

struct interval  {                       /* structure for interval record     */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milli second                      */
};
                                            /* external functions: input line */
extern void getline (char idata *, unsigned char n);
extern void measure_display (struct mrec d);/*           display measurements */
extern void set_time (char * buffer);       /*           set current time     */
extern void set_interval (char * buffer);   /*           set interval time    */

struct interval setinterval;                /* interval setting values        */
struct interval interval;                   /* interval counter               */

unsigned char intcycle = 0;                 /* Interrupt cycle counter        */

bit measurement_interval = 0;               /* measurement interval over      */
bit mdisplay = 0;                           /* measurement display requested  */
bit startflag = 0;                          /* start measurement recording    */

struct mrec current;                        /* current measurements           */

#define XRAM    8192                        /* size of RAM is 8 KBytes        */
#define SCNT  XRAM / sizeof (current)       /* number of records in XDATA RAM */

struct mrec NEAR save_record [SCNT];        /* buffer for measurements        */
unsigned int sindex;                        /* save index                     */
unsigned int savefirst;                     /* save first index               */

char CONST ERROR [] = "\n*** ERROR: %s\n";  /* ERROR message string in code   */

#define PERIOD     -250                     /* 250 usec interrupt period      */
#define WRONGINDEX 0xffff                   /* error signal for wrong index   */


/* 
 * The following function is called from the interrupt service routine.  This
 * means that the code must be generated in the same Register Bank as the
 * interrupt service function.
 */
#pragma REGISTERBANK (1)                    /* use Register Bank 1 for coding */

/******************************************************************************/
/*               Save current measurements in save_record                     */
/******************************************************************************/
void save_measurements (void) {
  save_record[sindex++] = current;             /* copy current measurements   */
  if (sindex == SCNT) sindex = 0;              /* check bounds of sindex      */
  if (sindex == savefirst)  {                  /* check circular buffer limits*/
    if (++savefirst == SCNT)  savefirst = 0;   /* check bounds of savefirst   */
  }
}


/******************************************************************************/
/*                Timer 0 interrupt service function                          */
/*                executes each 250us @ 12 MHz Crystal Clock                  */
/******************************************************************************/
void timer0(void) interrupt 1 using 1 {   /* Int Vector at 000BH, Reg Bank 1  */
#ifdef c251a1
  unsigned char i;
#endif
  if (measurement_interval)  {                 /* measurement done ?          */
    save_measurements ();                      /* yes -> save measurements    */
    measurement_interval = 0;                  /* Save measurements done      */
  }

  if (++intcycle == 4)  {                      /* 1 msec = 4 * 250 usec cycle */
    intcycle = 0;
                                               /* check if interval is over   */
    if (interval.min  == 0 && 
        interval.sec  == 0 && 
        interval.msec == 0     )  {
      interval = setinterval;                  /* set interval time again     */
      measurement_interval = startflag;        /* determine measurement flag  */
    }
    else  {                                    /* update interval time        */
      if (interval.msec-- == 0)  {             /* calculate millisecond       */
        interval.msec = 999;
        if (interval.sec-- == 0)  {            /* calculate second            */
          interval.sec = 59;
          interval.min--;                      /* calculate minute            */
        }
      }
    }
                                               /* update current time         */
    if (++current.time.msec == 1000)  {        /* update millisecond cnt      */
      current.time.msec = 0;

      if (++current.time.sec == 60)  {         /* update second counter       */
        current.time.sec = 0;

        if (++current.time.min == 60)  {       /* update minute counter       */
          current.time.min = 0;

          if (++current.time.hour == 24)  {    /* update hour counter         */
            current.time.hour = 0;
          }
        }
      }
    }	/* end of if( ++current.time.msec... */

    if (measurement_interval || mdisplay)  {   /* process measurement         */
      current.port1 = P1;                      /* read port 4                 */
      current.port3 = P3;                      /* read port 5                 */
#ifdef c251a1
      for (i = 0; i != 4; i++)  {              /* loop for 4 A/D inputs       */
        ADCON = i | 0x08;                      /* select A/D input            */
        while (ADCON & 0x08);                  /* wait for A/D result         */
        current.analog[i] = ADAT;              /* result of A/D process       */ 
      }
#endif
      mdisplay = 0;                            /* mdisplay = 0 for ready sig. */
    }
  }
}


/* 
 * The following functions are called from the main routine.  Therefore
 * Register Bank 0 must be used when coding these functions.
 */

#pragma REGISTERBANK (0)                    /* use Register Bank 0 for coding */
/******************************************************************************/
/*                       Calculate first Read Index                           */
/******************************************************************************/
unsigned int read_index (char *buffer) {
  int index = 0;
  unsigned char args;

  if (setinterval.min == 0     &&              /* check if setinterval is     */
      setinterval.sec == 0     &&              /* below 1 second and          */
      setinterval.msec < 999   &&              /* measurements are collected  */
      startflag                   )  {         
    printf (ERROR, "QUIT MEASUREMENTS BEFORE READ");
    return (WRONGINDEX);                       /* no display on the fly if    */
  }                                            /* interval time < 1 second    */
  args = sscanf (buffer, "%d", &index);        /* scan input for read count   */
  if (args == 0  ||  index == 0  || args == (unsigned char) EOF) index = SCNT-1;
  index = sindex - index;                      /* calculate first read index  */
  if (index < 0) index += SCNT;                /* from read count             */
  return (index);
}
  

/******************************************************************************/
/*                         Clear Measurement Records                          */
/******************************************************************************/
void clear_records (void) {
  unsigned int idx;                            /* index for loop              */

  startflag = 0;                               /* stop measurement collecting */
  sindex = savefirst = 0;                      /* reset circular buffer index */
  for (idx = 0; idx != SCNT; idx++)  {         /* mark all records unused     */
    save_record[idx].time.hour = 0xff;         /* unused flag: hour = 0xff    */
  }     
}

#ifdef MCB251
extern bit instat (void);
#endif

/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
void main ( void )  {                          /* main entry for program      */
  char idata cmdbuf [15];                      /* command input buffer        */
  unsigned char i;                             /* index for command buffer    */
  unsigned int idx;                            /* index for circular buffer   */

#ifndef MCB251
  /* initialize the serial interface */
  SCON  = 0x50;                   /* SCON: mode 1, 8-bit UART, enable rcvr    */
  TMOD |= 0x20;                   /* TMOD: timer 1, mode 2, 8-bit reload      */
  TH1   = 0xf3;                   /* TH1:  reload value for 2400 baud         */
  TR1   = 1;                      /* TR1:  timer 1 run                        */
  TI    = 1;                      /* TI:   set TI to send first char of UART  */
#endif

  /* setup the timer 0 interrupt */
  TH0 = PERIOD;                                /* set timer period            */
  TL0 = PERIOD;
  TMOD = TMOD | 0x02;                          /* select mode 2               */
  TR0 = 1;                                     /* start timer 0               */
  ET0 = 1;                                     /* enable timer 0 interrupt    */
  EA  = 1;                                     /* global interrupt enable     */

  clear_records ();                            /* initialize circular buffer  */
  printf ( menu );                             /* display command menu        */
  while (1)  {                                 /* loop forever                */
    printf ("\nCommand: ");                    
    getline (&cmdbuf[0], sizeof (cmdbuf));     /* input command line          */

    for (i = 0; cmdbuf[i] != 0; i++)  {        /* convert to upper characters */
      cmdbuf[i] = toupper(cmdbuf[i]);
    }

    for (i = 0; cmdbuf[i] == ' '; i++);        /* skip blanks                 */

    switch (cmdbuf[i])  {                      /* proceed to command function */

      case 'R':                                /* Read circular Buffer        */
        if ((idx = read_index (&cmdbuf[i+1])) == WRONGINDEX)  break;
        while (idx != sindex)  {               /* check end of table          */
#ifdef MCB251
          if (instat ())                       /* check serial interface      */
#else
          if (RI)                              /* check serial interface      */
#endif
          {
            if (_getkey() == 0x1B) break;      /* for escape character        */
          }
          if (save_record[idx].time.hour != 0xff)  {
            measure_display (save_record[idx]);      /* display record        */
            printf ("\n");
          }
          if (++idx == SCNT) idx = 0;          /* next circular buffer entry  */
        }
        break;

      case 'T':                                /* Enter Current Time          */
        set_time (&cmdbuf[i+1]);
        break;

      case 'I':                                /* Enter Interval Time         */
        set_interval (&cmdbuf[i+1]);
        break;

      case 'D':                                /* Display Command             */
        printf ("\nDisplay current Measurements: (ESC to abort)\n");
        do  {                                  
#ifdef MCB251
          while (! instat ())                  /* check serial interface      */
#else
          while (! RI)                         /* check serial interface      */
#endif
          {
            mdisplay = 1;                      /* request measurement         */
            while (mdisplay);                  /* wait for measurement        */
            measure_display (current);         /* display values              */
          }
        } while (_getkey () != 0x1b);          /* escape terminates command   */
        printf ("\n\n");
        break;

      case 'S':                                /* Start Command               */
        printf ("\nStart Measurement Recording\n");
        startflag = 1;
        break;

      case 'Q':                                /* Quit Command                */
        printf ("\nQuit Measurement Recording\n");
        startflag = 0;
        break;

      case 'C':                                /* Clear Command               */
        printf ("\nClear Measurement Records\n");
        clear_records ();
        break;

      default:                                 /* Error Handling              */
        printf (ERROR, "UNKNOWN COMMAND");
        printf (menu);                         /* display command menu        */
        break;
    }
  }
}

