`include "common.vh"

module WBU(
    input               clk,
    input               rst,

    // idu_to_wbu_data is_ecall[9], is_mret[8], wbu_we[7], wbu_w_addr[6:2], wbu_wd_sel[1:0]
    input       [9:0]   idu_to_wbu_data_in,

    input       [31:0]  exu_res_in,
    input       [31:0]  lsu_r_data_in,
    input       [31:0]  csr_r_data_in,

    output reg          gpr_we_out,
    output reg  [4:0]   gpr_w_addr_out,
    output reg  [31:0]  gpr_w_data_out,

    output reg          csr_w_ecall_out,
    output reg          csr_w_mret_out,

    input               lsu_to_wbu_valid_in,
    output reg          wbu_to_lsu_ready_out,

    output reg          wbu_to_pc_valid_out,
    input               pc_to_wbu_ready_in
);

parameter S_IDLE = 1'd0;
parameter S_BUSY = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        wbu_to_lsu_ready_out <= 1'b0;
        wbu_to_pc_valid_out <= 1'b0;
        gpr_we_out <= 1'b0;
        gpr_w_addr_out <= 5'b0;
        gpr_w_data_out <= 32'b0;
        csr_w_ecall_out <= 1'b0;
        csr_w_mret_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (lsu_to_wbu_valid_in) begin
                    wbu_to_lsu_ready_out <= 1'b1;
                    wbu_to_pc_valid_out <= 1'b1;
                    gpr_we_out <= wbu_we_r;
                    gpr_w_addr_out <= wbu_w_addr_r;
                    gpr_w_data_out <= gpr_w_data_r;
                    csr_w_ecall_out <= ecall_r;
                    csr_w_mret_out <= mret_r;
                end
            end
            S_BUSY: begin
                wbu_to_lsu_ready_out <= 1'b0;
                gpr_we_out <= 1'b0;
                gpr_w_addr_out <= 5'b0;
                gpr_w_data_out <= 32'b0;
                csr_w_ecall_out <= 1'b0;
                csr_w_mret_out <= 1'b0;
                if (wbu_to_pc_valid_out & pc_to_wbu_ready_in) begin
                    wbu_to_pc_valid_out <= 1'b0;
                end
            end
            default: begin
                wbu_to_lsu_ready_out <= 1'b0;
                wbu_to_pc_valid_out <= 1'b0;
                gpr_we_out <= 1'b0;
                gpr_w_addr_out <= 5'b0;
                gpr_w_data_out <= 32'b0;
                csr_w_ecall_out <= 1'b0;
                csr_w_mret_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (lsu_to_wbu_valid_in) begin
                next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (wbu_to_pc_valid_out & pc_to_wbu_ready_in) begin
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
assign {ecall_r, mret_r, wbu_we_r, wbu_w_addr_r, wbu_wd_sel_r} = idu_to_wbu_data_in;

reg [31:0]  gpr_w_data_r;

assign gpr_w_data_r =   (wbu_wd_sel_r == `GPR_WD_SEL_ALU_RES)  ? exu_res_in   :
                        (wbu_wd_sel_r == `GPR_WD_SEL_MEM_DATA) ? lsu_r_data_in:
                        (wbu_wd_sel_r == `GPR_WD_SEL_CSR_DATA) ? csr_r_data_in:
                        32'b0;

// always @(*) begin
//     if (wbu_we_r) begin
//         gpr_w_addr_out = wbu_w_addr_r;
//         gpr_w_data_out = gpr_w_data_r;
//     end else begin
//         gpr_w_addr_out = 5'b0;
//         gpr_w_data_out = 32'b0;
//     end
// end

endmodule
