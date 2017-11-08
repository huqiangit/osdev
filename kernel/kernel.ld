OUTPUT_FORMAT("elf32-i386")
ENTRY(main)
SECTIONS
{
	.grub_sig 0x100000 : AT(0x100000)
	{
		*(.grub_sig)
	}
	.text :
	{
		*(.text)
	}
	.data :
	{
		*(.data)
	}
	.bss :
	{
		*(.bss)
	}
	/DISCARD/ :
	{
		*(.comment)
			*(.eh_frame)
	}
}
