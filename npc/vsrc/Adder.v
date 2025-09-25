module Adder(
        input mode,
        input [31:0] a, b,
        output [31:0] result,
        output carry, overflow, zero
    );

wire [31:0] t_no_Cin = {32{ mode }} ^ b;
assign {carry, result} = a + t_no_Cin + {31'b0, mode};
assign overflow = (a[31] == t_no_Cin[31]) && (result[31] != a[31]);
assign zero = ~(| result);

endmodule
