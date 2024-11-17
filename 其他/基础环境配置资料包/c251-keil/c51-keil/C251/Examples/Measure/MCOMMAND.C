/******************************************************************************/
/*                                                                            */
/*     MCOMMAND.C:  Time Set Commands for the Remote Measurement Recorder     */
/*                                                                            */
/******************************************************************************/

#if __C251__ >= 200                                               
#define CONST  const   /* for C251 Version 2: place constants into const area */
#define NEAR   near    /* for C251 Version 2: near variables into near space  */
#else
#define CONST  code    /* for C251 Version 1: place constants into code space */
#define NEAR   xdata   /* for C251 Version 1: near variables into xdata space */
#endif


#include <stdio.h>                       /* standard ANSI I/O .h-file         */
#ifdef c251a1
#include <reg251a1.h>                    /* special function register 80251A1 */
#else 
#include <reg251s.h>                     /* special function register 80251SB */
#endif
struct clock {                           /* structure of the clock record     */
  unsigned char    hour;                 /* hour                              */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milli second                      */
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
  unsigned int     msec;                 /* millisecond                       */
};


extern char CONST ERROR [];              /* ERROR message string              */
extern struct mrec current;              /* current measurements              */
extern struct interval setinterval;      /* interval setting values           */
extern struct interval interval;         /* interval counter                  */



/******************************************************************************/
/*                           Display measurements                             */
/******************************************************************************/
void measure_display (struct mrec display)  {    
#ifdef c251a1
  unsigned char i;                       /* index count for AN0 - AN3         */
#endif
#if __C251__ >= 200
  printf ("\rTime: %2d:%02d:%02d.%03d  P1:%02X P3:%02X ",
#else
  printf ("\rTime: %2bd:%02bd:%02bd.%03d  P1:%b02X P3:%b02X ",
#endif
           display.time.hour,            /* display hour                      */
           display.time.min,             /* display minute                    */
           display.time.sec,             /* display second                    */
           display.time.msec,            /* display millisecond               */
           display.port1,                /* display port 1 value              */
           display.port3);               /* display port 3 value              */
#ifdef c251a1
  for (i = 0; i != 4; i++)  {            /* display AN0 through AN3           */
#if __C251__ >= 200
    printf (" AN%d:%4.2fV", i, (float) display.analog[i] * 5.0 / 256);
#else
    printf (" AN%bd:%4.2fV", i, (float) display.analog[i] * 5.0 / 256);
#endif
  }
#endif
}


/******************************************************************************/
/*                           Set Current Time                                 */
/******************************************************************************/
void set_time (char * buffer)
{
  struct clock time;                     /* temporary time values             */
  unsigned char args;                    /* number of arguments               */

  time.sec = 0;                          /* preset seconds...                 */
  time.msec = 0;                         /* ...and milliseconds               */
  args = sscanf (buffer, "%bd:%bd:%bd",  /* scan input line for               */
                 &time.hour,             /* hour, minute and second           */
                 &time.min,
                 &time.sec);
  if (time.hour > 23  ||  time.min > 59  ||    /* check for valid inputs      */
      time.sec > 59   ||  args < 2       ||  args == (unsigned char) EOF)  {
    printf (ERROR, "INVALID TIME FORMAT");
  } 
  else  {                                /* if inputs valid then              */
    EA = 0;                              /* disable interrupts while          */
    current.time = time;                 /* setting the new time              */
    interval.min = 0;                    /* force new interval                */
    interval.sec = 0;
    interval.msec = 0;
    EA = 1;                              /* enable interrupts again           */
  }
}
  

/******************************************************************************/
/*                            Set Interval Time                               */
/******************************************************************************/
void set_interval (char * buffer) {
  struct interval itime;                 /* temporary interval record         */
  unsigned char args;                    /* number of arguments               */
  float second;                          /* float sec for ss.mmm format       */

  args = sscanf (buffer, "%bd:%f",       /* scan input line for               */
                 &itime.min,             /* minute, second and                */
                 &second);               /* milliseconds                      */
                                         /* check valid inputs                */
  if (second >= 60.0  ||  args < 2  || args == (unsigned char) EOF)  {
    printf (ERROR, "INVALID INTERVAL FORMAT");
  }
  else  {                                /* if inputs are valid then          */
    itime.sec = second;                  /* calculate second and millisecond..*/
    itime.msec = (second - itime.sec) * 1000;  /* ..from float values         */
    if (itime.min != 0 || itime.sec != 0 || itime.msec != 0)  {
      if (itime.msec-- == 0)  {          /* correct interval time for         */
        itime.msec = 999;                /* interrupt routine                 */
        if (itime.sec-- == 0)  {
          itime.sec = 59;
          itime.min--;
        }
      }
    }
    EA = 0;                              /* disable interrupts for copy       */
    setinterval = itime;                 /* of the new setinterval time       */
    interval.min = 0;                    /* force new interval                */
    interval.sec = 0;
    interval.msec = 0;
    EA = 1;                              /* enable interrupts again           */
  }
}
