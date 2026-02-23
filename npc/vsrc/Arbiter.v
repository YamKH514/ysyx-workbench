module Arbiter(
    input               clk,
    input               rst,

    input               bs_i,

    input               br1_i,
    output  reg         bg1_o,

    input               br2_i,
    output  reg         bg2_o
);

localparam S_IDLE = 1'd0;
localparam S_BUSY = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        bg1_o <= 1'b0;
        bg2_o <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (br1_i) begin
                    bg1_o <= 1'b1;
                end else if (br2_i) begin
                    bg2_o <= 1'b1;
                end
            end
            S_BUSY: begin
                if (bs_i) begin
                    bg1_o <= 1'b0;
                    bg2_o <= 1'b0;
                end
            end
            default: begin
                bg1_o <= 1'b0;
                bg2_o <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (bs_i) begin
                next_state = S_BUSY;
            end
        end
        S_BUSY: begin
            if (!bs_i) begin
                next_state = S_IDLE;
            end
        end
    endcase
end

endmodule
