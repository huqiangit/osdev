GateTrap_DPL_0 equ 0x00
GateTrap_DPL_1 equ 0x20
GateTrap_DPL_2 equ 0x40
GateTrap_DPL_3 equ 0x60

GateTrap_P_0 equ 0x00
GateTrap_P_1 equ 0x80

; usage: Gate Selector, Offset, DCount, Attr
;        Selector:  dw(16)
;        Offset:    dd(32)
;        DCount:    db(5)
;        Attr:      db(8)
%macro GateTrap 4 
	dw (%2 & 0x0000FFFF)				; 偏移 1				(2 字节)
	dw (%1)					 	; 选择子				(2 字节)
	db %3 & 0x1F 
	db %4 & 0xEF
	dw ((%2 >> 16) & 0xFFFF) 			; 偏移 2				(2 字节)
%endmacro

