`include "common.vh"
module LSU(
    input         clk,
    input         rst,

    input  [31:0] exu_pc_i,
    output [31:0] lsu_pc_o,

    input  [31:0] exu_lsu_wbu_gpr_wdata_i,
    input         exu_lsu_wbu_csr_we_i,
    input  [ 2:0] exu_lsu_wbu_csr_func3_i,
    input  [11:0] exu_lsu_wbu_csr_waddr_i,
    input  [ 9:0] exu_lsu_wbu_data_i,

    // idu_to_lsu_data lsu_r_func[8:6], lsu_re[5], lsu_w_mask[4:1], lsu_we[0]
    input  [ 8:0] exu_lsu_data_i,
    input  [31:0] exu_lsu_res_i,
    input  [63:0] exu_lsu_gpr_rdata_i,

    output [31:0] lsu_wbu_rdata_o,
    output [ 9:0] lsu_wbu_data_o,
    output [31:0] lsu_wbu_gpr_wdata_o,
    output        lsu_wbu_csr_we_o,
    output [ 2:0] lsu_wbu_csr_func3_o,
    output [11:0] lsu_wbu_csr_waddr_o,
    output [31:0] lsu_wbu_csr_wdata_o,
`ifdef FOR_SIMULATION_ENV
    input  [31:0]   target_pc_i,
    output [31:0]   target_pc_o,
`endif
    input         exu_lsu_valid_i,
    output        exu_lsu_ready_o,

    output        lsu_wbu_valid_o,
    input         lsu_wbu_ready_i,

    output [ 3:0] arid_o,
    output [31:0] araddr_o,
    output [ 3:0] arlen_o,
    output [ 2:0] arsize_o,
    output [ 1:0] arburst_o,
    output        arvalid_o,
    input         arready_i,
    input  [ 3:0] rid_i,
    input  [31:0] rdata_i,
    input  [ 1:0] rresp_i,
    input         rlast_i,
    input         rvalid_i,
    output        rready_o,

    output [ 3:0] awid_o,
    output [31:0] awaddr_o,
    output [ 3:0] awlen_o,
    output [ 2:0] awsize_o,
    output [ 1:0] awburst_o,
    output        awvalid_o,
    input         awready_i,
    output [31:0] wdata_o,
    output [ 3:0] wstrb_o,
    output        wlast_o,
    output        wvalid_o,
    input         wready_i,
    input  [ 3:0] bid_i,
    input  [ 1:0] bresp_i,
    input         bvalid_i,
    output        bready_o,

    output        bs_o,
    output        br_o,
    input         bg_i
);

assign lsu_pc_o = exu_pc_i;
assign lsu_wbu_gpr_wdata_o = exu_lsu_wbu_gpr_wdata_i;
assign lsu_wbu_csr_we_o = exu_lsu_wbu_csr_we_i;
assign lsu_wbu_csr_func3_o = exu_lsu_wbu_csr_func3_i;
assign lsu_wbu_csr_waddr_o = exu_lsu_wbu_csr_waddr_i;
assign lsu_wbu_csr_wdata_o = exu_lsu_gpr_rdata_i[31:0];
assign lsu_wbu_data_o = exu_lsu_wbu_data_i;

import "DPI-C" function void mem_tracer_read(input int addr,input int data, input int is_inst);
import "DPI-C" function void mem_tracer_write(input int addr,input int data, input int strb);
import "DPI-C" function void perip_difftest_skip(input int addr);

reg  [2:0] lsu_r_func_r;
reg        lsu_re_r;
wire [3:0] lsu_w_mask_r;
wire       lsu_we_r;
assign {lsu_r_func_r, lsu_re_r, lsu_w_mask_r, lsu_we_r} = exu_lsu_data_i;

reg        aw_handshake_r;
reg        w_handshake_r;
reg [ 3:0] rid_r;
reg [31:0] rdata_r;
reg [ 3:0] bid_r;

assign br_o = state == S_WAIT_ARB;
assign bs_o = (rvalid_i & rready_o & rlast_i) | (bvalid_i & bready_o);

always @(posedge clk) begin
    if (rst) begin
        aw_handshake_r <= 0;
    end else if (state == S_W_SEND && awvalid_o && awready_i) begin
        aw_handshake_r <= 1;
    end else if (state != S_W_SEND) begin
        aw_handshake_r <= 0;
    end
end

always @(posedge clk) begin
    if (rst) begin
        w_handshake_r <= 0;
    end else if (state == S_W_SEND && wvalid_o && wready_i) begin
        w_handshake_r <= 1;
    end else if (state !=S_W_SEND) begin
        w_handshake_r <= 0;
    end
end

assign awid_o    = 4'b0;
assign awaddr_o  = (state == S_W_SEND) ? exu_lsu_res_i : 32'd0;
assign awlen_o   = 4'b0;
assign awsize_o  = (state == S_W_SEND) ? awsize : 3'd0;
assign awburst_o = (state == S_W_SEND) ? 2'b01 : 2'd0;
assign awvalid_o = (state == S_W_SEND) & !aw_handshake_r;
assign wdata_o   = (state == S_W_SEND) ? wdata_aligned : 32'd0;
assign wstrb_o   = (state == S_W_SEND) ? wstrb_aligned : 4'd0;
assign wlast_o   = (state == S_W_SEND);
assign wvalid_o  = (state == S_W_SEND) & !w_handshake_r;
assign bready_o  = (state == S_GET_B);

assign arid_o    = 4'b0;
assign araddr_o  = (state == S_SEND_AR) ? exu_lsu_res_i : 32'b0;
assign arlen_o   = 4'b0;
assign arsize_o  = (state == S_SEND_AR) ? arsize : 3'b0;
assign arburst_o = (state == S_SEND_AR) ? 2'b01 : 2'b0;
assign arvalid_o = (state == S_SEND_AR);
assign rready_o  = (state == S_GET_R);

always @(posedge clk) begin
    if (rst) begin
        rid_r <= 4'b0;
        rdata_r <= 32'b0;
        bid_r <= 4'b0;
    end else begin
        case (state)    
            S_WAIT_ARB: begin
                if (bg_i) begin
                    if (lsu_re_r) begin
                        perip_difftest_skip(exu_lsu_res_i);
                    end else if (lsu_we_r) begin
                        mem_tracer_write(waddr_aligned, wdata_aligned, {28'b0, wstrb_aligned});
                        perip_difftest_skip(exu_lsu_res_i);
                    end
                end
            end
            S_GET_R: begin
                if (rvalid_i & rready_o & rlast_i) begin
                    mem_tracer_read(exu_lsu_res_i, rdata_i, 32'b0);
                    rid_r                <= rid_i;
                    rdata_r              <= rdata_i;
                    if (rresp_i != 2'b00) begin
                        $display("LSU rresp: %d\n", rresp_i);
                        if (rresp_i == 2'b11) $fatal;
                    end
                end
            end
            S_GET_B: begin
                if (bvalid_i & bready_o) begin
                    bid_r                <= bid_i;
                    if (bresp_i != 2'b00) begin
                        $display("LSU bresp: %d\n", rresp_i);
                        if (bresp_i == 2'b11) $fatal;
                    end
                end
            end
            default: begin
                rid_r <= 4'b0;
                rdata_r <= 32'b0;
                bid_r <= 4'b0;
            end
        endcase
    end
end

assign exu_lsu_ready_o = lsu_wbu_valid_o & lsu_wbu_ready_i;
assign lsu_wbu_valid_o = (state == S_WAIT_WBU);

localparam S_IDLE     = 3'd0;
localparam S_WAIT_ARB = 3'd1;
localparam S_SEND_AR  = 3'd2;
localparam S_GET_R    = 3'd3;
localparam S_W_SEND   = 3'd4;
localparam S_GET_B    = 3'd6;
localparam S_WAIT_WBU = 3'd7;

reg [2:0] state;

always @(posedge clk) begin
    case (state)
        S_IDLE: begin
            if (exu_lsu_valid_i) begin
                if (lsu_re_r | lsu_we_r) begin
                    state <= S_WAIT_ARB;
                end else begin
                    state <= S_WAIT_WBU;
                end
            end
        end
        S_WAIT_ARB: begin
            if (bg_i) begin
                state <= S_SEND_AR & {3{lsu_re_r}} | S_W_SEND & {3{lsu_we_r}};
            end
        end
        S_SEND_AR: begin
            if (arvalid_o & arready_i) begin
                state <= S_GET_R;
            end
        end
        S_GET_R: begin
            if (rvalid_i & rready_o & rlast_i) begin
                state <= S_WAIT_WBU;
            end
        end
        S_W_SEND: begin
            if (aw_handshake_r & w_handshake_r & wlast_o) begin
                state <= S_GET_B;
            end
        end
        S_GET_B: begin
            if (bvalid_i & bready_o) begin
                state <= S_WAIT_WBU;
            end
        end
        S_WAIT_WBU: begin
            if (lsu_wbu_valid_o & lsu_wbu_ready_i) begin
                state <= S_IDLE;
            end
        end
        default: begin
            state <= S_IDLE;
        end
    endcase
end

reg     [1:0]   byte_off_r;
wire    [7:0]   data_b;
wire    [15:0]  data_h;
wire    [2:0]   arsize;
wire    [2:0]   awsize;
wire    [31:0]  waddr_aligned;
wire    [1:0]   w_byte_off;
reg     [31:0]  wdata_aligned;
reg     [3:0]   wstrb_aligned;

assign byte_off_r = exu_lsu_res_i[1:0];
assign data_b = {8{byte_off_r == 2'b00}} & rdata_r[7:0]  |
                {8{byte_off_r == 2'b01}} & rdata_r[15:8] |
                {8{byte_off_r == 2'b10}} & rdata_r[23:16]|
                {8{byte_off_r == 2'b11}} & rdata_r[31:24];
assign data_h = byte_off_r[1] == 1'b0 ? rdata_r[15:0] : rdata_r[31:16];
assign lsu_wbu_rdata_o =   {32{lsu_r_func_r == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LW}}  & rdata_r;

assign arsize = (lsu_r_func_r == `MEM_READ_FUNC_LBU) ? 3'b000 :
                (lsu_r_func_r == `MEM_READ_FUNC_LB) ? 3'b000 :
                (lsu_r_func_r == `MEM_READ_FUNC_LHU) ? 3'b001 :
                (lsu_r_func_r == `MEM_READ_FUNC_LH) ? 3'b001 :
                3'b010;

assign awsize = (lsu_w_mask_r == 4'b0001) ? 3'b000 :
                (lsu_w_mask_r == 4'b0011) ? 3'b001 :
                3'b010;
assign waddr_aligned = {exu_lsu_res_i[31:2], 2'b00};
assign w_byte_off = exu_lsu_res_i[1:0];
assign wdata_aligned =  {32{w_byte_off == 2'b00}} & exu_lsu_gpr_rdata_i[63-:32]      |
                        {32{w_byte_off == 2'b01}} & exu_lsu_gpr_rdata_i[63-:32] << 8 |
                        {32{w_byte_off == 2'b10}} & exu_lsu_gpr_rdata_i[63-:32] << 16|
                        {32{w_byte_off == 2'b11}} & exu_lsu_gpr_rdata_i[63-:32] << 24;
assign wstrb_aligned = lsu_w_mask_r << w_byte_off;

`ifdef FOR_SIMULATION_ENV
assign target_pc_o = target_pc_i;

export "DPI-C" function lsu_w_call;
function int lsu_w_call();
    if (state == S_IDLE && exu_lsu_valid_i && lsu_we_r) return 1;
    else return 0;
endfunction

export "DPI-C" function lsu_r_call;
function int lsu_r_call();
    if (state == S_IDLE && exu_lsu_valid_i && lsu_re_r) return 1;
    else return 0;
endfunction

export "DPI-C" function lsu_commit;
function int lsu_commit();
    if (exu_lsu_valid_i & state == S_IDLE) return 1;
    else return 0;
endfunction
`endif

endmodule
