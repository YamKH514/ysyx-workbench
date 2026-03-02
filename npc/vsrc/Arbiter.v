module Arbiter(
    input   clk,
    input   rst,

    input   br1_i,
    output  bg1_o,
    input   bs1_i,

    input   br2_i,
    output  bg2_o,
    input   bs2_i
);

//* br请求信号，bg仲裁选中，bs占用结束

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
                if ((bs1_i & ~last_grant) | (bs2_i & last_grant)) begin
                    state <= S_IDLE;
                end
            end
        endcase
    end
end

endmodule
