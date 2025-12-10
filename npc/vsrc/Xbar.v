module Xbar(
    input               clk,
    input               rstn,

    input       [31:0]  m_araddr,
    input               m_arvalid,
    output              m_arready,
    output      [31:0]  m_rdata,
    output      [1:0]   m_rresp,
    output              m_rvalid,
    input               m_rready,
    input       [31:0]  m_awaddr,
    input               m_awvalid,
    output              m_awready,
    input       [31:0]  m_wdata,
    input       [3:0]   m_wstrb,
    input               m_wvalid,
    output              m_wready,
    output      [1:0]   m_bresp,
    output              m_bvalid,
    input               m_bready,

    output      [31:0]  s0_araddr,
    output              s0_arvalid,
    input               s0_arready,
    input       [31:0]  s0_rdata,
    input       [1:0]   s0_rresp,
    input               s0_rvalid,
    output              s0_rready,
    output      [31:0]  s0_awaddr,
    output              s0_awvalid,
    input               s0_awready,
    output      [31:0]  s0_wdata,
    output      [3:0]   s0_wstrb,
    output              s0_wvalid,
    input               s0_wready,
    input       [1:0]   s0_bresp,
    input               s0_bvalid,
    output              s0_bready,

    output      [31:0]  s1_araddr,
    output              s1_arvalid,
    input               s1_arready,
    input       [31:0]  s1_rdata,
    input       [1:0]   s1_rresp,
    input               s1_rvalid,
    output              s1_rready,
    output      [31:0]  s1_awaddr,
    output              s1_awvalid,
    input               s1_awready,
    output      [31:0]  s1_wdata,
    output      [3:0]   s1_wstrb,
    output              s1_wvalid,
    input               s1_wready,
    input       [1:0]   s1_bresp,
    input               s1_bvalid,
    output              s1_bready
);

parameter S_IDLE = 1'b0;
parameter S_BUSY = 1'b1;

reg r_state;
reg w_state;

reg cur_slave_r;
reg cur_slave_w;

reg aw_handshake_done;
reg w_handshake_done;

always @(posedge clk) begin
    // READ
    if(!rstn) begin
        r_state <= S_IDLE;
        cur_slave_r <= 0;
    end else begin
        case(r_state)
            S_IDLE: begin
                if(m_arvalid) begin
                    cur_slave_r <= (m_araddr[31:24]==8'h80) ? 1'b1 : 1'b0;
                    r_state <= S_BUSY;
                end
            end
            S_BUSY: begin
                if(m_rready && ((cur_slave_r==0) ? s0_rvalid : s1_rvalid))
                    r_state <= S_IDLE;
            end
        endcase
    end

    // WRITE
    if(!rstn) begin
        w_state <= S_IDLE;
        cur_slave_w <= 0;
        aw_handshake_done <= 0;
        w_handshake_done  <= 0;
    end else begin
        case(w_state)
            S_IDLE: begin
                if(m_awvalid || m_wvalid) begin
                    cur_slave_w <= (m_awaddr[31:24]==8'h80) ? 1'b1 : 1'b0;
                    aw_handshake_done <= 0;
                    w_handshake_done  <= 0;
                    w_state <= S_BUSY;
                end
            end
            S_BUSY: begin
                if(cur_slave_w==0) begin
                    if(s0_awready && m_awvalid) aw_handshake_done <= 1;
                    if(s0_wready  && m_wvalid)  w_handshake_done  <= 1;
                    if(aw_handshake_done && w_handshake_done && s0_bvalid && m_bready)
                        w_state <= S_IDLE;
                end else begin
                    $display("UART");
                    if(s1_awready && m_awvalid) aw_handshake_done <= 1;
                    if(s1_wready  && m_wvalid)  w_handshake_done  <= 1;
                    if(aw_handshake_done && w_handshake_done && s1_bvalid && m_bready)
                        w_state <= S_IDLE;
                end
            end
        endcase
    end
end

    // READ
    assign m_arready  = r_state & ((cur_slave_r) ? s1_arready : s0_arready);
    assign m_rdata    = {32{r_state}} & ((cur_slave_r) ? s1_rdata : s0_rdata);
    assign m_rresp    = {2{r_state}} & ((cur_slave_r) ? s1_rresp : s0_rresp);
    assign m_rvalid   = r_state & ((cur_slave_r) ? s1_rvalid : s0_rvalid);
    assign s0_araddr  = {32{r_state}} & (m_araddr& {32{!cur_slave_r}});
    assign s0_arvalid = r_state & (m_arvalid& !cur_slave_r);
    assign s0_rready  = r_state & (m_rready& !cur_slave_r);

    assign s1_araddr  = {32{r_state}} & (m_araddr & {32{cur_slave_r}});
    assign s1_arvalid = r_state & (m_arvalid & cur_slave_r);
    assign s1_rready  = r_state & (m_rready & cur_slave_r);

    // WRITE
    assign m_awready  = w_state & ((cur_slave_w) ? s1_awready : s0_awready);
    assign m_wready   = w_state & ((cur_slave_w) ? s1_wready : s0_wready);
    assign m_bresp    = {2{w_state}} & ((cur_slave_w) ? s1_bresp : s0_bresp);
    assign m_bvalid   = w_state & ((cur_slave_w) ? s1_bvalid : s0_bvalid);
    assign s0_awaddr  = {32{w_state}} & (m_awaddr & {32{!cur_slave_w}});
    assign s0_awvalid = w_state & (m_awvalid & !cur_slave_w);
    assign s0_wdata   = {32{w_state}} & (m_wdata & {32{!cur_slave_w}});
    assign s0_wstrb   = {4{w_state}} & (m_wstrb & {4{!cur_slave_w}});
    assign s0_wvalid  = w_state & (m_wvalid & !cur_slave_w);
    assign s0_bready  = w_state & (m_bready & !cur_slave_w);

    assign s1_awaddr  = {32{w_state}} & (m_awaddr & {32{cur_slave_w}});
    assign s1_awvalid = w_state & (m_awvalid & cur_slave_w);
    assign s1_wdata   = {32{w_state}} & (m_wdata & {32{cur_slave_w}});
    assign s1_wstrb   = {4{w_state}} & (m_wstrb & {4{cur_slave_w}});
    assign s1_wvalid  = w_state & (m_wvalid & cur_slave_w);
    assign s1_bready  = w_state & (m_bready & cur_slave_w);

endmodule
