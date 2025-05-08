module ALU(
    input [31:0] PC,
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
assign ALURes = AdderRes;

adder32 u_adder32(
            .mode       (0         ),
            .a          (Src1      ),
            .b          (Src2      ),
            .result     (AdderRes  ),
            .carry    	(carry     ),
            .overflow 	(overflow  ),
            .zero     	(zero      )
        );

endmodule
