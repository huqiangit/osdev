Code_DPL_0 equ 0x0000
Code_DPL_1 equ 0x0020
Code_DPL_2 equ 0x0040
Code_DPL_3 equ 0x0060

Code_P_0 equ 0x0000
Code_P_1 equ 0x0080

Code_TYPE_A_0 equ 0x0000
Code_TYPE_A_1 equ 0x0001
Code_TYPE_R_0 equ 0x0000
Code_TYPE_R_1 equ 0x0002
Code_TYPE_C_0 equ 0x0000
Code_TYPE_C_1 equ 0x0004

Code_G_0 equ 0x0000
Code_G_1 equ 0x8000

Code_D_0 equ 0x0000
Code_D_1 equ 0x4000

Code_AVL_0 equ 0x0000
Code_AVL_1 equ 0x1000

; usage: Descriptor Base, Limit, Attr
;        Base:  dd (32)
;        Limit: dd (20)
;        Attr:  dw (16)
%macro DescCode 3
	dw %2 & 0xFFFF				; 段界限 1				(2 字节)
	dw %1 & 0xFFFF                          ; 段基址 1				(2 字节)

	db (%1 >> 16) & 0xFF			; 段基址 2				(1 字节)
	dw ((%2 >> 8) & 0x0F00) | (%3 & 0xD0FF)	; 属性 1 + 段界限 2 + 属性 2		(2 字节)
	db (%1 >> 24) & 0xFF                    ; 段基址 3				(1 字节)
%endmacro

