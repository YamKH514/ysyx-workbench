module IFU(
    input               clk,
    input               rst,

    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_req_addr_out,
    input       [31:0]  ifu_req_inst_in,
    output  reg [31:0]  ifu_inst_out,

    output  reg         ifu_to_inst_valid_out,
    input               inst_to_ifu_ready_in,

    output  reg         ifu_to_idu_valid_out,
    input               idu_to_ifu_ready_in
);

parameter S_IDLE = 2'd0;
parameter S_WAIT_INST = 2'd1;
parameter S_WAIT_IDU = 2'd2;

reg [1:0]   state, next_state;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;
end

always @(*) begin
    case (state)
        S_IDLE: begin
            ifu_req_addr_out = ifu_current_pc_in;
            ifu_to_inst_valid_out = 1'b1;
            next_state = S_WAIT_INST;
        end
        S_WAIT_INST: begin
            if (inst_to_ifu_ready_in) begin
                ifu_inst_out = ifu_req_inst_in;
                ifu_to_inst_valid_out = 1'b0;
                ifu_to_idu_valid_out = 1'b1;
                next_state = S_WAIT_IDU;
            end
        end
        S_WAIT_IDU: begin
            if (idu_to_ifu_ready_in) begin
                ifu_to_idu_valid_out = 1'b0;
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

endmodule
