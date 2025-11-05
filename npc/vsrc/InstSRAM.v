module InstSRAM (
    // input               clk,
    input       [31:0]  inst_sram_addr_in,
    output  reg [31:0]  inst_sram_data_out

    // input               inst_sram_valid_in,
    // output  reg         inst_sram_ready_out
);

import "DPI-C" function int get_inst(input int pc);

assign inst_sram_data_out = get_inst(inst_sram_addr_in);

// reg [31:0]  addr;
// reg [31:0]  data;

// assign addr = inst_sram_addr_in;
// assign data = get_inst(addr);

// always @(posedge clk) begin
//     if (inst_sram_valid_in) begin
//         inst_sram_data_out  <= data;
//         inst_sram_ready_out <= 1'b1;
//     end else begin
//         inst_sram_ready_out <= 1'b0;
//     end
// end

endmodule
