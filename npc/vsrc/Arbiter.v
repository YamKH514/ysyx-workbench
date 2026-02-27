module Arbiter(
    input               clk,
    input               rst,

    input               bs_i,

    input               br1_i,
    output  reg         bg1_o,

    input               br2_i,
    output  reg         bg2_o
);

reg last_grant; // 0 -> device1, 1 -> device2

assign bg1_o = state == S_BUSY & !last_grant;
assign bg2_o = state == S_BUSY & last_grant;

always @(posedge clk) begin
    if (rst) begin
        last_grant <= 0;
    end else if (state == S_IDLE) begin
        case ({br2_i, br1_i})
            2'b01: last_grant <= 1'b0;
            2'b10: last_grant <= 1'b1;
            2'b11: last_grant <= ~last_grant;
            default: last_grant <= last_grant;
        endcase
    end
end

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (br1_i | br2_i) begin
                    state <= S_BUSY;
                end
            end
            S_BUSY: begin
                if (bs_i) begin
                    state <= S_IDLE;
                end
            end
        endcase
    end
end

endmodule
