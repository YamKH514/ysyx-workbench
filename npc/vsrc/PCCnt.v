module PCCnt(
    input           clk,
    input           rst,

    input   [31:0]  pc_target_pc_i,
    output  [31:0]  pc_cnt_pc_o,

    input           need_flush_i,
    output          pc_ifu_valid_o,
    input           pc_ifu_ready_i
);

parameter RESET_PC = 32'h30000000;

reg [31:0] pc_r;

assign pc_cnt_pc_o = pc_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= RESET_PC;
    end else if (need_flush_i) begin
        pc_r <= pc_target_pc_i;
    end else if (pc_ifu_valid_o & pc_ifu_ready_i) begin
        pc_r <= pc_r + 4;
    end
end

assign pc_ifu_valid_o = !rst;

endmodule
