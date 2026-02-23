module CLINT(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    // AR
    input       [3:0]   arid_i,
    input       [31:0]  araddr_i,
    input       [3:0]   arlen_i,
    input       [2:0]   arsize_i,
    input       [1:0]   arburst_i,
    input               arvalid_i,
    output              arready_o,

    // R
    output      [3:0]   rid_o,
    output      [31:0]  rdata_o,
    output      [1:0]   rresp_o,
    output              rlast_o,
    output              rvalid_o,
    input               rready_i,

    // AW
    input       [3:0]   awid_i,
    input       [31:0]  awaddr_i,
    input       [3:0]   awlen_i,
    input       [2:0]   awsize_i,
    input       [1:0]   awburst_i,
    input               awvalid_i,
    output              awready_o,

    // W
    input       [31:0]  wdata_i,
    input       [3:0]   wstrb_i,
    input               wlast_i,
    input               wvalid_i,
    output              wready_o,

    // B
    output      [3:0]   bid_o,
    output      [1:0]   bresp_o,
    output              bvalid_o,
    input               bready_i
);

import "DPI-C" function void clint_difftest_skip();

reg [3:0]   arid_r;
reg [31:0]  araddr_r;
reg [3:0]   arlen_r;
reg [2:0]   arsize_r;
reg [1:0]   arburst_r;

assign arready_o = r_state == S_IDLE;
assign rid_o = arid_r;
assign rdata_o = (araddr_r[7:0] == 8'h48 ? mtime[31:0] : mtime[63:32]);
assign rlast_o = r_state == S_SEND_R;
assign rresp_o = 2'b0;
assign rvalid_o = r_state == S_SEND_R;

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
                if (arvalid_i & arready_o) begin
                    arid_r      <= arid_i;
                    araddr_r    <= araddr_i;
                    arlen_r     <= arlen_i;
                    arsize_r    <= arsize_i;
                    arburst_r   <= arburst_i;
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
                if (arvalid_i & arready_o) begin
                    r_state <= S_SEND_R;
                end
            end
            S_SEND_R: begin
                if (rvalid_o & rready_i) begin
                    clint_difftest_skip();
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

assign awready_o = w_state == S_IDLE;
assign wready_o = w_state == S_GET_WD;
assign bid_o = 4'b0;
assign bresp_o = 2'b00;
assign bvalid_o = w_state == S_SEND_B;

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
                if (awvalid_i & awready_o) begin
                    awid_r      <= awid_i;
                    awaddr_r    <= awaddr_i;
                    awlen_r     <= awlen_i;
                    awsize_r    <= awsize_i;
                    awburst_r   <= awburst_i;
                end
            end
            S_GET_WD: begin
                if (wvalid_i & wready_o) begin
                    wdata_r    <= wdata_i;
                    wstrb_r    <= wstrb_i;
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
                if (awvalid_i & awready_o) begin
                    w_state <= S_GET_WD;
                end
            end
            S_GET_WD: begin
                if (wvalid_i & wready_o) begin
                    w_state <= S_SEND_B;
                end
            end
            S_SEND_B: begin
                if (bvalid_o & bready_i) begin
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
