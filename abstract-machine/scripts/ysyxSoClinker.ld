ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
    ASSERT(. <= ORIGIN(mrom) + LENGTH(mrom), ".text section too large for mrom");
  } > mrom : text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
    ASSERT(. <= ORIGIN(mrom) + LENGTH(mrom), ".rodata section too large for mrom");
  } > mrom
  .data : {
    _data_start = .;
    *(.data*)
    _data_end = .;
  } > sram AT > mrom : data
  _load_data_start = LOADADDR(.data);
  _load_data_size = SIZEOF(.data);
  edata = .;
  _data = .;
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > sram
  _heap_start = ALIGN(0x1000);
  _stack_top = ALIGN(0x1000);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
  end = .;
  _end = .;
}
