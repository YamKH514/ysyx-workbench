module Decode(
    input [31:0] inst,
    output [4:0] addr_s, addr_d,
    output [31:0] imm
);

    /* verilator lint_off UNUSED */
    wire [6:0]  opcode  = inst[6:0];
    wire [2:0]  funct3  = inst[14:12];
    /* verilator lint_on UNUSED */
    assign {imm[11:0], addr_s, addr_d} = {inst[31:15], inst[11:7]};
    assign imm[31:12] = (inst[31] == 0) ? 0 : 20'hFFFFF;

endmodule
