`include "common.vh"

module WBU(
    input               wbu_clk_in,
    input               wbu_rst_in,
    input               wbu_gpr_we_in,
    input               wbu_mem_we_in,
    output  reg         mem_we_out,
    output  reg         gpr_we_out,

    output  reg         mem_valid_out,
    input               mem_ready_in,

    input               wbu_valid_in,
    output  reg         wbu_ready_out
);

reg [1:0]   state;
reg [1:0]   next_state;

always @(posedge wbu_clk_in) begin
    if (wbu_rst_in) begin
        state <= `WBU_S_IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    next_state = state;
    mem_valid_out = 1'b0;
    mem_we_out = 1'b0;
    gpr_we_out = 1'b0;
    wbu_ready_out = 1'b0;
    case (state)
        `WBU_S_IDLE: begin
            wbu_ready_out = 1'b1;
            if (wbu_valid_in) begin
                if (wbu_gpr_we_in) begin
                    next_state = `WBU_S_WB;
                end else if (wbu_mem_we_in) begin
                    next_state = `WBU_S_WAIT_STORE;
                end
            end
        end
        `WBU_S_WAIT_STORE: begin
            mem_valid_out = 1'b1;
            mem_we_out = 1'b1;
            if (mem_ready_in) begin
                next_state = `WBU_S_IDLE;
            end
        end
        `WBU_S_WB: begin
            gpr_we_out = 1'b1;
            next_state = `WBU_S_IDLE;
        end
        default: begin
            next_state = `WBU_S_IDLE;
        end
    endcase
end

endmodule
