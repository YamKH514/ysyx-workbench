module Comparison(
    input [1:0] Func, // A==B(01) A<B(10) A<=B(11)
    input Zero,
    input Overflow,
    input Sign,
    output CMPRes
);

assign CMPRes = (Func == 2'b01) & Zero |
                (Func == 2'b10) & (Sign ^ Overflow) |
                (Func == 2'b11) & (Zero + (Sign ^ Overflow));

endmodule
