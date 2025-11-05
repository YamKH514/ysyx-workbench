`include "common.vh"

module PCCnt(
    input               clk,
    input               rst,
    input               pc_cnt_cmp_res_in,
    input       [31:0]  pc_cnt_rd1_in,
    input       [31:0]  pc_cnt_imm_in,
    input       [3:0]   pc_cnt_npc_src_sel_in, // npc = pc+4(0000) pc+imm(0001) src1+imm(0011) trap_npc(0100) res=0,jump(10--) res=1,jump(11--)
    input       [31:0]  pc_cnt_trap_npc_in,
    output  reg [31:0]  pc_cnt_pc_out,
    output  reg [31:0]  pc_cnt_npc_out,

    input               pc_cnt_valid_in,
    output              pc_cnt_ready_out
);

// reg pc_cnt_ready_r;

// reg state;
// reg next_state;

assign pc_cnt_npc_out = (pc_cnt_npc_src_sel_in[3] == 1'b0) ?
                        (pc_cnt_npc_src_sel_in[2] == 1'b1 ? pc_cnt_trap_npc_in : (((pc_cnt_npc_src_sel_in[1] == 1'b0) ? pc_cnt_pc_out : pc_cnt_rd1_in) + ((pc_cnt_npc_src_sel_in[0] == 1'b0) ? 32'd4 : pc_cnt_imm_in))) :
                        (pc_cnt_pc_out + ((pc_cnt_npc_src_sel_in[2] == pc_cnt_cmp_res_in) ? pc_cnt_imm_in : 4));

// always @(posedge clk) begin
//     if (rst) begin
//         state <= `PC_CNT_S_READY;
//     end else begin
//         state <= next_state;
//     end
// end

// always @(*) begin
//     next_state = state;
//     case (state)
//         `PC_CNT_S_READY: begin
//             if (pc_cnt_valid_in) begin
//                 next_state = `PC_CNT_S_WAIT_UPDATE;
//             end
//         end
//         `PC_CNT_S_WAIT_UPDATE: begin
//             next_state = `PC_CNT_S_READY;
//         end
//     endcase
// end

// assign pc_cnt_ready_out = pc_cnt_ready_r;

always @(posedge clk) begin
    if (rst) begin
        pc_cnt_pc_out <= 32'h80000000;
    end else begin
        if (pc_cnt_valid_in) begin
            pc_cnt_ready_out <= 1'b1;
            pc_cnt_pc_out <= pc_cnt_npc_out;
        end else begin
            pc_cnt_ready_out <=1'b0;
        end
    end
end

// always @(posedge clk) begin
//     if (rst) begin
//         pc_cnt_ready_r <= 1'b0;
//         pc_cnt_pc_out <= 32'h80000000;
//     end else begin
//         case (state)
//             `PC_CNT_S_READY: begin
//                 pc_cnt_ready_r <= 1'b1;
//             end
//             `PC_CNT_S_WAIT_UPDATE: begin
//                 pc_cnt_ready_r <= 1'b0;
//                 pc_cnt_pc_out <= pc_cnt_npc_out;
//             end
//         endcase
//     end
// end

endmodule
