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
    output reg          lsu_wbu_ready_o,

    output reg          wbu_pc_valid_o,
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
assign wbu_csr_we_o = lsu_wbu_csr_we_r;
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
    end else if (state == S_IDLE & lsu_wbu_valid_i) begin
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

parameter S_IDLE = 1'd0;
parameter S_BUSY = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        lsu_wbu_ready_o <= 1'b0;
        wbu_pc_valid_o <= 1'b0;
        wbu_gpr_we_o <= 1'b0;
        wbu_gpr_waddr_o <= 5'b0;
        wbu_gpr_wdata_o <= 32'b0;
        wbu_csr_ecall_o <= 1'b0;
        wbu_csr_mret_o <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (lsu_wbu_valid_i) begin
                    lsu_wbu_ready_o <= 1'b1;
                    wbu_pc_valid_o <= 1'b1;
                    wbu_gpr_we_o <= wbu_we_r;
                    wbu_gpr_waddr_o <= wbu_w_addr_r;
                    wbu_gpr_wdata_o <= gpr_w_data_r;
                    wbu_csr_ecall_o <= ecall_r;
                    wbu_csr_mret_o <= mret_r;
                end
            end
            S_BUSY: begin
                lsu_wbu_ready_o <= 1'b0;
                wbu_gpr_we_o <= 1'b0;
                wbu_gpr_waddr_o <= 5'b0;
                wbu_gpr_wdata_o <= 32'b0;
                wbu_csr_ecall_o <= 1'b0;
                wbu_csr_mret_o <= 1'b0;
                if (wbu_pc_valid_o & wbu_pc_ready_i) begin
                    wbu_pc_valid_o <= 1'b0;
                end
            end
            default: begin
                lsu_wbu_ready_o <= 1'b0;
                wbu_pc_valid_o <= 1'b0;
                wbu_gpr_we_o <= 1'b0;
                wbu_gpr_waddr_o <= 5'b0;
                wbu_gpr_wdata_o <= 32'b0;
                wbu_csr_ecall_o <= 1'b0;
                wbu_csr_mret_o <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (lsu_wbu_valid_i) begin
                next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (wbu_pc_valid_o & wbu_pc_ready_i) begin
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

reg         ecall_r;
reg         mret_r;
reg         wbu_we_r;
reg [4:0]   wbu_w_addr_r;
reg [1:0]   wbu_wd_sel_r;
assign {ecall_r, mret_r, wbu_we_r, wbu_w_addr_r, wbu_wd_sel_r} = lsu_wbu_data_i;

reg [31:0]  gpr_w_data_r;

assign gpr_w_data_r =   (wbu_wd_sel_r == `GPR_WD_SEL_ALU_RES)  ? lsu_wbu_res_i   :
                        (wbu_wd_sel_r == `GPR_WD_SEL_MEM_DATA) ? lsu_wbu_rdata_i:
                        (wbu_wd_sel_r == `GPR_WD_SEL_CSR_DATA) ? lsu_wbu_csr_rdata_i:
                        32'b0;

// always @(*) begin
//     if (wbu_we_r) begin
//         wbu_gpr_waddr_o = wbu_w_addr_r;
//         wbu_gpr_wdata_o = gpr_w_data_r;
//     end else begin
//         wbu_gpr_waddr_o = 5'b0;
//         wbu_gpr_wdata_o = 32'b0;
//     end
// end

endmodule
