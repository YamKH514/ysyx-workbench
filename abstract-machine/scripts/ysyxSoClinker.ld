ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } : text
  etext = .;
  _etext = .;
  .rodata : {
    *(.rodata*)
  }
  .data : AT(etext) {
    *(.data)
  } :data
  edata = .;
  _data = .;
  .bss : {
    _bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  _heap_start = _sram_start;
  . = _sram_start + 0x1000;
  _heap_end = .;
  _stack_top = ALIGN(0x1000);
  _stack_pointer = _sram_start + _sram_size;
  end = .;
  _end = .;
}
