module ICache(
    input               clk,
    input               rst,

    input [31-CACHE_M:0]araddr_in,
    input               arvalid_in,
    output  reg [31:0]  rdata_out,
    output  reg         rvalid_out,
    output  reg         rready_out,

    input [31-CACHE_M:0]awaddr_in,
    input               awvalid_in,
    input       [31:0]  wdata_in
);

parameter  CACHE_M = 2;  /* 2^m Byte, default every cache line has 4Byte size */
parameter  CACHE_N = 4;  /* CACHELINE_N = 2^n, default ICache has 16 cache line */
localparam CACHELINE_W = 8 * (2 ** CACHE_M);
localparam CACHELINE_N = 2 ** CACHE_N;

reg  [31-CACHE_M-CACHE_N:0] cache_tag  [CACHELINE_N];
reg  [CACHELINE_W-1:0]      cache_data [CACHELINE_N];
reg                         cache_valid[CACHELINE_N];
wire [31-CACHE_M-CACHE_N:0] r_tag;
wire [CACHE_N-1:0]          r_index;
wire [31-CACHE_M-CACHE_N:0] w_tag;
wire [CACHE_N-1:0]          w_index;

reg [31-CACHE_M:0] raddr_r;

assign {r_tag, r_index} = raddr_r;
assign rdata_out = cache_data[r_index];
assign rvalid_out = (cache_tag[r_index] == r_tag) && cache_valid[r_index];
assign {w_tag, w_index} = awaddr_in;

always @(posedge clk) begin
    if (rst) begin
        raddr_r    <= 'd0;
        rready_out <= 'd0;
    end else begin
        if (arvalid_in) begin
            raddr_r    <= araddr_in;
            rready_out <= 'd1;
        end else begin
            rready_out <= 'd0;
        end
    end
end

always @(posedge clk) begin
    if (!rst && awvalid_in) begin
        cache_tag[w_index]   <= w_tag;
        cache_data[w_index]  <= wdata_in;
        cache_valid[w_index] <= 'd1;
    end
end

endmodule
