module InstSRAM (
    input               clk,
    input               rst,

    input       [31:0]  inst_sram_addr_in,
    output  reg [31:0]  inst_sram_data_out,

    input               ifu_to_inst_valid_in,
    output  reg         inst_to_ifu_ready_out
);

import "DPI-C" function int get_inst(input int pc);

parameter S_IDLE = 1'd0;
parameter S_SEND_INST = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;
end

always @(*) begin
    case (state)
        S_IDLE: begin
            inst_to_ifu_ready_out = 1'b0;
            if (ifu_to_inst_valid_in) begin
                next_state = S_SEND_INST;
            end
        end
        S_SEND_INST: begin
            inst_sram_data_out = get_inst(inst_sram_addr_in);
            inst_to_ifu_ready_out = 1'b1;
            next_state = S_IDLE;
        end
    endcase
end

endmodule
