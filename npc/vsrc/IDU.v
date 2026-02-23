`include "common.vh"

module IDU(
    input               clk,
    input               rst,

    input       [31:0]  ifu_pc_i,
    input       [31:0]  ifu_inst_i,
    output      [31:0]  idu_pc_o,
    output      [31:0]  idu_inst_o,

    input       [31:0]  gpr_idu_rdata1_i,
    input       [31:0]  gpr_idu_rdata2_i,
    input       [31:0]  csr_idu_rdata_i,

    output              fence_i_o,

    output  reg [ 2:0]  idu_imm_type_o,
    output      [24:0]  idu_imm_inst_o,

    output  reg [ 5:0]  idu_exu_fun_o,
    output  reg [ 1:0]  idu_exu_src1_sel_o,
    output  reg [ 1:0]  idu_exu_src2_sel_o,
    output      [63:0]  idu_exu_rdata_o,

    // idu_to_lsu_data lsu_r_func[8:6], lsu_re[5], lsu_w_mask[4:1], lsu_we[0]
    output  reg [ 8:0]  idu_exu_lsu_data_o,
    // idu_to_wbu_data is_ecall[9], is_mret[8], wbu_we[7], wbu_w_addr[6:2], wbu_wd_sel[1:0]
    output  reg [ 9:0]  idu_exu_wbu_data_o,
    output      [31:0]  idu_exu_wbu_csr_rdata_o,
    output  reg         idu_exu_wbu_csr_we_o,
    output  reg [ 3:0]  idu_exu_pc_src_sel_o,

    input               ifu_idu_valid_i,
    output  reg         ifu_idu_ready_o,

    output  reg         idu_exu_valid_o,
    input               idu_exu_ready_i
);

reg [31:0] ifu_pc_r;
reg [31:0] ifu_inst_r;
reg [63:0] gpr_rdata_r;
reg [31:0] csr_rdata_r;

always @(posedge clk) begin
    if (rst) begin
        ifu_pc_r <= 32'b0;
        ifu_inst_r <= 32'b0;
        gpr_rdata_r <= 64'b0;
        csr_rdata_r <= 32'b0;
    end else if (state == S_IDLE && ifu_idu_valid_i) begin
        ifu_pc_r <= ifu_pc_i;
        ifu_inst_r <= ifu_inst_i;
        gpr_rdata_r <= {gpr_idu_rdata2_i, gpr_idu_rdata1_i};
        csr_rdata_r <= csr_idu_rdata_i;
    end
end

assign idu_imm_inst_o = ifu_inst_r[31:7];
assign idu_pc_o = ifu_pc_r;
assign idu_inst_o = ifu_inst_r;
assign idu_exu_rdata_o = gpr_rdata_r;
assign idu_exu_wbu_csr_rdata_o = csr_rdata_r;

reg [2:0]   lsu_r_func_r;
reg         lsu_re_r;
reg [3:0]   lsu_w_mask_r;
reg         lsu_we_r;
assign idu_exu_lsu_data_o = {lsu_r_func_r, lsu_re_r, lsu_w_mask_r, lsu_we_r};

reg         ecall_r;
reg         mret_r;
reg         wbu_we_r;
reg [4:0]   wbu_w_addr_r;
reg [1:0]   wbu_wd_sel_r;
assign idu_exu_wbu_data_o = {ecall_r, mret_r, wbu_we_r, wbu_w_addr_r, wbu_wd_sel_r};

parameter S_IDLE = 1'd0;
parameter S_WAIT_EXU = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        ifu_idu_ready_o <= 1'b0;
        idu_exu_valid_o <= 1'b0;
        ifu_inst_r <= 32'b0;
    end else begin
        case (state)
            S_IDLE: begin
                ifu_idu_ready_o <= 1'b0;
                idu_exu_valid_o <= 1'b0;
                if (ifu_idu_valid_i) begin
                    ifu_idu_ready_o <= 1'b1;
                    idu_exu_valid_o <= 1'b1;
                    ifu_inst_r <= ifu_inst_i;
                end
            end
            S_WAIT_EXU: begin
                ifu_idu_ready_o <= 1'b0;
                if (idu_exu_ready_i) begin
                    idu_exu_valid_o <= 1'b0;
                end
            end
            default: begin
                ifu_idu_ready_o <= 1'b0;
                idu_exu_valid_o <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (ifu_idu_valid_i) begin
                next_state = S_WAIT_EXU;
            end
        end
        S_WAIT_EXU: begin
            if (idu_exu_ready_i) begin
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

wire    [6:0]   inst_opcode;
wire    [2:0]   inst_func3;
wire    [6:0]   inst_func7;

assign inst_opcode  = ifu_inst_r[6:0];
assign inst_func3   = ifu_inst_r[14:12];
assign inst_func7   = ifu_inst_r[31:25];

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
wire inst_fence_i;  // I
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
assign inst_ecall   = (ifu_inst_r == 32'b00000000000000000000000001110011);
assign inst_ebreak  = (ifu_inst_r == 32'b00000000000100000000000001110011);
assign inst_fence_i = (inst_opcode == 7'b0001111) & (inst_func3 == 3'b001);
assign inst_csrrw   = (inst_opcode == 7'b1110011) & (inst_func3 == 3'b001);
assign inst_csrrs   = (inst_opcode == 7'b1110011) & (inst_func3 == 3'b010);
assign inst_mret    = (ifu_inst_r == 32'b00110000001000000000000001110011);

import "DPI-C" function void ebreak_trigger();

always @(posedge clk) begin
    if(inst_ebreak) begin
        ebreak_trigger();
    end
end

assign ecall_r = inst_ecall;
assign mret_r  = inst_mret;

assign idu_imm_type_o = `INST_TYPE_I & {3{inst_jalr | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu |  inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai | inst_fence_i | inst_csrrw | inst_csrrs}} |
                        `INST_TYPE_S & {3{inst_sb | inst_sh | inst_sw}} |
                        `INST_TYPE_B & {3{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu}} |
                        `INST_TYPE_U & {3{inst_lui | inst_auipc}} |
                        `INST_TYPE_J & {3{inst_jal}} |
                        `INST_TYPE_R & {3{inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}} ;

assign wbu_we_r = inst_lui | inst_auipc | inst_jal | inst_jalr | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and | inst_csrrw | inst_csrrs;

assign idu_exu_wbu_csr_we_o = inst_csrrw | inst_csrrs;

assign fence_i_o = inst_fence_i;

assign idu_exu_fun_o =  `ALU_SUB                & {6{inst_sub}} |
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

assign idu_exu_src1_sel_o = `ALU_SRC1_SEL_0     & {2{inst_lui}} |
                            `ALU_SRC1_SEL_PC    & {2{inst_jal | inst_jalr | inst_auipc}} |
                            `ALU_SRC1_SEL_RD1   & {2{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_sb | inst_sh | inst_sw | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi| inst_slli | inst_srli | inst_srai | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}};

assign idu_exu_src2_sel_o = `ALU_SRC2_SEL_RD2   & {2{inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_add | inst_sub | inst_sll | inst_slt | inst_sltu | inst_xor | inst_srl | inst_sra | inst_or | inst_and}} |
                            `ALU_SRC2_SEL_IMM   & {2{inst_lui | inst_auipc |inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu | inst_sb | inst_sh | inst_sw | inst_addi | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi | inst_slli | inst_srli | inst_srai}} |
                            `ALU_SRC2_SEL_4     & {2{inst_jal | inst_jalr}};

assign idu_exu_pc_src_sel_o =   `NPC_SRC_SEL_PC_IMM     & {4{inst_jal}} |
                                `NPC_SRC_SEL_SRC1_IMM   & {4{inst_jalr}} |
                                `NPC_SRC_SEL_TRAP_PC    & {4{inst_ecall | inst_mret}} |
                                `NPC_SRC_SEL_JUMP_0     & {4{inst_bne | inst_bge | inst_bgeu}} |
                                `NPC_SRC_SEL_JUMP_1     & {4{inst_beq | inst_blt | inst_bltu}} |
                                `NPC_SRC_SEL_PC_4;

assign wbu_w_addr_r = ifu_inst_r[11:7];

assign wbu_wd_sel_r =   `GPR_WD_SEL_MEM_DATA & {2{inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu}} |
                        `GPR_WD_SEL_CSR_DATA & {2{inst_csrrw | inst_csrrs}} |
                        `GPR_WD_SEL_ALU_RES;

assign lsu_w_mask_r =   inst_sw ? 4'b1111 :
                        inst_sh ? 4'b0011 :
                        inst_sb ? 4'b0001 :
                        4'b0;

assign lsu_re_r = (inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu);

assign lsu_we_r = (inst_sb | inst_sh | inst_sw);

assign lsu_r_func_r =   {3{inst_lbu}} & `MEM_READ_FUNC_LBU |
                        {3{inst_lb}}  & `MEM_READ_FUNC_LB  |
                        {3{inst_lhu}} & `MEM_READ_FUNC_LHU |
                        {3{inst_lh}}  & `MEM_READ_FUNC_LH  |
                        {3{inst_lw}}  & `MEM_READ_FUNC_LW  ;

endmodule
