`include "common.vh"

module WBU(
    input               clk,
    input               rst,

    input       [31:0]  lsu_pc_i,
    input       [31:0]  lsu_inst_i,

    // idu_to_wbu_data is_ecall[9], is_mret[8], wbu_we[7], wbu_w_addr[6:2], wbu_wd_sel[1:0]
    input       [9:0]   lsu_wbu_data_i,
    input       [31:0]  lsu_wbu_res_i,
    input       [31:0]  lsu_wbu_rdata_i,
    input       [31:0]  lsu_wbu_csr_rdata_i,
    input               lsu_wbu_csr_we_i,
    input       [31:0]  lsu_wbu_csr_wdata_i,
    input       [31:0]  lsu_wbu_pc_rdata1_i,
    input       [31:0]  lsu_wbu_pc_imm_i,
    input       [ 3:0]  lsu_wbu_pc_src_sel_i,

    output reg          wbu_gpr_we_o,
    output reg  [4:0]   wbu_gpr_waddr_o,
    output reg  [31:0]  wbu_gpr_wdata_o,

    output      [ 2:0]  wbu_csr_func3_o,
    output              wbu_csr_we_o,
    output      [11:0]  wbu_csr_waddr_o,
    output      [31:0]  wbu_csr_wdata_o,
    output      [31:0]  wbu_csr_mepc_o,
    output reg          wbu_csr_ecall_o,
    output reg          wbu_csr_mret_o,
    output              wbu_pc_ecall_o,
    output      [31:0]  wbu_pc_rdata1_o,
    output      [31:0]  wbu_pc_imm_o,
    output              wbu_pc_cmp_res_o,
    output      [ 3:0]  wbu_pc_src_sel_o,

    input               lsu_wbu_valid_i,
    output              lsu_wbu_ready_o,

    output              wbu_pc_valid_o,
    input               wbu_pc_ready_i
);

reg [31:0] pc_r;
reg [31:0] inst_r;
reg        lsu_wbu_csr_we_r;
reg [31:0] lsu_wbu_csr_wdata_r;
reg [31:0] lsu_wbu_pc_rdata1_r;
reg [31:0] lsu_wbu_pc_imm_r;
reg        lsu_wbu_pc_cmp_res_r;
reg [ 3:0] lsu_wbu_pc_src_sel_r;

assign wbu_csr_func3_o = inst_r[14:12];
assign wbu_csr_we_o = lsu_wbu_csr_we_r & S_BUSY;
assign wbu_csr_waddr_o = inst_r[31:20];
assign wbu_csr_wdata_o = lsu_wbu_csr_wdata_r;
assign wbu_csr_mepc_o = pc_r;
assign wbu_pc_ecall_o = ecall_r;
assign wbu_pc_rdata1_o = lsu_wbu_pc_rdata1_r;
assign wbu_pc_imm_o = lsu_wbu_pc_imm_r;
assign wbu_pc_cmp_res_o = lsu_wbu_pc_cmp_res_r;
assign wbu_pc_src_sel_o = lsu_wbu_pc_src_sel_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        inst_r <= 'b0;
        lsu_wbu_csr_we_r <= 'b0;
        lsu_wbu_csr_wdata_r <= 'b0;
        lsu_wbu_pc_rdata1_r <= 'b0;
        lsu_wbu_pc_imm_r <= 'b0;
        lsu_wbu_pc_cmp_res_r <= 'b0;
        lsu_wbu_pc_src_sel_r <= 'b0;
    end else if (lsu_wbu_valid_i & lsu_wbu_ready_o) begin
        pc_r <= lsu_pc_i;
        inst_r <= lsu_inst_i;
        lsu_wbu_csr_we_r <= lsu_wbu_csr_we_i;
        lsu_wbu_csr_wdata_r <= lsu_wbu_csr_wdata_i;
        lsu_wbu_pc_rdata1_r <= lsu_wbu_pc_rdata1_i;
        lsu_wbu_pc_imm_r <= lsu_wbu_pc_imm_i;
        lsu_wbu_pc_cmp_res_r <= lsu_wbu_res_i[0];
        lsu_wbu_pc_src_sel_r <= lsu_wbu_pc_src_sel_i;
    end
end

reg         ecall_r;
reg         mret_r;
reg         wbu_we_r;
reg [4:0]   wbu_w_addr_r;
reg [1:0]   wbu_wd_sel_r;

assign wbu_gpr_we_o = wbu_we_r & state == S_BUSY;
assign wbu_gpr_waddr_o = wbu_w_addr_r;
assign wbu_gpr_wdata_o = gpr_w_data_r;
assign wbu_csr_ecall_o = ecall_r;
assign wbu_csr_mret_o = mret_r;

always @(posedge clk) begin
    if (rst) begin
        ecall_r <= 'b0;
        mret_r <= 'b0;
        wbu_we_r <= 'b0;
        wbu_w_addr_r <= 'b0;
        wbu_wd_sel_r <= 'b0;
    end else if (lsu_wbu_valid_i & lsu_wbu_ready_o) begin
        {ecall_r, mret_r, wbu_we_r, wbu_w_addr_r, wbu_wd_sel_r} <= lsu_wbu_data_i;
    end
end

assign lsu_wbu_ready_o = state == S_IDLE & lsu_wbu_valid_i;
assign wbu_pc_valid_o = state == S_BUSY;

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (lsu_wbu_valid_i & lsu_wbu_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (wbu_pc_valid_o & wbu_pc_ready_i) state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

reg [31:0]  gpr_w_data_r;

assign gpr_w_data_r =   (wbu_wd_sel_r == `GPR_WD_SEL_ALU_RES)  ? lsu_wbu_res_i   :
                        (wbu_wd_sel_r == `GPR_WD_SEL_MEM_DATA) ? lsu_wbu_rdata_i:
                        (wbu_wd_sel_r == `GPR_WD_SEL_CSR_DATA) ? lsu_wbu_csr_rdata_i:
                        32'b0;

endmodule
