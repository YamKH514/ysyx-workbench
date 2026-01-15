module ysyx_25120296(
    input           clock,
    input           reset,
    input           io_interrupt,

    output  [3:0]   io_master_arid,
    output  [31:0]  io_master_araddr,
    output  [7:0]   io_master_arlen,
    output  [2:0]   io_master_arsize,
    output  [1:0]   io_master_arburst,
    output          io_master_arvalid,
    input           io_master_arready,
    input   [3:0]   io_master_rid,
    input   [31:0]  io_master_rdata,
    input   [1:0]   io_master_rresp,
    input           io_master_rlast,
    input           io_master_rvalid,
    output          io_master_rready,
    output  [3:0]   io_master_awid,
    output  [31:0]  io_master_awaddr,
    output  [7:0]   io_master_awlen,
    output  [2:0]   io_master_awsize,
    output  [1:0]   io_master_awburst,
    output          io_master_awvalid,
    input           io_master_awready,
    output  [31:0]  io_master_wdata,
    output  [3:0]   io_master_wstrb,
    output          io_master_wlast,
    output          io_master_wvalid,
    input           io_master_wready,
    input   [3:0]   io_master_bid,
    input   [1:0]   io_master_bresp,
    input           io_master_bvalid,
    output          io_master_bready,

    input   [3:0]   io_slave_arid,
    input   [31:0]  io_slave_araddr,
    input   [7:0]   io_slave_arlen,
    input   [2:0]   io_slave_arsize,
    input   [1:0]   io_slave_arburst,
    input           io_slave_arvalid,
    output          io_slave_arready,
    output  [3:0]   io_slave_rid,
    output  [31:0]  io_slave_rdata,
    output  [1:0]   io_slave_rresp,
    output          io_slave_rlast,
    output          io_slave_rvalid,
    input           io_slave_rready,
    input   [3:0]   io_slave_awid,
    input   [31:0]  io_slave_awaddr,
    input   [7:0]   io_slave_awlen,
    input   [2:0]   io_slave_awsize,
    input   [1:0]   io_slave_awburst,
    input           io_slave_awvalid,
    output          io_slave_awready,
    input   [31:0]  io_slave_wdata,
    input   [3:0]   io_slave_wstrb,
    input           io_slave_wlast,
    input           io_slave_wvalid,
    output          io_slave_wready,
    output  [3:0]   io_slave_bid,
    output  [1:0]   io_slave_bresp,
    output          io_slave_bvalid,
    input           io_slave_bready
);

assign io_slave_arready = 0;
assign io_slave_rid = 0;
assign io_slave_rdata = 0;
assign io_slave_rresp = 0;
assign io_slave_rlast = 0;
assign io_slave_rvalid = 0;
assign io_slave_awready = 0;
assign io_slave_wready = 0;
assign io_slave_bid = 0;
assign io_slave_bresp = 0;
assign io_slave_bvalid = 0;

wire    [31:0]  pc;
wire    [31:0]  npc;

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

wire            csr_we;
wire    [11:0]  csr_rw_addr;
wire    [31:0]  csr_w_data;
wire    [31:0]  csr_w_mepc;
wire    [31:0]  csr_r_data;
wire    [31:0]  csr_r_mtvec;
wire    [31:0]  csr_r_mepc;

wire            is_ecall;
wire            is_mret;

wire    [31:0]  lsu_r_data;

wire    [8:0]   idu_to_lsu_data;

wire    [9:0]   idu_to_wbu_data;

wire            wbu_to_pc_valid;
wire            pc_to_wbu_ready;
wire            pc_to_ifu_valid;
wire            ifu_to_pc_ready;

wire            ifu_to_idu_valid;
wire            idu_to_ifu_ready;

wire            idu_to_exu_valid;
wire            exu_to_idu_ready;
wire            exu_to_lsu_valid;
wire            lsu_to_exu_ready;

wire            lsu_to_wbu_valid;
wire            wbu_to_lsu_ready;

wire bs;
wire bs1;
wire br1;
wire bg1;
wire bs2;
wire br2;
wire bg2;

wire    [3:0]   inst_arid;
wire    [31:0]  inst_araddr;
wire    [3:0]   inst_arlen;
wire    [2:0]   inst_arsize;
wire    [1:0]   inst_arburst;
wire            inst_arvalid;
wire            inst_arready;
wire    [3:0]   inst_rid;
wire    [31:0]  inst_rdata;
wire    [1:0]   inst_rresp;
wire            inst_rlast;
wire            inst_rvalid;
wire            inst_rready;
wire    [3:0]   inst_awid;
wire    [31:0]  inst_awaddr;
wire    [3:0]   inst_awlen;
wire    [2:0]   inst_awsize;
wire    [1:0]   inst_awburst;
wire            inst_awvalid;
wire            inst_awready;
wire    [31:0]  inst_wdata;
wire    [3:0]   inst_wstrb;
wire            inst_wlast;
wire            inst_wvalid;
wire            inst_wready;
wire    [3:0]   inst_bid;
wire    [1:0]   inst_bresp;
wire            inst_bvalid;
wire            inst_bready;

wire    [3:0]   lsu_arid;
wire    [31:0]  lsu_araddr;
wire    [3:0]   lsu_arlen;
wire    [2:0]   lsu_arsize;
wire    [1:0]   lsu_arburst;
wire            lsu_arvalid;
wire            lsu_arready;
wire    [3:0]   lsu_rid;
wire    [31:0]  lsu_rdata;
wire    [1:0]   lsu_rresp;
wire            lsu_rlast;
wire            lsu_rvalid;
wire            lsu_rready;
wire    [3:0]   lsu_awid;
wire    [31:0]  lsu_awaddr;
wire    [3:0]   lsu_awlen;
wire    [2:0]   lsu_awsize;
wire    [1:0]   lsu_awburst;
wire            lsu_awvalid;
wire            lsu_awready;
wire    [31:0]  lsu_wdata;
wire    [3:0]   lsu_wstrb;
wire            lsu_wlast;
wire            lsu_wvalid;
wire            lsu_wready;
wire    [3:0]   lsu_bid;
wire    [1:0]   lsu_bresp;
wire            lsu_bvalid;
wire            lsu_bready;

wire    [3:0]   xbar_arid;
wire    [31:0]  xbar_araddr;
wire    [3:0]   xbar_arlen;
wire    [2:0]   xbar_arsize;
wire    [1:0]   xbar_arburst;
wire            xbar_arvalid;
wire            xbar_arready;
wire    [3:0]   xbar_rid;
wire    [31:0]  xbar_rdata;
wire    [1:0]   xbar_rresp;
wire            xbar_rlast;
wire            xbar_rvalid;
wire            xbar_rready;
wire    [3:0]   xbar_awid;
wire    [31:0]  xbar_awaddr;
wire    [3:0]   xbar_awlen;
wire    [2:0]   xbar_awsize;
wire    [1:0]   xbar_awburst;
wire            xbar_awvalid;
wire            xbar_awready;
wire    [31:0]  xbar_wdata;
wire    [3:0]   xbar_wstrb;
wire            xbar_wlast;
wire            xbar_wvalid;
wire            xbar_wready;
wire    [3:0]   xbar_bid;
wire    [1:0]   xbar_bresp;
wire            xbar_bvalid;
wire            xbar_bready;

wire    [3:0]   clint_arid;
wire    [31:0]  clint_araddr;
wire    [3:0]   clint_arlen;
wire    [2:0]   clint_arsize;
wire    [1:0]   clint_arburst;
wire            clint_arvalid;
wire            clint_arready;
wire    [3:0]   clint_rid;
wire    [31:0]  clint_rdata;
wire    [1:0]   clint_rresp;
wire            clint_rlast;
wire            clint_rvalid;
wire            clint_rready;
wire    [3:0]   clint_awid;
wire    [31:0]  clint_awaddr;
wire    [3:0]   clint_awlen;
wire    [2:0]   clint_awsize;
wire    [1:0]   clint_awburst;
wire            clint_awvalid;
wire            clint_awready;
wire    [31:0]  clint_wdata;
wire    [3:0]   clint_wstrb;
wire            clint_wlast;
wire            clint_wvalid;
wire            clint_wready;
wire    [3:0]   clint_bid;
wire    [1:0]   clint_bresp;
wire            clint_bvalid;
wire            clint_bready;

assign trap_npc = is_ecall ? csr_r_mtvec : csr_r_mepc;

PCCnt u_PCCnt(
    .clk                 	(clock              ),
    .rst                  	(reset              ),
    .pc_cnt_cmp_res_in     	(exu_res[0]         ),
    .pc_cnt_rd1_in         	(gpr_r_data1        ),
    .pc_cnt_imm_in         	(imm_ext            ),
    .pc_cnt_npc_src_sel_in 	(pc_cnt_npc_src_sel ),
    .pc_cnt_trap_npc_in    	(trap_npc           ),
    .pc_cnt_pc_out         	(pc                 ),
    .pc_cnt_npc_out        	(npc                ),
    .wbu_to_pc_valid_in     (wbu_to_pc_valid    ),
    .pc_to_wbu_ready_out    (pc_to_wbu_ready    ),
    .pc_to_ifu_valid_out    (pc_to_ifu_valid    ),
    .ifu_to_pc_ready_in     (ifu_to_pc_ready    )
);

IFU u_IFU(
    .clk                    (clock              ),
    .rst                    (reset              ),
    .ifu_current_pc_in  	(pc                 ),
    .ifu_inst_out       	(ifu_inst           ),
    .pc_to_ifu_valid_in     (pc_to_ifu_valid    ),
    .ifu_to_pc_ready_out    (ifu_to_pc_ready    ),
    .arid_out               (inst_arid          ),
    .araddr_out           	(inst_araddr        ),
    .arlen_out              (inst_arlen         ),
    .arsize_out             (inst_arsize        ),
    .arburst_out            (inst_arburst       ),
    .arvalid_out          	(inst_arvalid       ),
    .arready_in           	(inst_arready       ),
    .rid_in                 (inst_rid           ),
    .rdata_in             	(inst_rdata         ),
    .rresp_in             	(inst_rresp         ),
    .rlast_in               (inst_rlast         ),
    .rvalid_in            	(inst_rvalid        ),
    .rready_out           	(inst_rready        ),
    .awid_out               (inst_awid          ),
    .awaddr_out           	(inst_awaddr        ),
    .awlen_out              (inst_awlen         ),
    .awsize_out             (inst_awsize        ),
    .awburst_out            (inst_awburst       ),
    .awvalid_out          	(inst_awvalid       ),
    .awready_in           	(inst_awready       ),
    .wdata_out            	(inst_wdata         ),
    .wstrb_out            	(inst_wstrb         ),
    .wlast_out              (inst_wlast         ),
    .wvalid_out           	(inst_wvalid        ),
    .wready_in            	(inst_wready        ),
    .bid_in                 (inst_bid           ),
    .bresp_in             	(inst_bresp         ),
    .bvalid_in            	(inst_bvalid        ),
    .bready_out           	(inst_bready        ),
    .ifu_to_idu_valid_out   (ifu_to_idu_valid   ),
    .idu_to_ifu_ready_in    (idu_to_ifu_ready   ),
    .bs_out                 (bs1                ),
    .br_out                 (br1                ),
    .bg_in                  (bg1                )
);

IDU u_IDU(
    .clk                	(clock              ),
    .rst                    (reset              ),
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
    .clk                    (clock              ),
    .gpr_we_in    	        (gpr_we             ),
    .gpr_r_addr1_in         (ifu_inst[19:15]    ),
    .gpr_r_addr2_in         (ifu_inst[24:20]    ),
    .gpr_w_addr_in          (gpr_w_addr         ),
    .gpr_w_data_in          (gpr_w_data         ),
    .gpr_r_data1_out        (gpr_r_data1        ),
    .gpr_r_data2_out        (gpr_r_data2        )
);

EXU u_EXU(
    .clk                    (clock              ),
    .rst                    (reset              ),
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
    .clk                  	(clock              ),
    .rst                  	(reset              ),
    .idu_to_lsu_data_in   	(idu_to_lsu_data    ),
    .lsu_r_addr_in        	(exu_res            ),
    .lsu_r_data_out       	(lsu_r_data         ),
    .lsu_w_addr_in        	(exu_res            ),
    .lsu_w_data_in        	(gpr_r_data2        ),
    .arid_out               (lsu_arid           ),
    .araddr_out           	(lsu_araddr         ),
    .arlen_out              (lsu_arlen          ),
    .arsize_out             (lsu_arsize         ),
    .arburst_out            (lsu_arburst        ),
    .arvalid_out          	(lsu_arvalid        ),
    .arready_in           	(lsu_arready        ),
    .rid_in                 (lsu_rid            ),
    .rdata_in             	(lsu_rdata          ),
    .rresp_in             	(lsu_rresp          ),
    .rlast_in               (lsu_rlast          ),
    .rvalid_in            	(lsu_rvalid         ),
    .rready_out           	(lsu_rready         ),
    .awid_out               (lsu_awid           ),
    .awaddr_out           	(lsu_awaddr         ),
    .awlen_out              (lsu_awlen          ),
    .awsize_out             (lsu_awsize         ),
    .awburst_out            (lsu_awburst        ),
    .awvalid_out          	(lsu_awvalid        ),
    .awready_in           	(lsu_awready        ),
    .wdata_out            	(lsu_wdata          ),
    .wstrb_out            	(lsu_wstrb          ),
    .wlast_out              (lsu_wlast          ),
    .wvalid_out           	(lsu_wvalid         ),
    .wready_in            	(lsu_wready         ),
    .bid_in                 (lsu_bid            ),
    .bresp_in             	(lsu_bresp          ),
    .bvalid_in            	(lsu_bvalid         ),
    .bready_out           	(lsu_bready         ),
    .exu_to_lsu_valid_in  	(exu_to_lsu_valid   ),
    .lsu_to_exu_ready_out 	(lsu_to_exu_ready   ),
    .lsu_to_wbu_valid_out 	(lsu_to_wbu_valid   ),
    .wbu_to_lsu_ready_in  	(wbu_to_lsu_ready   ),
    .bs_out                 (bs2                ),
    .br_out                 (br2                ),
    .bg_in                  (bg2                )
);

WBU u_WBU(
    .clk                    (clock              ),
    .rst                    (reset              ),
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
    .wbu_to_pc_valid_out    (wbu_to_pc_valid    ),
    .pc_to_wbu_ready_in     (pc_to_wbu_ready    )
);

assign csr_w_data   = gpr_r_data1;
assign csr_w_mepc   = pc;
assign csr_rw_addr  = ifu_inst[31:20];

CSR u_CSR(
    .clk                    (clock              ),
    .rst                    (reset              ),
    .is_ecall               (is_ecall           ),
    .is_mret                (is_mret            ),
    .csr_func3_in           (ifu_inst[14:12]    ),
    .csr_we_in              (csr_we             ),
    .csr_rw_addr_in         (csr_rw_addr        ),
    .csr_w_data_in          (csr_w_data         ),
    .csr_w_mepc_in   	    (csr_w_mepc         ),
    .csr_r_data_out         (csr_r_data         ),
    .csr_r_mtvec_out   	    (csr_r_mtvec        ),
    .csr_r_mepc_out         (csr_r_mepc         )
);

assign bs = bs1 | bs2;

Arbiter u_Arbiter(
    .clk     	            (clock              ),
    .rst    	            (reset              ),
    .bs_in   	            (bs                 ),
    .br1_in  	            (br1                ),
    .bg1_out 	            (bg1                ),
    .br2_in  	            (br2                ),
    .bg2_out 	            (bg2                )
);

assign xbar_arid = inst_arid | lsu_arid;
assign xbar_araddr = inst_araddr | lsu_araddr;
assign xbar_arlen = inst_arlen | lsu_arlen;
assign xbar_arsize = inst_arsize | lsu_arsize;
assign xbar_arburst = inst_arburst | lsu_arburst;
assign xbar_arvalid = inst_arvalid | lsu_arvalid;
assign inst_arready = xbar_arready;
assign lsu_arready = xbar_arready;
assign inst_rid = xbar_rid;
assign lsu_rid = xbar_rid;
assign inst_rdata = xbar_rdata;
assign lsu_rdata = xbar_rdata;
assign inst_rresp = xbar_rresp;
assign lsu_rresp = xbar_rresp;
assign inst_rlast = xbar_rlast;
assign lsu_rlast = xbar_rlast;
assign inst_rvalid = xbar_rvalid;
assign lsu_rvalid = xbar_rvalid;
assign xbar_rready = inst_rready | lsu_rready;
assign xbar_awid = inst_awid | lsu_awid;
assign xbar_awaddr = inst_awaddr | lsu_awaddr;
assign xbar_awlen = inst_awlen | lsu_awlen;
assign xbar_awsize = inst_awsize | lsu_awsize;
assign xbar_awburst = inst_awburst | lsu_awburst;
assign xbar_awvalid = inst_awvalid | lsu_awvalid;
assign inst_awready = xbar_awready;
assign lsu_awready = xbar_awready;
assign xbar_wdata = inst_wdata | lsu_wdata;
assign xbar_wstrb = inst_wstrb | lsu_wstrb;
assign xbar_wlast = inst_wlast | lsu_wlast;
assign xbar_wvalid = inst_wvalid | lsu_wvalid;
assign inst_wready = xbar_wready;
assign lsu_wready = xbar_wready;
assign inst_bid = xbar_bid;
assign lsu_bid = xbar_bid;
assign inst_bresp = xbar_bresp;
assign lsu_bresp = xbar_bresp;
assign inst_bvalid = xbar_bvalid;
assign lsu_bvalid = xbar_bvalid;
assign xbar_bready = inst_bready | lsu_bready;

Xbar u_Xbar(
    .clk        	        (clock              ),
    .rst       	            (reset              ),
    .m_arid                 (xbar_arid          ),
    .m_araddr           	(xbar_araddr        ),
    .m_arlen                (xbar_arlen         ),
    .m_arsize               (xbar_arsize        ),
    .m_arburst              (xbar_arburst       ),
    .m_arvalid          	(xbar_arvalid       ),
    .m_arready           	(xbar_arready       ),
    .m_rid                  (xbar_rid           ),
    .m_rdata             	(xbar_rdata         ),
    .m_rresp             	(xbar_rresp         ),
    .m_rlast                (xbar_rlast         ),
    .m_rvalid            	(xbar_rvalid        ),
    .m_rready           	(xbar_rready        ),
    .m_awid                 (xbar_awid          ),
    .m_awaddr           	(xbar_awaddr        ),
    .m_awlen                (xbar_awlen         ),
    .m_awsize               (xbar_awsize        ),
    .m_awburst              (xbar_awburst       ),
    .m_awvalid          	(xbar_awvalid       ),
    .m_awready           	(xbar_awready       ),
    .m_wdata            	(xbar_wdata         ),
    .m_wstrb            	(xbar_wstrb         ),
    .m_wlast                (xbar_wlast         ),
    .m_wvalid           	(xbar_wvalid        ),
    .m_wready            	(xbar_wready        ),
    .m_bid                  (xbar_bid           ),
    .m_bresp             	(xbar_bresp         ),
    .m_bvalid            	(xbar_bvalid        ),
    .m_bready           	(xbar_bready        ),
    .s0_arid                (io_master_arid     ),
    .s0_araddr           	(io_master_araddr   ),
    .s0_arlen               (io_master_arlen[3:0]),
    .s0_arsize              (io_master_arsize   ),
    .s0_arburst             (io_master_arburst  ),
    .s0_arvalid          	(io_master_arvalid  ),
    .s0_arready           	(io_master_arready  ),
    .s0_rid                 (io_master_rid      ),
    .s0_rdata             	(io_master_rdata    ),
    .s0_rresp             	(io_master_rresp    ),
    .s0_rlast               (io_master_rlast    ),
    .s0_rvalid            	(io_master_rvalid   ),
    .s0_rready           	(io_master_rready   ),
    .s0_awid                (io_master_awid     ),
    .s0_awaddr           	(io_master_awaddr   ),
    .s0_awlen               (io_master_awlen[3:0]),
    .s0_awsize              (io_master_awsize   ),
    .s0_awburst             (io_master_awburst  ),
    .s0_awvalid          	(io_master_awvalid  ),
    .s0_awready           	(io_master_awready  ),
    .s0_wdata            	(io_master_wdata    ),
    .s0_wstrb            	(io_master_wstrb    ),
    .s0_wlast               (io_master_wlast    ),
    .s0_wvalid           	(io_master_wvalid   ),
    .s0_wready            	(io_master_wready   ),
    .s0_bid                 (io_master_bid      ),
    .s0_bresp             	(io_master_bresp    ),
    .s0_bvalid            	(io_master_bvalid   ),
    .s0_bready           	(io_master_bready   ),
    .s1_arid                (clint_arid         ),
    .s1_araddr           	(clint_araddr       ),
    .s1_arlen               (clint_arlen        ),
    .s1_arsize              (clint_arsize       ),
    .s1_arburst             (clint_arburst      ),
    .s1_arvalid          	(clint_arvalid      ),
    .s1_arready           	(clint_arready      ),
    .s1_rid                 (clint_rid          ),
    .s1_rdata             	(clint_rdata        ),
    .s1_rresp             	(clint_rresp        ),
    .s1_rlast               (clint_rlast        ),
    .s1_rvalid            	(clint_rvalid       ),
    .s1_rready           	(clint_rready       ),
    .s1_awid                (clint_awid         ),
    .s1_awaddr           	(clint_awaddr       ),
    .s1_awlen               (clint_awlen        ),
    .s1_awsize              (clint_awsize       ),
    .s1_awburst             (clint_awburst      ),
    .s1_awvalid          	(clint_awvalid      ),
    .s1_awready           	(clint_awready      ),
    .s1_wdata            	(clint_wdata        ),
    .s1_wstrb            	(clint_wstrb        ),
    .s1_wlast               (clint_wlast        ),
    .s1_wvalid           	(clint_wvalid       ),
    .s1_wready            	(clint_wready       ),
    .s1_bid                 (clint_bid          ),
    .s1_bresp             	(clint_bresp        ),
    .s1_bvalid            	(clint_bvalid       ),
    .s1_bready           	(clint_bready       )
);

CLINT u_CLINT(
    .clk         	        (clock              ),
    .rst        	        (reset              ),
    .arid_in     	        (clint_arid         ),
    .araddr_in   	        (clint_araddr       ),
    .arlen_in    	        (clint_arlen        ),
    .arsize_in   	        (clint_arsize       ),
    .arburst_in  	        (clint_arburst      ),
    .arvalid_in  	        (clint_arvalid      ),
    .arready_out 	        (clint_arready      ),
    .rid_out     	        (clint_rid          ),
    .rdata_out   	        (clint_rdata        ),
    .rresp_out   	        (clint_rresp        ),
    .rlast_out              (clint_rlast        ),
    .rvalid_out  	        (clint_rvalid       ),
    .rready_in   	        (clint_rready       ),
    .awid_in     	        (clint_awid         ),
    .awaddr_in   	        (clint_awaddr       ),
    .awlen_in    	        (clint_awlen        ),
    .awsize_in   	        (clint_awsize       ),
    .awburst_in  	        (clint_awburst      ),
    .awvalid_in  	        (clint_awvalid      ),
    .awready_out 	        (clint_awready      ),
    .wdata_in    	        (clint_wdata        ),
    .wstrb_in    	        (clint_wstrb        ),
    .wlast_in               (clint_wlast        ),
    .wvalid_in   	        (clint_wvalid       ),
    .wready_out  	        (clint_wready       ),
    .bid_out     	        (clint_bid          ),
    .bresp_out   	        (clint_bresp        ),
    .bvalid_out  	        (clint_bvalid       ),
    .bready_in   	        (clint_bready       )
);

endmodule
