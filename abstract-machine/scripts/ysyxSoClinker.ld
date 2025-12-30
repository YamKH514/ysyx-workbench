MEMORY {
  mrom : ORIGIN = 0x20000000, LENGTH = 4K
  sram : ORIGIN = 0x0f000000, LENGTH = 8K
}

ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  . = ORIGIN(mrom);
  .text : {
    *(entry)
    *(.text*)
  } > mrom AT > mrom : text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  } > mrom AT > mrom
  _data_start = ORIGIN(sram);
  _data_load_start = .;
  .data : {
    *(.data*)
  } > sram AT > mrom : data
  _data_load_end = _data_load_start + SIZEOF(.data);
  edata = .;
  _data = .;
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  } > sram AT > sram
  . = ORIGIN(sram) + SIZEOF(.data);
  _heap_start = .;
  . = . + 0x1000;
  _heap_end = .;
  _stack_top = ALIGN(0x1000);
  _stack_pointer = ORIGIN(sram) + LENGTH(sram);
  end = .;
  _end = .;
}
