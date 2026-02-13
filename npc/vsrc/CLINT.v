module CLINT(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    // AR
    input       [3:0]   arid_in,
    input       [31:0]  araddr_in,
    input       [3:0]   arlen_in,
    input       [2:0]   arsize_in,
    input       [1:0]   arburst_in,
    input               arvalid_in,
    output              arready_out,

    // R
    output      [3:0]   rid_out,
    output      [31:0]  rdata_out,
    output      [1:0]   rresp_out,
    output              rlast_out,
    output              rvalid_out,
    input               rready_in,

    // AW
    input       [3:0]   awid_in,
    input       [31:0]  awaddr_in,
    input       [3:0]   awlen_in,
    input       [2:0]   awsize_in,
    input       [1:0]   awburst_in,
    input               awvalid_in,
    output              awready_out,

    // W
    input       [31:0]  wdata_in,
    input       [3:0]   wstrb_in,
    input               wlast_in,
    input               wvalid_in,
    output              wready_out,

    // B
    output      [3:0]   bid_out,
    output      [1:0]   bresp_out,
    output              bvalid_out,
    input               bready_in
);

// import "DPI-C" function void clint_difftest_skip();

reg [3:0]   arid_r;
reg [31:0]  araddr_r;
reg [3:0]   arlen_r;
reg [2:0]   arsize_r;
reg [1:0]   arburst_r;

assign arready_out = r_state == S_IDLE;
assign rid_out = arid_r;
assign rdata_out = (araddr_r[7:0] == 8'h48 ? mtime[31:0] : mtime[63:32]);
assign rlast_out = r_state == S_SEND_R;
assign rresp_out = 2'b0;
assign rvalid_out = r_state == S_SEND_R;

localparam S_W      = 2;
localparam S_IDLE   = 2'd0;
localparam S_SEND_R = 2'd1;
localparam S_GET_WD = 2'd2;
localparam S_SEND_B = 2'd3;

reg [S_W-1:0]   r_state;
reg [S_W-1:0]   w_state;

always @(posedge clk) begin
    if (rst) begin
        arid_r      <= 4'b0;
        arlen_r     <= 4'b0;
        arsize_r    <= 3'b0;
        arburst_r   <= 2'b0;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (arvalid_in & arready_out) begin
                    arid_r      <= arid_in;
                    araddr_r    <= araddr_in;
                    arlen_r     <= arlen_in;
                    arsize_r    <= arsize_in;
                    arburst_r   <= arburst_in;
                end
            end
            default: begin
                arid_r      <= 4'b0;
                arlen_r     <= 4'b0;
                arsize_r    <= 3'b0;
                arburst_r   <= 2'b0;
            end
        endcase
    end
end

always @(posedge clk) begin
    if (rst) begin
        r_state <= S_IDLE;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (arvalid_in & arready_out) begin
                    r_state <= S_SEND_R;
                end
            end
            S_SEND_R: begin
                if (rvalid_out & rready_in) begin
                    // clint_difftest_skip();
                    r_state <= S_IDLE;
                end
            end
            default: begin
                r_state <= S_IDLE;
            end
        endcase
    end
end

reg [3:0]   awid_r;
reg [31:0]  awaddr_r;
reg [3:0]   awlen_r;
reg [2:0]   awsize_r;
reg [1:0]   awburst_r;
reg [31:0]  wdata_r;
reg [3:0]   wstrb_r;

assign awready_out = w_state == S_IDLE;
assign wready_out = w_state == S_GET_WD;
assign bid_out = 4'b0;
assign bresp_out = 2'b00;
assign bvalid_out = w_state == S_SEND_B;

always @(posedge clk) begin
    if (rst) begin
        awid_r      <= 4'b0;
        awlen_r     <= 4'b0;
        awsize_r    <= 3'b0;
        awburst_r   <= 2'b0;
        wdata_r     <= 32'b0;
        wstrb_r     <= 4'b0;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (awvalid_in & awready_out) begin
                    awid_r      <= awid_in;
                    awaddr_r    <= awaddr_in;
                    awlen_r     <= awlen_in;
                    awsize_r    <= awsize_in;
                    awburst_r   <= awburst_in;
                end
            end
            S_GET_WD: begin
                if (wvalid_in & wready_out) begin
                    wdata_r    <= wdata_in;
                    wstrb_r    <= wstrb_in;
                end
            end
            default: begin
                awid_r      <= 4'b0;
                awlen_r     <= 4'b0;
                awsize_r    <= 3'b0;
                awburst_r   <= 2'b0;
                wdata_r     <= 32'b0;
                wstrb_r     <= 4'b0;
            end
        endcase
    end
end

always @(posedge clk) begin
    if (rst) begin
        w_state <= S_IDLE;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (awvalid_in & awready_out) begin
                    w_state <= S_GET_WD;
                end
            end
            S_GET_WD: begin
                if (wvalid_in & wready_out) begin
                    w_state <= S_SEND_B;
                end
            end
            S_SEND_B: begin
                if (bvalid_out & bready_in) begin
                    w_state <= S_IDLE;
                end
            end
            default: begin
                w_state <= S_IDLE;
            end
        endcase
    end
end

reg [63:0]  mtime;

always @(posedge clk) begin
    if (rst) mtime <= 64'b0;
    else mtime <= mtime + 1;
end

endmodule
