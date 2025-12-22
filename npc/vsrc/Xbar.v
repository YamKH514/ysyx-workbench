`define DEVICE_BASE 32'ha0000000
`define SERIAL_PORT (`DEVICE_BASE + 32'h00003f8)
`define RTC_ADDR    (`DEVICE_BASE + 32'h0000048)

module Xbar(
    input               clk,
    input               rstn,

    input       [3:0]   m_arid,
    input       [31:0]  m_araddr,
    input       [3:0]   m_arlen,
    input       [2:0]   m_arsize,
    input       [1:0]   m_arburst,
    input               m_arvalid,
    output reg          m_arready,
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
    output reg          m_awready,
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
    output reg          s0_arvalid,
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
    output reg          s0_awvalid,
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
    output reg          s1_arvalid,
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
    output reg          s1_awvalid,
    input               s1_awready,
    output      [31:0]  s1_wdata,
    output      [3:0]   s1_wstrb,
    output              s1_wlast,
    output              s1_wvalid,
    input               s1_wready,
    input       [3:0]   s1_bid,
    input       [1:0]   s1_bresp,
    input               s1_bvalid,
    output              s1_bready,

    output      [3:0]   s2_arid,
    output      [31:0]  s2_araddr,
    output      [3:0]   s2_arlen,
    output      [2:0]   s2_arsize,
    output      [1:0]   s2_arburst,
    output reg          s2_arvalid,
    input               s2_arready,
    input       [3:0]   s2_rid,
    input       [31:0]  s2_rdata,
    input       [1:0]   s2_rresp,
    input               s2_rlast,
    input               s2_rvalid,
    output              s2_rready,
    output      [3:0]   s2_awid,
    output      [31:0]  s2_awaddr,
    output      [3:0]   s2_awlen,
    output      [2:0]   s2_awsize,
    output      [1:0]   s2_awburst,
    output reg          s2_awvalid,
    input               s2_awready,
    output      [31:0]  s2_wdata,
    output      [3:0]   s2_wstrb,
    output              s2_wlast,
    output              s2_wvalid,
    input               s2_wready,
    input       [3:0]   s2_bid,
    input       [1:0]   s2_bresp,
    input               s2_bvalid,
    output              s2_bready
);

parameter S_IDLE = 2'd0;
parameter S_SEL  = 2'd1;
parameter S_CNT  = 2'd2;
parameter S_BUSY = 2'd3;

reg [1:0]   r_state, r_next_state;
reg [1:0]   w_state, w_next_state;

reg [1:0]   cur_slave_r;
reg [1:0]   cur_slave_w;

reg [3:0]   arid_r;
reg [31:0]  araddr_r;
reg [3:0]   arlen_r;
reg [2:0]   arsize_r;
reg [1:0]   arburst_r;
reg [3:0]   awid_r;
reg [31:0]  awaddr_r;
reg [3:0]   awlen_r;
reg [2:0]   awsize_r;
reg [1:0]   awburst_r;

always @(posedge clk) begin
    if (!rstn) begin
        r_state <= S_IDLE;
        w_state <= S_IDLE;
    end else begin
        r_state <= r_next_state;
        w_state <= w_next_state;
    end

    // READ
    if (!rstn) begin
        cur_slave_r <= 2'b0;
        arid_r      <= 4'b0;
        araddr_r    <= 32'b0;
        arlen_r     <= 4'b0;
        arsize_r    <= 3'b0;
        arburst_r   <= 2'b0;
        m_arready   <= 1'b1;
        s0_arvalid  <= 1'b0;
        s1_arvalid  <= 1'b0;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (m_arvalid) begin
                    arid_r      <= m_arid;
                    araddr_r    <= m_araddr;
                    arlen_r     <= m_arlen;
                    arsize_r    <= m_arsize;
                    arburst_r   <= m_arburst;
                    m_arready   <= 1'b0;
                    cur_slave_r <=  (m_araddr == `SERIAL_PORT) ? 2'd0 :
                                    ((m_araddr == `RTC_ADDR) | (m_araddr == `RTC_ADDR + 32'h4)) ? 2'd2 :
                                    2'd1;
                end
            end
            S_SEL: begin
                case (cur_slave_r)
                    2'd0: begin
                        s0_arvalid <= 1'b1;
                        s0_arid    <= arid_r;
                        s0_araddr  <= araddr_r;
                        s0_arlen   <= arlen_r;
                        s0_arsize  <= arsize_r;
                        s0_arburst <= arburst_r;
                    end
                    2'd1: begin
                        s1_arvalid <= 1'b1;
                        s1_arid    <= arid_r;
                        s1_araddr  <= araddr_r;
                        s1_arlen   <= arlen_r;
                        s1_arsize  <= arsize_r;
                        s1_arburst <= arburst_r;
                    end
                    2'd2: begin
                        s2_arvalid <= 1'b1;
                        s2_arid    <= arid_r;
                        s2_araddr  <= araddr_r;
                        s2_arlen   <= arlen_r;
                        s2_arsize  <= arsize_r;
                        s2_arburst <= arburst_r;
                    end
                    default: begin
                    end
                endcase
            end
            S_CNT: begin
                case (cur_slave_r)
                    2'd0: begin
                        if (s0_arready) s0_arvalid <= 1'b0;
                    end
                    2'd1: begin
                        if (s1_arready) s1_arvalid <= 1'b0;
                    end
                    2'd2: begin
                        if (s2_arready) s2_arvalid <= 1'b0;
                    end
                    default: begin
                    end
                endcase
            end
            S_BUSY: begin
                case (cur_slave_r)
                    2'd0: begin
                        if (s0_rvalid & s0_rready) m_arready <= 1'b1;
                    end
                    2'd1: begin
                        if (s1_rvalid & s1_rready) m_arready <= 1'b1;
                    end
                    2'd2: begin
                        if (s2_rvalid & s2_rready) m_arready <= 1'b1;
                    end
                    default: begin
                    end
                endcase
            end
        endcase
    end

    //WRITE
    if (!rstn) begin
        cur_slave_w <= 2'b0;
        awid_r      <= 4'b0;
        awaddr_r    <= 32'b0;
        awlen_r     <= 4'b0;
        awsize_r    <= 3'b0;
        awburst_r   <= 2'b0;
        m_awready   <= 1'b1;
        s0_awvalid  <= 1'b0;
        s1_awvalid  <= 1'b0;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (m_awvalid) begin
                    arid_r      <= m_awid;
                    araddr_r    <= m_awaddr;
                    arlen_r     <= m_awlen;
                    arsize_r    <= m_awsize;
                    arburst_r   <= m_awburst;
                    m_awready   <= 1'b0;
                    cur_slave_w <=  (m_awaddr == `SERIAL_PORT) ? 2'd0 :
                                    ((m_awaddr == `RTC_ADDR) | (m_awaddr == `RTC_ADDR + 32'h4)) ? 2'd2 :
                                    2'd1;
                end
            end
            S_SEL: begin
                case (cur_slave_w)
                    2'd0: begin
                        s0_awvalid <= 1'b1;
                        s0_awid    <= awid_r;
                        s0_awaddr  <= awaddr_r;
                        s0_awlen   <= awlen_r;
                        s0_awsize  <= awsize_r;
                        s0_awburst <= awburst_r;
                    end
                    2'd1: begin
                        s1_awvalid <= 1'b1;
                        s1_awid    <= awid_r;
                        s1_awaddr  <= awaddr_r;
                        s1_awlen   <= awlen_r;
                        s1_awsize  <= awsize_r;
                        s1_awburst <= awburst_r;
                    end
                    2'd2: begin
                        s2_awvalid <= 1'b1;
                        s2_awid    <= awid_r;
                        s2_awaddr  <= awaddr_r;
                        s2_awlen   <= awlen_r;
                        s2_awsize  <= awsize_r;
                        s2_awburst <= awburst_r;
                    end
                    default: begin
                    end
                endcase
            end
            S_CNT: begin
                case (cur_slave_w)
                    2'd0: begin
                        if (s0_awready) s0_awvalid <= 1'b0;
                    end
                    2'd1: begin
                        if (s1_awready) s1_awvalid <= 1'b0;
                    end
                    2'd2: begin
                        if (s2_awready) s2_awvalid <= 1'b0;
                    end
                    default: begin
                    end
                endcase
            end
            S_BUSY: begin
                case (cur_slave_w)
                    2'd0: begin
                        if (s0_bvalid & s0_bready) m_awready <= 1'b1;
                    end
                    2'd1: begin
                        if (s1_bvalid & s1_bready) m_awready <= 1'b1;
                    end
                    2'd2: begin
                        if (s2_bvalid & s2_bready) m_awready <= 1'b1;
                    end
                    default: begin
                    end
                endcase
            end
        endcase
    end
end

always @(*) begin
    r_next_state = r_state;
    w_next_state = w_state;

    // READ
    case (r_state)
        S_IDLE: begin
            if (m_arvalid) begin
                r_next_state = S_SEL;
            end
        end
        S_SEL: begin
            r_next_state = S_CNT;
        end
        S_CNT: begin
            if (((cur_slave_r == 2'd0) & s0_arready) | ((cur_slave_r == 2'd1) & s1_arready) | ((cur_slave_r == 2'd2) & s2_arready)) begin
                r_next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (((cur_slave_r == 2'd0) & s0_rvalid & s0_rready) | ((cur_slave_r == 2'd1) & s1_rvalid & s1_rready) | ((cur_slave_r == 2'd2) & s2_rvalid & s2_rready)) begin
                r_next_state = S_IDLE;
            end
        end
    endcase

    //WRITE
    case (w_state)
        S_IDLE: begin
            if (m_awvalid) begin
                w_next_state = S_SEL;
            end
        end
        S_SEL: begin
            w_next_state = S_CNT;
        end
        S_CNT: begin
            if (((cur_slave_w == 2'd0) & s0_awready) | ((cur_slave_w == 2'd1) & s1_awready) | ((cur_slave_w == 2'd2) & s2_awready)) begin
                w_next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (((cur_slave_w == 2'd0) & s0_bvalid & s0_bready) | ((cur_slave_w == 2'd1) & s1_bvalid & s1_bready) | ((cur_slave_w == 2'd2) & s2_bvalid & s2_bready)) begin
                w_next_state = S_IDLE;
            end
        end
    endcase
end

assign m_rid     =  {4{(r_state == S_BUSY)}} & ((cur_slave_r == 2'd0) ? s0_rid :
                                                (cur_slave_r == 2'd1) ? s1_rid :
                                                s2_rid);
assign m_rdata   = {32{(r_state == S_BUSY)}} & ((cur_slave_r == 2'd0) ? s0_rdata :
                                                (cur_slave_r == 2'd1) ? s1_rdata :
                                                s2_rdata);
assign m_rresp   = {2{(r_state == S_BUSY)}}  & ((cur_slave_r == 2'd0) ? s0_rresp :
                                                (cur_slave_r == 2'd1) ? s1_rresp :
                                                s2_rresp);
assign m_rlast   =    (r_state == S_BUSY)    & ((cur_slave_r == 2'd0) ? s0_rlast :
                                                (cur_slave_r == 2'd1) ? s1_rlast :
                                                s2_rlast);
assign m_rvalid  =    (r_state == S_BUSY)    & ((cur_slave_r == 2'd0) ? s0_rvalid :
                                                (cur_slave_r == 2'd1) ? s1_rvalid :
                                                s2_rvalid);

assign s0_rready = ((cur_slave_r == 2'd0) & m_rready) & (r_state == S_BUSY);
assign s1_rready = ((cur_slave_r == 2'd1) & m_rready) & (r_state == S_BUSY);
assign s2_rready = ((cur_slave_r == 2'd2) & m_rready) & (r_state == S_BUSY);

assign m_wready  =    (w_state == S_BUSY)   &  ((cur_slave_w == 2'd0) ? s0_wready :
                                                (cur_slave_w == 2'd1) ? s1_wready :
                                                s2_wready);
assign m_bid     = {4{(w_state == S_BUSY)}} &  ((cur_slave_w == 2'd0) ? s0_bid :
                                                (cur_slave_w == 2'd1) ? s1_bid :
                                                s2_bid);
assign m_bresp   = {2{(w_state == S_BUSY)}} &  ((cur_slave_w == 2'd0) ? s0_bresp :
                                                (cur_slave_w == 2'd1) ? s1_bresp :
                                                s2_bresp);
assign m_bvalid  =    (w_state == S_BUSY)   &  ((cur_slave_w == 2'd0) ? s0_bvalid :
                                                (cur_slave_w == 2'd1) ? s1_bvalid :
                                                s2_bvalid);

assign s0_wdata  = ({32{(cur_slave_w == 2'd0)}} & m_wdata) & {32{(w_state == S_BUSY)}};
assign s0_wstrb  = ({4{(cur_slave_w == 2'd0)}} & m_wstrb) & {4{(w_state == S_BUSY)}};
assign s0_wlast  = ((cur_slave_w == 2'd0) & m_wlast) & (w_state == S_BUSY);
assign s0_wvalid = ((cur_slave_w == 2'd0) & m_wvalid) & (w_state == S_BUSY);
assign s0_bready = ((cur_slave_w == 2'd0) & m_bready) & (w_state == S_BUSY);
assign s1_wdata  = ({32{(cur_slave_w == 2'd1)}} & m_wdata) & {32{(w_state == S_BUSY)}};
assign s1_wstrb  = ({4{(cur_slave_w == 2'd1)}} & m_wstrb) & {4{(w_state == S_BUSY)}};
assign s1_wlast  = ((cur_slave_w == 2'd1) & m_wlast) & (w_state == S_BUSY);
assign s1_wvalid = ((cur_slave_w == 2'd1) & m_wvalid) & (w_state == S_BUSY);
assign s1_bready = ((cur_slave_w == 2'd1) & m_bready) & (w_state == S_BUSY);
assign s2_wdata  = ({32{(cur_slave_w == 2'd2)}} & m_wdata) & {32{(w_state == S_BUSY)}};
assign s2_wstrb  = ({4{(cur_slave_w == 2'd2)}} & m_wstrb) & {4{(w_state == S_BUSY)}};
assign s2_wlast  = ((cur_slave_w == 2'd2) & m_wlast) & (w_state == S_BUSY);
assign s2_wvalid = ((cur_slave_w == 2'd2) & m_wvalid) & (w_state == S_BUSY);
assign s2_bready = ((cur_slave_w == 2'd2) & m_bready) & (w_state == S_BUSY);

endmodule
