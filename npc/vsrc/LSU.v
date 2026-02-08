`include "common.vh"

module LSU(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    // idu_to_lsu_data lsu_r_func[8:6], lsu_re[5], lsu_w_mask[4:1], lsu_we[0]
    input       [8:0]   idu_to_lsu_data_in,
    input       [31:0]  lsu_r_addr_in,
    output  reg [31:0]  lsu_r_data_out,
    input       [31:0]  lsu_w_addr_in,
    input       [31:0]  lsu_w_data_in,

    // AR
    output      [3:0]   arid_out,
    output      [31:0]  araddr_out,
    output      [3:0]   arlen_out,
    output      [2:0]   arsize_out,
    output      [1:0]   arburst_out,
    output              arvalid_out,
    input               arready_in,

    // R
    input       [3:0]   rid_in,
    input       [31:0]  rdata_in,
    input       [1:0]   rresp_in,
    input               rlast_in,
    input               rvalid_in,
    output              rready_out,

    // AW
    output      [3:0]   awid_out,
    output      [31:0]  awaddr_out,
    output      [3:0]   awlen_out,
    output      [2:0]   awsize_out,
    output      [1:0]   awburst_out,
    output              awvalid_out,
    input               awready_in,

    // W
    output      [31:0]  wdata_out,
    output      [3:0]   wstrb_out,
    output              wlast_out,
    output              wvalid_out,
    input               wready_in,

    // B
    input       [3:0]   bid_in,
    input       [1:0]   bresp_in,
    input               bvalid_in,
    output              bready_out,

    input               exu_to_lsu_valid_in,
    output  reg         lsu_to_exu_ready_out,

    output  reg         lsu_to_wbu_valid_out,
    input               wbu_to_lsu_ready_in,

    output              bs_out,
    output              br_out,
    input               bg_in
);

import "DPI-C" function void mem_tracer_read(input int addr,input int data);
import "DPI-C" function void mem_tracer_write(input int addr,input int data);
import "DPI-C" function void perip_difftest_skip(input int addr);

reg [2:0]   lsu_r_func_r;
reg         lsu_re_r;
wire    [3:0]   lsu_w_mask_r;
wire            lsu_we_r;
assign {lsu_r_func_r, lsu_re_r, lsu_w_mask_r, lsu_we_r} = idu_to_lsu_data_in;

localparam S_IDLE     = 3'd0;
localparam S_WAIT_ARB = 3'd1;
localparam S_SEND_AR  = 3'd2;
localparam S_GET_R    = 3'd3;
localparam S_W_SEND   = 3'd4;
localparam S_GET_B    = 3'd6;
localparam S_WAIT_WBU = 3'd7;

reg [2:0] state;

reg         aw_handshake_r;
reg         w_handshake_r;
reg [3:0]   rid_r;
reg [31:0]  rdata_r;
reg [3:0]   bid_r;

assign br_out = state == S_WAIT_ARB;
assign bs_out = state == S_SEND_AR |
                state == S_GET_R   |
                state == S_W_SEND  |
                state == S_GET_B;

always @(posedge clk) begin
    if (rst) begin
        aw_handshake_r <= 0;
    end else if (state == S_W_SEND && awvalid_out && awready_in) begin
        aw_handshake_r <= 1;
    end else if (state != S_W_SEND) begin
        aw_handshake_r <= 0;
    end
end

always @(posedge clk) begin
    if (rst) begin
        w_handshake_r <= 0;
    end else if (state == S_W_SEND && wvalid_out && wready_in) begin
        w_handshake_r <= 1;
    end else if (state !=S_W_SEND) begin
        w_handshake_r <= 0;
    end
end

assign awid_out    = 4'b0;
assign awaddr_out  = (state == S_W_SEND) ? lsu_w_addr_in : 32'd0;
assign awlen_out   = 4'b0;
assign awsize_out  = (state == S_W_SEND) ? awsize : 3'd0;
assign awburst_out = (state == S_W_SEND) ? 2'b01 : 2'd0;
assign awvalid_out = (state == S_W_SEND) & !aw_handshake_r;
assign wdata_out   = (state == S_W_SEND) ? wdata_aligned : 32'd0;
assign wstrb_out   = (state == S_W_SEND) ? wstrb_aligned : 4'd0;
assign wlast_out   = (state == S_W_SEND);
assign wvalid_out  = (state == S_W_SEND) & !w_handshake_r;
assign bready_out  = (state == S_GET_B) & bvalid_in;

assign arid_out    = 4'b0;
assign araddr_out  = (state == S_SEND_AR) ? lsu_r_addr_in : 32'b0;
assign arlen_out   = 4'b0;
assign arsize_out  = (state == S_SEND_AR) ? arsize : 3'b0;
assign arburst_out = (state == S_SEND_AR) ? 2'b01 : 2'b0;
assign arvalid_out = (state == S_SEND_AR);
assign rready_out  = (state == S_GET_R);

always @(posedge clk) begin
    if (rst) begin
        lsu_to_exu_ready_out <= 1'b0;
        lsu_to_wbu_valid_out <= 1'b0;
    end else begin
        case (state)    
            S_IDLE: begin
                if (exu_to_lsu_valid_in) begin
                    lsu_to_exu_ready_out <= 1'b1;
                    if (!(lsu_re_r | lsu_we_r)) begin
                        lsu_to_wbu_valid_out <= 1'b1;
                    end
                end
            end
            S_WAIT_ARB: begin
                if (bg_in) begin
                    if (lsu_re_r) begin
                        perip_difftest_skip(lsu_r_addr_in);
                    end else if (lsu_we_r) begin
                        mem_tracer_write(lsu_w_addr_in, lsu_w_data_in);
                        perip_difftest_skip(lsu_w_addr_in);
                    end
                end
            end
            S_GET_R: begin
                if (rvalid_in & rready_out & rlast_in) begin
                    mem_tracer_read(lsu_r_addr_in, rdata_in);
                    rid_r                <= rid_in;
                    rdata_r              <= rdata_in;
                    if (rresp_in != 2'b00) begin
                        $display("LSU rresp: %d\n", rresp_in);
                        if (rresp_in == 2'b11) $fatal;
                    end
                    lsu_to_wbu_valid_out <= 1'b1;
                end
            end
            S_GET_B: begin
                if (bvalid_in & bready_out) begin
                    bid_r                <= bid_in;
                    if (bresp_in != 2'b00) begin
                        $display("LSU bresp: %d\n", rresp_in);
                        if (bresp_in == 2'b11) $fatal;
                    end
                    lsu_to_wbu_valid_out <= 1'b1;
                end
            end
            S_WAIT_WBU: begin
                if (wbu_to_lsu_ready_in) begin
                    lsu_to_wbu_valid_out <= 1'b0;
                end
            end
            default: begin
                lsu_to_exu_ready_out <= 1'b0;
                lsu_to_wbu_valid_out <= 1'b0;
            end
        endcase
    end
end

always @(posedge clk) begin
    case (state)
        S_IDLE: begin
            if (exu_to_lsu_valid_in) begin
                if (lsu_re_r | lsu_we_r) begin
                    state <= S_WAIT_ARB;
                end else begin
                    state <= S_WAIT_WBU;
                end
            end
        end
        S_WAIT_ARB: begin
            if (bg_in) begin
                state <= S_SEND_AR & {3{lsu_re_r}} | S_W_SEND & {3{lsu_we_r}};
            end
        end
        S_SEND_AR: begin
            if (arvalid_out & arready_in) begin
                state <= S_GET_R;
            end
        end
        S_GET_R: begin
            if (rvalid_in & rready_out & rlast_in) begin
                state <= S_WAIT_WBU;
            end
        end
        S_W_SEND: begin
            if (aw_handshake_r & w_handshake_r & wlast_out) begin
                state <= S_GET_B;
            end
        end
        S_GET_B: begin
            if (bvalid_in & bready_out) begin
                state <= S_WAIT_WBU;
            end
        end
        S_WAIT_WBU: begin
            if (wbu_to_lsu_ready_in) begin
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

assign byte_off_r = lsu_r_addr_in[1:0];
assign data_b = {8{byte_off_r == 2'b00}} & rdata_r[7:0]  |
                {8{byte_off_r == 2'b01}} & rdata_r[15:8] |
                {8{byte_off_r == 2'b10}} & rdata_r[23:16]|
                {8{byte_off_r == 2'b11}} & rdata_r[31:24];
assign data_h = byte_off_r[1] == 1'b0 ? rdata_r[15:0] : rdata_r[31:16];
assign lsu_r_data_out = {32{lsu_r_func_r == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
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
assign waddr_aligned = {lsu_w_addr_in[31:2], 2'b00};
assign w_byte_off = lsu_w_addr_in[1:0];
assign wdata_aligned =  {32{w_byte_off == 2'b00}} & lsu_w_data_in      |
                        {32{w_byte_off == 2'b01}} & lsu_w_data_in << 8 |
                        {32{w_byte_off == 2'b10}} & lsu_w_data_in << 16|
                        {32{w_byte_off == 2'b11}} & lsu_w_data_in << 24;
assign wstrb_aligned = lsu_w_mask_r << w_byte_off;

export "DPI-C" function lsu_w_call;
function int lsu_w_call();
    if (state == S_IDLE && exu_to_lsu_valid_in && lsu_we_r) return 1;
    else return 0;
endfunction

export "DPI-C" function lsu_r_call;
function int lsu_r_call();
    if (state == S_IDLE && exu_to_lsu_valid_in && lsu_re_r) return 1;
    else return 0;
endfunction

endmodule
