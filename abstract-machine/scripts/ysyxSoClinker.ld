MEMORY {
  flash (r x) : ORIGIN = 0x30000000, LENGTH = 16M
  sram  (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
  psram (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
  sdram (rwx) : ORIGIN = 0xa0000000, LENGTH = 128M
}
REGION_ALIAS("REGION_FSBL", flash);
REGION_ALIAS("REGION_SSBL", sdram);
REGION_ALIAS("REGION_TEXT", sdram);
REGION_ALIAS("REGION_RODATA", sdram);
REGION_ALIAS("REGION_DATA", sdram);
REGION_ALIAS("REGION_BSS", sdram);

ENTRY(_start)

SECTIONS {
  . = ORIGIN(flash);
  .fsbl : {
    fsbl_start = .;
    *(entry)
    *(fsbl)
    fsbl_end = .;
  } > REGION_FSBL AT > flash

  .ssbl : {
    . = ALIGN(4);
    ssbl_start = .;
    *(ssbl)
  } > REGION_SSBL AT > flash
  ssbl_size = SIZEOF(.ssbl);
  ssbl_load_start = LOADADDR(.ssbl);

  .text : {
    . = ALIGN(4);
    text_start = .;
    *(.text*)
  } > REGION_TEXT AT > flash
  text_size = SIZEOF(.text);
  text_load_start = LOADADDR(.text);
  etext = .;
  _etext = .;

  .rodata : {
    . = ALIGN(4);
    rodata_start = .;
    *(.rodata*)
    *(.srodata*)
    rodata_end = .;
  } > REGION_RODATA AT > flash
  rodata_size = SIZEOF(.rodata);
  rodata_load_start = LOADADDR(.rodata);

  .data : {
    . = ALIGN(4);
    data_start = .;
    *(.data*)
    *(.sdata*)
    data_end = .;
  } > REGION_DATA AT > flash
  data_size = SIZEOF(.data);
  data_load_start = LOADADDR(.data);
  data_extra_start = DEFINED(data_extra_start) ? data_extra_start : 0;
  data_extra_end = DEFINED(data_extra_end) ? data_extra_end : 0;
  data_extra_size = DEFINED(data_extra_size) ? data_extra_size : 0;
  data_extra_load_start = DEFINED(data_extra_load_start) ? data_extra_load_start : 0;
  edata = .;
  _data = .;

  .bss : {
    . = ALIGN(4);
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > REGION_BSS
  _bss_extra_start = DEFINED(_bss_extra_start) ? _bss_extra_start : 0;
  _bss_extra_end = DEFINED(_bss_extra_end) ? _bss_extra_end : 0;
  end = .;
  _end = .;

  _heap_start = ALIGN(0x1000);
  _heap_end = ORIGIN(sdram) + LENGTH(sdram);

  _stack_top = ORIGIN(sram);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
}
