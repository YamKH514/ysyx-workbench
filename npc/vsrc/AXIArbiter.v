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
);

parameter S_IDLE = 1'd0;
parameter S_BUSY = 1'd1;

reg state, next_state;
reg cur_master;

always @(posedge clk) begin
    if (!rstn) state <= S_IDLE;
    else state <= next_state;

    if (!rstn) begin
        cur_master <= 1'd0;
    end else begin
        case (state)
            S_IDLE: begin
                if (m0_arvalid | m0_awvalid) begin
                    cur_master <= 1'd0;
                end else if (m1_arvalid | m1_awvalid) begin
                    cur_master <= 1'd1;
                end
            end
            S_BUSY: begin
                s_araddr  <= (m0_araddr  & {32{!cur_master}}) | (m1_araddr  & {32{cur_master}});
                s_arvalid <= (m0_arvalid & !cur_master)       | (m1_arvalid & cur_master);
                s_rready  <= (m0_rready  & !cur_master)       | (m1_rready  & cur_master);
                s_awaddr  <= (m0_awaddr  & {32{!cur_master}}) | (m1_awaddr  & {32{cur_master}});
                s_awvalid <= (m0_awvalid & !cur_master)       | (m1_awvalid & cur_master);
                s_wdata   <= (m0_wdata   & {32{!cur_master}}) | (m1_wdata   & {32{cur_master}});
                s_wstrb   <= (m0_wstrb   & {4{!cur_master}})  | (m1_wstrb   & {4{cur_master}});
                s_wvalid  <= (m0_wvalid  & !cur_master)       | (m1_wvalid  & cur_master);
                s_bready  <= (m0_bready  & !cur_master)       | (m1_bready  & cur_master);

                m0_arready <= s_arready & !cur_master;
                m0_rdata   <= s_rdata   & {32{!cur_master}};
                m0_rresp   <= s_rresp   & {2{!cur_master}};
                m0_rvalid  <= s_rvalid  & !cur_master;
                m0_awready <= s_awready & !cur_master;
                m0_wready  <= s_wready  & !cur_master;
                m0_bresp   <= s_bresp   & {2{!cur_master}};
                m0_bvalid  <= s_bvalid  & !cur_master;

                m1_arready <= s_arready & cur_master;
                m1_rdata   <= s_rdata   & {32{cur_master}};
                m1_rresp   <= s_rresp   & {2{cur_master}};
                m1_rvalid  <= s_rvalid  & cur_master;
                m1_awready <= s_awready & cur_master;
                m1_wready  <= s_wready  & cur_master;
                m1_bresp   <= s_bresp   & {2{cur_master}};
                m1_bvalid  <= s_bvalid  & cur_master;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    if (!rstn) begin
        next_state = S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (m0_arvalid | m0_awvalid | m1_arvalid | m1_awvalid) begin
                    next_state = S_BUSY;
                end
            end
            S_BUSY: begin
                if ((m0_rvalid & m0_rready) | (m0_bvalid & m0_bready) | (m1_rvalid & m1_rready) | (m1_bvalid & m1_bready)) begin
                    next_state = S_IDLE;
                end
            end
        endcase
    end
end

endmodule
