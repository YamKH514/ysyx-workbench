module SRAM(
    input               clk,
    input               rst,
    input               sram_re_in,
    input       [31:0]  sram_r_addr_in,
    output  reg [31:0]  sram_r_data_out,
    input               sram_we_in,
    input       [31:0]  sram_w_addr_in,
    input       [31:0]  sram_w_data_in,
    input       [7:0]   sram_w_mask_in,

    input               lsu_to_sram_valid_in,
    output  reg         sram_to_lsu_ready_out
);

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);

reg     [31:0]  read_data_r;

parameter S_IDLE = 1'd0;
parameter S_WORK = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        sram_to_lsu_ready_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                sram_to_lsu_ready_out <= 1'b0;
                if (lsu_to_sram_valid_in) begin
                    sram_to_lsu_ready_out <= 1'b1;
                end
            end
            S_WORK: begin
                sram_to_lsu_ready_out <= 1'b0;
            end
            default: begin
                sram_to_lsu_ready_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    case (state)
        S_IDLE: begin
            if (lsu_to_sram_valid_in) begin
                next_state = S_WORK;
                if (sram_we_in & lsu_to_sram_valid_in) begin
                    paddr_write(sram_w_addr_in, sram_w_data_in, sram_w_mask_in);
                end else if (sram_re_in & lsu_to_sram_valid_in) begin
                    read_data_r = paddr_read(sram_r_addr_in);
                end
            end
        end
        S_WORK: begin
            next_state = S_IDLE;
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

// always @(*) begin
//     read_data_r = 0;
//     if (sram_we_in & lsu_to_sram_valid_in) begin
//         paddr_write(sram_w_addr_in, sram_w_data_in, sram_w_mask_in);
//     end
//     else if (sram_re_in & lsu_to_sram_valid_in) begin
//         read_data_r = paddr_read(sram_r_addr_in);
//     end
// end

assign sram_r_data_out = read_data_r;

endmodule
