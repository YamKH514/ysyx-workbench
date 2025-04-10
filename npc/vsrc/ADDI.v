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

module adder32(
        input mode,
        input [31:0] a, b,
        output [31:0] result,
        output carry, overflow, zero
    );

    reg [31:0] b_complement, carry_out;
    wire [31:0] t_add_Cin;

    assign b_complement = b ^ {32{mode}};

    adder1 u_adder0(
               .Cin  	(mode   ),
               .a    	(a[0]     ),
               .b    	(b_complement[0]     ),
               .Cout 	(carry_out[0]  ),
               .sum  	(result[0]   )
           );

    genvar i;
    generate
        for(i = 1; i < 32; i = i + 1) begin: gen_add
            adder1 u_adder1(
                       .Cin  	(carry_out[i - 1]   ),
                       .a    	(a[i]     ),
                       .b    	(b_complement[i]     ),
                       .Cout 	(carry_out[i]  ),
                       .sum  	(result[i]   )
                   );
        end
    endgenerate

    assign t_add_Cin = b_complement + {31'b0, mode};
    assign carry = carry_out[31];
    assign overflow = (a[31] == t_add_Cin[31]) && (result[31] != a[31]);
    assign zero = ~(| result);

    wire _unused_ok = &{
             1'b0,
             t_add_Cin,
             1'b0
         };

endmodule

module adder1(
        input Cin, a, b,
        output Cout, sum
    );

    assign sum = a + b + Cin;
    assign Cout = (a & b) | (a & Cin) | (b & Cin);

endmodule
