`include "common.vh"

module IFU(
    input               ifu_rst_in,
    input               ifu_clk_in,
    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_req_addr_out,
    input       [31:0]  ifu_req_inst_in,
    output  reg [31:0]  ifu_inst_out,

    input               inst_sram_ready_in,
    output  reg         inst_sram_valid_out,

    input               idu_ready_in,
    output  reg         idu_valid_out,

    input               pc_cnt_ready_in
);

reg [1:0]   state;
reg [1:0]   next_state;

always @(posedge ifu_clk_in) begin
    if (ifu_rst_in) begin
        state <= `IFU_S_IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    if (!ifu_rst_in) begin
        next_state = state;
        // ifu_req_addr_out = 32'h0;
        // ifu_inst_out = 32'h0;
        inst_sram_valid_out = 1'b0;
        idu_valid_out = 1'b0;
        case (state)
            `IFU_S_IDLE: begin
                if (pc_cnt_ready_in) begin
                    inst_sram_valid_out = 1;
                    ifu_req_addr_out = ifu_current_pc_in;
                    next_state = `IFU_S_WAIT_SRAM;
                end
            end
            `IFU_S_WAIT_SRAM: begin
                inst_sram_valid_out = 1;
                if (inst_sram_ready_in) begin
                    idu_valid_out = 1;
                    ifu_inst_out = ifu_req_inst_in;
                    next_state = `IFU_S_WAIT_IDU;
                end
            end
            `IFU_S_WAIT_IDU: begin
                idu_valid_out = 1;
                // ifu_inst_out = ifu_req_inst_in;
                if (idu_ready_in) begin
                    next_state = `IFU_S_IDLE;
                end
            end
            default: begin
                next_state = `IFU_S_IDLE;
            end
        endcase
    end
end

endmodule
