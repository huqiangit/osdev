%include "include/desc_code.inc"
%include "include/desc_data.inc"

[section boot vstart=0x7c00]
[bits 16]
	
	


[section magic start=510]
	db 0x55
	db 0xaa

