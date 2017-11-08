GateTask_DPL_0 equ 0x00
GateTask_DPL_1 equ 0x20
GateTask_DPL_2 equ 0x40
GateTask_DPL_3 equ 0x60

GateTask_P_0 equ 0x00
GateTask_P_1 equ 0x80

; usage: Gate Selector, Attr
;        Selector:  dw(16)
;        Attr:      db(8)
%macro GateTask 2 
	dw 0x0000					; 偏移 1				(2 字节)
	dw (%1)					 	; 选择子				(2 字节)
	db 0x00
	db %2 & 0xE5
	dw 0x0000					; 偏移 2				(2 字节)
%endmacro

