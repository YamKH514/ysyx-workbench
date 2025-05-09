module top(
    input clk, rst,
    // input [31:0] inst,
    output [31:0] pc,
    output [31:0] ReadData_a0
);

wire [31:0] inst;
wire RegWriteEn;
wire [2:0] ImmType;
wire [1:0] NPCSrcSel;
wire [1:0] ALUSrcSel1;
wire [1:0] ALUSrcSel2;
wire [31:0] ImmExt;
wire [31:0] ReadData1;
wire [31:0] ReadData2;
wire [31:0] ALURes;


PCCnt u_PCCnt(
    .clk       	(clk        ),
    .rst       	(rst        ),
    .ReadData1 	(ReadData1  ),
    .ImmExt    	(ImmExt     ),
    .NPCSrcSel 	(NPCSrcSel  ),
    .PC        	(pc         )
);

Inst u_Inst(
    .PC   	(pc    ),
    .inst 	(inst  )
);


Decode u_Decode(
    .clk            (clk         ),
    .inst       	(inst        ),
    .Opcode     	(inst[6:0]   ),
    .Funct3     	(inst[14:12] ),
    .Funct7     	(inst[31:25] ),
    .ImmType    	(ImmType     ),
    .RegWriteEn 	(RegWriteEn  ),
    .ALUSrcSel1 	(ALUSrcSel1  ),
    .ALUSrcSel2 	(ALUSrcSel2  ),
    .NPCSrcSel  	(NPCSrcSel   )
);


ImmDecode u_ImmDecode(
    .ImmType 	(ImmType        ),
    .Imm   	    (inst[31:7]     ),
    .ImmExt  	(ImmExt         )
);

ALU u_ALU(
    .PC         	(pc          ),
    .ReadData1  	(ReadData1   ),
    .ReadData2  	(ReadData2   ),
    .ImmExt     	(ImmExt      ),
    .ALUSrcSel1 	(ALUSrcSel1  ),
    .ALUSrcSel2 	(ALUSrcSel2  ),
    .ALURes     	(ALURes      )
);


GPR u_GPR(
    .clk         	(clk          ),
    .RegWrite    	(RegWriteEn   ),
    .ReadAddr1   	(inst[19:15]  ),
    .ReadAddr2   	(inst[24:20]  ),
    .WriteAddr   	(inst[11:7]   ),
    .WriteData   	(ALURes       ),
    .ReadData1   	(ReadData1    ),
    .ReadData2   	(ReadData2    ),
    .ReadData_a0 	(ReadData_a0  )
);

endmodule
