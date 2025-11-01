module InstSRAM (
    input               inst_sram_clk_in,
    input       [31:0]  inst_sram_addr_in,
    output  reg [31:0]  inst_sram_data_out,
    input               inst_sram_valid_in,
    output  reg         inst_sram_ready_out
);

wire [31:0]  data;

import "DPI-C" function int get_inst(input int pc);
assign data = get_inst(inst_sram_addr_in);

always @(posedge inst_sram_clk_in) begin
    if (inst_sram_valid_in) begin
        inst_sram_data_out  <= data;
        inst_sram_ready_out <= 1;
    end else begin
        inst_sram_ready_out <= 0;
    end
end

endmodule
