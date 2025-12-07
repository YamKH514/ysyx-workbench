module SRAM(
    input               clk,
    input               rst,

    // AR
    input       [31:0]  araddr_in,
    input               arvalid_in,
    output  reg         arready_out,

    // R
    output  reg [31:0]  rdata_out,
    output  reg [1:0]   rresp_out,
    output  reg         rvalid_out,
    input               rready_in,

    // AW
    input       [31:0]  awaddr_in,
    input               awvalid_in,
    output  reg         awready_out,

    // W
    input       [31:0]  wdata_in,
    input       [3:0]   wstrb_in,
    input               wvalid_in,
    output  reg         wready_out,

    // B
    output  reg [1:0]   bresp_out,
    output  reg         bvalid_out,
    input               bready_in
);

reg [3:0] r_delay_cnt;
reg [3:0] w_delay_cnt;
reg [7:0] lfsr;
wire lfsr_feedback = lfsr[7] ^ lfsr[5] ^ lfsr[4] ^ lfsr[3];

always @(posedge clk) begin
    if (rst) begin
        lfsr <= 8'hC1;
    end else begin
        lfsr <= {lfsr[6:0], lfsr_feedback};
    end
end

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);

reg [31:0]  araddr_r;
reg [31:0]  awaddr_r;

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
        arready_out <= 1'b1;
        rvalid_out  <= 1'b0;
        rresp_out   <= 2'b00;
        r_delay_cnt <= (lfsr[3:0]) + 4'd1;
    end else begin
        case (r_state)
            S_IDLE: begin
                r_delay_cnt <= (lfsr[3:0]) + 4'd1;
                if (arvalid_in) begin
                    araddr_r    <= araddr_in;
                    arready_out <= 1'b0;
                end
            end
            S_GET_AR: begin
                rvalid_out <= 1'b1 & (r_delay_cnt == 1);
                rresp_out  <= 2'b00;
                r_delay_cnt<= r_delay_cnt - 1;
            end
            S_SEND_R: begin
                if (rready_in) begin
                    arready_out <= 1'b1;
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
        awready_out <= 1'b1;
        wready_out  <= 1'b1;
        bresp_out   <= 2'b00;
        bvalid_out  <= 1'b0;
        w_delay_cnt <= (lfsr[3:0]) + 4'd1;
    end else begin
        case (w_state)
            S_IDLE: begin
                w_delay_cnt <= (lfsr[3:0]) + 4'd1;
                if (awvalid_in) begin
                    awaddr_r    <= awaddr_in;
                    awready_out <= 1'b0;
                end
            end
            S_GET_WR: begin
                if (wvalid_in) begin
                    wready_out <= 1'b0;
                end
            end
            S_GET_WD: begin
                bresp_out  <= 2'b00;
                bvalid_out <= 1'b1 & (w_delay_cnt == 1);
                w_delay_cnt <= w_delay_cnt - 1;
            end
            S_SEND_B: begin
                if (bready_in) begin
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
            if (arvalid_in) begin
                r_next_state = S_GET_AR;
            end
        end
        S_GET_AR: begin
            if (r_delay_cnt == 1) begin
                rdata_out = paddr_read(araddr_r);
                r_next_state = S_SEND_R;
            end
        end
        S_SEND_R: begin
            if (rready_in) begin
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
            if (awvalid_in) begin
                w_next_state = S_GET_WR;
            end
        end
        S_GET_WR: begin
            if (wvalid_in) begin
                w_next_state = S_GET_WD;
            end
        end
        S_GET_WD: begin
            if (w_delay_cnt == 1) begin
                paddr_write(awaddr_r, wdata_in, {4'b0, wstrb_in});
                w_next_state = S_SEND_B;
            end
        end
        S_SEND_B: begin
            if (bready_in) begin
                w_next_state = S_IDLE;
            end
        end
        default: begin
            w_next_state = S_IDLE;
        end
    endcase
end

endmodule
