ENTRY(_start)

MEMORY {
  flash (r x) : ORIGIN = 0x30000000, LENGTH = 128M
  sram  (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
  psram (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
}
REGION_ALIAS("REGION_BOOT", flash);
REGION_ALIAS("REGION_TEXT", sram);
REGION_ALIAS("REGION_RODATA", sram);
REGION_ALIAS("REGION_DATA", psram);
REGION_ALIAS("REGION_BSS", psram);

SECTIONS {
  . = ORIGIN(flash);
  .boot : {
    boot_start = .;
    *(entry)
    *(fsbl)
    boot_start = .;
  } > REGION_BOOT
  .text : {
    text_start = .;
    *(.text*)
    ASSERT(. <= ORIGIN(flash) + LENGTH(flash), ".text section too large for flash");
  } > REGION_TEXT AT > flash
  text_size = SIZEOF(.text);
  text_load_start = LOADADDR(.text);
  etext = .;
  _etext = .;
  .rodata : {
    rodata_start = .;
    *(.rodata*)
    rodata_end = .;
    ASSERT(. <= ORIGIN(flash) + LENGTH(flash), ".rodata section too large for flash");
  } > REGION_RODATA AT > flash
  rodata_size = SIZEOF(.rodata);
  rodata_load_start = LOADADDR(.rodata);
  .data : {
    data_start = .;
    *(.data*)
    *(.sdata*)
  } > REGION_DATA AT > flash
  data_size = SIZEOF(.data);
  data_load_start = LOADADDR(.data);
  edata = .;
  _data = .;
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > REGION_BSS
  _stack_top = ALIGN(0x1000);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);
}
