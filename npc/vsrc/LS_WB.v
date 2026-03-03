`include "common.vh"
module LS_WB(
    input           clk,
                    rst,

    input  [31:0] pc_i,
    input  [31:0] rdata_i,
    input  [ 9:0] data_i,
    input  [31:0] gpr_wdata_i,
    input         csr_we_i,
    input  [ 2:0] csr_func3_i,
    input  [11:0] csr_waddr_i,
    input  [31:0] csr_wdata_i,

    output [31:0] pc_o,
    output [ 7:0] data_o,
    output [31:0] gpr_wdata_o,
    output        csr_we_o,
    output [ 2:0] csr_func3_o,
    output [11:0] csr_waddr_o,
    output [31:0] csr_wdata_o,
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
reg [ 7:0] data_r;
reg [31:0] gpr_wdata_r;
reg        csr_we_r;
reg [ 2:0] csr_func3_r;
reg [11:0] csr_waddr_r;
reg [31:0] csr_wdata_r;
wire[ 1:0] wbu_wd_sel = data_i[1:0];

assign pc_o = pc_r;
assign data_o = data_r;
assign gpr_wdata_o = gpr_wdata_r;
assign csr_we_o = csr_we_r;
assign csr_func3_o = csr_func3_r;
assign csr_waddr_o = csr_waddr_r;
assign csr_wdata_o = csr_wdata_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        data_r <= 'b0;
        gpr_wdata_r <= 'b0;
        csr_we_r <= 'b0;
        csr_func3_r <= 'b0;
        csr_waddr_r <= 'b0;
        csr_wdata_r <= 'b0;
    end else if (ls_lswb_valid_i & ls_lswb_ready_o) begin
        pc_r <= pc_i;
        data_r <= data_i[9:2];
        gpr_wdata_r <= (wbu_wd_sel == `GPR_WD_SEL_MEM_DATA) ? rdata_i : gpr_wdata_i;
        csr_we_r <= csr_we_i;
        csr_func3_r <= csr_func3_i;
        csr_waddr_r <= csr_waddr_i;
        csr_wdata_r <= csr_wdata_i;
    end else if (lswb_wb_valid_o & lswb_wb_ready_i) begin
        pc_r <= 'b0;
        data_r <= 'b0;
        gpr_wdata_r <= 'b0;
        csr_we_r <= 'b0;
        csr_func3_r <= 'b0;
        csr_waddr_r <= 'b0;
        csr_wdata_r <= 'b0;
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
