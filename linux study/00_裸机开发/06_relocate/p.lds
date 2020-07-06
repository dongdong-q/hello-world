SECTIONS {
   . = 0x30000000;
   __code_start = .;
   . = ALIGN(4);
   .text   : { *(.text) }
   . = ALIGN(4);
   .rodata  : { *(.rodata) }
   . = ALIGN(4);
   .data : 
   { 
      data_load_addr = LOADADDR(.data);
	  . = ALIGN(4);
      data_start = . ;
      *(.data) 
      data_end = . ;
   }
   
   . = ALIGN(4);
   __bss_start = .;
   .bss  : { *(.bss) *(.COMMON) }
   __end = .;
}

