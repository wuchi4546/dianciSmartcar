MON251 Configuration

The MON251 Monitor firmware program is a HEX file that you use to create a ROM for
your 251 target hardware.  When your 251 target resets, the execution starts at FF:0000
where the MON251 firmware program must reside.  The MON251 firmware initializes your 
hardware and allows to connect to uVision using the MON251 driver.

Using uVision with the MON251 these two programs (one on the PC and one in your target) you can
easily load and test your 251 application programs.

You must create a 251 Monitor target program for your target hardware. The
following description provides a "General" overview of how to do this.  This
file also describes how to configure the 251 monitor for the Keil MCB251SB
evaluation board.

To create the 251 Monitor target program HEX file, you must invoke the 251
Monitor installation program from the Command Prompt.  The command line
format for the installation batch file is:

INSTALL  { MODBIN | MODSRC }  <serialtype>  <datastart>  [INTR2] [PAGE] [CODESTART]

where:

  MODBIN creates MON251 in binary mode

  MODSRC creates MON251 monitor in source mode

  <serialtype> = 0  uses Timer 1 at 9600 baud, 11.0592 MHz xtal
  <serialtype> = 1  uses Timer 2 at 9600 baud, xtal defined in INSTALL.A51
  <serialtype> = 2  Intel USBM Eval Board Rev.B  57600 bps
  <serialtype> = 3  Keil MCBx51 Eval Board Version 2.0  57600 bps

  <datastart> specifies the starting address for the monitor data area

  INTR2      creates the MON251 with support for 2-byte interrupt frames
  PAGE       configures for PAGE Mode (not working for Intel 80C251 Step A devices)
  CODESTART  specifies the starting address for the monitor code area

