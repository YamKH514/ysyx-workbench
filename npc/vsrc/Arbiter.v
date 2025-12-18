module Arbiter(
    input               clk,
    input               rstn,

    input               bs_in,

    input               br1_in,
    output  reg         bg1_out,

    input               br2_in,
    output  reg         bg2_out
);

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (!rstn) state <= S_IDLE;
    else state <= next_state;

    if (!rstn) begin
        bg1_out <= 1'b0;
        bg2_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (br1_in) begin
                    bg1_out <= 1'b1;
                end else if (br2_in) begin
                    bg2_out <= 1'b1;
                end
            end
            S_BUSY: begin
                if (bs_in) begin
                    bg1_out <= 1'b0;
                    bg2_out <= 1'b0;
                end
            end
            default: begin
                bg1_out <= 1'b0;
                bg2_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (bs_in) begin
                next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (!bs_in) begin
                next_state = S_IDLE;
            end
        end
    endcase
end

endmodule
