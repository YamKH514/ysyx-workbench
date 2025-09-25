module adder32(
        input mode,
        input [31:0] a, b,
        output [31:0] result,
        output carry, overflow, zero
    );

    reg [31:0] b_complement, carry_out;
    wire [31:0] t_add_Cin;

    assign b_complement = mode ? (~b + 1) : b;

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
