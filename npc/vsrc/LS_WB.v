`include "common.vh"
module LS_WB(
    input           clk,
                    rst,

    input  [31:0] pc_i,
    input  [31:0] res_i,
    input  [31:0] rdata_i,
    input  [ 9:0] data_i,
    input  [31:0] csr_rdata_i,

    output [31:0] pc_o,
    output [31:0] res_o,
    output [31:0] rdata_o,
    output [ 9:0] data_o,
    output [31:0] csr_rdata_o,
`ifdef FOR_SIMULATION_ENV
    input  [31:0]   target_pc_i,
    output [31:0]   target_pc_o,
`endif
    input           ls_lswb_valid_i,
    output          ls_lswb_ready_o,
    output          lswb_wb_valid_o,
    input           lswb_wb_ready_i
);

assign ls_lswb_ready_o = ls_lswb_valid_i & state == S_IDLE;
assign lswb_wb_valid_o = state == S_BUSY;

reg [31:0] pc_r;
reg [31:0] res_r;
reg [31:0] rdata_r;
reg [ 9:0] data_r;
reg [31:0] csr_rdata_r;

assign pc_o = pc_r;
assign res_o = res_r;
assign rdata_o = rdata_r;
assign data_o = data_r;
assign csr_rdata_o = csr_rdata_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        res_r <= 'b0;
        rdata_r <= 'b0;
        data_r <= 'b0;
        csr_rdata_r <= 'b0;
    end else if (ls_lswb_valid_i & ls_lswb_ready_o) begin
        pc_r <= pc_i;
        res_r <= res_i;
        rdata_r <= rdata_i;
        data_r <= data_i;
        csr_rdata_r <= csr_rdata_i;
    end else if (lswb_wb_valid_o & lswb_wb_ready_i) begin
        pc_r <= 'b0;
        res_r <= 'b0;
        rdata_r <= 'b0;
        data_r <= 'b0;
        csr_rdata_r <= 'b0;
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
                if (ls_lswb_valid_i & ls_lswb_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (lswb_wb_valid_o & lswb_wb_ready_i) state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

`ifdef FOR_SIMULATION_ENV
reg [31:0] target_pc_r;
assign target_pc_o = target_pc_r;
always @(posedge clk) begin
    if (rst) begin
        target_pc_r <= 'b0;
    end else if (ls_lswb_valid_i & ls_lswb_ready_o) begin
        target_pc_r <= target_pc_i;
    end
end
`endif

endmodule
