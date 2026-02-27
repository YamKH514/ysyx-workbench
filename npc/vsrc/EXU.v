module EXU(
    input         clk,
    input         rst,

    input  [31:0] idu_pc_i,
    output [31:0] exu_pc_o,

    input  [ 8:0] idu_exu_lsu_data_i,
    input  [ 9:0] idu_exu_wbu_data_i,
    input  [31:0] idu_exu_wbu_csr_rdata_i,
    input  [ 2:0] idu_exu_lsu_wbu_csr_func3_i,
    input  [11:0] idu_exu_lsu_wbu_csr_waddr_i,
    input         idu_exu_wbu_csr_we_i,
    input  [ 3:0] idu_exu_pc_src_sel_i,

    input  [63:0] idu_exu_rdata_i,
    input  [ 5:0] idu_exu_fun_i,
    input  [ 3:0] idu_exu_src_sel_i,
    input  [31:0] imm_exu_i,

    input  [31:0] csr_r_mtvec_i,
    input  [31:0] csr_r_mepc_i,

    output [31:0] exu_lsu_res_o,
    output [ 8:0] exu_lsu_data_o,
    output [63:0] exu_lsu_gpr_rdata_o,
    output [31:0] exu_lsu_wbu_csr_rdata_o,
    output [ 2:0] exu_lsu_wbu_csr_func3_o,
    output [11:0] exu_lsu_wbu_csr_waddr_o,
    output        exu_lsu_wbu_csr_we_o,
    output [ 9:0] exu_lsu_wbu_data_o,
    output [31:0] exu_pc_target_pc_o,

    output        need_flush_o,

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
assign exu_lsu_data_o = idu_exu_lsu_data_i;
assign exu_lsu_gpr_rdata_o = idu_exu_rdata_i;
assign exu_lsu_wbu_csr_rdata_o = idu_exu_wbu_csr_rdata_i;
assign exu_lsu_wbu_csr_func3_o = idu_exu_lsu_wbu_csr_func3_i;
assign exu_lsu_wbu_csr_waddr_o = idu_exu_lsu_wbu_csr_waddr_i;
assign exu_lsu_wbu_csr_we_o = idu_exu_wbu_csr_we_i;
assign exu_lsu_wbu_data_o = idu_exu_wbu_data_i;

assign need_flush_o = (state == S_WAIT_LSU) & (exu_pc_target_pc_o != idu_pc_i + 4);

assign idu_exu_ready_o = exu_lsu_valid_o & exu_lsu_ready_i;
assign exu_lsu_valid_o = (state == S_WAIT_LSU);

localparam S_W        = 2;
localparam S_IDLE     = 2'd0;
localparam S_WAIT_LSU = 2'd1;

reg [S_W-1:0] state;

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

wire        is_trap;
wire        is_jump;
wire        is_ecall;
wire [31:0] trap_pc;
wire [31:0] base;
wire [31:0] offset;

assign is_trap = ~idu_exu_pc_src_sel_i[3] & idu_exu_pc_src_sel_i[2];
assign is_jump = idu_exu_pc_src_sel_i[3];
assign is_ecall = exu_lsu_wbu_data_o[9];

// npc = pc+4(0000) pc+imm(0001) src1+imm(0011) trap_npc(0100) res=0,jump(10--) res=1,jump(11--)
assign trap_pc = is_ecall ? csr_r_mtvec_i : csr_r_mepc_i;
assign base = (!is_jump & idu_exu_pc_src_sel_i[1]) ? rd1 : idu_pc_i;
assign offset = 
            is_jump ?
            (idu_exu_pc_src_sel_i[2] == exu_lsu_res_o[0]) ? imm_exu_i : 4 :
            idu_exu_pc_src_sel_i[0] ? imm_exu_i : 32'd4;

assign exu_pc_target_pc_o = is_trap ? trap_pc : base + offset;

endmodule
