module IFU(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_inst_out,

    input               pc_to_ifu_ready_in,

    // AR
    output  reg [31:0]  araddr_out,
    output  reg         arvalid_out,
    input               arready_in,

    // R
    input       [31:0]  rdata_in,
    input       [1:0]   rresp_in,
    input               rvalid_in,
    output  reg         rready_out,

    // AW
    output  reg [31:0]  awaddr_out,
    output  reg         awvalid_out,
    input               awready_in,

    // W
    output  reg [31:0]  wdata_out,
    output  reg [3:0]   wstrb_out,
    output  reg         wvalid_out,
    input               wready_in,

    // B
    input       [1:0]   bresp_in,
    input               bvalid_in,
    output  reg         bready_out,

    output  reg         ifu_to_idu_valid_out,
    input               idu_to_ifu_ready_in
);

assign awaddr_out  = 32'b0;
assign awvalid_out = 1'b0;
assign wdata_out   = 32'b0;
assign wstrb_out   = 4'b0;
assign wvalid_out  = 1'b0;
assign bready_out  = 1'b0;

parameter S_IDLE      = 2'd0;
parameter S_SEND_AR   = 2'd1;
parameter S_WAIT_INST = 2'd2;
parameter S_WAIT_IDU  = 2'd3;

reg [1:0]   state, next_state;

always @(posedge clk) begin
    if (!rst) state <= S_IDLE;
    else state <= next_state;

    if (!rst) begin
        araddr_out           <= 32'b0;
        ifu_inst_out         <= 32'b0;
        arvalid_out          <= 1'b0;
        rready_out           <= 1'b1;
        ifu_to_idu_valid_out <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (pc_to_ifu_ready_in) begin
                    araddr_out  <= ifu_current_pc_in;
                    arvalid_out <= 1'b1;
                end
            end
            S_SEND_AR: begin
                if (arready_in) begin
                    arvalid_out <= 1'b0;
                end
            end
            S_WAIT_INST: begin
                if (rvalid_in) begin
                    ifu_inst_out         <= rdata_in;
                    if (rresp_in != 2'b00) begin
                    end
                    rready_out           <= 1'b0;
                    ifu_to_idu_valid_out <= 1'b1;
                end
            end
            S_WAIT_IDU: begin
                if (idu_to_ifu_ready_in) begin
                    rready_out           <= 1'b1;
                    ifu_to_idu_valid_out <= 1'b0;
                end
            end
            default: begin
                araddr_out           <= 32'b0;
                ifu_inst_out         <= 32'b0;
                arvalid_out          <= 1'b0;
                rready_out           <= 1'b1;
                ifu_to_idu_valid_out <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (pc_to_ifu_ready_in) begin
                next_state = S_SEND_AR;
            end
        end
        S_SEND_AR: begin
            if (arready_in) begin
                next_state = S_WAIT_INST;
            end
        end
        S_WAIT_INST: begin
            if (rvalid_in) begin
                next_state = S_WAIT_IDU;
            end
        end
        S_WAIT_IDU: begin
            if (idu_to_ifu_ready_in) begin
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

endmodule
