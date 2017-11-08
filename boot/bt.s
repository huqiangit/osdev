extern f_add



[section .text]
[bits 16]
global _start
_start:
	cli
	cld

	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax

seta20.1:
	in	al, 0x64               ;# Wait for not busy
	test    al, 0x02
	jnz     seta20.1

	mov    al, 0xd1               ;# 0xd1 -> port 0x64
	out    0x64, al

seta20.2:
	in     al, 0x64               ;# Wait for not busy
	test   al, 0x02
	jnz    seta20.2

	mov    al, 0xdf               ;# 0xdf -> port 0x60
	out    0x60, al
	

  	lgdt   gdtdesc
    	mov    eax, cr0
      	or     eax, CR0_PE_ON
        mov    cr0, eax
	  
	jmp	dword SelectorFlatC:(BaseOfLoaderPhyAddr+LABEL_PM_START)

[bits 32]
	push dword [i]
	push dword [j]
	call f_add
	add esp, 8

	jmp $
	
[segment .data]
i	dd 1
j	dd 2


