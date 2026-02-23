`include "common.vh"

module ImmExt(
    input   [2:0]   idu_imm_type_i,
    input   [31:7]  idu_imm_inst_i,
    output  [31:0]  imm_exu_o
);

// assign imm_exu_o = 
//             (idu_imm_type_i == `INST_TYPE_I) ? {{20{idu_imm_inst_i[31]}}, idu_imm_inst_i[31:20]} :
//             (idu_imm_type_i == `INST_TYPE_S) ? {{20{idu_imm_inst_i[31]}}, idu_imm_inst_i[31:25], idu_imm_inst_i[11:7]} :
//             (idu_imm_type_i == `INST_TYPE_B) ? {{19{idu_imm_inst_i[31]}}, idu_imm_inst_i[31], idu_imm_inst_i[7], idu_imm_inst_i[30:25], idu_imm_inst_i[11:8], 1'b0} :
//             (idu_imm_type_i == `INST_TYPE_U) ? {idu_imm_inst_i[31:12], 12'b0} :
//             (idu_imm_type_i == `INST_TYPE_J) ? {{11{idu_imm_inst_i[31]}}, idu_imm_inst_i[31], idu_imm_inst_i[19:12], idu_imm_inst_i[20], idu_imm_inst_i[30:21], 1'b0} :
//             32'b0;

wire [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;
reg  [31:0] imm_r;

assign imm_i = {{20{idu_imm_inst_i[31]}}, idu_imm_inst_i[31:20]};
assign imm_s = {{20{idu_imm_inst_i[31]}}, idu_imm_inst_i[31:25], idu_imm_inst_i[11:7]};
assign imm_b = {{19{idu_imm_inst_i[31]}}, idu_imm_inst_i[31], idu_imm_inst_i[7], idu_imm_inst_i[30:25], idu_imm_inst_i[11:8], 1'b0};
assign imm_u = {idu_imm_inst_i[31:12], 12'b0};
assign imm_j = {{11{idu_imm_inst_i[31]}}, idu_imm_inst_i[31], idu_imm_inst_i[19:12], idu_imm_inst_i[20], idu_imm_inst_i[30:21], 1'b0};
assign imm_exu_o = imm_r;

always @(*) begin
    case (idu_imm_type_i)
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
