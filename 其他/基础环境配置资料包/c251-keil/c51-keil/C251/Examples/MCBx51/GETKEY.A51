;-----------------------------------------------------------------------
; _getkey function for the external SIO interface of the MCB251 board
;-----------------------------------------------------------------------

; C prototype:   char _getkey (void);

$include (..\..\asm\reg251s.inc)   ; Register defintion file

$IF (MCB251V2)
SIOADDR	  EQU  0FFFFE700H     ; SIO Address
$ELSE
SIOADDR	  EQU  0FFFFFF00H     ; SIO Address
$ENDIF

PUBLIC	  _getkey

EXTERN EBIT       (XSIO_charflag)
EXTERN EDATA:BYTE (XSIO_char)

?PR?_getkey SEGMENT CODE
	RSEG	?PR?_getkey

_getkey		PROC	NEAR
		JBC	XSIO_charflag,charthere

getkey1:	MOV	DR0,#SIOADDR		; LSR
		MOV	R11,@DR0+5		; Check if Ready
		JNB	ACC.0,getkey1
$IF (C251V2)
		MOV	R11,@DR0
$ELSE	
		MOV	R7,@DR0	
$ENDIF
		RET  	

charthere:	
$IF (C251V2)
		MOV	R11,XSIO_char
$ELSE	
		MOV	R7,XSIO_char
$ENDIF
		RET
		ENDP

		END


