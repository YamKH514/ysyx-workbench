`ifndef COMMON_VH__
`define COMMON_VH__

// ==========================
// PC CNT  STATE
// ==========================
`define PC_CNT_S_READY          1'b0
`define PC_CNT_S_WAIT_UPDATE    1'b1

// ==========================
// IFU  STATE
// ==========================
`define IFU_S_IDLE      2'd0
`define IFU_S_WAIT_SRAM 2'd1
`define IFU_S_WAIT_IDU  2'd2

// ==========================
// IDU  STATE
// ==========================
`define IDU_S_IDLE          1'b0
`define IDU_S_WAIT_EXU      1'b1

// ==========================
// EXU  STATE
// ==========================
`define EXU_S_IDLE      2'b00
`define EXU_S_EXEC      2'b01
`define EXU_S_WAIT_WBU  2'b10

// ==========================
// WBU  STATE
// ==========================
`define WBU_S_IDLE          2'b00
`define WBU_S_WAIT_LOAD     2'b01
`define WBU_S_WAIT_STORE    2'b10
`define WBU_S_WB            2'b11

// ==========================
// MEM  STATE
// ==========================
`define MEM_S_IDLE  1'b0
`define MEM_S_WRITE 1'b1

// ==========================
// Inst Type
// ==========================
`define INST_TYPE_I  3'd0
`define INST_TYPE_S  3'd1
`define INST_TYPE_B  3'd2
`define INST_TYPE_U  3'd3
`define INST_TYPE_J  3'd4
`define INST_TYPE_R  3'd5

// ==========================
// ALU Function
// ==========================
`define ALU_ADD                 6'b000000
`define ALU_SUB                 6'b000001
`define ALU_EQU                 6'b010011
`define ALU_LT_SIGN             6'b010101
`define ALU_LT_OR_EQU_SIGN      6'b010111
`define ALU_LT_UNSIGN           6'b011101
`define ALU_LT_OR_EQU_UNSIGN    6'b011111
`define ALU_AND                 6'b101000
`define ALU_OR                  6'b101110
`define ALU_XOR                 6'b100110
`define ALU_SLL                 6'b110000
`define ALU_SRL                 6'b110001
`define ALU_SRA                 6'b110011

// ==========================
// ALU Src1 Select
// ==========================
`define ALU_SRC1_SEL_0      2'd0
`define ALU_SRC1_SEL_PC     2'd1
`define ALU_SRC1_SEL_RD1    2'd2

// ==========================
// ALU Src2 Select
// ==========================
`define ALU_SRC2_SEL_RD2    2'd0
`define ALU_SRC2_SEL_IMM    2'd1
`define ALU_SRC2_SEL_4      2'd2

// ==========================
// NPC SRC Select
// ==========================
`define NPC_SRC_SEL_PC_4        4'b0000
`define NPC_SRC_SEL_PC_IMM      4'b0001
`define NPC_SRC_SEL_SRC1_IMM    4'b0011
`define NPC_SRC_SEL_TRAP_PC     4'b0100
`define NPC_SRC_SEL_JUMP_0      4'b1000
`define NPC_SRC_SEL_JUMP_1      4'b1100

// ==========================
// GPR Write Data Select
// ==========================
`define GPR_WD_SEL_ALU_RES  2'd0
`define GPR_WD_SEL_MEM_DATA 2'd1
`define GPR_WD_SEL_CSR_DATA 2'd2

// ==========================
// Memory Read Func
// ==========================
`define MEM_READ_FUNC_LBU   3'b001
`define MEM_READ_FUNC_LB    3'b101
`define MEM_READ_FUNC_LHU   3'b010
`define MEM_READ_FUNC_LH    3'b110
`define MEM_READ_FUNC_LW    3'b011

`endif
