module top(
    input           clk,
    input           rst,
    output  [31:0]  pc,
    output  [31:0]  npc,
    output  [31:0]  ReadData_a0
);

wire            RegWriteEn;
wire    [2:0]   InstType;
wire    [3:0]   NPCSrcSel;
wire    [31:0]  TrapNPC;
wire    [1:0]   ALUSrcSel1;
wire    [1:0]   ALUSrcSel2;
wire    [31:0]  ImmExt;
wire    [31:0]  ReadData1;
wire    [31:0]  ReadData2;
wire    [31:0]  ALURes;
wire    [5:0]   ALUFunc;
wire    [31:0]  GPRwdata;
wire    [1:0]   GPRwdataSel;
wire    [31:0]  ReadData_a5;
wire            CSRWriteEn;
wire    [11:0]  CSRRWAddr;
wire    [31:0]  CSRWriteData;
wire    [31:0]  CSRWriteData_mepc;
wire    [31:0]  CSRWriteData_mcause;
wire    [31:0]  CSRReadData;
wire    [31:0]  CSRReadData_mtvec;
wire    [31:0]  CSRReadData_mepc;

wire            pc_cnt_valid;
wire            pc_cnt_ready;
wire            [31:0] ifu_req_addr;
wire            [31:0] ifu_req_inst;
reg             [31:0] ifu_inst_out;
wire            inst_sram_valid;
wire            inst_sram_ready;
wire            idu_valid;
wire            idu_ready;
wire            is_ecall;
wire            is_mret;
wire            exu_valid;
wire            exu_ready;
wire            mem_re;
wire    [31:0]  mem_r_addr;
wire    [31:0]  mem_r_data;
wire    [2:0]   mem_r_func;
wire            mem_we;
wire    [31:0]  mem_w_addr;
wire    [31:0]  mem_w_data;
wire    [7:0]   mem_w_mask;
wire            wbu_valid;
wire            wbu_ready;

assign TrapNPC = is_ecall ? CSRReadData_mtvec : CSRReadData_mepc;

PCCnt u_PCCnt(
    .pc_cnt_clk_in         	(clk            ),
    .pc_cnt_rst_in         	(rst            ),
    .pc_cnt_cmp_res_in     	(ALURes[0]      ),
    .pc_cnt_rd1_in         	(ReadData1      ),
    .pc_cnt_imm_in         	(ImmExt         ),
    .pc_cnt_npc_src_sel_in 	(NPCSrcSel      ),
    .pc_cnt_trap_npc_in    	(TrapNPC        ),
    .pc_cnt_pc_out         	(pc             ),
    .pc_cnt_npc_out        	(npc            ),
    .pc_cnt_valid_in        (pc_cnt_valid   ),
    .pc_cnt_ready_out       (pc_cnt_ready   )
);

IFU u_IFU(
    .ifu_rst_in         	(rst            ),
    .ifu_clk_in         	(clk            ),
    .ifu_current_pc_in  	(pc             ),
    .ifu_req_addr_out   	(ifu_req_addr   ),
    .ifu_req_inst_in    	(ifu_req_inst   ),
    .ifu_inst_out       	(ifu_inst_out   ),
    .inst_sram_valid_out    (inst_sram_valid),
    .inst_sram_ready_in     (inst_sram_ready),
    .idu_valid_out  	    (idu_valid      ),
    .idu_ready_in   	    (idu_ready      ),
    .pc_cnt_ready_in        (pc_cnt_ready   )
);

InstSRAM u_InstSRAM(
    .inst_sram_clk_in    	(clk            ),
    .inst_sram_addr_in   	(ifu_req_addr   ),
    .inst_sram_data_out  	(ifu_req_inst   ),
    .inst_sram_valid_in  	(inst_sram_valid),
    .inst_sram_ready_out 	(inst_sram_ready)
);

IDU u_IDU(
    .idu_clk_in            	(clk            ),
    .idu_rst_in             (rst            ),
    .idu_inst_in           	(ifu_inst_out   ),
    .idu_is_ecall          	(is_ecall       ),
    .idu_is_mret           	(is_mret        ),
    .idu_inst_type         	(InstType       ),
    .idu_reg_we_out        	(RegWriteEn     ),
    .idu_csr_we_out        	(CSRWriteEn     ),
    .idu_alu_fun_out       	(ALUFunc        ),
    .idu_alu_src1_sel_out  	(ALUSrcSel1     ),
    .idu_alu_src2_sel_out  	(ALUSrcSel2     ),
    .idu_npc_src_sel_out   	(NPCSrcSel      ),
    .idu_gpr_wd_sel_out    	(GPRwdataSel    ),
    .idu_mem_wmask_out     	(mem_w_mask     ),
    .idu_wbu_valid_out     	(wbu_valid      ),
    .idu_mem_re_out         (mem_re         ),
    .idu_mem_we_out        	(mem_we         ),
    .idu_mem_read_func_out 	(mem_r_func     ),
    .idu_valid_in          	(idu_valid      ),
    .idu_ready_out         	(idu_ready      ),
    .exu_ready_in           (exu_ready      ),
    .exu_valid_out          (exu_valid      )
);

ImmExt u_ImmExt(
    .imm_ext_inst_type_in 	(InstType           ),
    .imm_ext_imm_in       	(ifu_inst_out[31:7] ),
    .imm_ext_imm_out      	(ImmExt             )
);

assign GPRwdata = (GPRwdataSel[1] == 1'b0) ? ((GPRwdataSel[0] == 1'b0) ? ALURes : mem_r_data) : CSRReadData;

GPR u_GPR(
    .clk         	(clk                    ),
    .RegWrite    	(RegWriteEn             ),
    .ReadAddr1   	(ifu_inst_out[19:15]    ),
    .ReadAddr2   	(ifu_inst_out[24:20]    ),
    .WriteAddr   	(ifu_inst_out[11:7]     ),
    .WriteData   	(GPRwdata               ),
    .ReadData1   	(ReadData1              ),
    .ReadData2   	(ReadData2              ),
    .ReadData_a0 	(ReadData_a0            ),
    .ReadData_a5    (ReadData_a5            )
);

EXU u_EXU(
    .exu_clk_in          	(clk            ),
    .exu_rst_in          	(rst            ),
    .exu_pc_in           	(pc             ),
    .exu_alu_fun_in      	(ALUFunc        ),
    .exu_rd1_in          	(ReadData1      ),
    .exu_rd2_in          	(ReadData2      ),
    .exu_imm_in          	(ImmExt         ),
    .exu_alu_src1_sel_in 	(ALUSrcSel1     ),
    .exu_alu_src2_sel_in 	(ALUSrcSel2     ),
    .exu_res_out         	(ALURes         ),
    .exu_valid_in        	(exu_valid      ),
    .exu_ready_out       	(exu_ready      ),
    .wbu_ready_in        	(wbu_ready      ),
    .wbu_valid_out       	(wbu_valid      ),
    .pc_cnt_valid_out    	(pc_cnt_valid   )
);

assign mem_r_addr = ALURes;
assign mem_w_addr = ALURes;
assign mem_w_data = ReadData2;

Memory u_Memory(
    .mem_clk_in        	(clk            ),
    .mem_rst_in        	(rst            ),
    .mem_re_in         	(mem_re         ),
    .mem_r_addr_in  	(mem_r_addr     ),
    .mem_r_data_out 	(mem_r_data     ),
    .mem_r_func_in  	(mem_r_func     ),
    .mem_we_in         	(mem_we         ),
    .mem_w_addr_in 	    (mem_w_addr     ),
    .mem_w_data_in 	    (mem_w_data     ),
    .mem_w_mask_in 	    (mem_w_mask     ),
    .mem_valid_in      	(wbu_valid      ),
    .mem_ready_out     	(wbu_ready      )
);

assign CSRWriteData = ReadData1;
assign CSRWriteData_mcause = ReadData_a5;
assign CSRWriteData_mepc = pc;
assign CSRRWAddr = ifu_inst_out[31:20];

CSR u_CSR(
    .clk                 	(clk                  ),
    .rst                 	(rst                  ),
    .is_ecall            	(is_ecall             ),
    .is_mret                (is_mret              ),
    .CSRFunc3               (ifu_inst_out[14:12]  ),
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
