module SRAM(
    // input               clk,
    // input               rst,
    input               sram_re_in,
    input       [31:0]  sram_r_addr_in,
    output  reg [31:0]  sram_r_data_out,
    input               sram_we_in,
    input       [31:0]  sram_w_addr_in,
    input       [31:0]  sram_w_data_in,
    input       [7:0]   sram_w_mask_in
);

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);

reg     [31:0]  read_data_r;

always @(*) begin
    read_data_r = 0;
    if (sram_we_in) begin
        paddr_write(sram_w_addr_in, sram_w_data_in, sram_w_mask_in);
    end
    else if (sram_re_in) begin
        read_data_r = paddr_read(sram_r_addr_in);
    end
end

assign sram_r_data_out = read_data_r;

endmodule
