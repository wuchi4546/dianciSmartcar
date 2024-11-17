;-----------------------------------------------------------------------
; putchar function for the external SIO interface of the MCB251 board
;-----------------------------------------------------------------------

; C prototype:   char putchar (char);

$include (reg251s.inc)   ; Register defintion file

$IF (MCB251V2)
SIOADDR	  EQU  0FFFFE700H     ; SIO Address
$ELSE
SIOADDR	  EQU  0FFFFFF00H     ; SIO Address
$ENDIF
CRchar  	EQU	0DH
LFchar		EQU	0AH
CntlQ		EQU	11H
CntlS		EQU	13H


PUBLIC	  putchar

EXTERN EBIT       (XSIO_charflag)
EXTERN EDATA:BYTE (XSIO_char)


?PR?putchar SEGMENT CODE
	RSEG	?PR?putchar

putchar		PROC	NEAR
$IF C251V2

$ELSE
		MOV	A,R7
$ENDIF
		CJNE	A,#LFchar,putchar1
		MOV	A,#CRchar
		CALL	putchar1
		MOV	A,#LFchar

putchar1:	MOV	DR0,#SIOADDR
		MOV	R10,@DR0+5		; LSR
		JNB	B.0,putchar2		; Check if Input Char Ready
		MOV	R4,@DR0
		CJNE	R4,#CntlS,putcharsave

putchar3:	MOV	R10,@DR0+5		; LSR
		JNB	B.0,putchar3		; Check if Input Char Ready
		MOV	R4,@DR0
		CJNE	R4,#CntlQ,putchars2
	        SJMP	putchar2
putchars2:	CJNE	R4,#CntlS,putchars3
		SJMP	putchar3
putchars3:	JB	XSIO_charflag,putchar3
		MOV	XSIO_char,R4
		SETB	XSIO_charflag
		SJMP	putchar3

putcharsave:	CJNE	R4,#CntlQ,putchars1
		SJMP	putchar2
putchars1:	JB	XSIO_charflag,putchar2
		MOV	XSIO_char,R4
		SETB	XSIO_charflag

putchar2:	MOV	R10,@DR0+5		; LSR
		JNB	B.5,putchar2		; Check if Ready
		MOV	@DR0,R11
		RET
		ENDP

		END
