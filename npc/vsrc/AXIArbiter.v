module AXIArbiter(
    input               clk,
    input               rstn,

    input       [31:0]  m0_araddr,
    input               m0_arvalid,
    output  reg         m0_arready,
    output  reg [31:0]  m0_rdata,
    output  reg [1:0]   m0_rresp,
    output  reg         m0_rvalid,
    input               m0_rready,
    input       [31:0]  m0_awaddr,
    input               m0_awvalid,
    output  reg         m0_awready,
    input       [31:0]  m0_wdata,
    input       [3:0]   m0_wstrb,
    input               m0_wvalid,
    output  reg         m0_wready,
    output  reg [1:0]   m0_bresp,
    output  reg         m0_bvalid,
    input               m0_bready,

    input       [31:0]  m1_araddr,
    input               m1_arvalid,
    output  reg         m1_arready,
    output  reg [31:0]  m1_rdata,
    output  reg [1:0]   m1_rresp,
    output  reg         m1_rvalid,
    input               m1_rready,
    input       [31:0]  m1_awaddr,
    input               m1_awvalid,
    output  reg         m1_awready,
    input       [31:0]  m1_wdata,
    input       [3:0]   m1_wstrb,
    input               m1_wvalid,
    output  reg         m1_wready,
    output  reg [1:0]   m1_bresp,
    output  reg         m1_bvalid,
    input               m1_bready,

    output  reg [31:0]  s_araddr,
    output  reg         s_arvalid,
    input               s_arready,
    input       [31:0]  s_rdata,
    input       [1:0]   s_rresp,
    input               s_rvalid,
    output  reg         s_rready,
    output  reg [31:0]  s_awaddr,
    output  reg         s_awvalid,
    input               s_awready,
    output  reg [31:0]  s_wdata,
    output  reg [3:0]   s_wstrb,
    output  reg         s_wvalid,
    input               s_wready,
    input       [1:0]   s_bresp,
    input               s_bvalid,
    output  reg         s_bready

    // output  reg [31:0]  s1_araddr,
    // output  reg         s1_arvalid,
    // input               s1_arready,
    // input       [31:0]  s1_rdata,
    // input       [1:0]   s1_rresp,
    // input               s1_rvalid,
    // output  reg         s1_rready,
    // output  reg [31:0]  s1_awaddr,
    // output  reg         s1_awvalid,
    // input               s1_awready,
    // output  reg [31:0]  s1_wdata,
    // output  reg [3:0]   s1_wstrb,
    // output  reg         s1_wvalid,
    // input               s1_wready,
    // input       [1:0]   s1_bresp,
    // input               s1_bvalid,
    // output  reg         s1_bready
);

// parameter DEVICE_BASE = 32'ha0000000;
// parameter SERIAL_PORT = DEVICE_BASE + 32'h00003f8;

parameter S_IDLE = 1'b0;
parameter S_BUSY = 1'b1;

reg state;
reg cur_master;
// reg cur_slave;

always @(posedge clk) begin
    if (!rstn) begin
        state      <= S_IDLE;
        cur_master <= 0;
        // cur_slave  <= 0;
    end
    else begin
        case (state)
            S_IDLE: begin
                if (m0_arvalid || m0_awvalid) begin
                    cur_master <= 0;
                    // if (m0_arvalid) begin
                    //     cur_slave <= ((32'h10000000 <= m0_araddr) & (m0_araddr <= 32'h10000fff)) ? 1 : 0;
                    // end else begin
                    //     cur_slave <= ((32'h10000000 <= m0_awaddr) & (m0_awaddr <= 32'h10000fff)) ? 1 : 0;
                    // end
                    state      <= S_BUSY;
                end
                else if (m1_arvalid || m1_awvalid) begin
                    cur_master <= 1;
                    // if (m1_arvalid) begin
                    //     cur_slave <= ((32'h10000000 <= m1_araddr) & (m1_araddr <= 32'h10000fff)) ? 1 : 0;
                    // end else begin
                    //     cur_slave <= ((32'h10000000 <= m1_awaddr) & (m1_awaddr <= 32'h10000fff)) ? 1 : 0;
                    // end
                    state      <= S_BUSY;
                end
            end
            S_BUSY: begin
                // if (((cur_slave == 0) ? s_rvalid : s1_rvalid) && ((cur_master == 0) ? m0_rready : m1_rready)) begin
                if (s_rvalid && ((cur_master == 0) ? m0_rready : m1_rready)) begin
                    state <= S_IDLE;
                // end else if (((cur_slave == 0) ? s_bvalid : s1_bvalid) && ((cur_master == 0) ? m0_bready : m1_bready)) begin
                end else if (s_bvalid && ((cur_master == 0) ? m0_bready : m1_bready)) begin
                    state <= S_IDLE;
                end
            end
        endcase
    end
end

always @(*) begin
    m0_arready = 0;
    m0_rdata   = 0;
    m0_rresp   = 0;
    m0_rvalid  = 0;
    m0_awready = 0;
    m0_wready  = 0;
    m0_bresp   = 0;
    m0_bvalid  = 0;

    m1_arready = 0;
    m1_rdata   = 0;
    m1_rresp   = 0;
    m1_rvalid  = 0;
    m1_awready = 0;
    m1_wready  = 0;
    m1_bresp   = 0;
    m1_bvalid  = 0;

    s_araddr   = 0;
    s_arvalid  = 0;
    s_rready   = 0;
    s_awaddr   = 0;
    s_awvalid  = 0;
    s_wdata    = 0;
    s_wstrb    = 0;
    s_wvalid   = 0;
    s_bready   = 0;

    // s1_araddr   = 0;
    // s1_arvalid  = 0;
    // s1_rready   = 0;
    // s1_awaddr   = 0;
    // s1_awvalid  = 0;
    // s1_wdata    = 0;
    // s1_wstrb    = 0;
    // s1_wvalid   = 0;
    // s1_bready   = 0;

    if (state == S_IDLE) begin
        // if (m0_arvalid || m0_awvalid) begin
        //     if (m0_arvalid) begin
        //         s_araddr   = m0_araddr;
        //         s_arvalid  = 1;
        //         m0_arready = s_arready;
        //     end
        //     if (m0_awvalid) begin
        //         s_awaddr   = m0_awaddr;
        //         s_awvalid  = 1;
        //         m0_awready = s_awready;
        //     end
        //     if (m0_wvalid) begin
        //         s_wdata    = m0_wdata;
        //         s_wstrb    = m0_wstrb;
        //         s_wvalid   = 1;
        //         m0_wready  = s_wready;
        //     end
        // end
        // else if (m1_arvalid || m1_awvalid) begin
        //     if (m1_arvalid) begin
        //         s_araddr   = m1_araddr;
        //         s_arvalid  = 1;
        //         m1_arready = s_arready;
        //     end
        //     if (m1_awvalid) begin
        //         s_awaddr   = m1_awaddr;
        //         s_awvalid  = 1;
        //         m1_awready = s_awready;
        //     end
        //     if (m1_wvalid) begin
        //         s_wdata    = m1_wdata;
        //         s_wstrb    = m1_wstrb;
        //         s_wvalid   = 1;
        //         m1_wready  = s_wready;
        //     end
        // end
    end
    else begin
        if (cur_master == 0) begin
            m0_arready = s_arready;
            m0_rdata   = s_rdata;
            m0_rresp   = s_rresp;
            m0_rvalid  = s_rvalid;
            m0_awready = s_awready;
            m0_wready  = s_wready;
            m0_bresp   = s_bresp;
            m0_bvalid  = s_bvalid;

            s_araddr   = m0_araddr;
            s_arvalid  = m0_arvalid;
            s_awaddr   = m0_awaddr;
            s_awvalid  = m0_awvalid;
            s_wdata    = m0_wdata;
            s_wstrb    = m0_wstrb;
            s_wvalid   = m0_wvalid;
            s_rready   = m0_rready;
            s_bready   = m0_bready;
        end
        else begin
            m1_arready = s_arready;
            m1_rdata   = s_rdata;
            m1_rresp   = s_rresp;
            m1_rvalid  = s_rvalid;
            m1_awready = s_awready;
            m1_wready  = s_wready;
            m1_bresp   = s_bresp;
            m1_bvalid  = s_bvalid;

            s_araddr   = m1_araddr;
            s_arvalid  = m1_arvalid;
            s_awaddr   = m1_awaddr;
            s_awvalid  = m1_awvalid;
            s_wdata    = m1_wdata;
            s_wstrb    = m1_wstrb;
            s_wvalid   = m1_wvalid;
            s_rready   = m1_rready;
            s_bready   = m1_bready;
        end
    end
end

endmodule
