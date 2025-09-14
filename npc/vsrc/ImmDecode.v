module ImmDecode(
    input [2:0] InstType, // I(0) S(1) B(2) U(3) J(4) R(5)
    input [31:7] Imm,
    output [31:0] ImmExt
);

assign ImmExt = 
            (InstType == 3'd0) ? {{20{Imm[31]}}, Imm[31:20]} :
            (InstType == 3'd1) ? {{20{Imm[31]}}, Imm[31:25], Imm[11:8], Imm[7]} :
            (InstType == 3'd2) ? {{18{Imm[31]}}, {3{Imm[7]}}, Imm[30:25], Imm[11:8], 1'b0} :
            (InstType == 3'd3) ? {Imm[31:12], 12'b0} :
            (InstType == 3'd4) ? {{11{Imm[31]}}, Imm[20:12], Imm[20], Imm[30:21], 1'b0} :
            32'b0;

endmodule
