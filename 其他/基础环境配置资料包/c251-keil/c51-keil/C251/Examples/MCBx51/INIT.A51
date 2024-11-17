;-----------------------------------------------------------------------
; Initilization of the external SIO interface of the MCB251 board
;-----------------------------------------------------------------------

$include (..\..\asm\reg251s.inc)   ; Register defintion file

BAUDRATE  EQU  57600          ; DEFINE THE BAUDRATE

SIOCLK	  EQU  1843200        ; EXTERNAL SIO XTAL FREQUENZY
BAUDDIV   EQU  (SIOCLK / 16) / BAUDRATE
$IF (MCB251V2)
SIOADDR	  EQU  0FFFFE700H     ; SIO Address
$ELSE
SIOADDR	  EQU  0FFFFFF00H     ; SIO Address
$ENDIF


PUBLIC	  XSIOinit            ; INITILIZE SERIAL INTERFACE

?PR?XSIOinit SEGMENT CODE
	RSEG	?PR?XSIOinit

XSIOinit	PROC NEAR
		MOV	DR0,#SIOADDR
		MOV	A,#83H		; Select Baudrate Registers
		MOV	@DR0+3,R11
		MOV	A,#BYTE0 (BAUDDIV)
		MOV	@DR0,R11
		MOV	A,#BYTE1 (BAUDDIV)
		MOV	@DR0+1,R11
		MOV	A,#03H		; Mode: 8-bit, 1 stop, no parity
		MOV	@DR0+3,R11
		CLR	A
		MOV	@DR0+1,R11	; disable all interrupts
		MOV	@DR0+4,R11
		RET
		ENDP

		END


