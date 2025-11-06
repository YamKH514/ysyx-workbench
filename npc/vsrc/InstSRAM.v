module InstSRAM (
    input       [31:0]  inst_sram_addr_in,
    output  reg [31:0]  inst_sram_data_out
);

import "DPI-C" function int get_inst(input int pc);

assign inst_sram_data_out = get_inst(inst_sram_addr_in);

endmodule
