;---------------------------------------------------------------------------
;REG930.INC
;
;Header file for Intel 8x930xx
;Copyright (c) 1995-1996 Keil Software, Inc.  All rights reserved.
;---------------------------------------------------------------------------
$SAVE
$NOLIST
$NOSYMLIST

;-------------------------------------------------
;Byte Registers
;-------------------------------------------------
P0	DATA 080h
SP      DATA 081h
DPL     DATA 082h
DPH     DATA 083h
DPXL    DATA 084h
PCON    DATA 087h
TCON    DATA 088h
TMOD    DATA 089h
TL0     DATA 08Ah
TL1     DATA 08Bh
TH0     DATA 08Ch
TH1     DATA 08Dh
FADDR   DATA 08Fh

P1      DATA 090h
HADDR   DATA 097h   ; 930Hx only
SCON    DATA 098h
SBUF    DATA 099h
HPPWR   DATA 09Ah   ; 930Hx only

P2      DATA 0A0h
HIE     DATA 0A1h
FIE	DATA 0A2h
FIE1    DATA 0A3h
WDTRST  DATA 0A6h
WCON	DATA 0A7h
IE0     DATA 0A8h
IEN0	DATA 0A8h
SADDR   DATA 0A9h
HSTAT   DATA 0AEh   ; 930Hx only

P3      DATA 0B0h
IE1     DATA 0B1h
IEN1	DATA 0B1h
IPL1    DATA 0B2h
IPH1    DATA 0B3h
IPH0    DATA 0B7h
IPL0    DATA 0B8h
SADEN   DATA 0B9h
SPH     DATA 0BEh

FIFLG	DATA 0C0h
FIFLG1  DATA 0C1h
EPCONFIG DATA 0C7h
T2CON   DATA 0C8h
T2MOD   DATA 0C9h
RCAP2L  DATA 0CAh
RCAP2H  DATA 0CBh
TL2     DATA 0CCh
TH2     DATA 0CDh
HPCON   DATA 0CFh   ; 930Hx only

PSW     DATA 0D0h
PSW1    DATA 0D1h
SOFL    DATA 0D2h
SOFH    DATA 0D3h
HPINDEX DATA 0D4h   ; 930Hx only
HPSC    DATA 0D5h   ; 930Hx only
HPSTAT  DATA 0D7h   ; 930Hx only
CCON    DATA 0D8h
CMOD    DATA 0D9h
CCAPM0  DATA 0DAh
CCAPM1  DATA 0DBh
CCAPM2  DATA 0DCh
CCAPM3  DATA 0DDh
CCAPM4  DATA 0DEh
PCON1	DATA 0DFh

ACC     DATA 0E0h
EPCON	DATA 0E1h
RXSTAT	DATA 0E2h
RXDAT	DATA 0E3h
RXCON	DATA 0E4h
RXFLG	DATA 0E5h
RXCNT 	DATA 0E6h
RXCNTL	DATA 0E6h
RXCNTH	DATA 0E7h
HIFLG   DATA 0E8h   ; 930Hx only
CL      DATA 0E9h
CCAP0L  DATA 0EAh
CCAP1L  DATA 0EBh
CCAP2L  DATA 0ECh
CCAP3L  DATA 0EDh
CCAP4L  DATA 0EEh

B       DATA 0F0h
EPINDEX DATA 0F1h
TXSTAT  DATA 0F2h
TXDAT   DATA 0F3h
TXCON   DATA 0F4h
TXFLG   DATA 0F5h
TXCNT   DATA 0F6h
TXCNTL  DATA 0F6h
TXCNTH  DATA 0F7h
CH      DATA 0F9h
CCAP0H  DATA 0FAh
CCAP1H  DATA 0FBh
CCAP2H  DATA 0FCh
CCAP3H  DATA 0FDh
CCAP4H  DATA 0FEh

HTXDAT  DATA TXDAT     ; 930Hx only
HTXCNTL DATA TXCNTL    ; 930Hx only

;-------------------------------------------------
;PCON Bit Values
;-------------------------------------------------
IDL_    	EQU	01h
PD_     	EQU	02h
GF0_    	EQU	04h
GF1_    	EQU	08h
POF_    	EQU	10h

SMOD0_  	EQU	40h
SMOD1_  	EQU	80h


;-------------------------------------------------
;TCON Bit Registers
;-------------------------------------------------
IT0  		BIT	88h
IE0_ 		BIT	89h
IT1 		BIT	8Ah
IE1_ 		BIT	8Bh
TR0 		BIT	8Ch
TF0 		BIT	8Dh
TR1 		BIT	8Eh
TF1 		BIT	8Fh

;-------------------------------------------------
;TMOD Bit Values
;-------------------------------------------------
T0_M0_		EQU	01h
T0_M1_  	EQU	02h
T0_CT_  	EQU	04h
T0_GATE_	EQU	08h
T1_M0_  	EQU	10h
T1_M1_  	EQU	20h
T1_CT_  	EQU	40h
T1_GATE_	EQU	80h

T1_MASK_	EQU	0F0h
T0_MASK_	EQU	00Fh

;-------------------------------------------------
;P1 Bit Registers (Mnemonics)
;-------------------------------------------------
T2		BIT	90h
T2EX		BIT	91h
ECI    		BIT	92h
CEX0		BIT	93h
CEX1		BIT	94h
CEX2		BIT	95h
CEX3		BIT	96h
CEX4		BIT	97h

;-------------------------------------------------
;SCON Bit Registers
;-------------------------------------------------
RI		BIT	98h
TI		BIT	99h
RB8		BIT	9Ah
TB8		BIT	9Bh
REN		BIT	9Ch
SM2		BIT	9Dh
SM1		BIT	9Eh
SM0		BIT	9Fh

;-------------------------------------------------
;IE0 / IEN0 Bit Registers
;-------------------------------------------------
EX0		BIT	0A8h
ET0		BIT	0A9h
EX1		BIT	0AAh
ET1		BIT	0ABh
ES		BIT	0ACh
ET2		BIT	0ADh
EC		BIT	0AEh
EA		BIT	0AFh

;-------------------------------------------------
;P3 Bit Registers (Mnemonics)
;-------------------------------------------------
RXD		BIT	0B0h
TXD		BIT	0B1h
INT0		BIT	0B2h
INT1		BIT	0B3h
T0		BIT	0B4h
T1		BIT	0B5h
WR		BIT	0B6h
RD		BIT	0B7h

;-------------------------------------------------
;IE1 / IEN1 Bit Values
;-------------------------------------------------
IE1_0_		EQU	01h
IE1_1_		EQU	02h
IE1_2_		EQU	04h
IE1_3_		EQU	08h

;-------------------------------------------------
;IPL1 Bit Values
;-------------------------------------------------
IPL1_0_		EQU	01h
IPL1_1_		EQU	02h
IPL1_2_		EQU	04h
IPL1_3_		EQU	08h

;-------------------------------------------------
;IPH1 Bit Values
;-------------------------------------------------
IPH1_0_		EQU	01h
IPH1_1_		EQU	02h
IPH1_2_		EQU	04h
IPH1_3_		EQU	08h

;-------------------------------------------------
;IPH0 Bit Values
;-------------------------------------------------
IPH0_PX0_	EQU	01h
IPH0_PT0_	EQU	02h
IPH0_PX1_	EQU	04h
IPH0_PT1_	EQU	08h
IPH0_PS_ 	EQU	10h
IPH0_PT2_	EQU	20h
IPH0_PPC_	EQU	40h

;-------------------------------------------------
;IPL0 Bit Registers
;-------------------------------------------------
PX0		BIT	0B8h
PT0		BIT	0B9h
PX1		BIT	0BAh
PT1		BIT	0BBh
PS		BIT	0BCh
PT2		BIT	0BDh
PPC		BIT	0BEh

;-------------------------------------------------
;T2CON Bit Registers
;-------------------------------------------------
CP_RL2		BIT	0C8h
C_T2		BIT	0C9h
TR2		BIT	0CAh
EXEN2		BIT	0CBh
TCLK		BIT	0CCh
RCLK		BIT	0CDh
EXF2		BIT	0CEh
TF2		BIT	0CFh

;-------------------------------------------------
;T2MOD Bit Values
;-------------------------------------------------
DCEN_		EQU	01h
T2OE_		EQU	02h

;-------------------------------------------------
;PSW Bit Registers
;-------------------------------------------------
P		BIT	0D0h
FL		BIT	0D1h
OV		BIT	0D2h
RS0		BIT	0D3h
RS1		BIT	0D4h
F0		BIT	0D5h
AC		BIT	0D6h
CY		BIT	0D7h

;-------------------------------------------------
;PSW1 Bit Values
;-------------------------------------------------
PSW1_Z_		EQU	02h
PSW1_OV_	EQU	04h
PSW1_RS0_	EQU	08h
PSW1_RS1_	EQU	10h
PSW1_N_		EQU	20h
PSW1_AC_	EQU	40h
PSW1_CY_	EQU	80h

;-------------------------------------------------
;HSTAT Bit Values
;-------------------------------------------------
LPS_    	EQU	01h
OVI_    	EQU	02h
LPSC_   	EQU	04h
OVISC_  	EQU	08h
EP1EN_  	EQU	10h
EP1STL_ 	EQU	20h
HRWUPE_  	EQU	40h

;-------------------------------------------------
;HPSC Bit Values
;-------------------------------------------------
PCSC_   	EQU	01h
PESC_   	EQU	02h
PSSC_   	EQU	04h
POVSC_  	EQU	08h
RSTSC_  	EQU	10h

;-------------------------------------------------
;HPSTAT Bit Values
;-------------------------------------------------
PCSTAT_ 	EQU	01h
PESTAT_ 	EQU	02h
PSSTAT_ 	EQU	04h
PRSTAT_ 	EQU	08h
PPSTAT_ 	EQU	10h
LSSTAT_ 	EQU	20h
VMSTAT_ 	EQU	40h
VPSTAT_ 	EQU	80h

;-------------------------------------------------
;FIE Bit Values
;-------------------------------------------------
FTXIE0_ 	EQU	01h
FRXIE0_ 	EQU	02h
FTXIE1_ 	EQU	04h
FRXIE1_ 	EQU	08h
FTXIE2_ 	EQU	10h
FRXIE2_ 	EQU	20h
FTXIE3_ 	EQU	40h
FRXIE3_ 	EQU	80h

;-------------------------------------------------
;FIE1 Bit Values
;-------------------------------------------------
FTXIE4_ 	EQU	01h
FRXIE4_ 	EQU	02h
FTXIE5_ 	EQU	04h
FRXIE5_ 	EQU	08h

;-------------------------------------------------
;EPCONFIG Bit Values
;-------------------------------------------------
SIXEPPEN_ 	EQU	01h

;-------------------------------------------------
;SOFH Bit Values
;-------------------------------------------------
TS_MASK_	EQU	07h

SOFODIS_  	EQU	08h
F_LOCK_   	EQU	10h
SOFIE_    	EQU	20h
RXSOF_		EQU	40h
SFACK_		EQU	80h

;-------------------------------------------------
;PCON1 Bit Values
;-------------------------------------------------
GSUS_     	EQU	01h
GRSM_     	EQU	02h
RWU_       	EQU	04h
URST_      	EQU	08h
URDIS_     	EQU	10h

;-------------------------------------------------
;CCON Bit Registers
;-------------------------------------------------
CCF0		BIT	0D8h
CCF1		BIT	0D9h
CCF2		BIT	0DAh
CCF3		BIT	0DBh
CCF4		BIT	0DCh
CR		BIT	0DEh
CF		BIT	0DFh

;-------------------------------------------------
;CMOD Bit Values
;-------------------------------------------------
ECF_		EQU	01h
CPS0_		EQU	02h
CPS1_		EQU	04h

WDTE_		EQU	40h
CIDL_		EQU	80h

;-------------------------------------------------
;CCAPM? Bit Values
;-------------------------------------------------
ECCF_		EQU	01h
PWM_		EQU	02h
TOG_		EQU	04h
MAT_		EQU	08h
CAPN_		EQU	10h
CAPP_		EQU	20h
ECOM_		EQU	40h

;-------------------------------------------------
;EPCON  Bit Values
;-------------------------------------------------
TXEPEN_  	EQU	01h
TXOE_    	EQU	02h
RXEPEN_  	EQU	04h
RXIE_    	EQU	08h
RXSPM_   	EQU	10h
CTLEP_   	EQU	20h
TXSTL_   	EQU	40h
RXSTL_   	EQU	80h

;-------------------------------------------------
;RXSTAT Bit Values   
;-------------------------------------------------
RXACK_    	EQU	01h
RXERR_    	EQU	02h
RXVOID_   	EQU	04h
RXDTO_    	EQU	08h
EDOVW_    	EQU	10h
STOVW_    	EQU	20h
RXSETUP_  	EQU	40h
RXSEQ_    	EQU	80h

;-------------------------------------------------
;RXCON Bit Values    
;-------------------------------------------------
REVWP_    	EQU	01h
ADVWM_    	EQU	02h
ARM_      	EQU	04h
RXISO_    	EQU	08h
RXFFRC_   	EQU	10h
RXWS_     	EQU	20h
RXCLR_    	EQU	80h

;-------------------------------------------------
;RXFLG Bit Values    
;-------------------------------------------------
RXOVF_    	EQU	01h
RXURF_    	EQU	02h
RXFULL_   	EQU	04h
RXEMP_    	EQU	08h
RXFIF0_   	EQU	40h
RXFIF1_   	EQU	80h

;-------------------------------------------------
;EPINDEX Bit Values
;-------------------------------------------------
EPIDX0_    	EQU	01h
EPIDX1_    	EQU	02h
EPIDX2_    	EQU	04h
HORF_      	EQU	80h

;-------------------------------------------------
;TXSTAT  Bit Values
;-------------------------------------------------
TXACK_    	EQU	01h
TXERR_    	EQU	02h
TXVOID_   	EQU	04h
TXSOVW_   	EQU	08h
TXFLUSH_  	EQU	10h
TXSEQ_    	EQU	80h

;-------------------------------------------------
;TXCON Bit Values    
;-------------------------------------------------
REVRP_    	EQU	01h
ADVRM_    	EQU	02h
ATM_      	EQU	04h
TXISO_    	EQU	08h
FFSZ0_    	EQU	20h
FFSZ1_    	EQU	40h
TXCLR_    	EQU	80h

;-------------------------------------------------
;TXFLG Bit Values    
;-------------------------------------------------
TXOVF_    	EQU	01h
TXURF_    	EQU	02h
TXFULL_   	EQU	04h
TXEMP_    	EQU	08h
TXFIF0_   	EQU	40h
TXFIF1_   	EQU	80h

;-------------------------------------------------
;Interrupt Vectors:
;Interrupt Address = (Number * 8) + 3
;-------------------------------------------------
IE0_VECTOR	EQU	 0	; 03h 
TF0_VECTOR	EQU	 1	; 0Bh 
IE1_VECTOR	EQU	 2	; 13h 
TF1_VECTOR	EQU	 3	; 1Bh 
SIO_VECTOR	EQU	 4	; 23h 
TF2_VECTOR	EQU	 5	; 2Bh 
CF_VECTOR	EQU	 6	; 33h 

SOF_VECTOR	EQU	 8	; 43h 
ESOF_VECTOR	EQU	 8	; 43h 
USB_VECTOR	EQU	 9	; 4Bh 
EF_VECTOR	EQU	 9	; 4Bh 
GUSS_GRSM_VEC	EQU	10	; 53h 
ESR_VECTOR	EQU	10	; 53h 

TRAP_VECTOR	EQU	15	; 7Bh 


; 930Ax SFR bits

EEP3    BIT     IEN1.3
EEP2    BIT     IEN1.2
EEP1    BIT     IEN1.1
EEP0    BIT     IEN1.0

PEP3L   BIT     IPL1.3
PEP2L   BIT     IPL1.2
PEP1L   BIT     IPL1.1
PEP0L   BIT     IPL1.0
PEP3H   BIT     IPH1.3
PEP2H   BIT     IPH1.2
PEP1H   BIT     IPH1.1
PEP0H   BIT     IPH1.0

RTWCE   BIT     WCON.1
RTWE    BIT     WCON.0

PD      BIT     PCON.1
LC      BIT     PCON.5

URDIS   BIT     PCON1.4
URST    BIT     PCON1.3
RWU     BIT     PCON1.2
GRSM    BIT     PCON1.1
GSUS    BIT     PCON1.0

A6      BIT     FADDR.6
A5      BIT     FADDR.5
A4      BIT     FADDR.4
A3      BIT     FADDR.3
A2      BIT     FADDR.2
A1      BIT     FADDR.1
A0      BIT     FADDR.0

TS7     BIT     SOFL.7
TS6     BIT     SOFL.6
TS5     BIT     SOFL.5
TS4     BIT     SOFL.4
TS3     BIT     SOFL.3
TS2     BIT     SOFL.2
TS1     BIT     SOFL.1
TS0     BIT     SOFL.0

SFACK   BIT     SOFH.7
ASOF    BIT     SOFH.6
SOFIE   BIT     SOFH.5
FTLOCK  BIT     SOFH.4
SOFODIS BIT     SOFH.3
TS10    BIT     SOFH.2
TS9     BIT     SOFH.1
TS8     BIT     SOFH.0

FRXIE3  BIT     FIE.7
FTXIE3  BIT     FIE.6
FRXIE2  BIT     FIE.5
FTXIE2  BIT     FIE.4
FRXIE1  BIT     FIE.3
FTXIE1  BIT     FIE.2
FRXIE0  BIT     FIE.1
FTXIE0  BIT     FIE.0

FRXD3   BIT     FIFLG.7
FTXD3   BIT     FIFLG.6
FRXD2   BIT     FIFLG.5
FTXD2   BIT     FIFLG.4
FRXD1   BIT     FIFLG.3
FTXD1   BIT     FIFLG.2
FRXD0   BIT     FIFLG.1
FTXD0   BIT     FIFLG.0

RXSTL   BIT     EPCON.7
TXSTL   BIT     EPCON.6
CTLEP   BIT     EPCON.5
RXSPM   BIT     EPCON.4
RXIE    BIT     EPCON.3
RXEPEN  BIT     EPCON.2
TXOE    BIT     EPCON.1
TXEPEN  BIT     EPCON.0

RXSEQ   BIT     RXSTAT.7 
RXSETUP BIT     RXSTAT.6
STOVW   BIT     RXSTAT.5
EDOVW   BIT     RXSTAT.4
RXDTO   BIT     RXSTAT.3
RXVOID  BIT     RXSTAT.2
RXERR   BIT     RXSTAT.1
RXACK   BIT     RXSTAT.0

RXCLR   BIT     RXCON.7
RXWS    BIT     RXCON.5
RXFFRC  BIT     RXCON.4
RXISO   BIT     RXCON.3
ARM     BIT     RXCON.2
ADVWM   BIT     RXCON.1
REVWP   BIT     RXCON.0

RXFIF1  BIT     RXFLG.7
RXFIF0  BIT     RXFLG.6
RXEMP   BIT     RXFLG.3
RXFULL  BIT     RXFLG.2
RXURF   BIT     RXFLG.1
RXOVF   BIT     RXFLG.0

TXSEQ   BIT     TXSTAT.7
TXFLUSH BIT     TXSTAT.4
TXSOVW  BIT     TXSTAT.3
TXVOID  BIT     TXSTAT.2
TXERR   BIT     TXSTAT.1
TXACK   BIT     TXSTAT.0

TXCLR   BIT     TXCON.7
FFSZ1   BIT     TXCON.6
FFSZ0   BIT     TXCON.5
TXISO   BIT     TXCON.3
ATM     BIT     TXCON.2
ADVRM   BIT     TXCON.1
REVRP   BIT     TXCON.0

TXFIF1  BIT     TXFLG.7
TXFIF0  BIT     TXFLG.6
TXEMP   BIT     TXFLG.3
TXFULL  BIT     TXFLG.2
TXURF   BIT     TXFLG.1
TXOVF   BIT     TXFLG.0


; 930Hx SFR bits

HRWUPE  BIT     HSTAT.6
EP1STL  BIT     HSTAT.5
EP1EN   BIT     HSTAT.4
OVISC   BIT     HSTAT.3
LPSC    BIT     HSTAT.2
OVI     BIT     HSTAT.1
LPS     BIT     HSTAT.0

HTXD0   BIT     HIFLG.0
HRXD0   BIT     HIFLG.1

HPPWR4  BIT     HPPWR.4
HPPWR3  BIT     HPPWR.3
HPPWR2  BIT     HPPWR.2
HPPWR1  BIT     HPPWR.1

VPSTAT  BIT     HPSTAT.7
VMSTAT  BIT     HPSTAT.6
LSSTAT  BIT     HPSTAT.5
PPSTAT  BIT     HPSTAT.4
PRSTAT  BIT     HPSTAT.3
PSSTAT  BIT     HPSTAT.2
PESTAT  BIT     HPSTAT.1
PCSTAT  BIT     HPSTAT.0

PSTSC   BIT     HPSC.4
POTSC   BIT     HPSC.3
PSSC    BIT     HPSC.2
PESC    BIT     HPSC.1
PCSC    BIT     HPSC.0

$RESTORE
;---------------------------------------------------------------------------
;---------------------------------------------------------------------------
