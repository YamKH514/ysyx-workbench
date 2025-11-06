`include "common.vh"

module WBU(
    input               wbu_we_in,
    input       [4:0]   wbu_w_addr_in,
    input       [1:0]   wbu_w_data_sel,

    input       [31:0]  exu_res_in,
    input       [31:0]  lsu_r_data_in,
    input       [31:0]  csr_r_data_in,

    output reg          gpr_we_out,
    output reg  [4:0]   gpr_w_addr_out,
    output reg  [31:0]  gpr_w_data_out
);

reg [31:0]  gpr_w_data_r;

assign gpr_w_data_r =   (wbu_w_data_sel == `GPR_WD_SEL_ALU_RES)  ? exu_res_in   :
                        (wbu_w_data_sel == `GPR_WD_SEL_MEM_DATA) ? lsu_r_data_in:
                        (wbu_w_data_sel == `GPR_WD_SEL_CSR_DATA) ? csr_r_data_in:
                        32'b0;

always @(*) begin
    if (wbu_we_in) begin
        gpr_we_out = 1'b1;
        gpr_w_addr_out = wbu_w_addr_in;
        gpr_w_data_out = gpr_w_data_r;
    end else begin
        gpr_we_out = 1'b0;
        gpr_w_addr_out = 5'b0;
        gpr_w_data_out = 32'b0;
    end
end

endmodule
