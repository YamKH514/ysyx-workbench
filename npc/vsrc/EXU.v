module EXU(
    input         clk,
    input         rst,

    input  [31:0] idu_pc_i,
    input  [31:0] idu_inst_i,
    output [31:0] exu_pc_o,
    output [31:0] exu_inst_o,

    input  [ 8:0] idu_exu_lsu_data_i,
    input  [31:0] idu_exu_wbu_csr_rdata_i,
    input  [ 9:0] idu_exu_wbu_data_i,
    input         idu_exu_wbu_csr_we_i,
    input  [ 3:0] idu_exu_pc_src_sel_i,

    input  [63:0] idu_exu_rdata_i,
    input  [ 5:0] idu_exu_fun_i,
    input  [ 3:0] idu_exu_src_sel_i,
    input  [31:0] imm_exu_i,

    output [31:0] exu_lsu_res_o,
    output [ 8:0] exu_lsu_data_o,
    output [63:0] exu_lsu_gpr_rdata_o,
    output [31:0] exu_lsu_wbu_csr_rdata_o,
    output        exu_lsu_wbu_csr_we_o,
    output [ 9:0] exu_lsu_wbu_data_o,
    output [31:0] exu_lsu_pc_imm_o,
    output [ 3:0] exu_lsu_pc_src_sel_o,

    input         idu_exu_valid_i,
    output        idu_exu_ready_o,

    output        exu_lsu_valid_o,
    input         exu_lsu_ready_i
);

wire [31:0] rd1;
wire [31:0] rd2;
wire [ 1:0] alu_src1_sel_r;
wire [ 1:0] alu_src2_sel_r;

assign {rd2, rd1} = idu_exu_rdata_i;
assign {alu_src2_sel_r, alu_src1_sel_r} = idu_exu_src_sel_i;

assign exu_pc_o = idu_pc_i;
assign exu_inst_o = idu_inst_i;
assign exu_lsu_data_o = idu_exu_lsu_data_i;
assign exu_lsu_gpr_rdata_o = idu_exu_rdata_i;
assign exu_lsu_wbu_csr_rdata_o = idu_exu_wbu_csr_rdata_i;
assign exu_lsu_wbu_csr_we_o = idu_exu_wbu_csr_we_i;
assign exu_lsu_wbu_data_o = idu_exu_wbu_data_i;
assign exu_lsu_pc_imm_o = imm_exu_i;
assign exu_lsu_pc_src_sel_o = idu_exu_pc_src_sel_i;

assign idu_exu_ready_o = exu_lsu_valid_o & exu_lsu_ready_i;
assign exu_lsu_valid_o = (state == S_WAIT_LSU);

localparam S_IDLE = 2'd0;
localparam S_WAIT_LSU = 2'd1;

reg [1:0] state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (idu_exu_valid_i) state <= S_WAIT_LSU;
            end
            S_WAIT_LSU: begin
                if (exu_lsu_valid_o & exu_lsu_ready_i) state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

ALU u_ALU(
    .PC         	(idu_pc_i       ),
    .ALUFunc    	(idu_exu_fun_i  ),
    .ReadData1  	(rd1            ),
    .ReadData2  	(rd2            ),
    .ImmExt     	(imm_exu_i      ),
    .ALUSrcSel1 	(alu_src1_sel_r ),
    .ALUSrcSel2 	(alu_src2_sel_r ),
    .ALURes     	(exu_lsu_res_o  )
);

endmodule
