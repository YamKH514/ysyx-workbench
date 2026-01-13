ENTRY(_start)

MEMORY {
  flash (r x) : ORIGIN = 0x30000000, LENGTH = 128M
  sram  (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
  psram (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
}
REGION_ALIAS("REGION_TEXT", flash);
REGION_ALIAS("REGION_RODATA", flash);
REGION_ALIAS("REGION_DATA", psram);
REGION_ALIAS("REGION_BSS", psram);

SECTIONS {
  .text : {
    *(entry)
    *(.text*)
    ASSERT(. <= ORIGIN(flash) + LENGTH(flash), ".text section too large for flash");
  } > REGION_TEXT
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    rodata_end = .;
    ASSERT(. <= ORIGIN(flash) + LENGTH(flash), ".rodata section too large for flash");
  } > REGION_RODATA
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
  _stack_top = ALIGN(0x4);
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x4);
  _heap_end = ORIGIN(psram) + LENGTH(psram);
}
