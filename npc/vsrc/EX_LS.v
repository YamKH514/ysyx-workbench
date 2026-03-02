`include "common.vh"
module EX_LS(
    input           clk,
                    rst,

    input  [31:0]   pc_i,
    input  [31:0]   res_i,
    input  [ 8:0]   data_i,
    input  [63:0]   gpr_rdata_i,
    input  [31:0]   wbu_csr_rdata_i,
    input           wbu_csr_we_i,
    input  [ 2:0]   wbu_csr_func3_i,
    input  [11:0]   wbu_csr_waddr_i,
    input  [ 7:0]   wbu_data_i,

    output [31:0]   pc_o,
    output [31:0]   res_o,
    output [ 8:0]   data_o,
    output [63:0]   gpr_rdata_o,
    output [31:0]   wbu_csr_rdata_o,
    output          wbu_csr_we_o,
    output [ 2:0]   wbu_csr_func3_o,
    output [11:0]   wbu_csr_waddr_o,
    output [ 7:0]   wbu_data_o,
`ifdef FOR_SIMULATION_ENV
    input  [31:0]   target_pc_i,
    output [31:0]   target_pc_o,
`endif
    input           ex_exls_valid_i,
    output          ex_exls_ready_o,
    output          exls_ls_valid_o,
    input           exls_ls_ready_i
);

assign ex_exls_ready_o = ex_exls_valid_i & state == S_IDLE;
assign exls_ls_valid_o = state == S_BUSY;

reg [31:0] pc_r;
reg [31:0] res_r;
reg [ 8:0] data_r;
reg [63:0] gpr_rdata_r;
reg [31:0] wbu_csr_rdata_r;
reg        wbu_csr_we_r;
reg [ 2:0] wbu_csr_func3_r;
reg [11:0] wbu_csr_waddr_r;
reg [ 7:0] wbu_data_r;

assign pc_o = pc_r;
assign res_o = res_r;
assign data_o = data_r;
assign gpr_rdata_o = gpr_rdata_r;
assign wbu_csr_rdata_o = wbu_csr_rdata_r;
assign wbu_csr_we_o = wbu_csr_we_r;
assign wbu_csr_func3_o = wbu_csr_func3_r;
assign wbu_csr_waddr_o = wbu_csr_waddr_r;
assign wbu_data_o = wbu_data_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        res_r <= 'b0;
        data_r <= 'b0;
        gpr_rdata_r <= 'b0;
        wbu_csr_rdata_r <= 'b0;
        wbu_csr_we_r <= 'b0;
        wbu_csr_func3_r <= 'b0;
        wbu_csr_waddr_r <= 'b0;
        wbu_data_r <= 'b0;
    end else if (ex_exls_valid_i & ex_exls_ready_o) begin
        pc_r <= pc_i;
        res_r <= res_i;
        data_r <= data_i;
        gpr_rdata_r <= gpr_rdata_i;
        wbu_csr_rdata_r <= wbu_csr_rdata_i;
        wbu_csr_we_r <= wbu_csr_we_i;
        wbu_csr_func3_r <= wbu_csr_func3_i;
        wbu_csr_waddr_r <= wbu_csr_waddr_i;
        wbu_data_r <= wbu_data_i;
    end else if (exls_ls_valid_o & exls_ls_ready_i) begin
        pc_r <= 'b0;
        res_r <= 'b0;
        data_r <= 'b0;
        gpr_rdata_r <= 'b0;
        wbu_csr_rdata_r <= 'b0;
        wbu_csr_we_r <= 'b0;
        wbu_csr_func3_r <= 'b0;
        wbu_csr_waddr_r <= 'b0;
        wbu_data_r <= 'b0;
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
                if (ex_exls_valid_i & ex_exls_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (exls_ls_valid_o & exls_ls_ready_i) state <= S_IDLE;
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
    end else if (ex_exls_valid_i & ex_exls_ready_o) begin
        target_pc_r <= target_pc_i;
    end
end
`endif

endmodule
