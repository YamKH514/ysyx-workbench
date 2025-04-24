module ImmDecode(
    input [2:0] imm_type, // I(000) S(001) B(010) U(011) J(100)
    input [31:7] imm_in,
    output [31:0] imm_out
);

    assign imm_out = 
                (imm_type == 3'b000) ? {{21{imm_in[31]}}, imm_in[30:20]} :
                (imm_type == 3'b001) ? {{21{imm_in[31]}}, imm_in[30:25], imm_in[11:8], imm_in[7]} :
                (imm_type == 3'b010) ? {{18{imm_in[31]}}, {3{imm_in[7]}}, imm_in[30:25], imm_in[11:8], 1'b0} :
                (imm_type == 3'b011) ? {imm_in[31:12], 12'b0} :
                (imm_type == 3'b100) ? {{12{imm_in[31]}}, imm_in[19:12], imm_in[20], imm_in[30:21], 1'b0} :
                32'b0;

endmodule
