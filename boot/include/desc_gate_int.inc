GateInt_DPL_0 equ 0x00
GateInt_DPL_1 equ 0x20
GateInt_DPL_2 equ 0x40
GateInt_DPL_3 equ 0x60

GateInt_P_0 equ 0x00
GateInt_P_1 equ 0x80

; usage: Gate Selector, Offset, DCount, Attr
;        Selector:  dw(16)
;        Offset:    dd(32)
;        DCount:    db(5)
;        Attr:      db(8)
%macro GateInt 4 
	dw (%2 & 0x0000FFFF)				; 偏移 1				(2 字节)
	dw (%1)					 	; 选择子				(2 字节)
	db %3 & 0x1F 
	db %4 & 0xEE
	dw ((%2 >> 16) & 0xFFFF) 			; 偏移 2				(2 字节)
%endmacro

