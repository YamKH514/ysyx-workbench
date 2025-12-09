module Xbar(
    input               clk,
    input               rstn,

    input       [31:0]  m_araddr,
    input               m_arvalid,
    output  reg         m_arready,
    output  reg [31:0]  m_rdata,
    output  reg [1:0]   m_rresp,
    output  reg         m_rvalid,
    input               m_rready,
    input       [31:0]  m_awaddr,
    input               m_awvalid,
    output  reg         m_awready,
    input       [31:0]  m_wdata,
    input       [3:0]   m_wstrb,
    input               m_wvalid,
    output  reg         m_wready,
    output  reg [1:0]   m_bresp,
    output  reg         m_bvalid,
    input               m_bready,

    output  reg [31:0]  s0_araddr,
    output  reg         s0_arvalid,
    input               s0_arready,
    input       [31:0]  s0_rdata,
    input       [1:0]   s0_rresp,
    input               s0_rvalid,
    output  reg         s0_rready,
    output  reg [31:0]  s0_awaddr,
    output  reg         s0_awvalid,
    input               s0_awready,
    output  reg [31:0]  s0_wdata,
    output  reg [3:0]   s0_wstrb,
    output  reg         s0_wvalid,
    input               s0_wready,
    input       [1:0]   s0_bresp,
    input               s0_bvalid,
    output  reg         s0_bready,

    output  reg [31:0]  s1_araddr,
    output  reg         s1_arvalid,
    input               s1_arready,
    input       [31:0]  s1_rdata,
    input       [1:0]   s1_rresp,
    input               s1_rvalid,
    output  reg         s1_rready,
    output  reg [31:0]  s1_awaddr,
    output  reg         s1_awvalid,
    input               s1_awready,
    output  reg [31:0]  s1_wdata,
    output  reg [3:0]   s1_wstrb,
    output  reg         s1_wvalid,
    input               s1_wready,
    input       [1:0]   s1_bresp,
    input               s1_bvalid,
    output  reg         s1_bready
);
parameter S_IDLE = 1'b0;
parameter S_BUSY = 1'b1;

reg state;
reg cur_slave;

always @(posedge clk) begin
    if (!rstn) begin
        state      <= S_IDLE;
        cur_slave  <= 0;
    end
    else begin
        case (state)
            S_IDLE: begin
                if (m_arvalid || m_awvalid) begin
                    if (m_araddr[31:12] == 20'h10000) begin
                        cur_slave <= 1'b0;
                    end else if (m_araddr[31:24] == 8'h80) begin
                        cur_slave <= 1'b1;
                    end
                    state  <= S_BUSY;
                end
            end
            S_BUSY: begin
                if (((cur_slave == 0) ? s0_rvalid : s1_rvalid) && m_rready) begin
                    state <= S_IDLE;
                end else if (((cur_slave == 0) ? s0_bvalid : s1_bvalid) && m_rready) begin
                    state <= S_IDLE;
                end
            end
        endcase
    end
end

always @(*) begin
    m_arready  = 0;
    m_rdata    = 0;
    m_rresp    = 0;
    m_rvalid   = 0;
    m_awready  = 0;
    m_wready   = 0;
    m_bresp    = 0;
    m_bvalid   = 0;

    s0_araddr  = 0;
    s0_arvalid = 0;
    s0_rready  = 0;
    s0_awaddr  = 0;
    s0_awvalid = 0;
    s0_wdata   = 0;
    s0_wstrb   = 0;
    s0_wvalid  = 0;
    s0_bready  = 0;

    s1_araddr  = 0;
    s1_arvalid = 0;
    s1_rready  = 0;
    s1_awaddr  = 0;
    s1_awvalid = 0;
    s1_wdata   = 0;
    s1_wstrb   = 0;
    s1_wvalid  = 0;
    s1_bready  = 0;

    if (state == S_BUSY) begin
        case (cur_slave)
            1'b0: begin
                m_arready  = s0_arready;
                m_rdata    = s0_rdata;
                m_rresp    = s0_rresp;
                m_rvalid   = s0_rvalid;
                m_awready  = s0_awready;
                m_wready   = s0_wready;
                m_bresp    = s0_bresp;
                m_bvalid   = s0_bvalid;

                s0_araddr  = m_araddr;
                s0_arvalid = m_arvalid;
                s0_awaddr  = m_awaddr;
                s0_awvalid = m_awvalid;
                s0_wdata   = m_wdata;
                s0_wstrb   = m_wstrb;
                s0_wvalid  = m_wvalid;
                s0_rready  = m_rready;
                s0_bready  = m_bready;
            end
            1'b1: begin
                m_arready  = s1_arready;
                m_rdata    = s1_rdata;
                m_rresp    = s1_rresp;
                m_rvalid   = s1_rvalid;
                m_awready  = s1_awready;
                m_wready   = s1_wready;
                m_bresp    = s1_bresp;
                m_bvalid   = s1_bvalid;

                s1_araddr  = m_araddr;
                s1_arvalid = m_arvalid;
                s1_awaddr  = m_awaddr;
                s1_awvalid = m_awvalid;
                s1_wdata   = m_wdata;
                s1_wstrb   = m_wstrb;
                s1_wvalid  = m_wvalid;
                s1_rready  = m_rready;
                s1_bready  = m_bready;
            end
        endcase
    end
end

endmodule
