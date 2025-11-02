`include "common.vh"

module EXU(
    input               exu_clk_in,
    input               exu_rst_in,
    input       [31:0]  exu_pc_in,
    input       [5:0]   exu_alu_fun_in,
    input       [31:0]  exu_rd1_in,
    input       [31:0]  exu_rd2_in,
    input       [31:0]  exu_imm_in,
    input       [1:0]   exu_alu_src1_sel_in,
    input       [1:0]   exu_alu_src2_sel_in,
    output  reg [31:0]  exu_res_out,

    input               exu_valid_in,
    output  reg         exu_ready_out,

    input               wbu_ready_in,
    output  reg         wbu_valid_out,

    output  reg         pc_cnt_valid_out
);

reg [1:0]   state;
reg [1:0]   next_state;

reg [31:0]  pc;
reg [5:0]   alu_fun;
reg [31:0]  rd1;
reg [31:0]  rd2;
reg [31:0]  imm;
reg [1:0]   alu_src1_sel;
reg [1:0]   alu_src2_sel;

always @(posedge exu_clk_in) begin
    if (exu_rst_in) begin
        state <= `EXU_S_IDLE;
    end else begin
        state <= next_state;
    end

    if ((state == `EXU_S_IDLE) & (exu_valid_in)) begin
        pc           <= exu_pc_in;
        alu_fun      <= exu_alu_fun_in;
        rd1          <= exu_rd1_in;
        rd2          <= exu_rd2_in;
        imm          <= exu_imm_in;
        alu_src1_sel <= exu_alu_src1_sel_in;
        alu_src2_sel <= exu_alu_src2_sel_in;
    end
end

always @(*) begin
    next_state = state;
    exu_ready_out = 1'b0;
    wbu_valid_out = 1'b0;
    pc_cnt_valid_out = 1'b0;
    case (state)
        `EXU_S_IDLE: begin
            exu_ready_out = 1'b1;
            if (exu_valid_in) begin
                next_state = `EXU_S_EXEC;
            end
        end
        `EXU_S_EXEC: begin
            next_state = `EXU_S_WAIT_WBU;
        end
        `EXU_S_WAIT_WBU: begin
            wbu_valid_out = 1'b1;
            pc_cnt_valid_out = 1'b1;
            if (wbu_ready_in) begin
                next_state = `EXU_S_IDLE;
            end
        end
        default: begin
            next_state = `EXU_S_IDLE;
        end
    endcase
end

ALU u_ALU(
    .PC         	(pc             ),
    .ALUFunc    	(alu_fun        ),
    .ReadData1  	(rd1            ),
    .ReadData2  	(rd2            ),
    .ImmExt     	(imm            ),
    .ALUSrcSel1 	(alu_src1_sel   ),
    .ALUSrcSel2 	(alu_src2_sel   ),
    .ALURes     	(exu_res_out    )
);

endmodule
