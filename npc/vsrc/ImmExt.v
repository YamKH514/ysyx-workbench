`include "common.vh"

module ImmExt(
    input   [2:0]   imm_ext_inst_type_in,
    input   [31:7]  imm_ext_imm_in,
    output  [31:0]  imm_ext_imm_out
);

// assign imm_ext_imm_out = 
//             (imm_ext_inst_type_in == `INST_TYPE_I) ? {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:20]} :
//             (imm_ext_inst_type_in == `INST_TYPE_S) ? {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:25], imm_ext_imm_in[11:7]} :
//             (imm_ext_inst_type_in == `INST_TYPE_B) ? {{19{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[7], imm_ext_imm_in[30:25], imm_ext_imm_in[11:8], 1'b0} :
//             (imm_ext_inst_type_in == `INST_TYPE_U) ? {imm_ext_imm_in[31:12], 12'b0} :
//             (imm_ext_inst_type_in == `INST_TYPE_J) ? {{11{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[19:12], imm_ext_imm_in[20], imm_ext_imm_in[30:21], 1'b0} :
//             32'b0;

wire [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;
reg  [31:0] imm_r;

assign imm_i = {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:20]};
assign imm_s = {{20{imm_ext_imm_in[31]}}, imm_ext_imm_in[31:25], imm_ext_imm_in[11:7]};
assign imm_b = {{19{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[7], imm_ext_imm_in[30:25], imm_ext_imm_in[11:8], 1'b0};
assign imm_u = {imm_ext_imm_in[31:12], 12'b0};
assign imm_j = {{11{imm_ext_imm_in[31]}}, imm_ext_imm_in[31], imm_ext_imm_in[19:12], imm_ext_imm_in[20], imm_ext_imm_in[30:21], 1'b0};
assign imm_ext_imm_out = imm_r;

always @(*) begin
    case (imm_ext_inst_type_in)
        `INST_TYPE_I: begin
            imm_r = imm_i;
        end
        `INST_TYPE_S: begin
            imm_r = imm_s;
        end
        `INST_TYPE_B: begin
            imm_r = imm_b;
        end
        `INST_TYPE_U: begin
            imm_r = imm_u;
        end
        `INST_TYPE_J: begin
            imm_r = imm_j;
        end
        default: begin
            imm_r = 32'b0;
        end
    endcase
end

endmodule
