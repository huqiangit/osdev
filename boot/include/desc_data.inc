Data_DPL_0 equ 0x0000
Data_DPL_1 equ 0x0020
Data_DPL_2 equ 0x0040
Data_DPL_3 equ 0x0060

Data_P_0 equ 0x0000
Data_P_1 equ 0x0080

Data_TYPE_A_0 equ 0x0000
Data_TYPE_A_1 equ 0x0001
Data_TYPE_W_0 equ 0x0000
Data_TYPE_W_1 equ 0x0002
Data_TYPE_E_0 equ 0x0000
Data_TYPE_E_1 equ 0x0004

Data_G_0 equ 0x0000
Data_G_1 equ 0x8000

Data_B_0 equ 0x0000
Data_B_1 equ 0x4000

Data_AVL_0 equ 0x0000
Data_AVL_1 equ 0x1000


; usage: Descriptor Base, Limit, Attr
;        Base:  dd (32)
;        Limit: dd (20)
;        Attr:  dw (16)
%macro DescData 3
	dw %2 & 0xFFFF				; 段界限 1				(2 字节)
	dw %1 & 0xFFFF                          ; 段基址 1				(2 字节)

	db (%1 >> 16) & 0xFF			; 段基址 2				(1 字节)
	dw ((%2 >> 8) & 0x0F00) | (%3 & 0xD0F7)	; 属性 1 + 段界限 2 + 属性 2		(2 字节)
	db (%1 >> 24) & 0xFF                    ; 段基址 3				(1 字节)
%endmacro

