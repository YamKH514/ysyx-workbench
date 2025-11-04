`include "common.vh"

module EXU(
    input               clk,
    input               rst,
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

    input               pc_cnt_ready_in,
    output  reg         pc_cnt_valid_out
);

reg         exu_ready_r;
reg         wbu_valid_r;
reg         pc_cnt_valid_r;

reg [1:0]   state;
reg [1:0]   next_state;

reg [31:0]  pc_r;
reg [5:0]   alu_fun_r;
reg [31:0]  rd1_r;
reg [31:0]  rd2_r;
reg [31:0]  imm_r;
reg [1:0]   alu_src1_sel_r;
reg [1:0]   alu_src2_sel_r;

always @(posedge clk) begin
    if (rst) begin
        state <= `EXU_S_IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    next_state = state;
    case (state)
        `EXU_S_IDLE: begin
            if (exu_valid_in) begin
                next_state = `EXU_S_EXEC;
            end
        end
        `EXU_S_EXEC: begin
            next_state = `EXU_S_WAIT_WBU;
        end
        `EXU_S_WAIT_WBU: begin
            if (wbu_ready_in & pc_cnt_ready_in) begin
                next_state = `EXU_S_IDLE;
            end
        end
        default: begin
            next_state = `EXU_S_IDLE;
        end
    endcase
end

assign exu_ready_out = exu_ready_r;
assign wbu_valid_out = wbu_valid_r;
assign pc_cnt_valid_out = pc_cnt_valid_r;

always @(posedge clk) begin
    if (rst) begin
        exu_ready_r <= 1'b0;
        wbu_valid_r <= 1'b0;
        pc_cnt_valid_r <= 1'b0;

        pc_r            <= 32'b0;
        alu_fun_r       <= 6'b0;
        rd1_r           <= 32'b0;
        rd2_r           <= 32'b0;
        imm_r           <= 32'b0;
        alu_src1_sel_r  <= 2'b0;
        alu_src2_sel_r  <= 2'b0;
    end else begin
        case (state)
            `EXU_S_IDLE: begin
                exu_ready_r <= 1'b1;
                wbu_valid_r <= 1'b0;
                pc_cnt_valid_r <= 1'b0;
                if (exu_valid_in) begin
                    pc_r           <= exu_pc_in;
                    alu_fun_r      <= exu_alu_fun_in;
                    rd1_r          <= exu_rd1_in;
                    rd2_r          <= exu_rd2_in;
                    imm_r          <= exu_imm_in;
                    alu_src1_sel_r <= exu_alu_src1_sel_in;
                    alu_src2_sel_r <= exu_alu_src2_sel_in;
                end
            end
            `EXU_S_EXEC: begin
                exu_ready_r <= 1'b0;
                wbu_valid_r <= 1'b0;
                pc_cnt_valid_r <= 1'b0;
            end
            `EXU_S_WAIT_WBU: begin
                exu_ready_r <= 1'b0;
                wbu_valid_r <= 1'b1;
                pc_cnt_valid_r <= 1'b1;
            end
            default: begin
                exu_ready_r <= 1'b1;
                wbu_valid_r <= 1'b0;
                pc_cnt_valid_r <= 1'b0;
            end
        endcase
    end
end

ALU u_ALU(
    .PC         	(pc_r           ),
    .ALUFunc    	(alu_fun_r      ),
    .ReadData1  	(rd1_r          ),
    .ReadData2  	(rd2_r          ),
    .ImmExt     	(imm_r          ),
    .ALUSrcSel1 	(alu_src1_sel_r ),
    .ALUSrcSel2 	(alu_src2_sel_r ),
    .ALURes     	(exu_res_out    )
);

endmodule
