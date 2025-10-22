module top(
    input           clk,
    input           rst,
    output  [31:0]  pc,
    output  [31:0]  npc,
    output  [31:0]  ReadData_a0
);

wire    [31:0]  inst;
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

assign TrapNPC = is_ecall ? CSRReadData_mtvec : CSRReadData_mepc;

PCCnt u_PCCnt(
    .clk       	(clk        ),
    .rst       	(rst        ),
    .CMPRes     (ALURes[0]  ),
    .ReadData1 	(ReadData1  ),
    .ImmExt    	(ImmExt     ),
    .NPCSrcSel 	(NPCSrcSel  ),
    .TrapNPC    (TrapNPC    ),
    .PC        	(pc         ),
    .NPC        (npc        )
);

Inst u_Inst(
    .PC   	(pc    ),
    .inst 	(inst  )
);

assign Memraddr = ALURes;
assign Memwaddr = ALURes;
assign Memwdata = ReadData2;

Memory u_Memory(
    .clk        (clk          ),
    .npc        (npc          ),
    .raddr    	(Memraddr     ),
    .waddr    	(Memwaddr     ),
    .wdata    	(Memwdata     ),
    .wmask    	(Memwmask     ),
    .MemValid   (MemValid     ),
    .MemWrite 	(MemWrite     ),
    .MemReadFunc(MemReadFunc  ),
    .rdata    	(Memrdata     )
);


Decode u_Decode(
    .clk            (clk         ),
    .inst       	(inst        ),
    .Opcode     	(inst[6:0]   ),
    .Funct3     	(inst[14:12] ),
    .Funct7     	(inst[31:25] ),
    .is_ecall       (is_ecall    ),
    .is_mret        (is_mret     ),
    .InstType    	(InstType    ),
    .RegWriteEn 	(RegWriteEn  ),
    .CSRWriteEn     (CSRWriteEn  ),
    .ALUFunc        (ALUFunc     ),
    .ALUSrcSel1 	(ALUSrcSel1  ),
    .ALUSrcSel2 	(ALUSrcSel2  ),
    .NPCSrcSel  	(NPCSrcSel   ),
    .GPRwdataSel    (GPRwdataSel ),
    .Memwmask       (Memwmask    ),
    .MemValid       (MemValid    ),
    .MemWrite       (MemWrite    ),
    .MemReadFunc    (MemReadFunc )
);


ImmDecode u_ImmDecode(
    .InstType 	(InstType       ),
    .Imm   	    (inst[31:7]     ),
    .ImmExt  	(ImmExt         )
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
    .clk         	(clk          ),
    .RegWrite    	(RegWriteEn   ),
    .ReadAddr1   	(inst[19:15]  ),
    .ReadAddr2   	(inst[24:20]  ),
    .WriteAddr   	(inst[11:7]   ),
    .WriteData   	(GPRwdata     ),
    .ReadData1   	(ReadData1    ),
    .ReadData2   	(ReadData2    ),
    .ReadData_a0 	(ReadData_a0  ),
    .ReadData_a5    (ReadData_a5  )
);

assign CSRWriteData = ReadData1;
assign CSRWriteData_mcause = ReadData_a5;
assign CSRWriteData_mepc = pc;
assign CSRRWAddr = inst[31:20];

CSR u_CSR(
    .clk                 	(clk                  ),
    .rst                 	(rst                  ),
    .is_ecall            	(is_ecall             ),
    .is_mret                (is_mret              ),
    .CSRFunc3               (inst[14:12]          ),
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
