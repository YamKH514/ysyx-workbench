module top(
    input           clk,
    input           rst,
    output  [31:0]  pc,
    output  [31:0]  npc,
    output  [31:0]  ReadData_a0
);

wire    [2:0]   InstType;
wire    [3:0]   NPCSrcSel;
wire    [31:0]  TrapNPC;
wire    [1:0]   ALUSrcSel1;
wire    [1:0]   ALUSrcSel2;
wire    [31:0]  ImmExt;
wire    [31:0]  ALURes;
wire    [5:0]   ALUFunc;

wire            wbu_we;
wire    [4:0]   wbu_w_addr;
wire    [1:0]   wbu_w_data_sel;

wire            gpr_we;
wire    [4:0]   gpr_w_addr;
wire    [31:0]  gpr_w_data;
wire    [31:0]  gpr_r_data1;
wire    [31:0]  gpr_r_data2;
wire    [31:0]  gpr_r_a5;

wire            CSRWriteEn;
wire    [11:0]  CSRRWAddr;
wire    [31:0]  CSRWriteData;
wire    [31:0]  CSRWriteData_mepc;
wire    [31:0]  CSRWriteData_mcause;
wire    [31:0]  CSRReadData;
wire    [31:0]  CSRReadData_mtvec;
wire    [31:0]  CSRReadData_mepc;

wire            [31:0] ifu_req_addr;
wire            [31:0] ifu_req_inst;
reg             [31:0] ifu_inst_r;

wire            is_ecall;
wire            is_mret;

wire            mem_re;
wire    [31:0]  mem_r_addr;
wire    [31:0]  mem_r_data;
wire    [2:0]   mem_r_func;
wire            mem_we;
wire    [31:0]  mem_w_addr;
wire    [31:0]  mem_w_data;
wire    [7:0]   mem_w_mask;

assign TrapNPC = is_ecall ? CSRReadData_mtvec : CSRReadData_mepc;

PCCnt u_PCCnt(
    .clk                 	(clk            ),
    .rst                 	(rst            ),
    .pc_cnt_cmp_res_in     	(ALURes[0]      ),
    .pc_cnt_rd1_in         	(gpr_r_data1    ),
    .pc_cnt_imm_in         	(ImmExt         ),
    .pc_cnt_npc_src_sel_in 	(NPCSrcSel      ),
    .pc_cnt_trap_npc_in    	(TrapNPC        ),
    .pc_cnt_pc_out         	(pc             ),
    .pc_cnt_npc_out        	(npc            )
);

IFU u_IFU(
    .ifu_current_pc_in  	(pc             ),
    .ifu_req_addr_out   	(ifu_req_addr   ),
    .ifu_req_inst_in    	(ifu_req_inst   ),
    .ifu_inst_out       	(ifu_inst_r     )
);

InstSRAM u_InstSRAM(
    .inst_sram_addr_in   	(ifu_req_addr   ),
    .inst_sram_data_out  	(ifu_req_inst   )
);

IDU u_IDU(
    .clk                	(clk            ),
    .idu_inst_in           	(ifu_inst_r     ),
    .idu_is_ecall_out      	(is_ecall       ),
    .idu_is_mret_out       	(is_mret        ),
    .idu_inst_type_out     	(InstType       ),
    .csr_we_out        	    (CSRWriteEn     ),
    .exu_alu_fun_out       	(ALUFunc        ),
    .exu_alu_src1_sel_out  	(ALUSrcSel1     ),
    .exu_alu_src2_sel_out  	(ALUSrcSel2     ),
    .pc_cnt_npc_src_sel_out (NPCSrcSel      ),
    .wbu_gpr_we_out         (wbu_we         ),
    .wbu_gpr_w_addr_out     (wbu_w_addr     ),
    .wbu_gpr_wd_sel_out    	(wbu_w_data_sel ),
    .lsu_mem_wmask_out     	(mem_w_mask     ),
    .lsu_mem_we_out         (mem_we         ),
    .lsu_mem_re_out         (mem_re         ),
    .lsu_mem_read_func_out 	(mem_r_func     )
    // .idu_mem_valid_out      (mem_valid      )
);

ImmExt u_ImmExt(
    .imm_ext_inst_type_in 	(InstType           ),
    .imm_ext_imm_in       	(ifu_inst_r[31:7]   ),
    .imm_ext_imm_out      	(ImmExt             )
);

GPR u_GPR(
    .clk            (clk                ),
    .gpr_we_in    	(gpr_we             ),
    .gpr_r_addr1_in (ifu_inst_r[19:15]  ),
    .gpr_r_addr2_in (ifu_inst_r[24:20]  ),
    .gpr_w_addr_in  (gpr_w_addr         ),
    .gpr_w_data_in  (gpr_w_data         ),
    .gpr_r_data1_out(gpr_r_data1        ),
    .gpr_r_data2_out(gpr_r_data2        ),
    .gpr_r_a0_out 	(ReadData_a0        ),
    .gpr_r_a5_out   (gpr_r_a5           )
);

EXU u_EXU(
    .exu_pc_in           	(pc             ),
    .exu_alu_fun_in      	(ALUFunc        ),
    .exu_rd1_in          	(gpr_r_data1    ),
    .exu_rd2_in          	(gpr_r_data2    ),
    .exu_imm_in          	(ImmExt         ),
    .exu_alu_src1_sel_in 	(ALUSrcSel1     ),
    .exu_alu_src2_sel_in 	(ALUSrcSel2     ),
    .exu_res_out         	(ALURes         )
);

WBU u_WBU(
    .wbu_we_in      	(wbu_we         ),
    .wbu_w_addr_in  	(wbu_w_addr     ),
    .wbu_w_data_sel     (wbu_w_data_sel ),
    .exu_res_in         (ALURes         ),
    .lsu_r_data_in      (mem_r_data     ),
    .csr_r_data_in      (CSRReadData    ),
    .gpr_we_out     	(gpr_we         ),
    .gpr_w_addr_out 	(gpr_w_addr     ),
    .gpr_w_data_out 	(gpr_w_data     )
);


assign mem_r_addr = ALURes;
assign mem_w_addr = ALURes;
assign mem_w_data = gpr_r_data2;

LSU u_LSU(
    .lsu_re_in          (mem_re         ),
    .lsu_r_addr_in  	(mem_r_addr     ),
    .lsu_r_data_out 	(mem_r_data     ),
    .lsu_r_func_in  	(mem_r_func     ),
    .lsu_we_in          (mem_we         ),
    .lsu_w_addr_in 	    (mem_w_addr     ),
    .lsu_w_data_in 	    (mem_w_data     ),
    .lsu_w_mask_in 	    (mem_w_mask     )
);

assign CSRWriteData = gpr_r_data1;
assign CSRWriteData_mcause = gpr_r_a5;
assign CSRWriteData_mepc = pc;
assign CSRRWAddr = ifu_inst_r[31:20];

CSR u_CSR(
    .clk                 	(clk                  ),
    .rst                 	(rst                  ),
    .is_ecall            	(is_ecall             ),
    .is_mret                (is_mret              ),
    .CSRFunc3               (ifu_inst_r[14:12]    ),
    .CSRWriteEn          	(CSRWriteEn           ),
    .CSRRWAddr              (CSRRWAddr            ),
    .CSRWriteData        	(CSRWriteData         ),
    .CSRWriteData_mcause 	(CSRWriteData_mcause  ),
    .CSRWriteData_mepc   	(CSRWriteData_mepc    ),
    .CSRReadData         	(CSRReadData          ),
    .CSRReadData_mtvec   	(CSRReadData_mtvec    ),
    .CSRReadData_mepc       (CSRReadData_mepc     )
);

endmodule
