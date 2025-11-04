`include "common.vh"

module WBU(
    input               clk,
    input               rst,
    input               wbu_gpr_we_in,
    input               wbu_mem_we_in,
    output              gpr_we_out,

    output              mem_valid_out,
    input               mem_ready_in,

    input               wbu_valid_in,
    output              wbu_ready_out
);

reg wbu_ready_r;
reg gpr_we_r;
reg mem_valid_r;

reg [1:0]   state;
reg [1:0]   next_state;

always @(posedge clk) begin
    if (rst) begin
        state <= `WBU_S_IDLE;
    end else begin
        state <= next_state;
    end
end

always @(*) begin
    next_state = state;
    case (state)
        `WBU_S_IDLE: begin
            if (wbu_valid_in) begin
                if (wbu_gpr_we_in) begin
                    next_state = `WBU_S_WB;
                end else if (wbu_mem_we_in) begin
                    next_state = `WBU_S_WAIT_STORE;
                end
            end
        end
        `WBU_S_WAIT_STORE: begin
            if (mem_ready_in) begin
                next_state = `WBU_S_IDLE;
            end
        end
        `WBU_S_WB: begin
            next_state = `WBU_S_IDLE;
        end
        default: begin
            next_state = `WBU_S_IDLE;
        end
    endcase
end

assign  wbu_ready_out = wbu_ready_r;
assign  gpr_we_out = gpr_we_r;
assign  mem_valid_out = mem_valid_r;

always @(posedge clk) begin
    if (rst) begin
        wbu_ready_r <= 1'b1;
        gpr_we_r <= 1'b0;
        mem_valid_r <= 1'b0;
    end else begin
        case (state)
            `WBU_S_IDLE: begin
                wbu_ready_r <= 1'b1;
                gpr_we_r <= 1'b0;
                mem_valid_r <= 1'b0;
            end
            `WBU_S_WAIT_STORE: begin
                wbu_ready_r <= 1'b0;
                gpr_we_r <= 1'b0;
                mem_valid_r <= 1'b1;
            end
            `WBU_S_WB: begin
                wbu_ready_r <= 1'b0;
                gpr_we_r <= 1'b1;
                mem_valid_r <= 1'b0;
            end
            default: begin
                wbu_ready_r <= 1'b1;
                gpr_we_r <= 1'b0;
                mem_valid_r <= 1'b0;
            end
        endcase
    end
end

endmodule
