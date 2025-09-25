module ALU(
    input [31:0] PC,
    input [5:0] ALUFunc, // add(00---0) sub(00---1) A==B(010011) A<B signed(010101) A<=B signed(010111) A<B unsigned(011101) A<=B unsigned(011111) AND(101000) OR(101110) XOR(100110) SLL(11--00) SRL(11--01) SRA(11--11)
    input [31:0] ReadData1,
    input [31:0] ReadData2,
    input [31:0] ImmExt,
    input [1:0] ALUSrcSel1,
    input [1:0] ALUSrcSel2,
    output [31:0] ALURes
);
/* verilator lint_off UNUSED */
wire carry, overflow, zero;
/* verilator lint_off UNUSED */

wire [31:0] Src1 =  ({32{ALUSrcSel1 == 2'd0}} & 32'b0    ) |
                    ({32{ALUSrcSel1 == 2'd1}} & PC       ) |
                    ({32{ALUSrcSel1 == 2'd2}} & ReadData1) ;
wire [31:0] Src2 =  ({32{ALUSrcSel2 == 2'd0}} & ReadData2) |
                    ({32{ALUSrcSel2 == 2'd1}} & ImmExt   ) |
                    ({32{ALUSrcSel2 == 2'd2}} & 32'd4    ) ;
wire [31:0] AdderRes;
wire CMPRes;
wire [31:0] ShifterRes;
wire [31:0] BoolRes;

Adder u_Adder(
            .mode       (ALUFunc[0]),
            .a          (Src1      ),
            .b          (Src2      ),
            .result     (AdderRes  ),
            .carry    	(carry     ),
            .overflow 	(overflow  ),
            .zero     	(zero      )
        );

Comparison u_Comparison(
    .Func     	(ALUFunc[3:1]   ),
    .Zero     	(zero           ),
    .Overflow 	(overflow       ),
    .Carry      (carry          ),
    .Sign     	(AdderRes[31]   ),
    .CMPRes   	(CMPRes         )
);

Shifter u_Shifter(
    .Src         	(Src1          ),
    .Shamt       	(Src2[4:0]     ),
    .ShifterFunc 	(ALUFunc[1:0]  ),
    .ShifterRes  	(ShifterRes    )
);

Bool u_Bool(
    .Src1     	(Src1           ),
    .Src2     	(Src2           ),
    .BoolFunc 	(ALUFunc[3:0]   ),
    .BoolRes  	(BoolRes        )
);

assign ALURes = ({32{ALUFunc[5:4] == 2'b00}} & AdderRes) |
                ({32{ALUFunc[5:4] == 2'b01}} & {31'b0, CMPRes}) |
                ({32{ALUFunc[5:4] == 2'b10}} & BoolRes) |
                ({32{ALUFunc[5:4] == 2'b11}} & ShifterRes);

endmodule
