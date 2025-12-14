module Xbar(
    input               clk,
    input               rstn,

    input       [31:0]  m_araddr,
    input               m_arvalid,
    output reg          m_arready,
    output      [31:0]  m_rdata,
    output      [1:0]   m_rresp,
    output              m_rvalid,
    input               m_rready,
    input       [31:0]  m_awaddr,
    input               m_awvalid,
    output reg          m_awready,
    input       [31:0]  m_wdata,
    input       [3:0]   m_wstrb,
    input               m_wvalid,
    output              m_wready,
    output      [1:0]   m_bresp,
    output              m_bvalid,
    input               m_bready,

    output      [31:0]  s0_araddr,
    output reg          s0_arvalid,
    input               s0_arready,
    input       [31:0]  s0_rdata,
    input       [1:0]   s0_rresp,
    input               s0_rvalid,
    output              s0_rready,
    output      [31:0]  s0_awaddr,
    output reg          s0_awvalid,
    input               s0_awready,
    output      [31:0]  s0_wdata,
    output      [3:0]   s0_wstrb,
    output              s0_wvalid,
    input               s0_wready,
    input       [1:0]   s0_bresp,
    input               s0_bvalid,
    output              s0_bready,

    output      [31:0]  s1_araddr,
    output reg          s1_arvalid,
    input               s1_arready,
    input       [31:0]  s1_rdata,
    input       [1:0]   s1_rresp,
    input               s1_rvalid,
    output              s1_rready,
    output      [31:0]  s1_awaddr,
    output reg          s1_awvalid,
    input               s1_awready,
    output      [31:0]  s1_wdata,
    output      [3:0]   s1_wstrb,
    output              s1_wvalid,
    input               s1_wready,
    input       [1:0]   s1_bresp,
    input               s1_bvalid,
    output              s1_bready
);

parameter S_IDLE = 2'd0;
parameter S_SEL  = 2'd1;
parameter S_CNT  = 2'd2;
parameter S_BUSY = 2'd3;

reg [1:0]   r_state, r_next_state;
reg [1:0]   w_state, w_next_state;

reg cur_slave_r;
reg cur_slave_w;

reg [31:0]  araddr_r;
reg [31:0]  awaddr_r;

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
        cur_slave_r <= 1'b0;
        m_arready <= 1'b1;
        s0_arvalid <= 1'b0;
        s1_arvalid <= 1'b0;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (m_arvalid) begin
                    araddr_r  <= m_araddr;
                    m_arready <= 1'b0;
                    cur_slave_r <= (m_araddr == 32'ha00003f8) ? 1'b0 : 1'b1;
                end
            end
            S_SEL: begin
                case (cur_slave_r)
                    1'b0: begin
                        s0_arvalid <= 1'b1;
                        s0_araddr  <= araddr_r;
                    end
                    1'b1: begin
                        s1_arvalid <= 1'b1;
                        s1_araddr  <= araddr_r;
                    end
                endcase
            end
            S_CNT: begin
                if ((!cur_slave_r & s0_arready) | (cur_slave_r & s1_arready)) begin
                    s0_arvalid <= 1'b0;
                    s1_arvalid <= 1'b0;
                end
            end
            S_BUSY: begin
                if ((!cur_slave_r & s0_rvalid & s0_rready) | (cur_slave_r & s1_rvalid & s1_rready)) begin
                    m_arready <= 1'b1;
                end
            end
        endcase
    end

    //WRITE
    if (!rstn) begin
        cur_slave_w <= 1'b0;
        m_awready <= 1'b1;
        s0_awvalid <= 1'b0;
        s1_awvalid <= 1'b0;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (m_awvalid) begin
                    awaddr_r  <= m_awaddr;
                    m_awready <= 1'b0;
                    cur_slave_w <= (m_araddr == 32'ha00003f8) ? 1'b0 : 1'b1;
                end
            end
            S_SEL: begin
                case (cur_slave_w)
                    1'b0: begin
                        s0_awvalid <= 1'b1;
                        s0_awaddr  <= awaddr_r;
                    end
                    1'b1: begin
                        s1_awvalid <= 1'b1;
                        s1_awaddr  <= awaddr_r;
                    end
                endcase
            end
            S_CNT: begin
                if ((!cur_slave_w & s0_awready) | (cur_slave_w & s1_awready)) begin
                    s0_awvalid <= 1'b0;
                    s1_awvalid <= 1'b0;
                end
            end
            S_BUSY: begin
                if ((!cur_slave_w & s0_bvalid & s0_bready) | (cur_slave_w & s1_bvalid & s1_bready)) begin
                    m_awready <= 1'b1;
                end
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
            if ((!cur_slave_r & s0_arready) | (cur_slave_r & s1_arready)) begin
                r_next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if ((!cur_slave_r & s0_rvalid & s0_rready) | (cur_slave_r & s1_rvalid & s1_rready)) begin
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
            $display("UART");
            w_next_state = S_CNT;
        end
        S_CNT: begin
            if ((!cur_slave_w & s0_awready) | (cur_slave_w & s1_awready)) begin
                w_next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if ((!cur_slave_w & s0_bvalid & s0_bready) | (cur_slave_w & s1_bvalid & s1_bready)) begin
                w_next_state = S_IDLE;
            end
        end
    endcase
end

assign m_rdata   = ((cur_slave_r) ? s1_rdata : s0_rdata) & {32{(r_state == S_BUSY)}};
assign m_rresp   = ((cur_slave_r) ? s1_rresp : s0_rresp) & {2{(r_state == S_BUSY)}};
assign m_rvalid  = ((cur_slave_r) ? s1_rvalid : s0_rvalid) & (r_state == S_BUSY);
assign s0_rready = (!cur_slave_r & m_rready) & (r_state == S_BUSY);
assign s1_rready = (cur_slave_r & m_rready) & (r_state == S_BUSY);

assign m_wready  = ((cur_slave_w) ? s1_wready : s0_wready) & (w_state == S_BUSY);
assign m_bresp   = ((cur_slave_w) ? s1_bresp : s0_bresp) & {2{(w_state == S_BUSY)}};
assign m_bvalid  = ((cur_slave_w) ? s1_bvalid : s0_bvalid) & (w_state == S_BUSY);
assign s0_wdata  = ({32{!cur_slave_w}} & m_wdata) & {32{(w_state == S_BUSY)}};
assign s0_wstrb  = ({4{!cur_slave_w}} & m_wstrb) & {4{(w_state == S_BUSY)}};
assign s0_wvalid = (!cur_slave_w & m_wvalid) & (w_state == S_BUSY);
assign s0_bready = (!cur_slave_w & m_bready) & (w_state == S_BUSY);
assign s1_wdata  = ({32{cur_slave_w}} & m_wdata) & {32{(w_state == S_BUSY)}};
assign s1_wstrb  = ({4{cur_slave_w}} & m_wstrb) & {4{(w_state == S_BUSY)}};
assign s1_wvalid = (cur_slave_w & m_wvalid) & (w_state == S_BUSY);
assign s1_bready = (cur_slave_w & m_bready) & (w_state == S_BUSY);
endmodule
