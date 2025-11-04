`include "common.vh"

module Memory(
    input               clk,
    input               rst,
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

reg mem_ready_r;

reg state;
reg next_state;

reg     [31:0]  read_data_r;
reg     [2:0]   read_func_r;
reg     [1:0]   byte_off_r;
wire    [7:0]   data_b;
wire    [15:0]  data_h;

reg     [31:0]  write_addr_r;
reg     [31:0]  write_data_r;
reg     [7:0]   write_mask_r;

always @(posedge clk) begin
    if (rst) begin
        state <= `MEM_S_IDLE;
    end else begin
        state <= next_state;
    end

    read_data_r  <= paddr_read(mem_r_addr_in);
    byte_off_r   <= mem_r_addr_in[1:0];
    read_func_r  <= mem_r_func_in;
    write_addr_r <= mem_w_addr_in;
    write_data_r <= mem_w_data_in;
    write_mask_r <= mem_w_mask_in;
end

always @(*) begin
    case (state)
        `MEM_S_IDLE: begin
            if (mem_valid_in) begin
                next_state = `MEM_S_WRITE;
            end
        end
        `MEM_S_WRITE: begin
            next_state = `MEM_S_IDLE;
        end
    endcase
end

assign mem_ready_out = mem_ready_r;

always @(posedge clk) begin
    if (rst) begin
        mem_ready_r <= 1'b1;
    end else begin
        case (state)
            `MEM_S_IDLE: begin
                mem_ready_r <= 1'b1;
            end
            `MEM_S_WRITE: begin
                mem_ready_r <= 1'b0;
                paddr_write(write_addr_r, write_data_r, write_mask_r);
            end
        endcase
    end
end

assign data_b = {8{byte_off_r == 2'b00}} & read_data_r[7:0]  |
                {8{byte_off_r == 2'b01}} & read_data_r[15:8] |
                {8{byte_off_r == 2'b10}} & read_data_r[23:16]|
                {8{byte_off_r == 2'b11}} & read_data_r[31:24];

assign data_h = byte_off_r[1] == 1'b0 ? read_data_r[15:0] : read_data_r[31:16];

assign mem_r_data_out = {32{read_func_r == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{read_func_r == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{read_func_r == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{read_func_r == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{read_func_r == `MEM_READ_FUNC_LW}}  & read_data_r ;

endmodule
