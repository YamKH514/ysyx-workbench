`include "common.vh"

module Memory(
    input               mem_re_in,
    input       [31:0]  mem_r_addr_in,
    output  reg [31:0]  mem_r_data_out,
    input       [2:0]   mem_r_func_in,
    input               mem_we_in,
    input       [31:0]  mem_w_addr_in,
    input       [31:0]  mem_w_data_in,
    input       [7:0]   mem_w_mask_in
);

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);

reg     [31:0]  read_data_r;
reg     [1:0]   byte_off_r;
wire    [7:0]   data_b;
wire    [15:0]  data_h;

always @(*) begin
    read_data_r = 0;
    if (mem_we_in) begin
        paddr_write(mem_w_addr_in, mem_w_data_in, mem_w_mask_in);
    end
    else if (mem_re_in) begin
        read_data_r = paddr_read(mem_r_addr_in);
    end
end

assign byte_off_r = mem_r_addr_in[1:0];

assign data_b = {8{byte_off_r == 2'b00}} & read_data_r[7:0]  |
                {8{byte_off_r == 2'b01}} & read_data_r[15:8] |
                {8{byte_off_r == 2'b10}} & read_data_r[23:16]|
                {8{byte_off_r == 2'b11}} & read_data_r[31:24];

assign data_h = byte_off_r[1] == 1'b0 ? read_data_r[15:0] : read_data_r[31:16];

assign mem_r_data_out = {32{mem_r_func_in == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{mem_r_func_in == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{mem_r_func_in == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{mem_r_func_in == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{mem_r_func_in == `MEM_READ_FUNC_LW}}  & read_data_r ;

endmodule
