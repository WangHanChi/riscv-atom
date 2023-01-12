OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  /*. = 0x80000000;*/
  . = 0x00000000;
  .text.init : { *(.text.init) }
  . = ALIGN(0x1000);
  .tohost : { *(.tohost) }
  . = ALIGN(0x1000);
  .text : { *(.text) }
  . = ALIGN(0x1000);
  . = 0x04000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
  _end = .;
}

