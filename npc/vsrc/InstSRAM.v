module InstSRAM (
    input               clk,
    input               rst,

    input       [31:0]  inst_sram_addr_in,
    output  reg [31:0]  inst_sram_data_out,

    input               ifu_to_inst_arvalid_in,
    output  reg         inst_to_ifu_arready_out,
    output  reg         inst_to_ifu_rvalid_out,
    input               ifu_to_inst_rready_in
);

import "DPI-C" function int get_inst(input int pc);
reg [31:0]  r_addr_r;
// reg [31:0]  r_data_r = get_inst(r_addr_r);

parameter S_IDLE   = 2'd0;
parameter S_GET_AR = 2'd1;
parameter S_SEND_R = 2'd2;

reg [1:0]   state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        // inst_sram_data_out <= 32'b0;
        inst_to_ifu_arready_out <= 1'b0;
        inst_to_ifu_rvalid_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (ifu_to_inst_arvalid_in) begin
                    r_addr_r <= inst_sram_addr_in;
                    inst_to_ifu_arready_out <= 1'b0;
                end
            end
            S_GET_AR: begin
                // inst_sram_data_out <= r_data_r;
                inst_to_ifu_rvalid_out <= 1'b1;
            end
            S_SEND_R: begin
                if (ifu_to_inst_rready_in) begin
                    inst_to_ifu_rvalid_out <= 1'b0;
                    inst_to_ifu_arready_out <= 1'b1;
                end
            end
            default: begin
                // inst_sram_data_out <= 32'b0;
                inst_to_ifu_arready_out <= 1'b0;
                inst_to_ifu_rvalid_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (ifu_to_inst_arvalid_in) begin
                next_state = S_GET_AR;
            end
        end
        S_GET_AR: begin
            inst_sram_data_out = get_inst(r_addr_r);
            next_state = S_SEND_R;
        end
        S_SEND_R: begin
            if (ifu_to_inst_rready_in) begin
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

endmodule
