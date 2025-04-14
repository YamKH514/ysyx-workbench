module Decode(
    input [31:0] inst,
    output [4:0] addr_s, addr_d,
    output [31:0] imm,
    output addi_en, ebreak_en
);

    wire [6:0]  opcode  = inst[6:0];
    wire [2:0]  funct3  = inst[14:12];
    assign addi_en = (opcode == 7'b0010011) && (funct3 == 3'b000);
    assign ebreak_en = (opcode == 7'b1110011) && (funct3 == 3'b000);
    assign {imm[11:0], addr_s, addr_d} = {inst[31:15], inst[11:7]};
    assign imm[31:12] = (inst[31] == 0) ? 0 : 20'hFFFFF;


endmodule
