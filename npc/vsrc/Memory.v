`include "common.vh"

module Memory(
    input               mem_clk_in,
    input               mem_rst_in,
    input       [31:0]  mem_r_addr_in,
    output  reg [31:0]  mem_r_data_out,
    input       [2:0]   mem_r_func_in,
    input       [31:0]  mem_w_addr_in,
    input       [31:0]  mem_w_data_in,
    input       [7:0]   mem_w_mask_in,

    input               mem_valid_in,
    output  reg         mem_ready_out
);

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);

reg state;
reg next_state;

reg     [31:0]  read_data;
reg     [2:0]   read_func;
reg     [1:0]   byte_off;
wire    [7:0]   data_b;
wire    [15:0]  data_h;

reg     [31:0]  write_addr;
reg     [31:0]  write_data;
reg     [7:0]   write_mask;

always @(posedge mem_clk_in) begin
    if (mem_rst_in) begin
        state <= `MEM_S_IDLE;
    end else begin
        state <= next_state;
    end

    read_data <= paddr_read(mem_r_addr_in);
    byte_off  <= mem_r_addr_in[1:0];
    read_func <= mem_r_func_in;
    write_addr <= mem_w_addr_in;
    write_data <= mem_w_data_in;
    write_mask <= mem_w_mask_in;
end

always @(*) begin
    mem_ready_out = 1'b0;
    case (state)
    `MEM_S_IDLE: begin
        mem_ready_out = 1'b1;
        if (mem_valid_in) begin
            next_state = `MEM_S_WRITE;
        end
    end
    `MEM_S_WRITE: begin
        paddr_write(write_addr, write_data, write_mask);
        next_state = `MEM_S_IDLE;
    end
    endcase
end

assign data_b = {8{byte_off == 2'b00}} & read_data[7:0]  |
                {8{byte_off == 2'b01}} & read_data[15:8] |
                {8{byte_off == 2'b10}} & read_data[23:16]|
                {8{byte_off == 2'b11}} & read_data[31:24];

assign data_h = byte_off[1] == 1'b0 ? read_data[15:0] : read_data[31:16];

assign mem_r_data_out = {32{read_func == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{read_func == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{read_func == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{read_func == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{read_func == `MEM_READ_FUNC_LW}}  & read_data ;

endmodule
