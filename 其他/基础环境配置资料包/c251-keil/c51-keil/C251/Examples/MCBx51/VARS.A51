;-----------------------------------------------------------------------
; variables for the external SIO interface of the MCB251 board
;-----------------------------------------------------------------------

PUBLIC	XSIO_char, XSIO_charflag

?ED?xsiovars	SEGMENT EDATA
		RSEG ?ED?xsiovars
XSIO_char:	DSB	1

?EB?xsiobits	SEGMENT EBIT
		RSEG ?EB?xsiobits
XSIO_charflag:	DBIT	1

		END

