module ADD(
        input [31:0] imm,
        input [31:0] src,
        output [31:0] res
    );
    /* verilator lint_off UNUSED */
    wire carry, overflow, zero;
    /* verilator lint_off UNUSED */

    adder32 u_adder32(
                .mode       (0         ),
                .a          (src       ),
                .b          (imm       ),
                .result     (res       ),
                .carry    	(carry     ),
                .overflow 	(overflow  ),
                .zero     	(zero      )
            );

endmodule
