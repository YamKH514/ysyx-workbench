ENTRY(_start)
PHDRS { text PT_LOAD; data PT_LOAD; }

SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;
  .text : {
    *(entry)
    *(.text*)
  } : text
  .rodata : {
    *(.rodata*)
  }
  etext = .;
  _etext = .;

  .data : AT(etext) {
    _data_start_load = .;
    _data_start = _sram_start;
    *(.data)
    _data_end = _sram_start + SIZEOF(.data);
  } : data
  edata = .;
  _data = .;

  . = _sram_start + SIZEOF(.data);
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  _heap_start = ALIGN(0x1000);
  _heap_end = _sram_start + _sram_size - 1;
  _stack_top = ALIGN(0x1000);
  . = _sram_start + _sram_size - 1;
  _stack_pointer = .;
  end = .;
  _end = .;
}
