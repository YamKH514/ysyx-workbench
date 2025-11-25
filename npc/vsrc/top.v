module top(
    input           clk,
    input           rst,
    output  [31:0]  pc,
    output  [31:0]  npc,
    output  [31:0]  ReadData_a0
);

wire    [2:0]   inst_type;
wire    [31:0]  trap_npc;
wire    [31:0]  imm_ext;
wire    [3:0]   pc_cnt_npc_src_sel;

wire            pc_to_ifu_ready;
wire            ifu_to_inst_valid;
wire            inst_to_ifu_ready;
wire            ifu_to_idu_valid;
wire            idu_to_ifu_ready;
wire            idu_to_pc_valid;

wire    [1:0]   exu_alu_src_sel1;
wire    [1:0]   exu_alu_src_sel2;
wire    [31:0]  exu_res;
wire    [5:0]   exu_alu_func;

wire            wbu_we;
wire    [4:0]   wbu_w_addr;
wire    [1:0]   wbu_w_data_sel;

wire            gpr_we;
wire    [4:0]   gpr_w_addr;
wire    [31:0]  gpr_w_data;
wire    [31:0]  gpr_r_data1;
wire    [31:0]  gpr_r_data2;
wire    [31:0]  gpr_r_a5;

wire            csr_we;
wire    [11:0]  csr_rw_addr;
wire    [31:0]  csr_w_data;
wire    [31:0]  csr_w_mepc;
wire    [31:0]  csr_w_mcause;
wire    [31:0]  csr_r_data;
wire    [31:0]  csr_r_mtvec;
wire    [31:0]  csr_r_mepc;

wire    [31:0]  ifu_req_addr;
wire    [31:0]  ifu_req_inst;
reg     [31:0]  ifu_inst_r;

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

wire            sram_re;
wire    [31:0]  sram_r_addr;
wire    [31:0]  sram_r_data;
wire            sram_we;
wire    [31:0]  sram_w_addr;
wire    [31:0]  sram_w_data;
wire    [7:0]   sram_w_mask;

assign trap_npc = is_ecall ? csr_r_mtvec : csr_r_mepc;

PCCnt u_PCCnt(
    .clk                 	(clk                ),
    .rst                 	(rst                ),
    .pc_cnt_cmp_res_in     	(exu_res[0]         ),
    .pc_cnt_rd1_in         	(gpr_r_data1        ),
    .pc_cnt_imm_in         	(imm_ext            ),
    .pc_cnt_npc_src_sel_in 	(pc_cnt_npc_src_sel ),
    .pc_cnt_trap_npc_in    	(trap_npc           ),
    .pc_cnt_pc_out         	(pc                 ),
    .pc_cnt_npc_out        	(npc                ),
    .idu_to_pc_valid_in     (idu_to_pc_valid),
    .pc_to_ifu_ready_out    (pc_to_ifu_ready)
);

IFU u_IFU(
    .clk                    (clk            ),
    .rst                    (rst            ),
    .ifu_current_pc_in  	(pc             ),
    .ifu_req_addr_out   	(ifu_req_addr   ),
    .ifu_req_inst_in    	(ifu_req_inst   ),
    .ifu_inst_out       	(ifu_inst_r     ),
    .pc_to_ifu_ready_in     (pc_to_ifu_ready),
    .ifu_to_inst_valid_out  (ifu_to_inst_valid),
    .inst_to_ifu_ready_in   (inst_to_ifu_ready),
    .ifu_to_idu_valid_out   (ifu_to_idu_valid),
    .idu_to_ifu_ready_in    (idu_to_ifu_ready)
);

InstSRAM u_InstSRAM(
    .clk                    (clk),
    .rst                    (rst),
    .inst_sram_addr_in   	(ifu_req_addr   ),
    .inst_sram_data_out  	(ifu_req_inst   ),
    .ifu_to_inst_valid_in   (ifu_to_inst_valid),
    .inst_to_ifu_ready_out  (inst_to_ifu_ready)
);

IDU u_IDU(
    .clk                	(clk                ),
    .rst                    (rst),
    .idu_inst_in           	(ifu_inst_r         ),
    .idu_is_ecall_out      	(is_ecall           ),
    .idu_is_mret_out       	(is_mret            ),
    .idu_inst_type_out     	(inst_type          ),
    .csr_we_out        	    (csr_we             ),
    .exu_alu_fun_out       	(exu_alu_func       ),
    .exu_alu_src1_sel_out  	(exu_alu_src_sel1   ),
    .exu_alu_src2_sel_out  	(exu_alu_src_sel2   ),
    .pc_cnt_npc_src_sel_out (pc_cnt_npc_src_sel ),
    .wbu_gpr_we_out         (wbu_we             ),
    .wbu_gpr_w_addr_out     (wbu_w_addr         ),
    .wbu_gpr_wd_sel_out    	(wbu_w_data_sel     ),
    .lsu_mem_wmask_out     	(mem_w_mask         ),
    .lsu_mem_we_out         (mem_we             ),
    .lsu_mem_re_out         (mem_re             ),
    .lsu_mem_read_func_out 	(mem_r_func         ),
    .ifu_to_idu_valid_in    (ifu_to_idu_valid),
    .idu_to_ifu_ready_out   (idu_to_ifu_ready),
    .idu_to_pc_valid_out    (idu_to_pc_valid)
);

ImmExt u_ImmExt(
    .imm_ext_inst_type_in 	(inst_type          ),
    .imm_ext_imm_in       	(ifu_inst_r[31:7]   ),
    .imm_ext_imm_out      	(imm_ext            )
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
    .exu_pc_in           	(pc                 ),
    .exu_alu_fun_in      	(exu_alu_func       ),
    .exu_rd1_in          	(gpr_r_data1        ),
    .exu_rd2_in          	(gpr_r_data2        ),
    .exu_imm_in          	(imm_ext            ),
    .exu_alu_src1_sel_in 	(exu_alu_src_sel1   ),
    .exu_alu_src2_sel_in 	(exu_alu_src_sel2   ),
    .exu_res_out         	(exu_res            )
);

WBU u_WBU(
    .wbu_we_in      	(wbu_we         ),
    .wbu_w_addr_in  	(wbu_w_addr     ),
    .wbu_w_data_sel     (wbu_w_data_sel ),
    .exu_res_in         (exu_res        ),
    .lsu_r_data_in      (mem_r_data     ),
    .csr_r_data_in      (csr_r_data     ),
    .gpr_we_out     	(gpr_we         ),
    .gpr_w_addr_out 	(gpr_w_addr     ),
    .gpr_w_data_out 	(gpr_w_data     )
);

assign mem_r_addr = exu_res;
assign mem_w_addr = exu_res;
assign mem_w_data = gpr_r_data2;

LSU u_LSU(
    .lsu_re_in          (mem_re         ),
    .lsu_r_addr_in  	(mem_r_addr     ),
    .lsu_r_data_out 	(mem_r_data     ),
    .lsu_r_func_in  	(mem_r_func     ),
    .lsu_we_in          (mem_we         ),
    .lsu_w_addr_in 	    (mem_w_addr     ),
    .lsu_w_data_in 	    (mem_w_data     ),
    .lsu_w_mask_in 	    (mem_w_mask     ),
    .sram_re_out        (sram_re        ),
    .sram_r_addr_out    (sram_r_addr    ),
    .sram_r_data_in     (sram_r_data    ),
    .sram_we_out        (sram_we        ),
    .sram_w_addr_out    (sram_w_addr    ),
    .sram_w_data_out    (sram_w_data    ),
    .sram_w_mask_out    (sram_w_mask    )
);

SRAM u_SRAM(
    .sram_re_in      	(sram_re        ),
    .sram_r_addr_in  	(sram_r_addr    ),
    .sram_r_data_out 	(sram_r_data    ),
    .sram_we_in      	(sram_we        ),
    .sram_w_addr_in  	(sram_w_addr    ),
    .sram_w_data_in  	(sram_w_data    ),
    .sram_w_mask_in  	(sram_w_mask    )
);

assign csr_w_data   = gpr_r_data1;
assign csr_w_mcause = gpr_r_a5;
assign csr_w_mepc   = pc;
assign csr_rw_addr  = ifu_inst_r[31:20];

CSR u_CSR(
    .clk                (clk                ),
    .rst                (rst                ),
    .is_ecall           (is_ecall           ),
    .is_mret            (is_mret            ),
    .csr_func3_in       (ifu_inst_r[14:12]  ),
    .csr_we_in          (csr_we             ),
    .csr_rw_addr_in     (csr_rw_addr        ),
    .csr_w_data_in      (csr_w_data         ),
    .csr_w_mcause_in 	(csr_w_mcause       ),
    .csr_w_mepc_in   	(csr_w_mepc         ),
    .csr_r_data_out     (csr_r_data         ),
    .csr_r_mtvec_out   	(csr_r_mtvec        ),
    .csr_r_mepc_out     (csr_r_mepc         )
);

endmodule
