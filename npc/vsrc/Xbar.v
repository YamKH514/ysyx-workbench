`define DEVICE_BASE 32'h02000000
`define RTC_ADDR    (`DEVICE_BASE + 32'h0000048)

module Xbar(
    input               clk,
    input               rst,

    input       [3:0]   m_arid,
    input       [31:0]  m_araddr,
    input       [3:0]   m_arlen,
    input       [2:0]   m_arsize,
    input       [1:0]   m_arburst,
    input               m_arvalid,
    output              m_arready,
    output      [3:0]   m_rid,
    output      [31:0]  m_rdata,
    output      [1:0]   m_rresp,
    output              m_rlast,
    output              m_rvalid,
    input               m_rready,
    input       [3:0]   m_awid,
    input       [31:0]  m_awaddr,
    input       [3:0]   m_awlen,
    input       [2:0]   m_awsize,
    input       [1:0]   m_awburst,
    input               m_awvalid,
    output              m_awready,
    input       [31:0]  m_wdata,
    input       [3:0]   m_wstrb,
    input               m_wlast,
    input               m_wvalid,
    output              m_wready,
    output      [3:0]   m_bid,
    output      [1:0]   m_bresp,
    output              m_bvalid,
    input               m_bready,

    output      [3:0]   s0_arid,
    output      [31:0]  s0_araddr,
    output      [3:0]   s0_arlen,
    output      [2:0]   s0_arsize,
    output      [1:0]   s0_arburst,
    output              s0_arvalid,
    input               s0_arready,
    input       [3:0]   s0_rid,
    input       [31:0]  s0_rdata,
    input       [1:0]   s0_rresp,
    input               s0_rlast,
    input               s0_rvalid,
    output              s0_rready,
    output      [3:0]   s0_awid,
    output      [31:0]  s0_awaddr,
    output      [3:0]   s0_awlen,
    output      [2:0]   s0_awsize,
    output      [1:0]   s0_awburst,
    output              s0_awvalid,
    input               s0_awready,
    output      [31:0]  s0_wdata,
    output      [3:0]   s0_wstrb,
    output              s0_wlast,
    output              s0_wvalid,
    input               s0_wready,
    input       [3:0]   s0_bid,
    input       [1:0]   s0_bresp,
    input               s0_bvalid,
    output              s0_bready,

    output      [3:0]   s1_arid,
    output      [31:0]  s1_araddr,
    output      [3:0]   s1_arlen,
    output      [2:0]   s1_arsize,
    output      [1:0]   s1_arburst,
    output              s1_arvalid,
    input               s1_arready,
    input       [3:0]   s1_rid,
    input       [31:0]  s1_rdata,
    input       [1:0]   s1_rresp,
    input               s1_rlast,
    input               s1_rvalid,
    output              s1_rready,
    output      [3:0]   s1_awid,
    output      [31:0]  s1_awaddr,
    output      [3:0]   s1_awlen,
    output      [2:0]   s1_awsize,
    output      [1:0]   s1_awburst,
    output              s1_awvalid,
    input               s1_awready,
    output      [31:0]  s1_wdata,
    output      [3:0]   s1_wstrb,
    output              s1_wlast,
    output              s1_wvalid,
    input               s1_wready,
    input       [3:0]   s1_bid,
    input       [1:0]   s1_bresp,
    input               s1_bvalid,
    output              s1_bready
);

reg cur_slave_r;
reg cur_slave_w;

localparam S_W = 2;
localparam S_IDLE = 2'd0;
localparam S_BUSY = 2'd1;

reg [S_W-1:0] state_r;
reg [S_W-1:0] state_w;

// Read
always @(posedge clk) begin
    if (rst) begin
        state_r <= S_IDLE;
        cur_slave_r <= 0;
    end else begin
        case (state_r)
            S_IDLE: begin
                if (m_arvalid) begin
                    state_r <= S_BUSY;
                    cur_slave_r <= m_araddr == `RTC_ADDR;
                end else begin
                    state_r <= state_r;
                    cur_slave_r <= cur_slave_r;
                end
            end
            S_BUSY: begin
                if (m_rvalid && m_rready) begin
                    state_r <= S_IDLE;
                    cur_slave_r <= 0;
                end else begin
                    state_r <= state_r;
                    cur_slave_r <= cur_slave_r;
                end
            end
            default: begin
                state_r <= S_IDLE;
                cur_slave_r <= 0;
            end
        endcase
    end
end

// Write
always @(posedge clk) begin
    if (rst) begin
        state_w <= S_IDLE;
        cur_slave_w <= 0;
    end else begin
        case (state_w)
            S_IDLE: begin
                if (m_awvalid) begin
                    state_w <= S_BUSY;
                    cur_slave_w <= m_awaddr == `RTC_ADDR;
                end else begin
                    state_w <= state_w;
                    cur_slave_w <= cur_slave_w;
                end
            end
            S_BUSY: begin
                if (m_bvalid && m_bready) begin
                    state_w <= S_IDLE;
                    cur_slave_w <= 0;
                end else begin
                    state_w <= state_w;
                    cur_slave_w <= cur_slave_w;
                end
            end
            default: begin
                state_w <= S_IDLE;
                cur_slave_w <= 0;
            end
        endcase
    end
end

assign s0_arid    = ({4{(cur_slave_r == 0)}} & m_arid) & {4{(state_r == S_BUSY)}};
assign s1_arid    = ({4{(cur_slave_r == 1)}} & m_arid) & {4{(state_r == S_BUSY)}};
assign s0_araddr  = ({32{(cur_slave_r == 0)}} & m_araddr) & {32{(state_r == S_BUSY)}};
assign s1_araddr  = ({32{(cur_slave_r == 1)}} & m_araddr) & {32{(state_r == S_BUSY)}};
assign s0_arlen   = ({4{(cur_slave_r == 0)}} & m_arlen) & {4{(state_r == S_BUSY)}};
assign s1_arlen   = ({4{(cur_slave_r == 1)}} & m_arlen) & {4{(state_r == S_BUSY)}};
assign s0_arsize  = ({3{(cur_slave_r == 0)}} & m_arsize) & {3{(state_r == S_BUSY)}};
assign s1_arsize  = ({3{(cur_slave_r == 1)}} & m_arsize) & {3{(state_r == S_BUSY)}};
assign s0_arburst = ({2{(cur_slave_r == 0)}} & m_arburst) & {2{(state_r == S_BUSY)}};
assign s1_arburst = ({2{(cur_slave_r == 1)}} & m_arburst) & {2{(state_r == S_BUSY)}};
assign s0_arvalid = ((cur_slave_r == 0) & m_arvalid) & (state_r == S_BUSY);
assign s1_arvalid = ((cur_slave_r == 1) & m_arvalid) & (state_r == S_BUSY);

assign m_arready =  (state_r == S_BUSY) & ((cur_slave_r == 0) ? s0_arready : s1_arready);

assign m_rid     = {4{(state_r == S_BUSY)}} & ((cur_slave_r == 0) ? s0_rid : s1_rid);
assign m_rdata   = {32{(state_r == S_BUSY)}} & ((cur_slave_r == 0) ? s0_rdata : s1_rdata);
assign m_rresp   = {2{(state_r == S_BUSY)}} & ((cur_slave_r == 0) ? s0_rresp : s1_rresp);
assign m_rlast   = (state_r == S_BUSY) & ((cur_slave_r == 0) ? s0_rlast : s1_rlast);
assign m_rvalid  = (state_r == S_BUSY) & ((cur_slave_r == 0) ? s0_rvalid : s1_rvalid);

assign s0_rready = ((cur_slave_r == 0) & m_rready) & (state_r == S_BUSY);
assign s1_rready = ((cur_slave_r == 1) & m_rready) & (state_r == S_BUSY);

assign s0_awid    = ({4{(cur_slave_w == 0)}} & m_awid) & {4{(state_w == S_BUSY)}};
assign s1_awid    = ({4{(cur_slave_w == 1)}} & m_awid) & {4{(state_w == S_BUSY)}};
assign s0_awaddr  = ({32{(cur_slave_w == 0)}} & m_awaddr) & {32{(state_w == S_BUSY)}};
assign s1_awaddr  = ({32{(cur_slave_w == 1)}} & m_awaddr) & {32{(state_w == S_BUSY)}};
assign s0_awlen   = ({4{(cur_slave_w == 0)}} & m_awlen) & {4{(state_w == S_BUSY)}};
assign s1_awlen   = ({4{(cur_slave_w == 1)}} & m_awlen) & {4{(state_w == S_BUSY)}};
assign s0_awsize  = ({3{(cur_slave_w == 0)}} & m_awsize) & {3{(state_w == S_BUSY)}};
assign s1_awsize  = ({3{(cur_slave_w == 1)}} & m_awsize) & {3{(state_w == S_BUSY)}};
assign s0_awburst = ({2{(cur_slave_w == 0)}} & m_awburst) & {2{(state_w == S_BUSY)}};
assign s1_awburst = ({2{(cur_slave_w == 1)}} & m_awburst) & {2{(state_w == S_BUSY)}};
assign s0_awvalid = ((cur_slave_w == 0) & m_awvalid) & (state_w == S_BUSY);
assign s1_awvalid = ((cur_slave_w == 1) & m_awvalid) & (state_w == S_BUSY);

assign m_awready = (state_w == S_BUSY) & ((cur_slave_w == 0) ? s0_awready : s1_awready);

assign m_wready  = (state_w == S_BUSY) & ((cur_slave_w == 0) ? s0_wready : s1_wready);
assign m_bid     = {4{(state_w == S_BUSY)}} & ((cur_slave_w == 0) ? s0_bid : s1_bid);
assign m_bresp   = {2{(state_w == S_BUSY)}} & ((cur_slave_w == 0) ? s0_bresp : s1_bresp);
assign m_bvalid  = (state_w == S_BUSY) & ((cur_slave_w == 0) ? s0_bvalid : s1_bvalid);

assign s0_wdata  = ({32{(cur_slave_w == 0)}} & m_wdata) & {32{(state_w == S_BUSY)}};
assign s0_wstrb  = ({4{(cur_slave_w == 0)}} & m_wstrb) & {4{(state_w == S_BUSY)}};
assign s0_wlast  = ((cur_slave_w == 0) & m_wlast) & (state_w == S_BUSY);
assign s0_wvalid = ((cur_slave_w == 0) & m_wvalid) & (state_w == S_BUSY);
assign s0_bready = ((cur_slave_w == 0) & m_bready) & (state_w == S_BUSY);
assign s1_wdata  = ({32{(cur_slave_w == 1)}} & m_wdata) & {32{(state_w == S_BUSY)}};
assign s1_wstrb  = ({4{(cur_slave_w == 1)}} & m_wstrb) & {4{(state_w == S_BUSY)}};
assign s1_wlast  = ((cur_slave_w == 1) & m_wlast) & (state_w == S_BUSY);
assign s1_wvalid = ((cur_slave_w == 1) & m_wvalid) & (state_w == S_BUSY);
assign s1_bready = ((cur_slave_w == 1) & m_bready) & (state_w == S_BUSY);

endmodule
