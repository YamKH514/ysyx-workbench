module top(
    input           clk,
    input           rst,
    output  [31:0]  pc,
    output  [31:0]  npc
);

wire    [2:0]   inst_type;
wire    [31:0]  trap_npc;
wire    [31:0]  imm_ext;
wire    [3:0]   pc_cnt_npc_src_sel;

wire            to_pc_valid;
wire            pc_to_ifu_ready;

wire    [31:0]  inst_araddr;
wire            inst_arvalid;
wire            inst_arready;
wire    [31:0]  inst_rdata;
wire            inst_rvalid;
wire            inst_rready;

wire            ifu_to_idu_valid;
wire            idu_to_ifu_ready;

wire            idu_to_exu_valid;
wire            exu_to_idu_ready;
wire            exu_to_lsu_valid;
wire            lsu_to_exu_ready;

wire            lsu_to_wbu_valid;
wire            wbu_to_lsu_ready;

wire    [1:0]   exu_alu_src_sel1;
wire    [1:0]   exu_alu_src_sel2;
wire    [31:0]  exu_res;
wire    [5:0]   exu_alu_func;

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

wire    [31:0]  ifu_inst;

wire            is_ecall;
wire            is_mret;

wire    [31:0]  lsu_r_data;

wire    [8:0]   idu_to_lsu_data;

wire    [9:0]   idu_to_wbu_data;

wire    [31:0]  sram_araddr;
wire            sram_arvalid;
wire            sram_arready;
wire    [31:0]  sram_rdata;
wire    [1:0]   sram_rresp;
wire            sram_rvalid;
wire            sram_rready;
wire    [31:0]  sram_awaddr;
wire            sram_awvalid;
wire            sram_awready;
wire    [31:0]  sram_wdata;
wire    [3:0]   sram_wstrb;
wire            sram_wvalid;
wire            sram_wready;
wire    [1:0]   sram_bresp;
wire            sram_bvalid;
wire            sram_bready;

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
    .idu_to_pc_valid_in     (to_pc_valid        ),
    .pc_to_ifu_ready_out    (pc_to_ifu_ready    )
);

IFU u_IFU(
    .clk                    (clk                ),
    .rst                    (rst                ),
    .ifu_current_pc_in  	(pc                 ),
    .ifu_inst_out       	(ifu_inst         ),
    .pc_to_ifu_ready_in     (pc_to_ifu_ready    ),
    .araddr_out             (inst_araddr        ),
    .arvalid_out            (inst_arvalid       ),
    .arready_in             (inst_arready       ),
    .rdata_in               (inst_rdata         ),
    .rvalid_in              (inst_rvalid        ),
    .rready_out             (inst_rready        ),
    .ifu_to_idu_valid_out   (ifu_to_idu_valid   ),
    .idu_to_ifu_ready_in    (idu_to_ifu_ready   )
);

InstSRAM u_InstSRAM(
    .clk                    (clk                ),
    .rst                    (rst                ),
    .inst_sram_addr_in   	(inst_araddr        ),
    .inst_sram_data_out  	(inst_rdata         ),
    .ifu_to_inst_arvalid_in (inst_arvalid       ),
    .inst_to_ifu_arready_out(inst_arready       ),
    .inst_to_ifu_rvalid_out (inst_rvalid        ),
    .ifu_to_inst_rready_in  (inst_rready        )
);

IDU u_IDU(
    .clk                	(clk                ),
    .rst                    (rst                ),
    .idu_inst_in           	(ifu_inst         ),
    .idu_inst_type_out     	(inst_type          ),
    .csr_we_out        	    (csr_we             ),
    .exu_alu_fun_out       	(exu_alu_func       ),
    .exu_alu_src1_sel_out  	(exu_alu_src_sel1   ),
    .exu_alu_src2_sel_out  	(exu_alu_src_sel2   ),
    .pc_cnt_npc_src_sel_out (pc_cnt_npc_src_sel ),
    .idu_to_lsu_data_out    (idu_to_lsu_data    ),
    .idu_to_wbu_data_out    (idu_to_wbu_data    ),
    .ifu_to_idu_valid_in    (ifu_to_idu_valid   ),
    .idu_to_ifu_ready_out   (idu_to_ifu_ready   ),
    .idu_to_exu_valid_out   (idu_to_exu_valid   ),
    .exu_to_idu_ready_in    (exu_to_idu_ready   )
);

ImmExt u_ImmExt(
    .imm_ext_inst_type_in 	(inst_type          ),
    .imm_ext_imm_in       	(ifu_inst[31:7]   ),
    .imm_ext_imm_out      	(imm_ext            )
);

GPR u_GPR(
    .clk                    (clk                ),
    .gpr_we_in    	        (gpr_we             ),
    .gpr_r_addr1_in         (ifu_inst[19:15]  ),
    .gpr_r_addr2_in         (ifu_inst[24:20]  ),
    .gpr_w_addr_in          (gpr_w_addr         ),
    .gpr_w_data_in          (gpr_w_data         ),
    .gpr_r_data1_out        (gpr_r_data1        ),
    .gpr_r_data2_out        (gpr_r_data2        ),
    .gpr_r_a5_out           (gpr_r_a5           )
);

EXU u_EXU(
    .clk                    (clk                ),
    .rst                    (rst                ),
    .exu_pc_in           	(pc                 ),
    .exu_alu_fun_in      	(exu_alu_func       ),
    .exu_rd1_in          	(gpr_r_data1        ),
    .exu_rd2_in          	(gpr_r_data2        ),
    .exu_imm_in          	(imm_ext            ),
    .exu_alu_src1_sel_in 	(exu_alu_src_sel1   ),
    .exu_alu_src2_sel_in 	(exu_alu_src_sel2   ),
    .exu_res_out         	(exu_res            ),
    .idu_to_exu_valid_in    (idu_to_exu_valid   ),
    .exu_to_idu_ready_out   (exu_to_idu_ready   ),
    .exu_to_lsu_valid_out   (exu_to_lsu_valid   ),
    .lsu_to_exu_ready_in    (lsu_to_exu_ready   )
);

LSU u_LSU(
    .clk                  	(clk                ),
    .rst                  	(rst                ),
    .idu_to_lsu_data_in   	(idu_to_lsu_data    ),
    .lsu_r_addr_in        	(exu_res            ),
    .lsu_r_data_out       	(lsu_r_data         ),
    .lsu_w_addr_in        	(exu_res            ),
    .lsu_w_data_in        	(gpr_r_data2        ),
    .araddr_out           	(sram_araddr        ),
    .arvalid_out          	(sram_arvalid       ),
    .arready_in           	(sram_arready       ),
    .rdata_in             	(sram_rdata         ),
    .rresp_in             	(sram_rresp         ),
    .rvalid_in            	(sram_rvalid        ),
    .rready_out           	(sram_rready        ),
    .awaddr_out           	(sram_awaddr        ),
    .awvalid_out          	(sram_awvalid       ),
    .awready_in           	(sram_awready       ),
    .wdata_out            	(sram_wdata         ),
    .wstrb_out            	(sram_wstrb         ),
    .wvalid_out           	(sram_wvalid        ),
    .wready_in            	(sram_wready        ),
    .bresp_in             	(sram_bresp         ),
    .bvalid_in            	(sram_bvalid        ),
    .bready_out           	(sram_bready        ),
    .exu_to_lsu_valid_in  	(exu_to_lsu_valid   ),
    .lsu_to_exu_ready_out 	(lsu_to_exu_ready   ),
    .lsu_to_wbu_valid_out 	(lsu_to_wbu_valid   ),
    .wbu_to_lsu_ready_in  	(wbu_to_lsu_ready   )
);

WBU u_WBU(
    .clk                    (clk                ),
    .rst                    (rst                ),
    .idu_to_wbu_data_in     (idu_to_wbu_data    ),
    .exu_res_in             (exu_res            ),
    .lsu_r_data_in          (lsu_r_data         ),
    .csr_r_data_in          (csr_r_data         ),
    .gpr_we_out     	    (gpr_we             ),
    .gpr_w_addr_out 	    (gpr_w_addr         ),
    .gpr_w_data_out 	    (gpr_w_data         ),
    .csr_w_ecall_out        (is_ecall           ),
    .csr_w_mret_out         (is_mret            ),
    .lsu_to_wbu_valid_in    (lsu_to_wbu_valid   ),
    .wbu_to_lsu_ready_out   (wbu_to_lsu_ready   ),
    .wbu_to_pc_valid_out    (to_pc_valid        )
);

SRAM u_SRAM(
    .clk         	        (clk                ),
    .rst         	        (rst                ),
    .araddr_in   	        (sram_araddr        ),
    .arvalid_in  	        (sram_arvalid       ),
    .arready_out 	        (sram_arready       ),
    .rdata_out   	        (sram_rdata         ),
    .rresp_out   	        (sram_rresp         ),
    .rvalid_out  	        (sram_rvalid        ),
    .rready_in   	        (sram_rready        ),
    .awaddr_in   	        (sram_awaddr        ),
    .awvalid_in  	        (sram_awvalid       ),
    .awready_out 	        (sram_awready       ),
    .wdata_in    	        (sram_wdata         ),
    .wstrb_in    	        (sram_wstrb         ),
    .wvalid_in   	        (sram_wvalid        ),
    .wready_out  	        (sram_wready        ),
    .bresp_out   	        (sram_bresp         ),
    .bvalid_out  	        (sram_bvalid        ),
    .bready_in   	        (sram_bready        )
);

assign csr_w_data   = gpr_r_data1;
assign csr_w_mcause = gpr_r_a5;
assign csr_w_mepc   = pc;
assign csr_rw_addr  = ifu_inst[31:20];

CSR u_CSR(
    .clk                    (clk                ),
    .rst                    (rst                ),
    .is_ecall               (is_ecall           ),
    .is_mret                (is_mret            ),
    .csr_func3_in           (ifu_inst[14:12]  ),
    .csr_we_in              (csr_we             ),
    .csr_rw_addr_in         (csr_rw_addr        ),
    .csr_w_data_in          (csr_w_data         ),
    .csr_w_mcause_in 	    (csr_w_mcause       ),
    .csr_w_mepc_in   	    (csr_w_mepc         ),
    .csr_r_data_out         (csr_r_data         ),
    .csr_r_mtvec_out   	    (csr_r_mtvec        ),
    .csr_r_mepc_out         (csr_r_mepc         )
);

endmodule
