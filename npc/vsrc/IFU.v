`include "common.vh"

module IFU(
    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_req_addr_out,
    input       [31:0]  ifu_req_inst_in,
    output  reg [31:0]  ifu_inst_out
);

assign ifu_req_addr_out = ifu_current_pc_in;
assign ifu_inst_out = ifu_req_inst_in;

endmodule
