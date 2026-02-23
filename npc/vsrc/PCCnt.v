module PCCnt(
    input               clk,
    input               rst,
    input               pc_cnt_cmp_res_i,
    input       [31:0]  pc_cnt_rd1_i,
    input       [31:0]  pc_cnt_imm_i,
    input       [3:0]   pc_cnt_npc_src_sel_i, // npc = pc+4(0000) pc+imm(0001) src1+imm(0011) trap_npc(0100) res=0,jump(10--) res=1,jump(11--)
    input       [31:0]  pc_cnt_trap_npc_i,
    output  reg [31:0]  pc_cnt_pc_o,

    input               wbu_pc_valid_i,
    output  reg         wbu_pc_ready_o,
    output  reg         pc_ifu_valid_o,
    input               pc_ifu_ready_i
);

parameter RESET_PC = 32'h30000000;

reg [31:0] pc_r;

assign pc_cnt_pc_o = pc_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= RESET_PC;
    end else if (wbu_pc_valid_i & wbu_pc_ready_o) begin
        pc_r <= is_trap ? pc_cnt_trap_npc_i : addr_res;
    end
end

wire        is_trap;
wire        is_jump;
wire [31:0] base;
wire [31:0] offset;
wire [31:0] addr_res;

assign is_trap = ~pc_cnt_npc_src_sel_i[3] & pc_cnt_npc_src_sel_i[2];
assign is_jump = pc_cnt_npc_src_sel_i[3];

assign base = 
            is_trap ? 32'b0 :
            (!is_jump & pc_cnt_npc_src_sel_i[1]) ? pc_cnt_rd1_i : pc_r;
assign offset = 
            is_trap ? 32'b0 :
            is_jump ?
            (pc_cnt_npc_src_sel_i[2] == pc_cnt_cmp_res_i) ? pc_cnt_imm_i : 4 :
            pc_cnt_npc_src_sel_i[0] ? pc_cnt_imm_i : 32'd4;

assign addr_res = base + offset;

assign wbu_pc_ready_o = state == S_IDLE & wbu_pc_valid_i;
assign pc_ifu_valid_o = state == S_BUSY;

// always @(posedge clk) begin
//     if (rst) begin
//         pc_ifu_valid_o <= 1'b1;
//     end else begin
//         case (state)
//             S_IDLE: begin
//                 if (wbu_pc_valid_i & wbu_pc_ready_o) begin
//                     pc_ifu_valid_o <= 1'b1;
//                 end
//             end
//             S_BUSY: begin
//                 if (pc_ifu_valid_o & pc_ifu_ready_i) begin
//                     pc_ifu_valid_o <= 1'b0;
//                 end
//             end
//         endcase
//     end
// end

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_BUSY;
    end else begin
        case (state)
            S_IDLE: begin
                if (wbu_pc_valid_i & wbu_pc_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (pc_ifu_valid_o & pc_ifu_ready_i) state <= S_IDLE;
            end
        endcase
    end
end

endmodule
