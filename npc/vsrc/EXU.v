`include "common.vh"

module EXU(
    input       [31:0]  exu_pc_in,
    input       [5:0]   exu_alu_fun_in,
    input       [31:0]  exu_rd1_in,
    input       [31:0]  exu_rd2_in,
    input       [31:0]  exu_imm_in,
    input       [1:0]   exu_alu_src1_sel_in,
    input       [1:0]   exu_alu_src2_sel_in,
    output  reg [31:0]  exu_res_out
);

reg [31:0]  pc_r;
reg [5:0]   alu_fun_r;
reg [31:0]  rd1_r;
reg [31:0]  rd2_r;
reg [31:0]  imm_r;
reg [1:0]   alu_src1_sel_r;
reg [1:0]   alu_src2_sel_r;
reg [31:0]  alu_res_r;

assign pc_r           = exu_pc_in;
assign alu_fun_r      = exu_alu_fun_in;
assign rd1_r          = exu_rd1_in;
assign rd2_r          = exu_rd2_in;
assign imm_r          = exu_imm_in;
assign alu_src1_sel_r = exu_alu_src1_sel_in;
assign alu_src2_sel_r = exu_alu_src2_sel_in;

assign exu_res_out = alu_res_r;

ALU u_ALU(
    .PC         	(pc_r           ),
    .ALUFunc    	(alu_fun_r      ),
    .ReadData1  	(rd1_r          ),
    .ReadData2  	(rd2_r          ),
    .ImmExt     	(imm_r          ),
    .ALUSrcSel1 	(alu_src1_sel_r ),
    .ALUSrcSel2 	(alu_src2_sel_r ),
    .ALURes     	(alu_res_r      )
);

endmodule
