module Decode(
    input clk,
    input [31:0] inst,
    input [6:0] Opcode,
    input [2:0] Funct3,
    input [6:0] Funct7,
    output [2:0] InstType, // I(0) S(1) B(2) U(3) J(4) R(5)
    output RegWriteEn,
    output [5:0] ALUFunc, // add(00---0) sub(00---1) A==B(01-011) A<B(01-101) A<=B(01-111) AND(101000) OR(101110) XOR(100110) SLL(11--00) SRL(11--01) SRA(11--11)
    output [1:0] ALUSrcSel1, // 0(0) PC(1) ReadData1(2)
    output [1:0] ALUSrcSel2, // ReadData2(0) ImmExt(1) 4(2)
    output [3:0] NPCSrcSel, // npc = pc+4(0-00) pc+imm(0-01) src1+imm(0-11) res=0,jump(10--) res=1,jump(11--)
    output GPRwdataSel, // ALURes(0) Memrdata(1)
    output [7:0] Memwmask,
    output MemValid,
    output MemWrite,
    output [2:0] MemReadFunc // unsigned(0--) signed(1--) lb(-01) lh(-10) lw(011)
);

wire inst_lui;      // U
wire inst_auipc;    // U
wire inst_jal;      // J
wire inst_jalr;     // I
wire inst_beq;      // B
wire inst_bne;      // B
wire inst_lw;       // I
wire inst_lbu;      // I
wire inst_sb;       // S
wire inst_sh;       // S
wire inst_sw;       // S
wire inst_addi;     // I
wire inst_sltiu;    // I
wire inst_xori;     // I
wire inst_andi;     // I
wire inst_slli;     // I
wire inst_srai;     // I
wire inst_add;      // R
wire inst_sub;      // R
wire inst_sll;      // R
wire inst_sltu;     // R
wire inst_xor;      // R
wire inst_or;       // R
wire inst_and;      // R
wire inst_ebreak;

assign inst_lui   = (Opcode == 7'b0110111);
assign inst_auipc = (Opcode == 7'b0010111);
assign inst_jal   = (Opcode == 7'b1101111);
assign inst_jalr  = (Opcode == 7'b1100111) & (Funct3 == 3'b000);
assign inst_beq   = (Opcode == 7'b1100011) & (Funct3 == 3'b000);
assign inst_bne   = (Opcode == 7'b1100011) & (Funct3 == 3'b001);
assign inst_lw    = (Opcode == 7'b0000011) & (Funct3 == 3'b010);
assign inst_lbu   = (Opcode == 7'b0000011) & (Funct3 == 3'b100);
assign inst_sb    = (Opcode == 7'b0100011) & (Funct3 == 3'b000);
assign inst_sh    = (Opcode == 7'b0100011) & (Funct3 == 3'b001);
assign inst_sw    = (Opcode == 7'b0100011) & (Funct3 == 3'b010);
assign inst_addi  = (Opcode == 7'b0010011) & (Funct3 == 3'b000);
assign inst_sltiu = (Opcode == 7'b0010011) & (Funct3 == 3'b011);
assign inst_xori  = (Opcode == 7'b0010011) & (Funct3 == 3'b100);
assign inst_andi  = (Opcode == 7'b0010011) & (Funct3 == 3'b111);
assign inst_slli  = (Opcode == 7'b0010011) & (Funct3 == 3'b001) & (Funct7 == 7'b0000000);
assign inst_srai  = (Opcode == 7'b0010011) & (Funct3 == 3'b101) & (Funct7 == 7'b0100000);
assign inst_add   = (Opcode == 7'b0110011) & (Funct3 == 3'b000) & (Funct7 == 7'b0000000);
assign inst_sub   = (Opcode == 7'b0110011) & (Funct3 == 3'b000) & (Funct7 == 7'b0100000);
assign inst_sll   = (Opcode == 7'b0110011) & (Funct3 == 3'b001) & (Funct7 == 7'b0000000);
assign inst_sltu  = (Opcode == 7'b0110011) & (Funct3 == 3'b011) & (Funct7 == 7'b0000000);
assign inst_xor   = (Opcode == 7'b0110011) & (Funct3 == 3'b100) & (Funct7 == 7'b0000000);
assign inst_or    = (Opcode == 7'b0110011) & (Funct3 == 3'b110) & (Funct7 == 7'b0000000);
assign inst_and   = (Opcode == 7'b0110011) & (Funct3 == 3'b111) & (Funct7 == 7'b0000000);
assign inst_ebreak = inst == 32'b00000000000100000000000001110011;

import "DPI-C" function void ebreak_trigger();

always @(posedge clk) begin
    if(inst_ebreak) begin
        ebreak_trigger();
    end
end

assign InstType =   {3{inst_jalr | inst_lw | inst_lbu | inst_addi | inst_sltiu | inst_xori | inst_andi | inst_slli | inst_srai}} & 3'd0 | // I
                    {3{inst_sb | inst_sh | inst_sw}} & 3'd1 | // S
                    {3{inst_beq | inst_bne}} & 3'd2 | // B
                    {3{inst_lui | inst_auipc}} & 3'd3 | // U
                    {3{inst_jal}} & 3'd4 | // J
                    {3{inst_add | inst_sub | inst_sll | inst_sltu | inst_xor | inst_or | inst_and}} & 3'd5; // R

assign RegWriteEn = inst_lui | inst_auipc | inst_jal | inst_jalr | inst_lw | inst_lbu | inst_addi | inst_sltiu | inst_xori | inst_andi | inst_slli | inst_srai | inst_add | inst_sub | inst_sll | inst_sltu | inst_xor | inst_or | inst_and;

assign ALUFunc =    {6{inst_sub}} & 6'b000001 | // sub
                    {6{inst_beq | inst_bne}} & 6'b010011 | // A==B
                    {6{1'b0}} & 6'b010101 | // A<B signed
                    {6{1'b0}} & 6'b010111 | // A<=B signed
                    {6{inst_sltiu | inst_sltu}} & 6'b011101 | // A<B unsigned
                    {6{1'b0}} & 6'b011111 | // A<=B unsigned
                    {6{inst_andi | inst_and}} & 6'b101000 | // AND
                    {6{inst_or}} & 6'b101110 | // OR
                    {6{inst_xori | inst_xor}} & 6'b100110 | // XOR
                    {6{inst_slli | inst_sll}} & 6'b110000 | // SLL
                    {6{1'b0}} & 6'b110001 | // SRL
                    {6{inst_srai}} & 6'b110011 | // SRA
                    6'b000000; // add

assign ALUSrcSel1 = {2{inst_lui}} & 2'd0 | // 0
                    {2{inst_jal | inst_jalr | inst_auipc}} & 2'd1 | // PC
                    {2{inst_beq | inst_bne | inst_lw | inst_lbu | inst_sb | inst_sh | inst_sw | inst_addi | inst_sltiu | inst_xori | inst_andi| inst_slli | inst_srai | inst_add | inst_sub | inst_sll | inst_sltu | inst_xor | inst_or | inst_and}} & 2'd2; // ReadData1

assign ALUSrcSel2 = {2{inst_beq | inst_bne | inst_add | inst_sub | inst_sll | inst_sltu | inst_xor | inst_or | inst_and}} & 2'd0 | // ReadData2
                    {2{inst_lui | inst_auipc | inst_lw | inst_lbu | inst_sb | inst_sh | inst_sw | inst_addi | inst_sltiu | inst_xori | inst_andi | inst_slli | inst_srai}} & 2'd1 | // ImmExt
                    {2{inst_jal | inst_jalr}} & 2'd2; // 4

assign NPCSrcSel =  
                    {4{inst_jal}} & 4'b0001 | // pc+imm
                    {4{inst_jalr}} & 4'b0011 | // src1+imm
                    {4{inst_bne}} & 4'b1000 | // res=0,jump
                    {4{inst_beq}} & 4'b1100 | // res=1,jump
                    4'b0000; // pc+4

assign GPRwdataSel =    (inst_lw | inst_lbu) & 1'b1 | // Memrdata
                        1'b0; // ALURes

assign Memwmask =   {8{inst_lw | inst_sw}} & 8'd4 |
                    {8{inst_sh}} & 8'd2 |
                    {8{inst_lbu | inst_sb}} & 8'd1 |
                    8'd0;

assign MemValid =   (inst_lw | inst_lbu | inst_sb | inst_sh | inst_sw) & 1'b1 |
                    1'b0;

assign MemWrite =   (inst_sb | inst_sh | inst_sw) & 1'b1 |
                    1'b0;
// unsigned(0--) signed(1--) lb(-01) lh(-10) lw(011)
assign MemReadFunc =    {3{inst_lbu}} & 3'b001 |
                        {3{inst_lw}} & 3'b011;

endmodule
