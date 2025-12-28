module IFU(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_inst_out,

    input               pc_to_ifu_valid_in,
    output  reg         ifu_to_pc_ready_out,

    // AR
    output  reg [3:0]   arid_out,
    output  reg [31:0]  araddr_out,
    output  reg [3:0]   arlen_out,
    output  reg [2:0]   arsize_out,
    output  reg [1:0]   arburst_out,
    output  reg         arvalid_out,
    input               arready_in,

    // R
    input       [3:0]   rid_in,
    input       [31:0]  rdata_in,
    input       [1:0]   rresp_in,
    input               rlast_in,
    input               rvalid_in,
    output  reg         rready_out,

    // AW
    output  reg [3:0]   awid_out,
    output  reg [31:0]  awaddr_out,
    output  reg [3:0]   awlen_out,
    output  reg [2:0]   awsize_out,
    output  reg [1:0]   awburst_out,
    output  reg         awvalid_out,
    input               awready_in,

    // W
    output  reg [31:0]  wdata_out,
    output  reg [3:0]   wstrb_out,
    output  reg         wlast_out,
    output  reg         wvalid_out,
    input               wready_in,

    // B
    input       [3:0]   bid_in,
    input       [1:0]   bresp_in,
    input               bvalid_in,
    output  reg         bready_out,

    output  reg         ifu_to_idu_valid_out,
    input               idu_to_ifu_ready_in,

    output  reg         bs_out,
    output  reg         br_out,
    input               bg_in
);

assign awid_out    = 4'b0;
assign awaddr_out  = 32'b0;
assign awlen_out   = 4'b0;
assign awsize_out  = 3'b0;
assign awburst_out = 2'b0;
assign awvalid_out = 1'b0;
assign wdata_out   = 32'b0;
assign wstrb_out   = 4'b0;
assign wlast_out   = 1'b0;
assign wvalid_out  = 1'b0;
assign bready_out  = 1'b0;

localparam S_IDLE      = 3'd0;
localparam S_WAIT_ARB  = 3'd1;
localparam S_SEND_AR   = 3'd2;
localparam S_WAIT_INST = 3'd3;
localparam S_WAIT_IDU  = 3'd4;

reg [2:0]   state, next_state;

reg [3:0]   rid_r;

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else state <= next_state;

    if (rst) begin
        arid_out             <= 4'b0;
        araddr_out           <= 32'b0;
        arlen_out            <= 4'b0;
        arsize_out           <= 3'b0;
        arburst_out          <= 2'b0;
        ifu_inst_out         <= 32'b0;
        arvalid_out          <= 1'b0;
        rready_out           <= 1'b0;
        ifu_to_pc_ready_out  <= 1'b1;
        ifu_to_idu_valid_out <= 1'b0;
        br_out               <= 1'b0;
        bs_out               <= 1'b0;
    end else begin
        case (state)
            S_IDLE: begin
                if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) begin
                    ifu_to_pc_ready_out <= 1'b0;
                    br_out <= 1'b1;
                end
            end
            S_WAIT_ARB: begin
                if (bg_in) begin
                    arid_out    <= 4'b0;
                    araddr_out  <= ifu_current_pc_in;
                    arlen_out   <= 4'b0;
                    arsize_out  <= 3'b010;
                    arburst_out <= 2'b01;
                    arvalid_out <= 1'b1;
                    br_out      <= 1'b0;
                    bs_out      <= 1'b1;
                end
            end
            S_SEND_AR: begin
                if (arvalid_out & arready_in) begin
                    araddr_out  <= 32'b0;
                    arlen_out   <= 4'b0;
                    arsize_out  <= 3'b0;
                    arburst_out <= 2'b0;
                    arvalid_out <= 1'b0;
                    rready_out  <= 1'b1;
                end
            end
            S_WAIT_INST: begin
                if (rvalid_in & rready_out) begin
                    rid_r                <= rid_in;
                    ifu_inst_out         <= rdata_in;
                    if (rresp_in != 2'b00) begin
                    end
                    if (rlast_in) begin
                        rready_out           <= 1'b0;
                        ifu_to_idu_valid_out <= 1'b1;
                        bs_out               <= 1'b0;
                    end else begin
                        rready_out           <= 1'b1;
                    end
                end
            end
            S_WAIT_IDU: begin
                if (idu_to_ifu_ready_in) begin
                    ifu_to_pc_ready_out  <= 1'b1;
                    ifu_to_idu_valid_out <= 1'b0;
                end
            end
            default: begin
                araddr_out           <= 32'b0;
                ifu_inst_out         <= 32'b0;
                arvalid_out          <= 1'b0;
                rready_out           <= 1'b0;
                ifu_to_idu_valid_out <= 1'b0;
                br_out               <= 1'b0;
                bs_out               <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    next_state = state;
    case (state)
        S_IDLE: begin
            if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) begin
                next_state = S_WAIT_ARB;
            end
        end
        S_WAIT_ARB: begin
            if (bg_in) begin
                next_state = S_SEND_AR;
            end
        end
        S_SEND_AR: begin
            if (arvalid_out & arready_in) begin
                next_state = S_WAIT_INST;
            end
        end
        S_WAIT_INST: begin
            if (rvalid_in & rready_out & rlast_in) begin
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
