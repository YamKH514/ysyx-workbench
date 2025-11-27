`include "common.vh"

module WBU(
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

    input               lsu_to_wbu_valid_in
);

reg         ecall_r;
reg         mret_r;
reg         wbu_we_r;
reg [4:0]   wbu_w_addr_r;
reg [1:0]   wbu_wd_sel_r;
assign {ecall_r, mret_r, wbu_we_r, wbu_w_addr_r, wbu_wd_sel_r} = idu_to_wbu_data_in;

assign csr_w_ecall_out = ecall_r & lsu_to_wbu_valid_in;
assign csr_w_mret_out = mret_r & lsu_to_wbu_valid_in;

reg [31:0]  gpr_w_data_r;

assign gpr_w_data_r =   (wbu_wd_sel_r == `GPR_WD_SEL_ALU_RES)  ? exu_res_in   :
                        (wbu_wd_sel_r == `GPR_WD_SEL_MEM_DATA) ? lsu_r_data_in:
                        (wbu_wd_sel_r == `GPR_WD_SEL_CSR_DATA) ? csr_r_data_in:
                        32'b0;

always @(*) begin
    if (wbu_we_r & lsu_to_wbu_valid_in) begin
        gpr_we_out = 1'b1;
        gpr_w_addr_out = wbu_w_addr_r;
        gpr_w_data_out = gpr_w_data_r;
    end else begin
        gpr_we_out = 1'b0;
        gpr_w_addr_out = 5'b0;
        gpr_w_data_out = 32'b0;
    end
end

endmodule
