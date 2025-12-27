MEMORY {
    SRAM(rwx): ORIGIN = 0x0f000000, LENGTH = 8K
    MROM(rx): ORIGIN = 0x20000000, LENGTH = 4K
  }

ENTRY(_start)
/* PHDRS { text PT_LOAD; data PT_LOAD; } */

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = ORIGIN(MROM);
  .text : {
    *(entry)
    *(.text*)
  } > MROM
  .rodata : {
    *(.rodata*)
  } > MROM
  etext = .;
  _etext = .;

  .data : {
    _data_start_load = LOADADDR(.data);
    _data_start = ORIGIN(SRAM);
    *(.data*)
    _data_end = ORIGIN(SRAM) + SIZEOF(.data);
  } > SRAM AT > MROM
  edata = .;
  _data = .;

  . = ORIGIN(SRAM) + SIZEOF(.data);
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
    _bss_end = .;
  } > SRAM
  _heap_start = ALIGN(0x1000);
  _heap_end = ORIGIN(SRAM) + LENGTH(SRAM);
  _stack_top = ALIGN(0x1000);
  . = ORIGIN(SRAM) + LENGTH(SRAM);
  _stack_pointer = .;
  end = .;
  _end = .;
}
