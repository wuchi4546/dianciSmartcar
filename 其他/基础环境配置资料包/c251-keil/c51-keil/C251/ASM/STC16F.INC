;STC16F.INC
;包含本头文件后,不用另外再包含"REG251.INC"

$SAVE
$NOLIST

P0          DATA        080H
P00         BIT         P0.0
P01         BIT         P0.1
P02         BIT         P0.2
P03         BIT         P0.3
P04         BIT         P0.4
P05         BIT         P0.5
P06         BIT         P0.6
P07         BIT         P0.7
                        
SP          DATA        081H
DPL         DATA        082H
DPH         DATA        083H
DPXL        DATA        084H
USBCLK      DATA        085H
DPS         DATA        086H
PCON        DATA        087H
                        
TCON        DATA        088H
IT0         BIT         TCON.0
IE0         BIT         TCON.1
IT1         BIT         TCON.2
IE1         BIT         TCON.3
TR0         BIT         TCON.4
TF0         BIT         TCON.5
TR1         BIT         TCON.6
TF1         BIT         TCON.7
                        
TMOD        DATA        089H
TL0         DATA        08AH
TL1         DATA        08BH
TH0         DATA        08CH
TH1         DATA        08DH
CKCON       DATA        08EH
DMAIR       DATA        08FH
                        
P1          DATA        090H
P10         BIT         P1.0
P11         BIT         P1.1
P12         BIT         P1.2
P13         BIT         P1.3
P14         BIT         P1.4
P15         BIT         P1.5
P16         BIT         P1.6
P17         BIT         P1.7
                        
USBCON      DATA        091H
WTST        DATA        092H
AUXR        DATA        093H
AUXR2       DATA        094H
INTCLKO     DATA        095H
USBADR      DATA        096H
USBDAT      DATA        097H
                        
SCON        DATA        098H
RI          BIT         SCON.0
TI          BIT         SCON.1
RB8         BIT         SCON.2
TB8         BIT         SCON.3
REN         BIT         SCON.4
SM2         BIT         SCON.5
SM1         BIT         SCON.6
SM0         BIT         SCON.7
                        
SBUF        DATA        099H
P_SW1       DATA        09AH
P_SW2       DATA        09BH
BGTRIM      DATA        09CH
VRTRIM      DATA        09DH
LIRTRIM     DATA        09EH
IRTRIM      DATA        09FH
                        
P2          DATA        0A0H
P20         BIT         P2.0
P21         BIT         P2.1
P22         BIT         P2.2
P23         BIT         P2.3
P24         BIT         P2.4
P25         BIT         P2.5
P26         BIT         P2.6
P27         BIT         P2.7
                        
CANICR      DATA        0A1H
CANAR       DATA        0A2H
CANDR       DATA        0A3H
                        
IE          DATA        0A8H
EX0         BIT         IE.0
ET0         BIT         IE.1
EX1         BIT         IE.2
ET1         BIT         IE.3
ES          BIT         IE.4
EADC        BIT         IE.5
ELVD        BIT         IE.6
EA          BIT         IE.7
                        
IRCBAND     DATA        0A9H
WKTCL       DATA        0AAH
WKTCH       DATA        0ABH
VOCTRL      DATA        0ACH
VOSEL       DATA        0ADH
                        
P3          DATA        0B0H
P30         BIT         P3.0
P31         BIT         P3.1
P32         BIT         P3.2
P33         BIT         P3.3
P34         BIT         P3.4
P35         BIT         P3.5
P36         BIT         P3.6
P37         BIT         P3.7
                        
RD          BIT         P3.7
WR          BIT         P3.6
T1          BIT         P3.5
T0          BIT         P3.4
INT1        BIT         P3.3
INT0        BIT         P3.2
TXD         BIT         P3.1
RXD         BIT         P3.0
                        
LINICR      DATA        0B1H
LINAR       DATA        0B2H
LINDR       DATA        0B3H
CMPCR1      DATA        0B4H
CMPCR2      DATA        0B5H
IP2H        DATA        0B6H
IPH         DATA        0B7H
                        
IP          DATA        0B8H
PX0         BIT         IP.0
PT0         BIT         IP.1
PX1         BIT         IP.2
PT1         BIT         IP.3
PS0         BIT         IP.4
PS          BIT         IP.4
PADC        BIT         IP.5
PLVD        BIT         IP.6
PPWM1       BIT         IP.7
                        
SPSTAT      DATA        0B9H
SPCTL       DATA        0BAH
SPDAT       DATA        0BBH
S4CON       DATA        0BCH
S4BUF       DATA        0BDH
SPH         DATA        0BEH
BUSSPD      DATA        0BFH
                        
P4          DATA        0C0H
P40         BIT         P4.0
P41         BIT         P4.1
P42         BIT         P4.2
P43         BIT         P4.3
P44         BIT         P4.4
P45         BIT         P4.5
P46         BIT         P4.6
P47         BIT         P4.7
                        
DID         DATA        0C1H
IAP_DATA    DATA        0C2H
IAP_ADDRH   DATA        0C3H
IAP_ADDRL   DATA        0C4H
IAP_CMD     DATA        0C5H
IAP_TRIG    DATA        0C6H
IAP_CONTR   DATA        0C7H
                        
P5          DATA        0C8H
P50         BIT         P5.0
P51         BIT         P5.1
P52         BIT         P5.2
P53         BIT         P5.3
P54         BIT         P5.4
P55         BIT         P5.5
P56         BIT         P5.6
P57         BIT         P5.7
                        
T4H         DATA        0C9H
T4L         DATA        0CAH
T3H         DATA        0CBH
T3L         DATA        0CCH
T2H         DATA        0CDH
T2L         DATA        0CEH
                        
T3T4M       DATA        0DBH
TH4         DATA        0C9H
TL4         DATA        0CAH
TH3         DATA        0CBH
TL3         DATA        0CCH
TH2         DATA        0CDH
TL2         DATA        0CEH

PSW         DATA        0D0H
P           BIT         PSW.0
F1          BIT         PSW.1
OV          BIT         PSW.2
RS0         BIT         PSW.3
RS1         BIT         PSW.4
F0          BIT         PSW.5
AC          BIT         PSW.6
CY          BIT         PSW.7
                        
PSW1        DATA        0D1H
P7M1        DATA        0D2H
P7M0        DATA        0D3H
RSTIF       DATA        0D8H
AUXINTIF    DATA        0DAH
T4T3M       DATA        0DBH
ADC_CONTR   DATA        0DCH
ADC_RES     DATA        0DDH
ADC_RESL    DATA        0DEH
ADCCFG      DATA        0DFH
ACC         DATA        0E0H
SADDR       DATA        0E1H
SADEN       DATA        0E2H
S2CON       DATA        0E3H
S2BUF       DATA        0E4H
S3CON       DATA        0E5H
S3BUF       DATA        0E6H
IE2         DATA        0E7H
                        
P6          DATA        0E8H
P60         BIT         P6.0
P61         BIT         P6.1
P62         BIT         P6.2
P63         BIT         P6.3
P64         BIT         P6.4
P65         BIT         P6.5
P66         BIT         P6.6
P67         BIT         P6.7
                        
MXAX        DATA        0EAH
TA          DATA        0EBH
P5M1        DATA        0ECH
P5M0        DATA        0EDH
P6M1        DATA        0EEH
P6M0        DATA        0EFH
B           DATA        0F0H
P0M1        DATA        0F1H
P0M0        DATA        0F2H
P1M1        DATA        0F3H
P1M0        DATA        0F4H
P2M1        DATA        0F5H
P2M0        DATA        0F6H
IAP_TPS     DATA        0F7H
                        
P7          DATA        0F8H
P70         BIT         P7.0
P71         BIT         P7.1
P72         BIT         P7.2
P73         BIT         P7.3
P74         BIT         P7.4
P75         BIT         P7.5
P76         BIT         P7.6
P77         BIT         P7.7
                        
P3M1        DATA        0F9H
P3M0        DATA        0FAH
P4M1        DATA        0FBH
P4M0        DATA        0FCH
WDT_CONTR   DATA        0FDH
IP2         DATA        0FEH
RSTCFG      DATA        0FFH

;如下特殊功能寄存器位于扩展RAM区域
;访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

CLKSEL          EQU     07EFE00H
CLKDIV          EQU     07EFE01H
IRC24MCR        EQU     07EFE02H
XOSCCR          EQU     07EFE03H
IRC32KCR        EQU     07EFE04H
PLLCR           EQU     07EFE05H
USBCON1         EQU     07EFE06H
MCLKOCR         EQU     07EFE07H
IRC48MCR        EQU     07EFE08H
IRC48ATRIM      EQU     07EFE09H
IRC48BTRIM      EQU     07EFE0AH
IRCDB           EQU     07EFE0BH
                
P0PU            EQU     07EFE10H
P1PU            EQU     07EFE11H
P2PU            EQU     07EFE12H
P3PU            EQU     07EFE13H
P4PU            EQU     07EFE14H
P5PU            EQU     07EFE15H
P6PU            EQU     07EFE16H
P7PU            EQU     07EFE17H
P0NCS           EQU     07EFE18H
P1NCS           EQU     07EFE19H
P2NCS           EQU     07EFE1AH
P3NCS           EQU     07EFE1BH
P4NCS           EQU     07EFE1CH
P5NCS           EQU     07EFE1DH
P6NCS           EQU     07EFE1EH
P7NCS           EQU     07EFE1FH
P0SR            EQU     07EFE20H
P1SR            EQU     07EFE21H
P2SR            EQU     07EFE22H
P3SR            EQU     07EFE23H
P4SR            EQU     07EFE24H
P5SR            EQU     07EFE25H
P6SR            EQU     07EFE26H
P7SR            EQU     07EFE27H
P0DR            EQU     07EFE28H
P1DR            EQU     07EFE29H
P2DR            EQU     07EFE2AH
P3DR            EQU     07EFE2BH
P4DR            EQU     07EFE2CH
P5DR            EQU     07EFE2DH
P6DR            EQU     07EFE2EH
P7DR            EQU     07EFE2FH
P0IE            EQU     07EFE30H
P1IE            EQU     07EFE31H
                
I2CCFG          EQU     07EFE80H
I2CMSCR         EQU     07EFE81H
I2CMSST         EQU     07EFE82H
I2CSLCR         EQU     07EFE83H
I2CSLST         EQU     07EFE84H
I2CSLADR        EQU     07EFE85H
I2CTXD          EQU     07EFE86H
I2CRXD          EQU     07EFE87H
I2CMSAUX        EQU     07EFE88H
                
TIMER2PS        EQU     07EFEA2H
TIMER3PS        EQU     07EFEA3H
TIMER4PS        EQU     07EFEA4H
                
ADCTIM          EQU     07EFEABH
T3T4PS          EQU     07EFEACH
                
PWM1_ETRPS      EQU     07EFEB0H
PWM1_ENO        EQU     07EFEB1H
PWM1_PS         EQU     07EFEB2H
PWM1_IOAUX      EQU     07EFEB3H
PWM2_ETRPS      EQU     07EFEB4H
PWM2_ENO        EQU     07EFEB5H
PWM2_PS         EQU     07EFEB6H
PWM2_IOAUX      EQU     07EFEB7H
                
PWMA_ETRPS      EQU     07EFEB0H
PWMA_ENO        EQU     07EFEB1H
PWMA_PS         EQU     07EFEB2H
PWMA_IOAUX      EQU     07EFEB3H
PWMB_ETRPS      EQU     07EFEB4H
PWMB_ENO        EQU     07EFEB5H
PWMB_PS         EQU     07EFEB6H
PWMB_IOAUX      EQU     07EFEB7H
                
PWM1_CR1        EQU     07EFEC0H
PWM1_CR2        EQU     07EFEC1H
PWM1_SMCR       EQU     07EFEC2H
PWM1_ETR        EQU     07EFEC3H
PWM1_IER        EQU     07EFEC4H
PWM1_SR1        EQU     07EFEC5H
PWM1_SR2        EQU     07EFEC6H
PWM1_EGR        EQU     07EFEC7H
PWM1_CCMR1      EQU     07EFEC8H
PWM1_CCMR2      EQU     07EFEC9H
PWM1_CCMR3      EQU     07EFECAH
PWM1_CCMR4      EQU     07EFECBH
PWM1_CCER1      EQU     07EFECCH
PWM1_CCER2      EQU     07EFECDH
PWM1_CNTRH      EQU     07EFECEH
PWM1_CNTRL      EQU     07EFECFH
PWM1_PSCRH      EQU     07EFED0H
PWM1_PSCRL      EQU     07EFED1H
PWM1_ARRH       EQU     07EFED2H
PWM1_ARRL       EQU     07EFED3H
PWM1_RCR        EQU     07EFED4H
PWM1_CCR1H      EQU     07EFED5H
PWM1_CCR1L      EQU     07EFED6H
PWM1_CCR2H      EQU     07EFED7H
PWM1_CCR2L      EQU     07EFED8H
PWM1_CCR3H      EQU     07EFED9H
PWM1_CCR3L      EQU     07EFEDAH
PWM1_CCR4H      EQU     07EFEDBH
PWM1_CCR4L      EQU     07EFEDCH
PWM1_BKR        EQU     07EFEDDH
PWM1_DTR        EQU     07EFEDEH
PWM1_OISR       EQU     07EFEDFH
                
PWM2_CR1        EQU     07EFEE0H
PWM2_CR2        EQU     07EFEE1H
PWM2_SMCR       EQU     07EFEE2H
PWM2_ETR        EQU     07EFEE3H
PWM2_IER        EQU     07EFEE4H
PWM2_SR1        EQU     07EFEE5H
PWM2_SR2        EQU     07EFEE6H
PWM2_EGR        EQU     07EFEE7H
PWM2_CCMR1      EQU     07EFEE8H
PWM2_CCMR2      EQU     07EFEE9H
PWM2_CCMR3      EQU     07EFEEAH
PWM2_CCMR4      EQU     07EFEEBH
PWM2_CCER1      EQU     07EFEECH
PWM2_CCER2      EQU     07EFEEDH
PWM2_CNTRH      EQU     07EFEEEH
PWM2_CNTRL      EQU     07EFEEFH
PWM2_PSCRH      EQU     07EFEF0H
PWM2_PSCRL      EQU     07EFEF1H
PWM2_ARRH       EQU     07EFEF2H
PWM2_ARRL       EQU     07EFEF3H
PWM2_RCR        EQU     07EFEF4H
PWM2_CCR1H      EQU     07EFEF5H
PWM2_CCR1L      EQU     07EFEF6H
PWM2_CCR2H      EQU     07EFEF7H
PWM2_CCR2L      EQU     07EFEF8H
PWM2_CCR3H      EQU     07EFEF9H
PWM2_CCR3L      EQU     07EFEFAH
PWM2_CCR4H      EQU     07EFEFBH
PWM2_CCR4L      EQU     07EFEFCH
PWM2_BKR        EQU     07EFEFDH
PWM2_DTR        EQU     07EFEFEH
PWM2_OISR       EQU     07EFEFFH
                
PWMA_CR1        EQU     07EFEC0H
PWMA_CR2        EQU     07EFEC1H
PWMA_SMCR       EQU     07EFEC2H
PWMA_ETR        EQU     07EFEC3H
PWMA_IER        EQU     07EFEC4H
PWMA_SR1        EQU     07EFEC5H
PWMA_SR2        EQU     07EFEC6H
PWMA_EGR        EQU     07EFEC7H
PWMA_CCMR1      EQU     07EFEC8H
PWMA_CCMR2      EQU     07EFEC9H
PWMA_CCMR3      EQU     07EFECAH
PWMA_CCMR4      EQU     07EFECBH
PWMA_CCER1      EQU     07EFECCH
PWMA_CCER2      EQU     07EFECDH
PWMA_CNTRH      EQU     07EFECEH
PWMA_CNTRL      EQU     07EFECFH
PWMA_PSCRH      EQU     07EFED0H
PWMA_PSCRL      EQU     07EFED1H
PWMA_ARRH       EQU     07EFED2H
PWMA_ARRL       EQU     07EFED3H
PWMA_RCR        EQU     07EFED4H
PWMA_CCR1H      EQU     07EFED5H
PWMA_CCR1L      EQU     07EFED6H
PWMA_CCR2H      EQU     07EFED7H
PWMA_CCR2L      EQU     07EFED8H
PWMA_CCR3H      EQU     07EFED9H
PWMA_CCR3L      EQU     07EFEDAH
PWMA_CCR4H      EQU     07EFEDBH
PWMA_CCR4L      EQU     07EFEDCH
PWMA_BKR        EQU     07EFEDDH
PWMA_DTR        EQU     07EFEDEH
PWMA_OISR       EQU     07EFEDFH
                
PWMB_CR1        EQU     07EFEE0H
PWMB_CR2        EQU     07EFEE1H
PWMB_SMCR       EQU     07EFEE2H
PWMB_ETR        EQU     07EFEE3H
PWMB_IER        EQU     07EFEE4H
PWMB_SR1        EQU     07EFEE5H
PWMB_SR2        EQU     07EFEE6H
PWMB_EGR        EQU     07EFEE7H
PWMB_CCMR1      EQU     07EFEE8H
PWMB_CCMR2      EQU     07EFEE9H
PWMB_CCMR3      EQU     07EFEEAH
PWMB_CCMR4      EQU     07EFEEBH
PWMB_CCER1      EQU     07EFEECH
PWMB_CCER2      EQU     07EFEEDH
PWMB_CNTRH      EQU     07EFEEEH
PWMB_CNTRL      EQU     07EFEEFH
PWMB_PSCRH      EQU     07EFEF0H
PWMB_PSCRL      EQU     07EFEF1H
PWMB_ARRH       EQU     07EFEF2H
PWMB_ARRL       EQU     07EFEF3H
PWMB_RCR        EQU     07EFEF4H
PWMB_CCR1H      EQU     07EFEF5H
PWMB_CCR1L      EQU     07EFEF6H
PWMB_CCR2H      EQU     07EFEF7H
PWMB_CCR2L      EQU     07EFEF8H
PWMB_CCR3H      EQU     07EFEF9H
PWMB_CCR3L      EQU     07EFEFAH
PWMB_CCR4H      EQU     07EFEFBH
PWMB_CCR4L      EQU     07EFEFCH
PWMB_BKR        EQU     07EFEFDH
PWMB_DTR        EQU     07EFEFEH
PWMB_OISR       EQU     07EFEFFH

$RESTORE

