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
wire    [31:0]  Memraddr;
wire    [31:0]  Memwaddr;
wire    [31:0]  Memwdata;
wire    [7:0]   Memwmask;
wire            MemValid;
wire            MemWrite;
wire    [2:0]   MemReadFunc;
wire    [31:0]  Memrdata;
wire    [31:0]  GPRwdata;
wire    [1:0]   GPRwdataSel;
wire    [31:0]  ReadData_a5;
wire            is_ecall;
wire            is_mret;
wire            CSRWriteEn;
wire    [11:0]  CSRRWAddr;
wire    [31:0]  CSRWriteData;
wire    [31:0]  CSRWriteData_mepc;
wire    [31:0]  CSRWriteData_mcause;
wire    [31:0]  CSRReadData;
wire    [31:0]  CSRReadData_mtvec;
wire    [31:0]  CSRReadData_mepc;

wire [31:0] ifu_req_addr;
wire [31:0] ifu_req_inst;
wire [31:0] ifu_inst_out;
wire ifu_sram_valid;
wire ifu_sram_ready;
wire ifu_idu_valid;
wire ifu_idu_ready;

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
    .idu_valid_in          	(ifu_idu_valid  ),
    .idu_ready_in          	(ifu_idu_ready  )
);

IFU u_IFU(
    .ifu_rst_in         	(rst            ),
    .ifu_clk_in         	(clk            ),
    .ifu_current_pc_in  	(pc             ),
    .ifu_req_addr_out   	(ifu_req_addr   ),
    .ifu_req_inst_in    	(ifu_req_inst   ),
    .ifu_inst_out       	(ifu_inst_out   ),
    .ifu_sram_valid_out 	(ifu_sram_valid ),
    .ifu_sram_ready_in  	(ifu_sram_ready ),
    .ifu_idu_valid_out  	(ifu_idu_valid  ),
    .ifu_idu_ready_in   	(ifu_idu_ready  )
);

InstSRAM u_InstSRAM(
    .inst_sram_clk_in    	(clk            ),
    .inst_sram_addr_in   	(ifu_req_addr   ),
    .inst_sram_data_out  	(ifu_req_inst   ),
    .inst_sram_valid_in  	(ifu_sram_valid ),
    .inst_sram_ready_out 	(ifu_sram_ready )
);

IDU u_IDU(
    .idu_clk_in            	(clk            ),
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
    .idu_mem_wmask_out     	(Memwmask       ),
    .idu_mem_valid_out     	(MemValid       ),
    .idu_mem_we_out        	(MemWrite       ),
    .idu_mem_read_func_out 	(MemReadFunc    ),
    .idu_valid_in          	(ifu_idu_valid  ),
    .idu_ready_out         	(ifu_idu_ready  )
);

assign Memraddr = ALURes;
assign Memwaddr = ALURes;
assign Memwdata = ReadData2;

Memory u_Memory(
    .raddr    	(Memraddr     ),
    .waddr    	(Memwaddr     ),
    .wdata    	(Memwdata     ),
    .wmask    	(Memwmask     ),
    .MemValid   (MemValid     ),
    .MemWrite 	(MemWrite     ),
    .MemReadFunc(MemReadFunc  ),
    .rdata    	(Memrdata     )
);

ImmExt u_ImmExt(
    .imm_ext_inst_type_in 	(InstType           ),
    .imm_ext_imm_in       	(ifu_inst_out[31:7] ),
    .imm_ext_imm_out      	(ImmExt             )
);

ALU u_ALU(
    .PC         	(pc          ),
    .ALUFunc        (ALUFunc     ),
    .ReadData1  	(ReadData1   ),
    .ReadData2  	(ReadData2   ),
    .ImmExt     	(ImmExt      ),
    .ALUSrcSel1 	(ALUSrcSel1  ),
    .ALUSrcSel2 	(ALUSrcSel2  ),
    .ALURes     	(ALURes      )
);

assign GPRwdata = (GPRwdataSel[1] == 1'b0) ? ((GPRwdataSel[0] == 1'b0) ? ALURes : Memrdata) : CSRReadData;

GPR u_GPR(
    .clk         	(clk                ),
    .RegWrite    	(RegWriteEn         ),
    .ReadAddr1   	(ifu_inst_out[19:15]),
    .ReadAddr2   	(ifu_inst_out[24:20]),
    .WriteAddr   	(ifu_inst_out[11:7] ),
    .WriteData   	(GPRwdata           ),
    .ReadData1   	(ReadData1          ),
    .ReadData2   	(ReadData2          ),
    .ReadData_a0 	(ReadData_a0        ),
    .ReadData_a5    (ReadData_a5        )
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
