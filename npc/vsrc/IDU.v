`include "common.vh"

module IDU(
    input               idu_clk_in,
    input               idu_rst_in,
    input       [31:0]  idu_inst_in,
    output  reg         idu_is_ecall,
    output  reg         idu_is_mret,
    output  reg [2:0]   idu_inst_type,
    output  reg         idu_wbu_gpr_we_out,
    output  reg         idu_csr_we_out,
    output  reg [5:0]   idu_alu_fun_out,
    output  reg [1:0]   idu_alu_src1_sel_out,
    output  reg [1:0]   idu_alu_src2_sel_out,
    output  reg [3:0]   idu_npc_src_sel_out,
    output  reg [1:0]   idu_gpr_wd_sel_out,
    output  reg [7:0]   idu_mem_wmask_out,
    output  reg         idu_wbu_mem_we_out,
    output  reg [2:0]   idu_mem_read_func_out,

    input               idu_valid_in,
    output  reg         idu_ready_out,

    input               exu_ready_in,
    output  reg         exu_valid_out
);

reg state;
reg next_state;

reg     [31:0]  inst_reg;
wire    [6:0]   inst_opcode;
wire    [2:0]   inst_func3;
wire    [6:0]   inst_func7;

always @(posedge idu_clk_in) begin
    if (idu_rst_in) begin
        state <= `IDU_S_IDLE;
    end else begin
        state <= next_state;
    end

    if (idu_rst_in) begin
        inst_reg <= 32'b0;
    end else if ((state == `IDU_S_IDLE) & (idu_valid_in)) begin
        inst_reg <= idu_inst_in;
    end
end

always @(*) begin
    next_state = state;
    idu_ready_out = 1'b0;
    exu_valid_out = 1'b0;
    case (state)
        `IDU_S_IDLE: begin
            idu_ready_out = 1'b1;
            if (idu_valid_in) begin
                next_state = `IDU_S_WAIT_EXU;
            end
        end
        `IDU_S_WAIT_EXU: begin
            exu_valid_out = 1'b1;
            if (exu_ready_in) begin
                next_state = `IDU_S_IDLE;
            end
        end
    endcase
end

assign inst_opcode  = inst_reg[6:0];
assign inst_func3   = inst_reg[14:12];
assign inst_func7   = inst_reg[31:25];

wire inst_lui;      // U
wire inst_auipc;    // U
wire inst_jal;      // J
wire inst_jalr;     // I
wire inst_beq;      // B
wire inst_bne;      // B
wire inst_blt;      // B
wire inst_bge;      // B
wire inst_bltu;     // B
wire inst_bgeu;     // B
wire inst_lb;       // I
wire inst_lh;       // I
wire inst_lw;       // I
wire inst_lbu;      // I
wire inst_lhu;      // I
wire inst_sb;       // S
wire inst_sh;       // S
wire inst_sw;       // S
wire inst_addi;     // I
wire inst_slti;     // I
wire inst_sltiu;    // I
wire inst_xori;     // I
wire inst_ori;      // I
wire inst_andi;     // I
wire inst_slli;     // I
wire inst_srli;     // I
wire inst_srai;     // I
wire inst_add;      // R
wire inst_sub;      // R
wire inst_sll;      // R
wire inst_slt;      // R
wire inst_sltu;     // R
wire inst_xor;      // R
wire inst_srl;      // R
wire inst_sra;      // R
wire inst_or;       // R
wire inst_and;      // R
wire inst_ecall;
wire inst_ebreak;
wire inst_csrrw;    // I
wire inst_csrrs;    // I
wire inst_mret;

assign inst_lui     = (inst_opcode == 7'b0110111);
assign inst_auipc   = (inst_opcode == 7'b0010111);
assign inst_jal     = (inst_opcode == 7'b1101111);
assign inst_jalr    = (inst_opcode == 7'b1100111) & (inst_func3 == 3'b000);
assign inst_beq     = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b000);
assign inst_bne     = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b001);
assign inst_blt     = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b100);
assign inst_bge     = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b101);
assign inst_bltu    = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b110);
assign inst_bgeu    = (inst_opcode == 7'b1100011) & (inst_func3 == 3'b111);
assign inst_lb      = (inst_opcode == 7'b0000011) & (inst_func3 == 3'b000);
assign inst_lh      = (inst_opcode == 7'b0000011) & (inst_func3 == 3'b001);
assign inst_lw      = (inst_opcode == 7'b0000011) & (inst_func3 == 3'b010);
assign inst_lbu     = (inst_opcode == 7'b0000011) & (inst_func3 == 3'b100);
assign inst_lhu     = (inst_opcode == 7'b0000011) & (inst_func3 == 3'b101);
assign inst_sb      = (inst_opcode == 7'b0100011) & (inst_func3 == 3'b000);
assign inst_sh      = (inst_opcode == 7'b0100011) & (inst_func3 == 3'b001);
assign inst_sw      = (inst_opcode == 7'b0100011) & (inst_func3 == 3'b010);
assign inst_addi    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b000);
assign inst_slti    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b010);
assign inst_sltiu   = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b011);
assign inst_xori    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b100);
assign inst_ori     = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b110);
assign inst_andi    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b111);
assign inst_slli    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b001) & (inst_func7 == 7'b0000000);
assign inst_srli    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b101) & (inst_func7 == 7'b0000000);
assign inst_srai    = (inst_opcode == 7'b0010011) & (inst_func3 == 3'b101) & (inst_func7 == 7'b0100000);
assign inst_add     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b000) & (inst_func7 == 7'b0000000);
assign inst_sub     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b000) & (inst_func7 == 7'b0100000);
assign inst_sll     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b001) & (inst_func7 == 7'b0000000);
assign inst_slt     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b010) & (inst_func7 == 7'b0000000);
assign inst_sltu    = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b011) & (inst_func7 == 7'b0000000);
assign inst_xor     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b100) & (inst_func7 == 7'b0000000);
assign inst_srl     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b101) & (inst_func7 == 7'b0000000);
assign inst_sra     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b101) & (inst_func7 == 7'b0100000);
assign inst_or      = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b110) & (inst_func7 == 7'b0000000);
assign inst_and     = (inst_opcode == 7'b0110011) & (inst_func3 == 3'b111) & (inst_func7 == 7'b0000000);
assign inst_ecall   = (inst_reg == 32'b00000000000000000000000001110011);
assign inst_ebreak  = (inst_reg == 32'b00000000000100000000000001110011);
assign inst_csrrw   = (inst_opcode == 7'b1110011) & (inst_func3 == 3'b001);
assign inst_csrrs   = (inst_opcode == 7'b1110011) & (inst_func3 == 3'b010);
assign inst_mret    = (inst_reg == 32'b00110000001000000000000001110011);

import "DPI-C" function void ebreak_trigger();

always @(posedge idu_clk_in) begin
    if(inst_ebreak) begin
        ebreak_trigger();
    end
end

assign idu_is_ecall = inst_ecall;
assign idu_is_mret  = inst_mret;

assign idu_inst_type =  `INST_TYPE_I & {3{inst_jalr | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu |  inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai | inst_csrrw | inst_csrrs}} |
                        `INST_TYPE_S & {3{inst_sb | inst_sh | inst_sw}} |
                        `INST_TYPE_B & {3{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu}} |
                        `INST_TYPE_U & {3{inst_lui | inst_auipc}} |
                        `INST_TYPE_J & {3{inst_jal}} |
                        `INST_TYPE_R & {3{inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}} ;

assign idu_wbu_gpr_we_out = inst_lui | inst_auipc | inst_jal | inst_jalr | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and | inst_csrrw | inst_csrrs;

assign idu_csr_we_out = inst_csrrw | inst_csrrs;

assign idu_alu_fun_out =    `ALU_SUB                & {6{inst_sub}} |
                            `ALU_EQU                & {6{inst_beq | inst_bne}} |
                            `ALU_LT_SIGN            & {6{inst_blt | inst_bge | inst_slti | inst_slt}} |
                            `ALU_LT_OR_EQU_SIGN     & {6{1'b0}} |
                            `ALU_LT_UNSIGN          & {6{inst_bltu | inst_bgeu | inst_sltiu | inst_sltu}} |
                            `ALU_LT_OR_EQU_UNSIGN   & {6{1'b0}} |
                            `ALU_AND                & {6{inst_andi | inst_and}} |
                            `ALU_OR                 & {6{inst_ori | inst_or}} |
                            `ALU_XOR                & {6{inst_xori | inst_xor}} |
                            `ALU_SLL                & {6{inst_slli | inst_sll}} |
                            `ALU_SRL                & {6{inst_srli | inst_srl}} |
                            `ALU_SRA                & {6{inst_srai | inst_sra}} |
                            `ALU_ADD;

assign idu_alu_src1_sel_out =   `ALU_SRC1_SEL_0     & {2{inst_lui}} |
                                `ALU_SRC1_SEL_PC    & {2{inst_jal | inst_jalr | inst_auipc}} |
                                `ALU_SRC1_SEL_RD1   & {2{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_sb | inst_sh | inst_sw | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi| inst_slli | inst_srli | inst_srai | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}};

assign idu_alu_src2_sel_out =   `ALU_SRC2_SEL_RD2   & {2{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}} |
                                `ALU_SRC2_SEL_IMM   & {2{inst_lui | inst_auipc |inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_sb | inst_sh | inst_sw | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai}} |
                                `ALU_SRC2_SEL_4     & {2{inst_jal | inst_jalr}};

assign idu_npc_src_sel_out =    `NPC_SRC_SEL_PC_IMM     & {4{inst_jal}} |
                                `NPC_SRC_SEL_SRC1_IMM   & {4{inst_jalr}} |
                                `NPC_SRC_SEL_TRAP_PC    & {4{inst_ecall | inst_mret}} |
                                `NPC_SRC_SEL_JUMP_0     & {4{inst_bne | inst_bge | inst_bgeu}} |
                                `NPC_SRC_SEL_JUMP_1     & {4{inst_beq | inst_blt | inst_bltu}} |
                                `NPC_SRC_SEL_PC_4;

assign idu_gpr_wd_sel_out = `GPR_WD_SEL_MEM_DATA & {2{inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu}} |
                            `GPR_WD_SEL_CSR_DATA & {2{inst_csrrw | inst_csrrs}} |
                            `GPR_WD_SEL_ALU_RES;

assign idu_mem_wmask_out =  inst_sw ? 8'b00001111 :
                            inst_sh ? 8'b00000011 :
                            inst_sb ? 8'b00000001 :
                            8'b0;

// assign idu_wbu_mem_re_out = (inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu);

assign idu_wbu_mem_we_out = (inst_sb | inst_sh | inst_sw);

assign idu_mem_read_func_out =  {3{inst_lbu}} & `MEM_READ_FUNC_LBU |
                                {3{inst_lb}}  & `MEM_READ_FUNC_LB  |
                                {3{inst_lhu}} & `MEM_READ_FUNC_LHU |
                                {3{inst_lh}}  & `MEM_READ_FUNC_LH  |
                                {3{inst_lw}}  & `MEM_READ_FUNC_LW  ;

endmodule
