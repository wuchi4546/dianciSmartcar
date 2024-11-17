;-----------------------------------------------------------------------
; instat function for the external SIO interface of the MCB251 board
;-----------------------------------------------------------------------

; C prototype:   bit instat (void);

$include (..\..\asm\reg251s.inc)   ; Register defintion file

$IF (MCB251V2)
SIOADDR	  EQU  0FFFFE700H     ; SIO Address
$ELSE
SIOADDR	  EQU  0FFFFFF00H     ; SIO Address
$ENDIF

PUBLIC	  instat

EXTERN EBIT       (XSIO_charflag)

?PR?instat SEGMENT CODE
	RSEG	?PR?instat

instat		PROC	NEAR
		MOV	C,XSIO_charflag
		JC	done
		MOV	DR0,#SIOADDR		; LSR
		MOV	R11,@DR0+5
		MOV	C,ACC.0
done:		RET  	

		ENDP

		END


