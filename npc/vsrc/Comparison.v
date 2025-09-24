module Comparison(
    input [2:0] Func, // A==B(001) A<B signed(010) A<=B signed(011) A<B unsigned(110) A<=B unsigned(111)
    input Zero,
    input Overflow,
    input Carry,
    input Sign,
    output CMPRes
);

assign CMPRes = (Func == 3'b001) & Zero |
                (Func == 3'b010) & (Sign ^ Overflow) |
                (Func == 3'b011) & (Zero | (Sign ^ Overflow)) |
                (Func == 3'b110) & (~Carry) |
                (Func == 3'b111) & (Zero | ~Carry);

endmodule
