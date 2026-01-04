ENTRY(_start)

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}
REGION_ALIAS("REGION_TEXT", mrom);
REGION_ALIAS("REGION_RODATA", mrom);
REGION_ALIAS("REGION_DATA", sram);
REGION_ALIAS("REGION_BSS", sram);

SECTIONS {
  .text : {
    *(entry)
    *(.text*)
    ASSERT(. <= ORIGIN(mrom) + LENGTH(mrom), ".text section too large for mrom");
  } > REGION_TEXT
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    rodata_end = .;
    ASSERT(. <= ORIGIN(mrom) + LENGTH(mrom), ".rodata section too large for mrom");
  } > REGION_RODATA
  .data : {
    data_start = .;
    *(.data*)
  } > REGION_DATA AT > mrom
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
  . = _stack_top + 0x800;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x4);
  _heap_end = . + 0x400;
}
