module Bool (
        input   [31:0]  Src1,
        input   [31:0]  Src2,
        input   [3:0]   BoolFunc, // AND(1000) OR(1110) XOR(0110)
        output  [31:0]  BoolRes
    );

assign BoolRes =    {32{(BoolFunc == 4'b1000)}} & (Src1 & Src2) |
                    {32{(BoolFunc == 4'b1110)}} & (Src1 | Src2) |
                    {32{(BoolFunc == 4'b0110)}} & (Src1 ^ Src2) ;

endmodule
