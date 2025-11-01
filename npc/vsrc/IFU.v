`include "common.vh"

module IFU(
    input               ifu_rst_in,
    input               ifu_clk_in,
    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_req_addr_out,
    input       [31:0]  ifu_req_inst_in,
    output  reg [31:0]  ifu_inst_out,

    output  reg         ifu_sram_valid_out,
    input               ifu_sram_ready_in,

    output  reg         ifu_idu_valid_out,
    input               ifu_idu_ready_in,

    output  reg         ifu_pc_cnt_valid_out
);

reg [1:0]   state;
reg [1:0]   next_state;

always @(posedge ifu_clk_in) begin
    if (ifu_rst_in) begin
        state <= `S_IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    if (!ifu_rst_in) begin
        ifu_pc_cnt_valid_out = 0;
        ifu_req_addr_out = 32'h0;
        ifu_inst_out = 32'h0;
        ifu_sram_valid_out = 1'b0;
        ifu_idu_valid_out = 1'b0;
        next_state = state;
        case (state)
            `S_IDLE: begin
                ifu_pc_cnt_valid_out = 1;
                ifu_sram_valid_out = 1;
                ifu_req_addr_out = ifu_current_pc_in;
                next_state = `S_WAIT_SRAM;
            end
            `S_WAIT_SRAM: begin
                if (ifu_sram_ready_in) begin
                    ifu_idu_valid_out = 1;
                    ifu_inst_out = ifu_req_inst_in;
                    next_state = `S_WAIT_IDU;
                end
            end
            `S_WAIT_IDU: begin
                ifu_inst_out = ifu_req_inst_in;
                if (ifu_idu_ready_in) begin
                    next_state = `S_IDLE;
                end
            end
            default: begin
                next_state = `S_IDLE;
            end
        endcase
    end
end

endmodule
