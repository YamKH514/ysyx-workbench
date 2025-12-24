module UART(
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
    output  reg         arready_out,

    // R
    output  reg [3:0]   rid_out,
    output  reg [31:0]  rdata_out,
    output  reg [1:0]   rresp_out,
    output  reg         rlast_out,
    output  reg         rvalid_out,
    input               rready_in,

    // AW
    input       [3:0]   awid_in,
    input       [31:0]  awaddr_in,
    input       [3:0]   awlen_in,
    input       [2:0]   awsize_in,
    input       [1:0]   awburst_in,
    input               awvalid_in,
    output  reg         awready_out,

    // W
    input       [31:0]  wdata_in,
    input       [3:0]   wstrb_in,
    input               wlast_in,
    input               wvalid_in,
    output  reg         wready_out,

    // B
    output  reg [3:0]   bid_out,
    output  reg [1:0]   bresp_out,
    output  reg         bvalid_out,
    input               bready_in
);

import "DPI-C" function void uart_difftest_skip();

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
reg [31:0]  wdata_r;
reg [3:0]   wstrb_r;
reg [3:0]   bid_r;

parameter S_IDLE   = 3'd0;
parameter S_GET_AR = 3'd1;
parameter S_SEND_R = 3'd2;
parameter S_GET_WR = 3'd3;
parameter S_GET_WD = 3'd4;
parameter S_SEND_B = 3'd5;

reg [2:0]   r_state, r_next_state;
reg [2:0]   w_state, w_next_state;

always @(posedge clk) begin
    if (rst) begin
        r_state <= S_IDLE;
        w_state <= S_IDLE;
    end else begin
        r_state <= r_next_state;
        w_state <= w_next_state;
    end

    // READ
    if (rst) begin
        arid_r      <= 4'b0;
        arlen_r     <= 4'b0;
        arsize_r    <= 3'b0;
        arburst_r   <= 2'b0;
        arready_out <= 1'b1;
        rid_out     <= 4'b0;
        rlast_out   <= 1'b0;
        rresp_out   <= 2'b00;
        rvalid_out  <= 1'b0;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (arvalid_in & arready_out) begin
                    arid_r      <= arid_in;
                    arlen_r     <= arlen_in;
                    arsize_r    <= arsize_in;
                    arburst_r   <= arburst_in;
                    arready_out <= 1'b0;
                end
            end
            S_GET_AR: begin
                rid_out    <= arid_r;
                rdata_out  <= 32'b0;
                rlast_out  <= 1'b1;
                rresp_out  <= 2'b00;
                rvalid_out <= 1'b1;
            end
            S_SEND_R: begin
                if (rvalid_out & rready_in) begin
                    arready_out <= 1'b1;
                    rid_out     <= 4'b0;
                    rlast_out   <= 1'b0;
                    rresp_out   <= 2'b00;
                    rvalid_out  <= 1'b0;
                end
            end
            default: begin
                arready_out <= 1'b1;
                rvalid_out  <= 1'b0;
            end
        endcase
    end

    // WRITE
    if (rst) begin
        awid_r      <= 4'b0;
        awlen_r     <= 4'b0;
        awsize_r    <= 3'b0;
        awburst_r   <= 2'b0;
        awready_out <= 1'b1;
        wready_out  <= 1'b1;
        bid_r       <= 4'b0;
        bresp_out   <= 2'b00;
        bvalid_out  <= 1'b0;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (awvalid_in & awready_out) begin
                    awid_r      <= awid_in;
                    awaddr_r    <= awaddr_in;
                    awlen_r     <= awlen_in;
                    awsize_r    <= awsize_in;
                    awburst_r   <= awburst_in;
                    awready_out <= 1'b0;
                end
            end
            S_GET_WR: begin
                if (wvalid_in & wready_out) begin
                    wdata_r    <= wdata_in;
                    wstrb_r    <= wstrb_in;
                    wready_out <= 1'b0;
                end
            end
            S_GET_WD: begin
                bid_out    <= 4'b0;
                bresp_out  <= 2'b00;
                bvalid_out <= 1'b1;
            end
            S_SEND_B: begin
                if (bvalid_out & bready_in) begin
                    awready_out <= 1'b1;
                    wready_out  <=1'b1;
                    bvalid_out  <= 1'b0;
                end
            end
            default: begin
                awready_out <= 1'b1;
                wready_out  <= 1'b1;
                bvalid_out  <= 1'b0;
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
            if (arvalid_in & arready_out) begin
                r_next_state = S_GET_AR;
            end
        end
        S_GET_AR: begin
            r_next_state = S_SEND_R;
        end
        S_SEND_R: begin
            if (rvalid_out & rready_in) begin
                r_next_state = S_IDLE;
            end
        end
        default: begin
            r_next_state = S_IDLE;
        end
    endcase

    // WRITE
    case (w_state)
        S_IDLE: begin
            if (awvalid_in & awready_out) begin
                w_next_state = S_GET_WR;
            end
        end
        S_GET_WR: begin
            if (wvalid_in & wready_out) begin
                w_next_state = S_GET_WD;
            end
        end
        S_GET_WD: begin
            $write("%c", wdata_r[7:0]);
            uart_difftest_skip();
            w_next_state = S_SEND_B;
        end
        S_SEND_B: begin
            if (bvalid_out & bready_in) begin
                w_next_state = S_IDLE;
            end
        end
        default: begin
            w_next_state = S_IDLE;
        end
    endcase
end

endmodule
