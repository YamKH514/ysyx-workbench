module Decode(
    input [6:0] opcode,
    input [2:0] funct3,
    /* verilator lint_off UNUSED */
    input [6:0] funct7,
    /* verilator lint_off UNUSED */
    output [2:0] imm_type, // I(000) S(001) B(010) U(011) J(100)
    output wen,
    output [1:0] src1_sel, // 0(00) PC(01) src1(10)
    output [1:0] pc_sel // npc = pc+4(00) pc+imm(01) src1+imm(11)
);
    import "DPI-C" function void ebreak_trigger();
    always @(*) begin
        if((opcode == 7'b1101111)) begin
            ebreak_trigger();
        end
    end

    assign imm_type = 
                ((opcode == 7'b0010011 && funct3 == 3'b000) || (opcode == 7'b1100111 && funct3 == 3'b000)) ? 3'b000 :
                ((opcode == 7'b0010111) || (opcode == 7'b0110111)) ? 3'b011 :
                (opcode == 7'b1101111) ? 3'b100 :
                3'b000;
    assign wen = 1;
    assign src1_sel =
                (opcode == 7'b0110111) ? 2'b00 :
                ((opcode == 7'b0010111) || (opcode == 7'b1101111)) ? 2'b01 :
                ((opcode == 7'b0010011 && funct3 == 3'b000) || (opcode == 7'b1100111 && funct3 == 3'b000)) ? 2'b10 :
                2'b00;
    assign pc_sel =
                ((opcode == 7'b0010011 && funct3 == 3'b000) || opcode == 7'b0110111 || opcode == 7'b0010111) ? 2'b00:
                (opcode == 7'b1101111) ? 2'b01 :
                (opcode == 7'b1100111 && funct3 == 3'b000) ? 2'b11 :
                2'b00;

endmodule
