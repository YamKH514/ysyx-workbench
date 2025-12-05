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

reg [31:0]  r_data_r = get_inst(inst_sram_addr_in);

parameter S_IDLE = 1'd0;
parameter S_WORK = 1'd1;

reg state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        inst_sram_data_out <= 32'b0;
        inst_to_ifu_arready_out <= 1'b0;
        inst_to_ifu_rvalid_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                // inst_to_ifu_arready_out <= 1'b1;
                // inst_to_ifu_rvalid_out <= 1'b0;
                if (ifu_to_inst_arvalid_in) begin
                    inst_sram_data_out <= r_data_r;
                    inst_to_ifu_arready_out <= 1'b0;
                    inst_to_ifu_rvalid_out <= 1'b1;
                end
            end
            S_WORK: begin
                // inst_to_ifu_arready_out <= 1'b0;
                // inst_to_ifu_rvalid_out <= 1'b1;
                if (ifu_to_inst_rready_in) begin
                    inst_to_ifu_arready_out <= 1'b1;
                    inst_to_ifu_rvalid_out <= 1'b0;
                end
            end
        endcase
    end
end

always @(*) begin
    case (state)
        S_IDLE: begin
            if (ifu_to_inst_arvalid_in) begin
                next_state = S_WORK;
            end
        end
        S_WORK: begin
            if (ifu_to_inst_rready_in) begin
                next_state = S_IDLE;
            end
        end
    endcase
end

endmodule
