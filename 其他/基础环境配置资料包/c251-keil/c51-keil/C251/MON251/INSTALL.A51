$TITLE ('Configuration for MONITOR-51   (C) 1995 KEIL')
;***********************************************************************
;*                                                                     *
;* MONITOR-251  Configuration                                          *
;* COPYRIGHT KEIL ELEKTRONIK GmbH 1995                                 *
;*                                                                     *
;***********************************************************************

XTAL	   EQU	12000000	; 12.0 MHz XTAL frequency
$IF (SERIAL = 3)
BAUDRATE   EQU  57600           ; 57600 bps for MCB251SB external SIO
$ELSE
BAUDRATE   EQU  9600		; 9600 bps for all other targets
$ENDIF

$IF (SERIAL = 2)
INT_ADR_OFF	EQU	0004000H  ; FOR INTEL USB IT IS ADDRESS 004000H
$ELSE
INT_ADR_OFF	EQU	0FF4000H  ; INTERRUPT VECTOR OFFSET IF MONITOR
			          ; IS INSTALLED AT ADDRESS FF0000H
$ENDIF

;------------------------------------------------------------------------------
;
;  251 Configuration Bytes Definition for the 8XC251SA/SB/SP/SQ B-stepping!
;
$SET (BSTEPING = 1)  ; Set this variable to 0 for a 251 A-step device
;
; Wait State for PSEN#/RD#/WR# signal except region 01:xxxx (WSA1 & WSA0 Bits)
; WSA        Val  Description
; ---        ---  -----------
WSA  EQU 2  ; 3 = 0 wait state for all regions except region 01:xxxx
;           ; 2 = extended to 1 wait state  for all regions except 01:xxxx
;           ; 1 = extended to 2 wait states for all regions except 01:xxxx
;           ; 0 = extended to 3 wait states for all regions except 01:xxxx
;
; Extend ALE pulse
; XALE       Val  Description
; ----       ---  -----------
XALE EQU 1  ; 1 = ALE pulse is one TOSC
;           ; 0 = ALE pulse is three TOSC, this adds one external wait state
;
; RD# and PSEN# Function Select  (RD1 and RD0 Bits)
; RD         Val  RD Range   PSEN Range  P1.7 Func  Features
; --         ---  --------   ----------  ---------  --------
RDRG EQU 0  ; 3 = <=7F:FFFF  >=80:FFFF   P1.7/CEX4  Compatible with 8051
;           ; 2 = P3.7 only  All address P1.7/CEX4  One additional port pin
;           ; 1 = RD#=A16    All address P1.7/CEX4  128K External Address space
;           ; 0 = RD#=A16    All address P1.7=A17   256K External Address space
;
; Page Mode Select
; PAGE       Val  Description
; ----       ---  -----------
$IF (PAGEM)
PAGM EQU 0  ; 0 = Page Mode (A15:8/D7:0 on P2, A7:0 on P0)
$ELSE
PAGM EQU 1  ; 1 = Non-page Mode (A15:8 on P2, A7:0/D7:0 on P0, 8051 compatible)
$ENDIF
;
; Interrupt Mode Select
; INTR       Val  Description
; ----       ---  -----------
$IF (__INTR4__ = 0)
INTR EQU 0  ; 0 = Interrupt pushes 2 bytes onto the stack (PCL & PCH only)
$ELSE
INTR EQU 1  ; 1 = Interrupt pushes 4 bytes onto the stack (PC & PSW1)
$ENDIF
;
; Extended Data Float (EDF) Timing Feature
; EDF        Val  Description
; ----       ---  -----------
EDF  EQU 1  ; 1 = Standard (Compatibility) Mode
;           ; 0 = extend data float timing for slow memory devices
;
; Wait State for PSEN#/RD#/WR# signal for region 01:xxxx (WSB1 & WSB0 Bits)
; WSB        Val  Description
; ---        ---  -----------
WSB  EQU 3  ; 3 = 0 wait state for region 01:xxxx
;           ; 2 = extended to 1 wait state  for regions 01:xxxx
;           ; 1 = extended to 2 wait states for regions 01:xxxx
;           ; 0 = extended to 3 wait states for regions 01:xxxx
;
; EPROM/ROM Mapping
; WSA        Val  Description
; ---        ---  -----------
EMAP EQU 1 ;  1 = Map internal ROM only to region FF:xxxx
;          ;  0 = Map higher 8KB of internal ROM to region 00:E000 - 00:FFFF
;
;  Note:  the bit SRC is defined with the A251 directive MODSRC/MODBIN 
; 
;------------------------------------------------------------------------------

; Setting of the Chip Configuration Bytes (251 B-stepping!)
$IF __MODSRC__
SRCM		EQU	1  ; Select Source Mode
$ELSE
SRCM		EQU	0  ; Select Binary Mode
$ENDIF

$IF (BSTEPING)
CONFIG0		EQU     (WSA*20H)+(XALE*10H)+(RDRG*4)+(PAGM*2)+SRCM+80H
CONFIG1		EQU	(INTR*10H)+(EDF*8)+(WSB*2)+EMAP+0E0H
	
$IF (SERIAL = 2)
		CSEG	AT	01FF8H  ; Config Bytes for USB at 0x1FF8
$ELSE
		CSEG	AT	0FFF8H
$ENDIF
		DB	CONFIG0		; Config Byte 0
		DB	CONFIG1		; Config Byte 1
$ENDIF



		NAME	CONFIG

PUBLIC	RECEIVEBYTE         ; CHARACTER INPUT-ROUTINE 
PUBLIC	SENDBYTE            ; CHARACTER OUTPUT-ROUTINE 
PUBLIC	SENDCHECK           ; CHECK OUTPUT STATUS OF SERIAL INTERFACE
PUBLIC  SERINT_ENABLE       ; ENABLE SERIAL INTERRUPT
PUBLIC  IDENT_STRING        ; IDENTIFIER STRING
PUBLIC  INT_ADR_OFF         ; OFFSET FOR INTERRUPT VECTORS

$IF __MODBIN__
$IF (__INTR4__ = 0)
MONSTART	LIT	'MONSTART_B2'
MONBREAK	LIT	'MONBREAK_B2'
SERBREAK	LIT	'SERBREAK_B2'
SINTENABLE	LIT	'SINTENABLE_B2'
WARM_START	LIT	'WARM_START_B2'
EXT_UART	LIT	'EXT_UART_B2'
$ELSE
MONSTART	LIT	'MONSTART_B'
MONBREAK	LIT	'MONBREAK_B'
SERBREAK	LIT	'SERBREAK_B'
SINTENABLE	LIT	'SINTENABLE_B'
WARM_START	LIT	'WARM_START_B'
EXT_UART	LIT	'EXT_UART_B'
$ENDIF
$ELSE
$IF (__INTR4__ = 0)
MONSTART	LIT	'MONSTART_S2'
MONBREAK	LIT	'MONBREAK_S2'
SERBREAK	LIT	'SERBREAK_S2'
SINTENABLE	LIT	'SINTENABLE_S2'
WARM_START	LIT	'WARM_START_S2'
EXT_UART	LIT	'EXT_UART_S2'
$ELSE
MONSTART	LIT	'MONSTART_S'
MONBREAK	LIT	'MONBREAK_S'
SERBREAK	LIT	'SERBREAK_S'
SINTENABLE	LIT	'SINTENABLE_S'
WARM_START	LIT	'WARM_START_S'
EXT_UART	LIT	'EXT_UART_S'
$ENDIF
$ENDIF

EXTRN ECODE:FAR (MONSTART)    ; START OF MONITOR-51
EXTRN ECODE:FAR (MONBREAK)    ; BREAK RESTART OF MONITOR-251  
EXTRN ECODE:FAR (SERBREAK)    ; SERIAL INTERRUPT ENTRY OF MONITOR-251
EXTRN HDATA:BYTE(SINTENABLE)  ; SERIAL INTERRUPT ENABLE FLAG
EXTRN HDATA:BYTE(WARM_START)  ; WARM START FLAG
EXTRN HDATA:BYTE(EXT_UART)    ; EXTERNAL UART FLAG

; SFR SYMBOLS
TMOD    DATA    89H
TH1     DATA    8DH
SCON    DATA    98H
TR1     BIT     8EH
SBUF    DATA    99H
TI      BIT     99H
RI      BIT     98H
ACC     DATA    0E0H
ES	BIT	0ACH
EX0     BIT     0A8H
PSW1	DATA	0D1H
PCON	DATA	087H
EA	BIT	0AFH
IPH0	DATA	0B7H
IPL0	DATA	0B8H

INSTALLCODE	SEGMENT ECODE
		RSEG INSTALLCODE

$IF (SERIAL = 0)
;********************************************************************
;*  Using TIMER 1 to Generate Baud Rates                            *
;*  Oscillator frequency = 11.059 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************


InitSerial:	LABEL   FAR
		MOV	TMOD,#00100000B		;C/T = 0, Mode = 2
		MOV	TH1,#0FDH
		SETB	TR1
		MOV	SCON,#01011010B ; Init Serial Interface
		ECALL	MONSTART

IDENT_STRING:	DB	'MONITOR-251 USING TIMER 1 FOR BAUDRATES',0

$ENDIF

$IF (SERIAL = 1)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates                            *
;********************************************************************
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H

RCAPVAL  EQU  65536 - (XTAL / (BAUDRATE * 32))

InitSerial:	LABEL   FAR
		LJMP	Next
Next:		MOV	T2CON,#30H
		MOV	RCAP2H,#HIGH (RCAPVAL)
		MOV	RCAP2L,#LOW (RCAPVAL)
	        SETB	T2CON.2         ; start timer
		MOV	SCON,#01011010B ; Init Serial Interface
		ECALL	MONSTART

IDENT_STRING:	DB	'MONITOR-251 USING TIMER 2 FOR BAUDRATES',0
$ENDIF

$IF (SERIAL = 0 OR SERIAL = 1)
;********************************************************************
;*  Interface via standard on-chip UART                             *
;********************************************************************

SENDBYTE	PROC	NEAR
		CLR	TI		; Only A & PSW can be destroyed!
		MOV	SBUF,A
		RET
        	ENDP

SENDCHECK	PROC	NEAR
		JNB	TI,$		; Only A & PSW can be destroyed!
		RET
         	ENDP

RECEIVEBYTE	PROC	NEAR
		JNB	RI,$		; Only A & PSW can be destroyed!
		MOV	A,SBUF
		CLR	RI
		RET
           	ENDP

SERINT_ENABLE	PROC	NEAR
		CLR	TI		; No Transmitter Interrupt yet
		SETB	ES              ; Enable Serial Interrupt
		RET
		ENDP

MBREAK:		LABEL	FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	MNOTENABLED
		CLR	ES		; Disable Serial Interrupt
		SETB	TI		; Set Transmitter Interrupt Flag
MNOTENABLED:	POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP 	PSW1
$ENDIF
		EJMP	MONBREAK

SBREAK:		LABEL	FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	SNOTENABLED
		CLR	ES		; Disable Serial Interrupt
		SETB	TI		; Set Transmitter Interrupt Flag
		POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	SERBREAK

SNOTENABLED:	POP	DR0		; STANDARD INTERRUPT HANDLING
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	INT_ADR_OFF + 23H

$ENDIF


$IF (SERIAL = 3)
;********************************************************************
;*  Using MCB251SB external SIO for communication                   *
;********************************************************************
SIOCLK	  EQU  1843200        ; EXTERNAL SIO XTAL FREQUENZY
BAUDDIV   EQU  (SIOCLK / 16) / BAUDRATE
SIOADDR	  EQU  0FFFFFF00H     ; SIO Address

InitSerial:	LABEL   FAR
		MOV	DR0,#SIOADDR+3
		MOV	A,#83H		; Select Baudrate Registers
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR
		MOV	A,#BYTE0 (BAUDDIV)
		MOV	@DR0,R11
		INC	DR0,#1
		MOV	A,#BYTE1 (BAUDDIV)
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR+3
		MOV	A,#03H		; Mode: 8-bit, 1 stop, no parity
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR+1
		CLR	A
		MOV	@DR0,R11	; disable all interrupts
		MOV	DR0,#SIOADDR+4
		MOV	@DR0,R11
		ECALL	MONSTART

IDENT_STRING:	DB	'MCB251SB USING EXTERNAL SIO',0

SENDCHECK	PROC	NEAR
		PUSH	DR0
sendcheck1:	MOV	DR0,#SIOADDR+5		; LSR
		MOV	R11,@DR0		; Check if Ready
		JNB	ACC.5,sendcheck1
		POP	DR0
		RET
         	ENDP

SENDBYTE	PROC	NEAR
		PUSH	DR0
		MOV	DR0,#SIOADDR
		MOV	@DR0,R11
		POP	DR0
		RET
        	ENDP

RECEIVEBYTE	PROC	NEAR
		PUSH	DR0
receivebyte1:	MOV	DR0,#SIOADDR+5		; LSR
		MOV	R11,@DR0		; Check if Ready
		JNB	ACC.0,receivebyte1
		MOV	DR0,#SIOADDR
		MOV	R11,@DR0
		POP	DR0	
		RET  	
           	ENDP

SERINT_ENABLE	PROC	NEAR
		MOV	DR0,#SIOADDR+1
		MOV	A,#1		; enable Data Available Interrupt
		MOV	@DR0,R11
		SETB	EX0             ; Enable External Interrupt 0
		RET
		ENDP

MBREAK:		LABEL	FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	MNOTENABLED
		CLR	EX0		; Disable External Interrupt 0
		MOV	DR0,#SIOADDR+1
		CLR	A		; Disable SIO Interrupts
		MOV	@DR0,R11
MNOTENABLED:	POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP 	PSW1
$ENDIF
		EJMP	MONBREAK

EXT_SBREAK:	LABEL	FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	SNOTENABLED
		CLR	EX0		; Disable External Interrupt 0
		MOV	DR0,#SIOADDR+1
		CLR	A		; Disable SIO Interrupts
		MOV	@DR0,R11
		POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	SERBREAK

SNOTENABLED:	POP	DR0		; STANDARD INTERRUPT HANDLING
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	INT_ADR_OFF + 3H
$ENDIF

$IF (SERIAL = 2)
;********************************************************************
;*  Using Intel USBM Rev.B Baudrate 19200bps                        *
;********************************************************************
P1		DATA    090H

USB_BAUDRATE	EQU	57600	; USB Board works at 57600 bps


SIOCLK	  EQU  1843200        ; EXTERNAL SIO XTAL FREQUENZY
BAUDDIV   EQU  (SIOCLK / 16) / USB_BAUDRATE
SIOADDR	  EQU  0FFFFFFC0H     ; SIO Address

$IF (PAGEM)
IDENT_STRING:	DB	'Intel USBM Eval Board Rev. B (Page Mode)',0
$ELSE
IDENT_STRING:	DB	'Intel USBM Eval Board Rev. B (Non-Page Mode)',0
$ENDIF

Flash_LEDs      PROC    NEAR
		MOV     A,#01H
	        MOV     R0,#0
                MOV     R1,#0
Flash_loop:     SETB    C
                MOV     P1,A
Flash_wait:     DJNZ    R0,Flash_wait
                NOP
                DJNZ    R1,Flash_wait
                SLL     R11
                JNZ     Flash_loop
		RET
		ENDP

InitSerial:	LABEL   FAR
; Blink LED's on the USB Board
					; Check if external UART present
		MOV	DR0,#SIOADDR+7
		MOV	R11,@DR0
		CPL	A
		MOV	@DR0,R11
		NOP
		NOP
		CMP	R11,@DR0
		JE	External_UART	
; No External UART present
; Using TIMER 2 to Generate Baud Rates
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H
USB_XTAL EQU  12000000 * 2 ; double for broken timer 2 divider!!!

RCAPVAL  EQU  65536 - (USB_XTAL / (USB_BAUDRATE * 32))

Onchip_UART:	MOV	WR0,#WORD2 (EXT_UART)  ; Set ExtUART Flag
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	A,#0
		MOV	@DR0,R11

		MOV	T2CON,#30H
		MOV	RCAP2H,#HIGH (RCAPVAL)
		MOV	RCAP2L,#LOW (RCAPVAL)
	        SETB	T2CON.2         ; start timer
		MOV	SCON,#01011010B ; Init Serial Interface
		MOV	WR0,#WORD2 (WARM_START)  ; Check Warm Start Flag
		MOV	WR2,#WORD0 (WARM_START)
		MOV	R11,@DR0
		JZ	NoWARM_START_I
		JB	PCON.4,NoWARM_START_I
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	NOT_ENA_WARM_I
		SETB	ES              ; Enable Serial Interrupt
		SETB	EA
		ORL	IPH0,#10H	; Set to highest Priority
		SETB	IPL0.4
NOT_ENA_WARM_I:	EJMP	INT_ADR_OFF

NoWARM_START_I:	ANL	PCON,#0EFH	; Clear Power Off Flag (POF)
		CLR	A	
		MOV	@DR0,R11
		CALL	Flash_LEDs
		MOV	P1,#0FEH
		ECALL	MONSTART

; External UART present
External_UART:	MOV	WR0,#WORD2 (EXT_UART)  ; Set ExtUART Flag
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	A,#0FFH
		MOV	@DR0,R11

		MOV	DR0,#SIOADDR+3
		MOV	A,#83H		; Select Baudrate Registers
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR
		MOV	A,#BYTE0 (BAUDDIV)
		MOV	@DR0,R11
		INC	DR0,#1
		MOV	A,#BYTE1 (BAUDDIV)
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR+3
		MOV	A,#03H		; Mode: 8-bit, 1 stop, no parity
		MOV	@DR0,R11
		MOV	DR0,#SIOADDR+1
		CLR	A
		MOV	@DR0,R11	; disable all interrupts
		MOV	DR0,#SIOADDR+4
		MOV	@DR0,R11
		MOV	WR0,#WORD2 (WARM_START)  ; Check Warm Start Flag
		MOV	WR2,#WORD0 (WARM_START)
		MOV	R11,@DR0
		JZ	NoWARM_START_E
		JB	PCON.4,NoWARM_START_E
		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	NOT_ENA_WARM_E
		MOV	DR0,#SIOADDR+1
		MOV	A,#1		; enable Data Available Interrupt
		MOV	@DR0,R11
		SETB	EX0             ; Enable External Interrupt 0
		SETB	EA		; Enable All Interrupts
		ORL	IPH0,#01H	; Set to highest Priority
		SETB	IPL0.0
NOT_ENA_WARM_E:	EJMP	INT_ADR_OFF

NoWARM_START_E:	ANL	PCON,#0EFH	; Clear Power Off Flag (POF)
		CLR	A	
		MOV	@DR0,R11
		CALL	Flash_LEDs
		MOV	P1,#0FFH
		ECALL	MONSTART

SENDCHECK	PROC	NEAR
		PUSH	DR0
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JNZ	ext_sendcheck1	

int_sendcheck1:	JNB	TI,$		; Only A & PSW can be destroyed!
		POP	DR0
		RET

ext_sendcheck1:	MOV	DR0,#SIOADDR+5		; LSR
		MOV	R11,@DR0		; Check if Ready
		JNB	ACC.5,ext_sendcheck1
		POP	DR0
		RET
         	ENDP

SENDBYTE	PROC	NEAR
		PUSH	DR0
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R0,@DR0
		ANL	R0,R0
		JNE	ext_sendbyte

int_sendbyte:	CLR	TI		; Only A & PSW can be destroyed!
		MOV	SBUF,A
		POP	DR0
		RET

ext_sendbyte:	MOV	DR0,#SIOADDR
		MOV	@DR0,R11
		POP	DR0
		RET
        	ENDP

RECEIVEBYTE	PROC	NEAR
		PUSH	DR0
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JNZ	ext_rcvbyte1	

int_rcvbyte1:	JNB	RI,$		; Only A & PSW can be destroyed!
		MOV	A,SBUF
		CLR	RI
		POP	DR0
		RET

ext_rcvbyte1:	MOV	DR0,#SIOADDR+5		; LSR
		MOV	R11,@DR0		; Check if Ready
		JNB	ACC.0,ext_rcvbyte1
		MOV	DR0,#SIOADDR
		MOV	R11,@DR0
		POP	DR0	
		RET  	
           	ENDP

SERINT_ENABLE	PROC	NEAR
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JNZ	ext_serint_ena

int_serint_ena:	CLR	TI		; No Transmitter Interrupt yet
		SETB	ES              ; Enable Serial Interrupt
		SETB	EA
		ORL	IPH0,#10H	; Set to highest Priority
		SETB	IPL0.4
		RET

ext_serint_ena:	MOV	DR0,#SIOADDR+1
		MOV	A,#1		; enable Data Available Interrupt
		MOV	@DR0,R11
		SETB	EX0             ; Enable External Interrupt 0
		SETB	EA		; Enable All Interrupts
		ORL	IPH0,#01H	; Set to highest Priority
		SETB	IPL0.0
		RET
		ENDP

MBREAK:		LABEL	FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
        	MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	MNOTENABLED

; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JNZ	ext_mbreak
int_mbreak:
		CLR	ES		; Disable Serial Interrupt
		SETB	TI		; Set Transmitter Interrupt Flag
		SJMP	MNOTENABLED

ext_mbreak:	CLR	EX0		; Disable External Interrupt 0
		MOV	DR0,#SIOADDR+1
		CLR	A		; Disable SIO Interrupts
		MOV	@DR0,R11
MNOTENABLED:	POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP 	PSW1
$ENDIF
		EJMP	MONBREAK


; Interrupt service routine for INT0  (external UART interrupt)
EXT_SBREAK:	LABEL   FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JZ	ext_SNOT_ENA  ; No External UART -- user interrupt

		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	ext_SNOT_ENA
		CLR	EX0		; Disable External Interrupt 0
		MOV	DR0,#SIOADDR+1
		CLR	A		; Disable SIO Interrupts
		MOV	@DR0,R11
		POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	SERBREAK

ext_SNOT_ENA:	POP	DR0		; STANDARD INTERRUPT HANDLING
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	INT_ADR_OFF + 3H


; Interrupt service routine for on-chip Serial Interrupt
SBREAK:	LABEL   FAR
$IF (__INTR4__ = 0)
		PUSH	PSW1
$ENDIF
		PUSH	ACC
		PUSH	DR0
; Check External UART
		MOV	WR0,#WORD2 (EXT_UART)
		MOV	WR2,#WORD0 (EXT_UART)
		MOV	R11,@DR0
		JNZ	int_SNOT_ENA  ; ext. UART present -- user interrupt

		MOV	WR0,#WORD2 SINTENABLE
		MOV	WR2,#WORD0 SINTENABLE
		MOV	R11,@DR0
		JZ	int_SNOT_ENA
		CLR	ES		; Disable Serial Interrupt
		SETB	TI		; Set Transmitter Interrupt Flag
		POP	DR0
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	SERBREAK

int_SNOT_ENA:	POP	DR0		; STANDARD INTERRUPT HANDLING
		POP	ACC
$IF (__INTR4__ = 0)
		POP	PSW1
$ENDIF
		EJMP	INT_ADR_OFF + 23H
$ENDIF

;-----------------------------------------------------------------------------

			          ; IS INSTALLED AT ADDRESS 0000H

FILLGAP         MACRO
$IF __MODSRC__
		NOP
$ENDIF
		NOP
		NOP
		NOP
		ENDM

INITSEG		SEGMENT CODE OFFS 0H   ; (Default placement 0FF0000H)
		RSEG	INITSEG

		LJMP	Start
$IF (SERIAL = 2 OR SERIAL = 3)
		EJMP	EXT_SBREAK	; External UART Device Interrupt
$ELSE
		EJMP	INT_ADR_OFF + 03H
$ENDIF
		FILLGAP
		EJMP	INT_ADR_OFF + 0BH
		FILLGAP
		EJMP	INT_ADR_OFF + 13H
		FILLGAP
		EJMP	INT_ADR_OFF + 1BH
		FILLGAP
$IF (SERIAL = 0 OR SERIAL = 1 OR SERIAL = 2)
		EJMP	SBREAK		; On-chip UART Device Interrupt
$ELSE
		EJMP	INT_ADR_OFF + 23H
$ENDIF
		FILLGAP
		EJMP	INT_ADR_OFF + 2BH
		FILLGAP
		EJMP	INT_ADR_OFF + 33H
		FILLGAP
		EJMP	INT_ADR_OFF + 3BH
		FILLGAP
		EJMP	INT_ADR_OFF + 43H
		FILLGAP
		EJMP	INT_ADR_OFF + 4BH
		FILLGAP
		EJMP	INT_ADR_OFF + 53H
		FILLGAP
		EJMP	INT_ADR_OFF + 5BH
		FILLGAP
		EJMP	INT_ADR_OFF + 63H
		FILLGAP
		EJMP	INT_ADR_OFF + 6BH
		FILLGAP
		EJMP	INT_ADR_OFF + 73H
		FILLGAP
		EJMP	MBREAK
		FILLGAP
		EJMP	INT_ADR_OFF + 83H
		FILLGAP
		EJMP	INT_ADR_OFF + 8BH
		FILLGAP
		EJMP	INT_ADR_OFF + 93H
		FILLGAP
		EJMP	INT_ADR_OFF + 9BH
		FILLGAP
		EJMP	INT_ADR_OFF + 0A3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0ABH
		FILLGAP
		EJMP	INT_ADR_OFF + 0B3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0BBH
		FILLGAP
		EJMP	INT_ADR_OFF + 0C3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0CBH
		FILLGAP
		EJMP	INT_ADR_OFF + 0D3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0DBH
		FILLGAP
		EJMP	INT_ADR_OFF + 0E3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0EBH
		FILLGAP
		EJMP	INT_ADR_OFF + 0F3H
		FILLGAP
		EJMP	INT_ADR_OFF + 0FBH
Start:		EJMP	InitSerial


		END
