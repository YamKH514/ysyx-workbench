`include "common.vh"

module EXU(
    input               clk,
    input               rst,

    input       [31:0]  exu_pc_in,
    input       [31:0]  exu_rd1_in,
    input       [31:0]  exu_rd2_in,
    input       [31:0]  exu_imm_in,
    input       [5:0]   exu_alu_fun_in,
    input       [1:0]   exu_alu_src1_sel_in,
    input       [1:0]   exu_alu_src2_sel_in,
    output  reg [31:0]  exu_res_out,

    input               idu_to_exu_valid_in,
    output  reg         exu_to_idu_ready_out,

    output  reg         exu_to_pc_valid_out
);

parameter S_IDLE = 2'd0;
parameter S_WAIT_LBU = 2'd1;

reg [1:0] state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        exu_to_idu_ready_out <= 1'b0;
        exu_to_pc_valid_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                exu_to_idu_ready_out <= 1'b0;
                exu_to_pc_valid_out <= 1'b0;
                if (idu_to_exu_valid_in) begin
                    exu_to_idu_ready_out <= 1'b1;
                    exu_to_pc_valid_out <= 1'b1;
                end
            end
            S_WAIT_LBU: begin
                exu_to_idu_ready_out <= 1'b0;
                exu_to_pc_valid_out <= 1'b0;
            end
            default: begin
                exu_to_idu_ready_out <= 1'b0;
                exu_to_pc_valid_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    case (state)
        S_IDLE: begin
            if (idu_to_exu_valid_in) begin
                next_state = S_WAIT_LBU;
            end
        end
        S_WAIT_LBU: begin
            next_state = S_IDLE;
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

reg [31:0]  pc_r;
reg [5:0]   alu_fun_r;
reg [31:0]  rd1_r;
reg [31:0]  rd2_r;
reg [31:0]  imm_r;
reg [1:0]   alu_src1_sel_r;
reg [1:0]   alu_src2_sel_r;
reg [31:0]  alu_res_r;

assign pc_r           = exu_pc_in;
assign alu_fun_r      = exu_alu_fun_in;
assign rd1_r          = exu_rd1_in;
assign rd2_r          = exu_rd2_in;
assign imm_r          = exu_imm_in;
assign alu_src1_sel_r = exu_alu_src1_sel_in;
assign alu_src2_sel_r = exu_alu_src2_sel_in;

assign exu_res_out = alu_res_r;

ALU u_ALU(
    .PC         	(pc_r           ),
    .ALUFunc    	(alu_fun_r      ),
    .ReadData1  	(rd1_r          ),
    .ReadData2  	(rd2_r          ),
    .ImmExt     	(imm_r          ),
    .ALUSrcSel1 	(alu_src1_sel_r ),
    .ALUSrcSel2 	(alu_src2_sel_r ),
    .ALURes     	(alu_res_r      )
);

endmodule
