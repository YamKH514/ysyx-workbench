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

    input               idu_to_pc_valid_in
);

assign pc_cnt_npc_out = (pc_cnt_npc_src_sel_in[3] == 1'b0) ?
                        (pc_cnt_npc_src_sel_in[2] == 1'b1 ? pc_cnt_trap_npc_in : (((pc_cnt_npc_src_sel_in[1] == 1'b0) ? pc_cnt_pc_out : pc_cnt_rd1_in) + ((pc_cnt_npc_src_sel_in[0] == 1'b0) ? 32'd4 : pc_cnt_imm_in))) :
                        (pc_cnt_pc_out + ((pc_cnt_npc_src_sel_in[2] == pc_cnt_cmp_res_in) ? pc_cnt_imm_in : 4));

always @(posedge clk) begin
    if (rst) begin
        pc_cnt_pc_out <= 32'h80000000;
    end else if (idu_to_pc_valid_in) begin
        pc_cnt_pc_out <= pc_cnt_npc_out;
    end
end

endmodule
