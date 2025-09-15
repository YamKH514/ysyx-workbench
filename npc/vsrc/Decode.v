module Decode(
    input clk,
    input [31:0] inst,
    input [6:0] Opcode,
    input [2:0] Funct3,
    input [6:0] Funct7,
    output [2:0] InstType, // I(0) S(1) B(2) U(3) J(4) R(5)
    output RegWriteEn,
    output [5:0] ALUFunc, // add(00---0) sub(00---1) A==B(01-011) A<B(01-101) A<=B(01-111)
    output [1:0] ALUSrcSel1, // 0(0) PC(1) ReadData1(2)
    output [1:0] ALUSrcSel2, // ReadData2(0) ImmExt(1) 4(2)
    output [3:0] NPCSrcSel, // npc = pc+4(0-00) pc+imm(0-01) src1+imm(0-11) res=0,jump(100-) res=1,jump(110-)
    output GPRwdataSel, // ALURes(0) Memrdata(1)
    output [7:0] Memwmask,
    output MemValid,
    output MemWrite
);

wire inst_lui;      // U
wire inst_auipc;    // U
wire inst_jal;      // J
wire inst_jalr;     // I
wire inst_beq;      // B
wire inst_bne;      // B
wire inst_lw;       // I
wire inst_sw;       // S
wire inst_addi;     // I
wire inst_add;      // R
wire inst_sub;      // R
wire inst_ebreak;

assign inst_lui   = (Opcode == 7'b0110111);
assign inst_auipc = (Opcode == 7'b0010111);
assign inst_jal   = (Opcode == 7'b1101111);
assign inst_jalr  = (Opcode == 7'b1100111) & (Funct3 == 3'b000);
assign inst_beq   = (Opcode == 7'b1100011) & (Funct3 == 3'b000);
assign inst_bne   = (Opcode == 7'b1100011) & (Funct3 == 3'b001);
assign inst_lw    = (Opcode == 7'b0000011) & (Funct3 == 3'b010);
assign inst_sw    = (Opcode == 7'b0100011) & (Funct3 == 3'b010);
assign inst_addi  = (Opcode == 7'b0010011) & (Funct3 == 3'b000);
assign inst_add   = (Opcode == 7'b0110011) & (Funct3 == 3'b000) & (Funct7 == 7'b0000000);
assign inst_sub   = (Opcode == 7'b0110011) & (Funct3 == 3'b000) & (Funct7 == 7'b0100000);
assign inst_ebreak = inst == 32'b00000000000100000000000001110011;

import "DPI-C" function void ebreak_trigger();

always @(posedge clk) begin
    if(inst_ebreak) begin
        ebreak_trigger();
    end
end

// I(0) S(1) B(2) U(3) J(4) R(5)
assign InstType =   {3{inst_jalr | inst_lw | inst_addi}} & 3'd0 |
                    {3{inst_sw}} & 3'd1 |
                    {3{inst_beq | inst_bne}} & 3'd2 |
                    {3{inst_lui | inst_auipc}} & 3'd3 |
                    {3{inst_jal}} & 3'd4 |
                    {3{inst_add | inst_sub}} & 3'd5;

assign RegWriteEn = inst_lui | inst_auipc | inst_jal | inst_jalr | inst_lw | inst_addi | inst_add | inst_sub;

// add(00---0) sub(00---1) A==B(01-011) A<B(01-101) A<=B(01-111)
assign ALUFunc =    {6{inst_sub}} & 6'b000001 |
                    {6{inst_beq | inst_bne}} & 6'b010011 |
                    {6{1'b0}} & 6'b010101 |
                    {6{1'b0}} & 6'b010111 |
                    6'b0;

assign ALUSrcSel1 = {2{inst_lui}} & 2'd0 |
                    {2{inst_jal | inst_jalr | inst_auipc}} & 2'd1 |
                    {2{inst_beq | inst_bne | inst_lw | inst_addi | inst_add | inst_sub}} & 2'd2;

assign ALUSrcSel2 = {2{inst_beq | inst_bne | inst_add | inst_sub}} & 2'd0 |
                    {2{inst_lui | inst_auipc | inst_lw | inst_addi}} & 2'd1 |
                    {2{inst_jal | inst_jalr}} & 2'd2;

// npc = pc+4(0-00) pc+imm(0-01) src1+imm(0-11) res=0,jump(100-) res=1,jump(110-)
assign NPCSrcSel =  {4{inst_lui | inst_auipc | inst_lw | inst_sw | inst_addi | inst_add | inst_sub}} & 4'b0000 |
                    {4{inst_jal}} & 4'b0001 |
                    {4{inst_jalr}} & 4'b0011 |
                    {4{inst_bne}} & 4'b1000 |
                    {4{inst_beq}} & 4'b1100 |
                    4'b0000;

assign GPRwdataSel =    (inst_lw) & 1'b1 |
                        1'b0;

assign Memwmask =   {8{inst_sw}} & 8'd4 |
                    {8{1'b0}} & 8'd2 |
                    {8{1'b0}} & 8'd1 |
                    8'd0;

assign MemValid =  (inst_lw | inst_sw) & 1'b1 |
                1'b0;

assign MemWrite =   (inst_sw) & 1'b1 |
                    1'b0;

endmodule
