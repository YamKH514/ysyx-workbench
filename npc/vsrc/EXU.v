module EXU(
    input               clk,
    input               rst,

    input       [31:0]  idu_pc_i,
    input       [31:0]  idu_inst_i,
    output      [31:0]  exu_pc_o,
    output      [31:0]  exu_inst_o,

    input       [ 8:0]  idu_exu_lsu_data_i,
    input       [31:0]  idu_exu_wbu_csr_rdata_i,
    input       [ 9:0]  idu_exu_wbu_data_i,
    input               idu_exu_wbu_csr_we_i,
    input       [ 3:0]  idu_exu_pc_src_sel_i,

    input       [63:0]  idu_exu_rdata_i,
    input       [ 5:0]  idu_exu_fun_i,
    input       [ 3:0]  idu_exu_src_sel_i,
    input       [31:0]  imm_exu_i,

    output      [31:0]  exu_lsu_res_o,
    output      [ 8:0]  exu_lsu_data_o,
    output      [63:0]  exu_lsu_gpr_rdata_o,
    output      [31:0]  exu_lsu_wbu_csr_rdata_o,
    output              exu_lsu_wbu_csr_we_o,
    output      [ 9:0]  exu_lsu_wbu_data_o,
    output      [31:0]  exu_lsu_pc_imm_o,
    output      [ 3:0]  exu_lsu_pc_src_sel_o,

    input               idu_exu_valid_i,
    output  reg         idu_exu_ready_o,

    output  reg         exu_lsu_valid_o,
    input               exu_lsu_ready_i
);

// Pipeline Reg
reg [31:0]  pc_r;
reg [31:0]  inst_r;
reg [ 5:0]  alu_fun_r;
reg [31:0]  rd1_r;
reg [31:0]  rd2_r;
reg [31:0]  imm_r;
reg [ 1:0]  alu_src1_sel_r;
reg [ 1:0]  alu_src2_sel_r;

reg [ 8:0]  exu_lsu_data_r;
reg [63:0]  exu_lsu_gpr_rdata_r;
reg [31:0]  idu_exu_wbu_csr_rdata_r;
reg [ 9:0]  idu_exu_wbu_data_r;
reg         idu_exu_wbu_csr_we_r;
reg [ 3:0]  idu_exu_pc_src_sel_r;

assign exu_pc_o = pc_r;
assign exu_inst_o = inst_r;
assign exu_lsu_data_o = exu_lsu_data_r;
assign exu_lsu_gpr_rdata_o = exu_lsu_gpr_rdata_r;
assign exu_lsu_wbu_csr_rdata_o = idu_exu_wbu_csr_rdata_r;
assign exu_lsu_wbu_csr_we_o = idu_exu_wbu_csr_we_r;
assign exu_lsu_wbu_data_o = idu_exu_wbu_data_r;
assign exu_lsu_pc_imm_o = imm_r;
assign exu_lsu_pc_src_sel_o = idu_exu_pc_src_sel_r;

assign idu_exu_ready_o = (state == S_IDLE) && idu_exu_valid_i;
assign exu_lsu_valid_o = (state == S_WAIT_LSU);

always @(posedge clk) begin
    if (rst) begin
        pc_r           <= 32'b0;
        inst_r         <= 32'b0;
        alu_fun_r      <= 6'b0;
        {rd2_r, rd1_r} <= 64'b0;
        imm_r          <= 32'b0;
        alu_src1_sel_r <= 2'b0;
        alu_src2_sel_r <= 2'b0;

        exu_lsu_data_r       <= 9'b0;
        exu_lsu_gpr_rdata_r  <= 64'b0;
        idu_exu_wbu_csr_rdata_r <= 32'b0;
        idu_exu_wbu_data_r   <= 10'b0;
        idu_exu_wbu_csr_we_r <= 1'b0;
        idu_exu_pc_src_sel_r <= 4'b0;
    end else if (idu_exu_valid_i & idu_exu_ready_o) begin
        pc_r           <= idu_pc_i;
        inst_r         <= idu_inst_i;
        alu_fun_r      <= idu_exu_fun_i;
        {rd2_r, rd1_r} <= idu_exu_rdata_i;
        imm_r          <= imm_exu_i;
        alu_src1_sel_r <= idu_exu_src_sel_i[1:0];
        alu_src2_sel_r <= idu_exu_src_sel_i[3:2];

        exu_lsu_data_r       <= idu_exu_lsu_data_i;
        exu_lsu_gpr_rdata_r  <= idu_exu_rdata_i;
        idu_exu_wbu_csr_rdata_r <= idu_exu_wbu_csr_rdata_i;
        idu_exu_wbu_data_r   <= idu_exu_wbu_data_i;
        idu_exu_wbu_csr_we_r <= idu_exu_wbu_csr_we_i;
        idu_exu_pc_src_sel_r <= idu_exu_pc_src_sel_i;
    end
end

parameter S_IDLE = 2'd0;
parameter S_WAIT_LSU = 2'd1;

reg [1:0] state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (idu_exu_valid_i & idu_exu_ready_o) begin
                    state <= S_WAIT_LSU;
                end
            end
            S_WAIT_LSU: begin
                if (exu_lsu_valid_o & exu_lsu_ready_i) begin
                    state <= S_IDLE;
                end
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

ALU u_ALU(
    .PC         	(pc_r           ),
    .ALUFunc    	(alu_fun_r      ),
    .ReadData1  	(rd1_r          ),
    .ReadData2  	(rd2_r          ),
    .ImmExt     	(imm_r          ),
    .ALUSrcSel1 	(alu_src1_sel_r ),
    .ALUSrcSel2 	(alu_src2_sel_r ),
    .ALURes     	(exu_lsu_res_o  )
);

endmodule
