`include "common.vh"
module WBU(
    input               clk,
    input               rst,

    input       [31:0]  lsu_pc_i,

    // idu_to_wbu_data is_ecall[9], is_mret[8], wbu_we[7], wbu_w_addr[6:2], wbu_wd_sel[1:0]
    input       [ 7:0]  lsu_wbu_data_i,
    input       [31:0]  lsu_wbu_gpr_wdata_i,
    input               lsu_wbu_csr_we_i,
    input       [ 2:0]  lsu_wbu_csr_func3_i,
    input       [11:0]  lsu_wbu_csr_waddr_i,
    input       [31:0]  lsu_wbu_csr_wdata_i,

    output              wbu_gpr_we_o,
    output      [ 4:0]  wbu_gpr_waddr_o,
    output      [31:0]  wbu_gpr_wdata_o,
    output              wbu_csr_we_o,
    output      [ 2:0]  wbu_csr_func3_o,
    output      [11:0]  wbu_csr_waddr_o,
    output      [31:0]  wbu_csr_wdata_o,
    output      [31:0]  wbu_csr_mepc_o,
    output reg          wbu_csr_ecall_o,
    output reg          wbu_csr_mret_o,
`ifdef FOR_SIMULATION_ENV
    input  [31:0] target_pc_i,
`endif
    input         lsu_wbu_valid_i,
    output        lsu_wbu_ready_o
);

assign wbu_csr_func3_o = lsu_wbu_csr_func3_i;
assign wbu_csr_we_o = lsu_wbu_csr_we_i & state == S_BUSY;
assign wbu_csr_waddr_o = lsu_wbu_csr_waddr_i;
assign wbu_csr_wdata_o = lsu_wbu_csr_wdata_i;
assign wbu_csr_mepc_o = lsu_pc_i;

wire        ecall;
wire        mret;
wire        wbu_we;
wire [ 4:0] wbu_w_addr;

assign {ecall, mret, wbu_we, wbu_w_addr} = lsu_wbu_data_i;
assign wbu_gpr_we_o = wbu_we & state == S_BUSY;
assign wbu_gpr_waddr_o = wbu_w_addr;
assign wbu_gpr_wdata_o = lsu_wbu_gpr_wdata_i;
assign wbu_csr_ecall_o = ecall & state == S_BUSY;
assign wbu_csr_mret_o = mret & state == S_BUSY;

assign lsu_wbu_ready_o = state == S_BUSY;

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (lsu_wbu_valid_i) state <= S_BUSY;
            end
            S_BUSY: begin
                state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

`ifdef FOR_SIMULATION_ENV
reg [31:0] pc_r;
reg [31:0] target_pc_r;
always @(posedge clk) begin
    if (lsu_wbu_valid_i & state == S_IDLE) begin
        pc_r <= lsu_pc_i;
        target_pc_r <= target_pc_i;
    end
end

export "DPI-C" function wbu_commit;
function int wbu_commit();
    if (lsu_wbu_valid_i & lsu_wbu_ready_o) return 1;
    else return 0;
endfunction
`endif

endmodule
