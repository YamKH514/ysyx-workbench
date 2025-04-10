module ADDI(
        input [4:0] addr_s, addr_d,
        input [31:0] imm, src1,
        output wen,
        output [4:0] addr_s_out, addr_d_out,
        output [31:0] res,
        output success
    );
    /* verilator lint_off UNUSED */
    wire carry, overflow, zero;
    /* verilator lint_off UNUSED */
    assign addr_s_out = addr_s;
    assign addr_d_out = addr_d;

    adder32 u_adder32(
                .mode (0),
                .a (src1),
                .b (imm),
                .result (res),
                .carry    	(carry     ),
                .overflow 	(overflow  ),
                .zero     	(zero      )
            );
    
    assign success = 1;
    assign wen = (addr_d != 0) && success;

endmodule
