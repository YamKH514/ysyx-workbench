`include "common.vh"

module ImmExt(
    input   [2:0]   imm_ext_inst_type_in,
    input   [31:7]  imm_ext_imm_in,
    output  [31:0]  imm_ext_imm_out
);

assign imm_ext_imm_out = 
            (imm_ext_inst_type_in == `INST_TYPE_I) ? {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:20]} :
            (imm_ext_inst_type_in == `INST_TYPE_S) ? {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:25], imm_ext_imm_in[11:7]} :
            (imm_ext_inst_type_in == `INST_TYPE_B) ? {{19{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[7], imm_ext_imm_in[30:25], imm_ext_imm_in[11:8], 1'b0} :
            (imm_ext_inst_type_in == `INST_TYPE_U) ? {imm_ext_imm_in[31:12], 12'b0} :
            (imm_ext_inst_type_in == `INST_TYPE_J) ? {{11{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[19:12], imm_ext_imm_in[20], imm_ext_imm_in[30:21], 1'b0} :
            32'b0;

endmodule
