module PCCnt(
    input           clk,
    input           rst,

    input   [31:0]  pc_target_pc_i,
    output  [31:0]  pc_cnt_pc_o,

    input           wbu_pc_valid_i,
    output          wbu_pc_ready_o,
    output          pc_ifu_valid_o,
    input           pc_ifu_ready_i
);

parameter RESET_PC = 32'h30000000;

reg [31:0] pc_r;

assign pc_cnt_pc_o = pc_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= RESET_PC;
    end else if (wbu_pc_valid_i & wbu_pc_ready_o) begin
        pc_r <= pc_target_pc_i;
    end
end

assign wbu_pc_ready_o = state == S_IDLE & wbu_pc_valid_i;
assign pc_ifu_valid_o = state == S_BUSY;

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_BUSY;
    end else begin
        case (state)
            S_IDLE: begin
                if (wbu_pc_valid_i & wbu_pc_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (pc_ifu_valid_o & pc_ifu_ready_i) state <= S_IDLE;
            end
        endcase
    end
end

endmodule
