module ICache_top(
    input           clk,
    input           rst,

    input   [29:0]  paddr,
    output  [31:0]  pdata,
    input           pvalid,
    output          pready,

    // AR
    output  [3:0]   arid,
    output  [31:0]  araddr,
    output  [3:0]   arlen,
    output  [2:0]   arsize,
    output  [1:0]   arburst,
    output          arvalid,
    input           arready,

    // R
    input   [3:0]   rid,
    input   [31:0]  rdata,
    input   [1:0]   rresp,
    input           rlast,
    input           rvalid,
    output          rready,

    output          bs,
    output          br,
    input           bg
);

localparam ARLEN = 4'b0000;

wire [29:0] cache_paddr;
wire [31:0] cache_pdata;
wire        cache_datav;
wire        cache_valid;
wire        cache_ready;
wire [29:0] cache_waddr;
wire [31:0] cache_wdata;
wire        cache_wvalid;

reg  [29:0] addr_r;
reg  ar_handshake_r;
reg  [31:0] rdata_r;
reg  [29:0] r_cnt;

assign pdata = cache_pdata;
assign pready = state == S_GET_CACHE;

always @(posedge clk) begin
    if (rst) begin
        addr_r <= 0;
    end else if (state == S_IDLE && pvalid) begin
        addr_r <= paddr;
    end
end

always @(posedge clk) begin
    if (rst) begin
        ar_handshake_r <= 0;
    end else if (state == S_GET_DATA && arvalid && arready) begin
        ar_handshake_r <= 1;
    end else if (state == S_IDLE) begin
        ar_handshake_r <= 0;
    end
end

assign arid = 0;
assign araddr = bs ? {addr_r, 2'b00} : 0;
assign arlen = bs ? ARLEN : 0;
assign arsize = bs ? 3'b010 : 0;
assign arburst = bs ? 2'b01 : 0;
assign arvalid = bs ? (state == S_GET_DATA) & !ar_handshake_r : 0;
assign rready = bs ? (state == S_GET_DATA) & ar_handshake_r : 0;

always @(posedge clk) begin
    if (rst) begin
        rdata_r <= 0;
        r_cnt <= 0;
    end else if (state == S_GET_DATA) begin
        if (rvalid && rready) begin
            rdata_r <= rdata;
            r_cnt <= r_cnt + 1;
        end
    end else if (state == S_IDLE) begin
        rdata_r <= 0;
        r_cnt <= 0;
    end
end

assign cache_paddr = addr_r;
assign cache_valid = state == S_READ_CACHE;
assign cache_waddr = addr_r + (r_cnt - 1);
assign cache_wdata = rdata_r;
assign cache_wvalid = state == S_WRITE_CACHE;

assign br = state == S_WAIT_ARB;
assign bs = state == S_GET_DATA|
            state == S_WRITE_CACHE;

localparam S_W           = 3;
localparam S_IDLE        = 3'd0;
localparam S_READ_CACHE  = 3'd1;
localparam S_GET_CACHE   = 3'd2;
localparam S_WAIT_ARB    = 3'd3;
localparam S_GET_DATA    = 3'd4;
localparam S_WRITE_CACHE = 3'd5;

reg [S_W-1:0] state;
reg [S_W-1:0] target_state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
        target_state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (pvalid) state <= S_READ_CACHE;
            end
            S_READ_CACHE: begin
                if (cache_valid && cache_ready) state <= (cache_datav) ? S_GET_CACHE : S_WAIT_ARB;
            end
            S_GET_CACHE: begin
                if (pvalid && pready) state <= S_IDLE;
            end
            S_WAIT_ARB: begin
                if (bg) state <=S_GET_DATA;
            end
            S_GET_DATA: begin
                if (ar_handshake_r && rvalid && rready) begin
                    state <= S_WRITE_CACHE;
                    target_state <= rlast ? S_READ_CACHE : S_GET_DATA;
                end
            end
            S_WRITE_CACHE: begin
                state <= target_state;
            end
            default: begin
                state <= S_IDLE;
                target_state <= S_IDLE;
            end
        endcase
    end
end

ICache #(
    .CACHE_M 	(2  ),
    .CACHE_N 	(4  ))
u_ICache(
    .clk            	(clk            ),
    .rst            	(rst            ),
    .addr_in        	(cache_paddr    ),
    .data_out       	(cache_pdata    ),
    .data_valid_out 	(cache_datav    ),
    .valid_in       	(cache_valid    ),
    .ready_out      	(cache_ready    ),
    .waddr_in       	(cache_waddr    ),
    .wdata_in       	(cache_wdata    ),
    .wvalid_in      	(cache_wvalid   )
);

endmodule
