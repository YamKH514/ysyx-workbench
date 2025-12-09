module top(
    input           clk,
    input           rstn,
    output  [31:0]  pc,
    output  [31:0]  npc
);

wire    [2:0]   inst_type;
wire    [31:0]  trap_npc;
wire    [31:0]  imm_ext;
wire    [3:0]   pc_cnt_npc_src_sel;

wire    [31:0]  ifu_inst;

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

wire            is_ecall;
wire            is_mret;

wire    [31:0]  lsu_r_data;

wire    [8:0]   idu_to_lsu_data;

wire    [9:0]   idu_to_wbu_data;

wire            to_pc_valid;
wire            pc_to_ifu_ready;

wire            ifu_to_idu_valid;
wire            idu_to_ifu_ready;

wire            idu_to_exu_valid;
wire            exu_to_idu_ready;
wire            exu_to_lsu_valid;
wire            lsu_to_exu_ready;

wire            lsu_to_wbu_valid;
wire            wbu_to_lsu_ready;

wire    [31:0]  inst_araddr;
wire            inst_arvalid;
wire            inst_arready;
wire    [31:0]  inst_rdata;
wire    [1:0]   inst_rresp;
wire            inst_rvalid;
wire            inst_rready;
wire    [31:0]  inst_awaddr;
wire            inst_awvalid;
wire            inst_awready;
wire    [31:0]  inst_wdata;
wire    [3:0]   inst_wstrb;
wire            inst_wvalid;
wire            inst_wready;
wire    [1:0]   inst_bresp;
wire            inst_bvalid;
wire            inst_bready;

wire    [31:0]  lsu_araddr;
wire            lsu_arvalid;
wire            lsu_arready;
wire    [31:0]  lsu_rdata;
wire    [1:0]   lsu_rresp;
wire            lsu_rvalid;
wire            lsu_rready;
wire    [31:0]  lsu_awaddr;
wire            lsu_awvalid;
wire            lsu_awready;
wire    [31:0]  lsu_wdata;
wire    [3:0]   lsu_wstrb;
wire            lsu_wvalid;
wire            lsu_wready;
wire    [1:0]   lsu_bresp;
wire            lsu_bvalid;
wire            lsu_bready;

wire    [31:0]  xbar_araddr;
wire            xbar_arvalid;
wire            xbar_arready;
wire    [31:0]  xbar_rdata;
wire    [1:0]   xbar_rresp;
wire            xbar_rvalid;
wire            xbar_rready;
wire    [31:0]  xbar_awaddr;
wire            xbar_awvalid;
wire            xbar_awready;
wire    [31:0]  xbar_wdata;
wire    [3:0]   xbar_wstrb;
wire            xbar_wvalid;
wire            xbar_wready;
wire    [1:0]   xbar_bresp;
wire            xbar_bvalid;
wire            xbar_bready;

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

wire    [31:0]  uart_araddr;
wire            uart_arvalid;
wire            uart_arready;
wire    [31:0]  uart_rdata;
wire    [1:0]   uart_rresp;
wire            uart_rvalid;
wire            uart_rready;
wire    [31:0]  uart_awaddr;
wire            uart_awvalid;
wire            uart_awready;
wire    [31:0]  uart_wdata;
wire    [3:0]   uart_wstrb;
wire            uart_wvalid;
wire            uart_wready;
wire    [1:0]   uart_bresp;
wire            uart_bvalid;
wire            uart_bready;

assign trap_npc = is_ecall ? csr_r_mtvec : csr_r_mepc;

PCCnt u_PCCnt(
    .clk                 	(clk                ),
    .rstn                 	(rstn               ),
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
    .rstn                   (rstn               ),
    .ifu_current_pc_in  	(pc                 ),
    .ifu_inst_out       	(ifu_inst           ),
    .pc_to_ifu_ready_in     (pc_to_ifu_ready    ),
    .araddr_out           	(inst_araddr        ),
    .arvalid_out          	(inst_arvalid       ),
    .arready_in           	(inst_arready       ),
    .rdata_in             	(inst_rdata         ),
    .rresp_in             	(inst_rresp         ),
    .rvalid_in            	(inst_rvalid        ),
    .rready_out           	(inst_rready        ),
    .awaddr_out           	(inst_awaddr        ),
    .awvalid_out          	(inst_awvalid       ),
    .awready_in           	(inst_awready       ),
    .wdata_out            	(inst_wdata         ),
    .wstrb_out            	(inst_wstrb         ),
    .wvalid_out           	(inst_wvalid        ),
    .wready_in            	(inst_wready        ),
    .bresp_in             	(inst_bresp         ),
    .bvalid_in            	(inst_bvalid        ),
    .bready_out           	(inst_bready        ),
    .ifu_to_idu_valid_out   (ifu_to_idu_valid   ),
    .idu_to_ifu_ready_in    (idu_to_ifu_ready   )
);

IDU u_IDU(
    .clk                	(clk                ),
    .rstn                   (rstn               ),
    .idu_inst_in           	(ifu_inst           ),
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
    .imm_ext_imm_in       	(ifu_inst[31:7]     ),
    .imm_ext_imm_out      	(imm_ext            )
);

GPR u_GPR(
    .clk                    (clk                ),
    .gpr_we_in    	        (gpr_we             ),
    .gpr_r_addr1_in         (ifu_inst[19:15]    ),
    .gpr_r_addr2_in         (ifu_inst[24:20]    ),
    .gpr_w_addr_in          (gpr_w_addr         ),
    .gpr_w_data_in          (gpr_w_data         ),
    .gpr_r_data1_out        (gpr_r_data1        ),
    .gpr_r_data2_out        (gpr_r_data2        ),
    .gpr_r_a5_out           (gpr_r_a5           )
);

EXU u_EXU(
    .clk                    (clk                ),
    .rstn                   (rstn               ),
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
    .rstn                  	(rstn               ),
    .idu_to_lsu_data_in   	(idu_to_lsu_data    ),
    .lsu_r_addr_in        	(exu_res            ),
    .lsu_r_data_out       	(lsu_r_data         ),
    .lsu_w_addr_in        	(exu_res            ),
    .lsu_w_data_in        	(gpr_r_data2        ),
    .araddr_out           	(lsu_araddr         ),
    .arvalid_out          	(lsu_arvalid        ),
    .arready_in           	(lsu_arready        ),
    .rdata_in             	(lsu_rdata          ),
    .rresp_in             	(lsu_rresp          ),
    .rvalid_in            	(lsu_rvalid         ),
    .rready_out           	(lsu_rready         ),
    .awaddr_out           	(lsu_awaddr         ),
    .awvalid_out          	(lsu_awvalid        ),
    .awready_in           	(lsu_awready        ),
    .wdata_out            	(lsu_wdata          ),
    .wstrb_out            	(lsu_wstrb          ),
    .wvalid_out           	(lsu_wvalid         ),
    .wready_in            	(lsu_wready         ),
    .bresp_in             	(lsu_bresp          ),
    .bvalid_in            	(lsu_bvalid         ),
    .bready_out           	(lsu_bready         ),
    .exu_to_lsu_valid_in  	(exu_to_lsu_valid   ),
    .lsu_to_exu_ready_out 	(lsu_to_exu_ready   ),
    .lsu_to_wbu_valid_out 	(lsu_to_wbu_valid   ),
    .wbu_to_lsu_ready_in  	(wbu_to_lsu_ready   )
);

WBU u_WBU(
    .clk                    (clk                ),
    .rstn                   (rstn               ),
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

assign csr_w_data   = gpr_r_data1;
assign csr_w_mcause = gpr_r_a5;
assign csr_w_mepc   = pc;
assign csr_rw_addr  = ifu_inst[31:20];

CSR u_CSR(
    .clk                    (clk                ),
    .rstn                   (rstn               ),
    .is_ecall               (is_ecall           ),
    .is_mret                (is_mret            ),
    .csr_func3_in           (ifu_inst[14:12]    ),
    .csr_we_in              (csr_we             ),
    .csr_rw_addr_in         (csr_rw_addr        ),
    .csr_w_data_in          (csr_w_data         ),
    .csr_w_mcause_in 	    (csr_w_mcause       ),
    .csr_w_mepc_in   	    (csr_w_mepc         ),
    .csr_r_data_out         (csr_r_data         ),
    .csr_r_mtvec_out   	    (csr_r_mtvec        ),
    .csr_r_mepc_out         (csr_r_mepc         )
);

Arbiter u_Arbiter(
    .clk        	        (clk                ),
    .rstn       	        (rstn               ),
    .m0_araddr  	        (inst_araddr        ),
    .m0_arvalid 	        (inst_arvalid       ),
    .m0_arready 	        (inst_arready       ),
    .m0_rdata   	        (inst_rdata         ),
    .m0_rresp   	        (inst_rresp         ),
    .m0_rvalid  	        (inst_rvalid        ),
    .m0_rready  	        (inst_rready        ),
    .m0_awaddr  	        (inst_awaddr        ),
    .m0_awvalid 	        (inst_awvalid       ),
    .m0_awready 	        (inst_awready       ),
    .m0_wdata   	        (inst_wdata         ),
    .m0_wstrb   	        (inst_wstrb         ),
    .m0_wvalid  	        (inst_wvalid        ),
    .m0_wready  	        (inst_wready        ),
    .m0_bresp   	        (inst_bresp         ),
    .m0_bvalid  	        (inst_bvalid        ),
    .m0_bready  	        (inst_bready        ),
    .m1_araddr  	        (lsu_araddr         ),
    .m1_arvalid 	        (lsu_arvalid        ),
    .m1_arready 	        (lsu_arready        ),
    .m1_rdata   	        (lsu_rdata          ),
    .m1_rresp   	        (lsu_rresp          ),
    .m1_rvalid  	        (lsu_rvalid         ),
    .m1_rready  	        (lsu_rready         ),
    .m1_awaddr  	        (lsu_awaddr         ),
    .m1_awvalid 	        (lsu_awvalid        ),
    .m1_awready 	        (lsu_awready        ),
    .m1_wdata   	        (lsu_wdata          ),
    .m1_wstrb   	        (lsu_wstrb          ),
    .m1_wvalid  	        (lsu_wvalid         ),
    .m1_wready  	        (lsu_wready         ),
    .m1_bresp   	        (lsu_bresp          ),
    .m1_bvalid  	        (lsu_bvalid         ),
    .m1_bready  	        (lsu_bready         ),
    .s_araddr   	        (xbar_araddr        ),
    .s_arvalid  	        (xbar_arvalid       ),
    .s_arready  	        (xbar_arready       ),
    .s_rdata    	        (xbar_rdata         ),
    .s_rresp    	        (xbar_rresp         ),
    .s_rvalid   	        (xbar_rvalid        ),
    .s_rready   	        (xbar_rready        ),
    .s_awaddr   	        (xbar_awaddr        ),
    .s_awvalid  	        (xbar_awvalid       ),
    .s_awready  	        (xbar_awready       ),
    .s_wdata    	        (xbar_wdata         ),
    .s_wstrb    	        (xbar_wstrb         ),
    .s_wvalid   	        (xbar_wvalid        ),
    .s_wready   	        (xbar_wready        ),
    .s_bresp    	        (xbar_bresp         ),
    .s_bvalid   	        (xbar_bvalid        ),
    .s_bready   	        (xbar_bready        )
);

Xbar u_Xbar(
    .clk        	        (clk                ),
    .rstn       	        (rstn               ),
    .m_araddr   	        (xbar_araddr        ),
    .m_arvalid  	        (xbar_arvalid       ),
    .m_arready  	        (xbar_arready       ),
    .m_rdata    	        (xbar_rdata         ),
    .m_rresp    	        (xbar_rresp         ),
    .m_rvalid   	        (xbar_rvalid        ),
    .m_rready   	        (xbar_rready        ),
    .m_awaddr   	        (xbar_awaddr        ),
    .m_awvalid  	        (xbar_awvalid       ),
    .m_awready  	        (xbar_awready       ),
    .m_wdata    	        (xbar_wdata         ),
    .m_wstrb    	        (xbar_wstrb         ),
    .m_wvalid   	        (xbar_wvalid        ),
    .m_wready   	        (xbar_wready        ),
    .m_bresp    	        (xbar_bresp         ),
    .m_bvalid   	        (xbar_bvalid        ),
    .m_bready   	        (xbar_bready        ),
    .s0_araddr  	        (uart_araddr        ),
    .s0_arvalid 	        (uart_arvalid       ),
    .s0_arready 	        (uart_arready       ),
    .s0_rdata   	        (uart_rdata         ),
    .s0_rresp   	        (uart_rresp         ),
    .s0_rvalid  	        (uart_rvalid        ),
    .s0_rready  	        (uart_rready        ),
    .s0_awaddr  	        (uart_awaddr        ),
    .s0_awvalid 	        (uart_awvalid       ),
    .s0_awready 	        (uart_awready       ),
    .s0_wdata   	        (uart_wdata         ),
    .s0_wstrb   	        (uart_wstrb         ),
    .s0_wvalid  	        (uart_wvalid        ),
    .s0_wready  	        (uart_wready        ),
    .s0_bresp   	        (uart_bresp         ),
    .s0_bvalid  	        (uart_bvalid        ),
    .s0_bready  	        (uart_bready        ),
    .s1_araddr  	        (sram_araddr        ),
    .s1_arvalid 	        (sram_arvalid       ),
    .s1_arready 	        (sram_arready       ),
    .s1_rdata   	        (sram_rdata         ),
    .s1_rresp   	        (sram_rresp         ),
    .s1_rvalid  	        (sram_rvalid        ),
    .s1_rready  	        (sram_rready        ),
    .s1_awaddr  	        (sram_awaddr        ),
    .s1_awvalid 	        (sram_awvalid       ),
    .s1_awready 	        (sram_awready       ),
    .s1_wdata   	        (sram_wdata         ),
    .s1_wstrb   	        (sram_wstrb         ),
    .s1_wvalid  	        (sram_wvalid        ),
    .s1_wready  	        (sram_wready        ),
    .s1_bresp   	        (sram_bresp         ),
    .s1_bvalid  	        (sram_bvalid        ),
    .s1_bready  	        (sram_bready        )
);

SRAM u_SRAM(
    .clk         	        (clk                ),
    .rstn         	        (rstn               ),
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

UART u_UART(
    .clk         	        (clk                ),
    .rstn        	        (rstn               ),
    .araddr_in   	        (uart_araddr        ),
    .arvalid_in  	        (uart_arvalid       ),
    .arready_out 	        (uart_arready       ),
    .rdata_out   	        (uart_rdata         ),
    .rresp_out   	        (uart_rresp         ),
    .rvalid_out  	        (uart_rvalid        ),
    .rready_in   	        (uart_rready        ),
    .awaddr_in   	        (uart_awaddr        ),
    .awvalid_in  	        (uart_awvalid       ),
    .awready_out 	        (uart_awready       ),
    .wdata_in    	        (uart_wdata         ),
    .wstrb_in    	        (uart_wstrb         ),
    .wvalid_in   	        (uart_wvalid        ),
    .wready_out  	        (uart_wready        ),
    .bresp_out   	        (uart_bresp         ),
    .bvalid_out  	        (uart_bvalid        ),
    .bready_in   	        (uart_bready        )
);

endmodule
