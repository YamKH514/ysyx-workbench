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

// To keep wire npc
reg [31:0] npc_r;
always @(posedge clock) begin
    npc_r <= npc;
end

wire [31:0] trap_npc;

wire [31:0] csr_r_mtvec;
wire [31:0] csr_r_mepc;

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

assign trap_npc = wbu_pc_ecall ? csr_r_mtvec : csr_r_mepc;

wire [31:0] ifu_pc;
wire [31:0] ifu_inst;
wire [ 9:0] gpr_raddr;
wire [11:0] csr_raddr;
wire [31:0] idu_pc;
wire [31:0] idu_inst;
wire        fence_i;
wire [ 2:0] idu_imm_type;
wire [24:0] idu_imm_inst;
wire [ 5:0] idu_exu_fun;
wire [ 1:0] idu_exu_src1_sel;
wire [ 1:0] idu_exu_src2_sel;
wire [63:0] idu_exu_rdata;
wire [ 8:0] idu_exu_lsu_data;
wire [ 9:0] idu_exu_wbu_data;
wire [31:0] idu_exu_wbu_csr_rdata;
wire        idu_exu_wbu_csr_we;
wire [ 3:0] idu_exu_pc_src_sel;
wire [31:0] exu_pc;
wire [31:0] exu_inst;
wire [ 3:0] idu_exu_src_sel;
wire [31:0] exu_lsu_res;
wire [ 8:0] exu_lsu_data;
wire [63:0] exu_lsu_gpr_rdata;
wire [31:0] exu_lsu_wbu_csr_rdata;
wire        exu_lsu_wbu_csr_we;
wire [ 9:0] exu_lsu_wbu_data;
wire [31:0] exu_lsu_pc_imm;
wire [ 3:0] exu_lsu_pc_src_sel;
wire [31:0] lsu_pc;
wire [31:0] lsu_inst;
wire [31:0] lsu_wbu_res;
wire [31:0] lsu_wbu_rdata;
wire [ 9:0] lsu_wbu_data;
wire        lsu_wbu_csr_we;
wire [31:0] lsu_wbu_csr_rdata;
wire [31:0] lsu_wbu_csr_wdata;
wire [31:0] lsu_wbu_pc_rdata1;
wire [31:0] lsu_wbu_pc_imm;
wire [ 3:0] lsu_wbu_pc_src_sel;
wire        wbu_gpr_we;
wire [ 4:0] wbu_gpr_waddr;
wire [31:0] wbu_gpr_wdata;
wire [ 2:0] wbu_csr_func3;
wire        wbu_csr_we;
wire [11:0] wbu_csr_waddr;
wire [31:0] wbu_csr_wdata;
wire [31:0] wbu_csr_mepc;
wire        wbu_csr_ecall;
wire        wbu_csr_mret;
wire        wbu_pc_ecall;
wire [31:0] wbu_pc_rdata1;
wire [31:0] wbu_pc_imm;
wire        wbu_pc_cmp_res;
wire [ 3:0] wbu_pc_src_sel;

wire [31:0] imm_exu;
wire [31:0] gpr_rdata1;
wire [31:0] gpr_rdata2;
wire [31:0] csr_rdata;
wire [31:0] csr_r_mtvec;
wire [31:0] csr_r_mepc;

wire ifu_idu_ready;
wire idu_exu_valid;
wire idu_exu_ready;
wire exu_lsu_valid;
wire exu_lsu_ready;
wire lsu_wbu_valid;
wire lsu_wbu_ready;
wire wbu_pc_valid;
wire wbu_pc_ready;
wire pc_ifu_valid;
wire pc_ifu_ready;
wire ifu_idu_valid;

PCCnt #(.RESET_PC 	(32'h30000000  )) u_PCCnt(
    .clk                  	(clock                 ),
    .rst                  	(reset                 ),
    .pc_cnt_cmp_res_i     	(wbu_pc_cmp_res        ),
    .pc_cnt_rd1_i         	(wbu_pc_rdata1         ),
    .pc_cnt_imm_i         	(wbu_pc_imm            ),
    .pc_cnt_npc_src_sel_i 	(wbu_pc_src_sel        ),
    .pc_cnt_trap_npc_i    	(trap_npc              ),
    .pc_cnt_pc_o          	(pc                    ),
    .pc_cnt_npc_o         	(npc                   ),
    .wbu_pc_valid_i       	(wbu_pc_valid          ),
    .wbu_pc_ready_o       	(wbu_pc_ready          ),
    .pc_ifu_valid_o       	(pc_ifu_valid          ),
    .pc_ifu_ready_i       	(pc_ifu_ready          )
);

IFU u_IFU(
    .clk             	(clock            ),
    .rst             	(reset            ),
    .pc_i            	(pc               ),
    .ifu_pc_o        	(ifu_pc           ),
    .ifu_inst_o      	(ifu_inst         ),
    .pc_ifu_valid_i  	(pc_ifu_valid     ),
    .pc_ifu_ready_o  	(pc_ifu_ready     ),
    .ifu_idu_valid_o 	(ifu_idu_valid    ),
    .ifu_idu_ready_i 	(ifu_idu_ready    ),
    .ifu_gpr_raddr_o    (gpr_raddr        ),
    .ifu_csr_raddr_o    (csr_raddr        ),
    .fence_i_i       	(fence_i          ),
    .arid_o          	(inst_arid        ),
    .araddr_o        	(inst_araddr      ),
    .arlen_o         	(inst_arlen       ),
    .arsize_o        	(inst_arsize      ),
    .arburst_o       	(inst_arburst     ),
    .arvalid_o       	(inst_arvalid     ),
    .arready_i       	(inst_arready     ),
    .rid_i           	(inst_rid         ),
    .rdata_i         	(inst_rdata       ),
    .rresp_i         	(inst_rresp       ),
    .rlast_i         	(inst_rlast       ),
    .rvalid_i        	(inst_rvalid      ),
    .rready_o        	(inst_rready      ),
    .awid_o          	(inst_awid        ),
    .awaddr_o        	(inst_awaddr      ),
    .awlen_o         	(inst_awlen       ),
    .awsize_o        	(inst_awsize      ),
    .awburst_o       	(inst_awburst     ),
    .awvalid_o       	(inst_awvalid     ),
    .awready_i       	(inst_awready     ),
    .wdata_o         	(inst_wdata       ),
    .wstrb_o         	(inst_wstrb       ),
    .wlast_o         	(inst_wlast       ),
    .wvalid_o        	(inst_wvalid      ),
    .wready_i        	(inst_wready      ),
    .bid_i           	(inst_bid         ),
    .bresp_i         	(inst_bresp       ),
    .bvalid_i        	(inst_bvalid      ),
    .bready_o        	(inst_bready      ),
    .bs_o            	(bs1              ),
    .br_o            	(br1              ),
    .bg_i            	(bg1              )
);

IDU u_IDU(
    .clk                     	(clock                    ),
    .rst                     	(reset                    ),
    .ifu_pc_i                   (ifu_pc                   ),
    .ifu_inst_i          	    (ifu_inst                 ),
    .idu_pc_o                   (idu_pc                   ),
    .idu_inst_o                 (idu_inst                 ),
    .gpr_idu_rdata1_i        	(gpr_rdata1               ),
    .gpr_idu_rdata2_i        	(gpr_rdata2               ),
    .csr_idu_rdata_i         	(csr_rdata                ),
    .fence_i_o               	(fence_i                  ),
    .idu_imm_type_o          	(idu_imm_type             ),
    .idu_imm_inst_o             (idu_imm_inst             ),
    .idu_exu_fun_o           	(idu_exu_fun              ),
    .idu_exu_src1_sel_o      	(idu_exu_src1_sel         ),
    .idu_exu_src2_sel_o      	(idu_exu_src2_sel         ),
    .idu_exu_rdata_o         	(idu_exu_rdata            ),
    .idu_exu_lsu_data_o      	(idu_exu_lsu_data         ),
    .idu_exu_wbu_data_o      	(idu_exu_wbu_data         ),
    .idu_exu_wbu_csr_rdata_o 	(idu_exu_wbu_csr_rdata    ),
    .idu_exu_wbu_csr_we_o    	(idu_exu_wbu_csr_we       ),
    .idu_exu_pc_src_sel_o    	(idu_exu_pc_src_sel       ),
    .ifu_idu_valid_i         	(ifu_idu_valid            ),
    .ifu_idu_ready_o         	(ifu_idu_ready            ),
    .idu_exu_valid_o         	(idu_exu_valid            ),
    .idu_exu_ready_i         	(idu_exu_ready            )
);

ImmExt u_ImmExt(
    .idu_imm_type_i         (idu_imm_type         ),
    .idu_imm_inst_i      	(idu_imm_inst         ),
    .imm_exu_o           	(imm_exu              )
);

assign idu_exu_src_sel = {idu_exu_src2_sel, idu_exu_src1_sel};

EXU u_EXU(
    .clk                     	(clock                    ),
    .rst                     	(reset                    ),
    .idu_pc_i            	    (idu_pc                   ),
    .idu_inst_i                 (idu_inst                 ),
    .exu_pc_o                   (exu_pc                   ),
    .exu_inst_o                 (exu_inst                 ),
    .idu_exu_lsu_data_i      	(idu_exu_lsu_data         ),
    .idu_exu_wbu_csr_rdata_i 	(idu_exu_wbu_csr_rdata    ),
    .idu_exu_wbu_data_i      	(idu_exu_wbu_data         ),
    .idu_exu_wbu_csr_we_i    	(idu_exu_wbu_csr_we       ),
    .idu_exu_pc_src_sel_i    	(idu_exu_pc_src_sel       ),
    .idu_exu_rdata_i         	(idu_exu_rdata            ),
    .idu_exu_fun_i           	(idu_exu_fun              ),
    .idu_exu_src_sel_i       	(idu_exu_src_sel          ),
    .imm_exu_i               	(imm_exu                  ),
    .exu_lsu_res_o           	(exu_lsu_res              ),
    .exu_lsu_data_o          	(exu_lsu_data             ),
    .exu_lsu_gpr_rdata_o     	(exu_lsu_gpr_rdata        ),
    .exu_lsu_wbu_csr_rdata_o 	(exu_lsu_wbu_csr_rdata    ),
    .exu_lsu_wbu_csr_we_o    	(exu_lsu_wbu_csr_we       ),
    .exu_lsu_wbu_data_o      	(exu_lsu_wbu_data         ),
    .exu_lsu_pc_imm_o           (exu_lsu_pc_imm           ),
    .exu_lsu_pc_src_sel_o    	(exu_lsu_pc_src_sel       ),
    .idu_exu_valid_i         	(idu_exu_valid            ),
    .idu_exu_ready_o         	(idu_exu_ready            ),
    .exu_lsu_valid_o         	(exu_lsu_valid            ),
    .exu_lsu_ready_i         	(exu_lsu_ready            )
);

LSU u_LSU(
    .clk                     	(clock                    ),
    .rst                     	(reset                    ),
    .exu_pc_i                   (exu_pc),
    .exu_inst_i                 (exu_inst),
    .lsu_pc_o                   (lsu_pc),
    .lsu_inst_o                 (lsu_inst),
    .exu_lsu_wbu_csr_rdata_i 	(exu_lsu_wbu_csr_rdata    ),
    .exu_lsu_wbu_data_i      	(exu_lsu_wbu_data         ),
    .exu_lsu_wbu_csr_we_i    	(exu_lsu_wbu_csr_we       ),
    .exu_lsu_pc_imm_i           (exu_lsu_pc_imm),
    .exu_lsu_pc_src_sel_i    	(exu_lsu_pc_src_sel       ),
    .exu_lsu_data_i          	(exu_lsu_data             ),
    .exu_lsu_res_i           	(exu_lsu_res              ),
    .exu_lsu_gpr_rdata_i     	(exu_lsu_gpr_rdata        ),
    .lsu_wbu_res_o           	(lsu_wbu_res              ),
    .lsu_wbu_rdata_o         	(lsu_wbu_rdata            ),
    .lsu_wbu_data_o          	(lsu_wbu_data             ),
    .lsu_wbu_csr_we_o        	(lsu_wbu_csr_we           ),
    .lsu_wbu_csr_rdata_o     	(lsu_wbu_csr_rdata        ),
    .lsu_wbu_csr_wdata_o     	(lsu_wbu_csr_wdata        ),
    .lsu_wbu_pc_rdata1_o        (lsu_wbu_pc_rdata1        ),
    .lsu_wbu_pc_imm_o           (lsu_wbu_pc_imm           ),
    .lsu_wbu_pc_src_sel_o    	(lsu_wbu_pc_src_sel       ),
    .exu_lsu_valid_i      	    (exu_lsu_valid            ),
    .exu_lsu_ready_o      	    (exu_lsu_ready            ),
    .lsu_wbu_valid_o      	    (lsu_wbu_valid            ),
    .lsu_wbu_ready_i      	    (lsu_wbu_ready            ),
    .arid_o                  	(lsu_arid                 ),
    .araddr_o                	(lsu_araddr               ),
    .arlen_o                 	(lsu_arlen                ),
    .arsize_o                	(lsu_arsize               ),
    .arburst_o               	(lsu_arburst              ),
    .arvalid_o               	(lsu_arvalid              ),
    .arready_i               	(lsu_arready              ),
    .rid_i                   	(lsu_rid                  ),
    .rdata_i                 	(lsu_rdata                ),
    .rresp_i                 	(lsu_rresp                ),
    .rlast_i                 	(lsu_rlast                ),
    .rvalid_i                	(lsu_rvalid               ),
    .rready_o                	(lsu_rready               ),
    .awid_o                  	(lsu_awid                 ),
    .awaddr_o                	(lsu_awaddr               ),
    .awlen_o                 	(lsu_awlen                ),
    .awsize_o                	(lsu_awsize               ),
    .awburst_o               	(lsu_awburst              ),
    .awvalid_o               	(lsu_awvalid              ),
    .awready_i               	(lsu_awready              ),
    .wdata_o                 	(lsu_wdata                ),
    .wstrb_o                 	(lsu_wstrb                ),
    .wlast_o                 	(lsu_wlast                ),
    .wvalid_o                	(lsu_wvalid               ),
    .wready_i                	(lsu_wready               ),
    .bid_i                   	(lsu_bid                  ),
    .bresp_i                 	(lsu_bresp                ),
    .bvalid_i                	(lsu_bvalid               ),
    .bready_o                	(lsu_bready               ),
    .bs_o                    	(bs2                      ),
    .br_o                    	(br2                      ),
    .bg_i                    	(bg2                      )
);

WBU u_WBU(
    .clk                  	(clock                 ),
    .rst                  	(reset                 ),
    .lsu_pc_i               (lsu_pc),
    .lsu_inst_i             (lsu_inst),
    .lsu_wbu_data_i       	(lsu_wbu_data          ),
    .lsu_wbu_res_i        	(lsu_wbu_res           ),
    .lsu_wbu_rdata_i      	(lsu_wbu_rdata         ),
    .lsu_wbu_csr_rdata_i  	(lsu_wbu_csr_rdata     ),
    .lsu_wbu_csr_we_i     	(lsu_wbu_csr_we        ),
    .lsu_wbu_csr_wdata_i  	(lsu_wbu_csr_wdata     ),
    .lsu_wbu_pc_rdata1_i    (lsu_wbu_pc_rdata1     ),
    .lsu_wbu_pc_imm_i       (lsu_wbu_pc_imm        ),
    .lsu_wbu_pc_src_sel_i 	(lsu_wbu_pc_src_sel    ),
    .wbu_gpr_we_o         	(wbu_gpr_we            ),
    .wbu_gpr_waddr_o      	(wbu_gpr_waddr         ),
    .wbu_gpr_wdata_o      	(wbu_gpr_wdata         ),
    .wbu_csr_func3_o      	(wbu_csr_func3         ),
    .wbu_csr_we_o         	(wbu_csr_we            ),
    .wbu_csr_waddr_o        (wbu_csr_waddr         ),
    .wbu_csr_wdata_o      	(wbu_csr_wdata         ),
    .wbu_csr_mepc_o       	(wbu_csr_mepc          ),
    .wbu_csr_ecall_o      	(wbu_csr_ecall         ),
    .wbu_csr_mret_o       	(wbu_csr_mret          ),
    .wbu_pc_ecall_o         (wbu_pc_ecall          ),
    .wbu_pc_rdata1_o        (wbu_pc_rdata1         ),
    .wbu_pc_imm_o           (wbu_pc_imm            ),
    .wbu_pc_cmp_res_o       (wbu_pc_cmp_res        ),
    .wbu_pc_src_sel_o     	(wbu_pc_src_sel        ),
    .lsu_wbu_valid_i      	(lsu_wbu_valid         ),
    .lsu_wbu_ready_o      	(lsu_wbu_ready         ),
    .wbu_pc_valid_o       	(wbu_pc_valid          ),
    .wbu_pc_ready_i       	(wbu_pc_ready          )
);

GPR u_GPR(
    .clk           	(clock          ),
    .gpr_we_i      	(wbu_gpr_we     ),
    .gpr_waddr_i  	(wbu_gpr_waddr  ),
    .gpr_wdata_i  	(wbu_gpr_wdata  ),
    .gpr_raddr1_i 	(gpr_raddr[4:0] ),
    .gpr_raddr2_i 	(gpr_raddr[9:5] ),
    .gpr_rdata1_o 	(gpr_rdata1     ),
    .gpr_rdata2_o 	(gpr_rdata2     )
);

CSR u_CSR(
    .clk           	(clock          ),
    .rst           	(reset          ),
    .is_ecall      	(wbu_csr_ecall  ),
    .is_mret       	(wbu_csr_mret   ),
    .csr_raddr_i   	(csr_raddr      ),
    .csr_rdata_o  	(csr_rdata      ),
    .csr_func3_i   	(wbu_csr_func3  ),
    .csr_we_i      	(wbu_csr_we     ),
    .csr_waddr_i   	(wbu_csr_waddr  ),
    .csr_wdata_i  	(wbu_csr_wdata  ),
    .csr_w_mepc_i  	(wbu_csr_mepc   ),
    .csr_r_mtvec_o 	(csr_r_mtvec    ),
    .csr_r_mepc_o  	(csr_r_mepc     )
);

assign bs = bs1 | bs2;

Arbiter u_Arbiter(
    .clk     	            (clock              ),
    .rst    	            (reset              ),
    .bs_i   	            (bs                 ),
    .br1_i  	            (br1                ),
    .bg1_o 	                (bg1                ),
    .br2_i  	            (br2                ),
    .bg2_o 	                (bg2                )
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
    .arid_i      	        (clint_arid         ),
    .araddr_i    	        (clint_araddr       ),
    .arlen_i     	        (clint_arlen        ),
    .arsize_i    	        (clint_arsize       ),
    .arburst_i   	        (clint_arburst      ),
    .arvalid_i   	        (clint_arvalid      ),
    .arready_o  	        (clint_arready      ),
    .rid_o      	        (clint_rid          ),
    .rdata_o    	        (clint_rdata        ),
    .rresp_o    	        (clint_rresp        ),
    .rlast_o                (clint_rlast        ),
    .rvalid_o   	        (clint_rvalid       ),
    .rready_i    	        (clint_rready       ),
    .awid_i      	        (clint_awid         ),
    .awaddr_i    	        (clint_awaddr       ),
    .awlen_i     	        (clint_awlen        ),
    .awsize_i    	        (clint_awsize       ),
    .awburst_i   	        (clint_awburst      ),
    .awvalid_i   	        (clint_awvalid      ),
    .awready_o  	        (clint_awready      ),
    .wdata_i     	        (clint_wdata        ),
    .wstrb_i     	        (clint_wstrb        ),
    .wlast_i                (clint_wlast        ),
    .wvalid_i    	        (clint_wvalid       ),
    .wready_o   	        (clint_wready       ),
    .bid_o      	        (clint_bid          ),
    .bresp_o    	        (clint_bresp        ),
    .bvalid_o   	        (clint_bvalid       ),
    .bready_i    	        (clint_bready       )
);

endmodule
