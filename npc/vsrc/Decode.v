module Decode(
    input clk,
    input [31:0] inst,
    input [6:0] Opcode,
    input [2:0] Funct3,
    /* verilator lint_off UNUSED */
    input [6:0] Funct7,
    /* verilator lint_off UNUSED */
    output [2:0] ImmType, // I(0) S(1) B(2) U(3) J(4)
    output RegWriteEn,
    output [1:0] ALUSrcSel1, // 0(0) PC(1) ReadData1(2)
    output [1:0] ALUSrcSel2, // ReadData2(0) ImmExt(1) 4(2)
    output [1:0] NPCSrcSel // npc = pc+4(00) pc+imm(01) src1+imm(11)
);

wire inst_lui;      // U
wire inst_auipc;    // U
wire inst_jal;      // J
wire inst_jalr;     // I
wire inst_sw;       // S
wire inst_addi;     // I
wire inst_ebreak;

assign inst_lui   = (Opcode == 7'b0110111);
assign inst_auipc = (Opcode == 7'b0010111);
assign inst_jal   = (Opcode == 7'b1101111);
assign inst_jalr  = (Opcode == 7'b1100111) & (Funct3 == 3'b000);
assign inst_sw    = (Opcode == 7'b0100011) & (Funct3 == 3'b010);
assign inst_addi  = (Opcode == 7'b0010011) & (Funct3 == 3'b000);
assign inst_ebreak = inst == 32'b00000000000100000000000001110011;

import "DPI-C" function void ebreak_trigger();

always @(posedge clk) begin
    if(inst_ebreak) begin
        ebreak_trigger();
    end
end

assign ImmType =    {3{inst_jalr | inst_addi}} & 3'd0 |
                    {3{inst_sw}} & 3'd1 |
                    {3{1'b0}} & 3'd2 |
                    {3{inst_lui | inst_auipc}} & 3'd3 |
                    {3{inst_jal}} & 3'd4;

assign RegWriteEn = inst_lui | inst_auipc  | inst_jalr | inst_addi;

assign ALUSrcSel1 = {2{inst_lui}} & 2'd0 |
                    {2{inst_jal | inst_jalr}} & 2'd1 |
                    {2{inst_addi}} & 2'd2;

assign ALUSrcSel2 = {2{1'b0}} & 2'd0 |
                    {2{inst_lui | inst_auipc | inst_addi}} & 2'd1 |
                    {2{inst_jal | inst_jalr}} & 2'd2;

assign NPCSrcSel =  {2{inst_lui | inst_auipc | inst_sw | inst_addi}} & 2'b00 |
                    {2{inst_jal}} & 2'b01 |
                    {2{inst_jalr}} & 2'b11;

endmodule
