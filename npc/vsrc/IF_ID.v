module IF_ID(
    input           clk,
                    rst,

    input  [31:0]   pc_i,
                    inst_i,
    input           need_flush_i,

    output [31:0]   pc_o,
                    inst_o,

    input           if_ifid_valid_i,
    output          if_ifid_ready_o,
    output          ifid_id_valid_o,
    input           ifid_id_ready_i
);

assign if_ifid_ready_o = if_ifid_valid_i & state == S_IDLE;
assign ifid_id_valid_o = state == S_BUSY & !need_flush_i;

reg [31:0] pc_r;
reg [31:0] inst_r;

assign pc_o = pc_r;
assign inst_o = inst_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        inst_r <= 'b0;
    end else if (if_ifid_valid_i & if_ifid_ready_o) begin
        pc_r <= pc_i;
        inst_r <= inst_i;
    end else if (need_flush_i | (ifid_id_valid_o & ifid_id_ready_i)) begin
        pc_r <= 'b0;
        inst_r <= 'b0;
    end
end

localparam S_W    = 2;
localparam S_IDLE = 2'd0;
localparam S_BUSY = 2'd1;

reg [S_W-1:0] state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (!need_flush_i & if_ifid_valid_i & if_ifid_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (need_flush_i | (ifid_id_valid_o & ifid_id_ready_i)) state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

endmodule
