`include "common.vh"

module LSU(
    input               clk,
    input               rstn,

    // idu_to_lsu_data lsu_r_func[8:6], lsu_re[5], lsu_w_mask[4:1], lsu_we[0]
    input       [8:0]   idu_to_lsu_data_in,
    input       [31:0]  lsu_r_addr_in,
    output  reg [31:0]  lsu_r_data_out,
    input       [31:0]  lsu_w_addr_in,
    input       [31:0]  lsu_w_data_in,

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

    input               exu_to_lsu_valid_in,
    output  reg         lsu_to_exu_ready_out,

    output  reg         lsu_to_wbu_valid_out,
    input               wbu_to_lsu_ready_in,

    output  reg         bs_out,
    output  reg         br_out,
    input               bg_in
);

reg         aw_handshake_r;
reg         w_handshake_r;

reg [2:0]   lsu_r_func_r;
reg         lsu_re_r;
reg [3:0]   lsu_w_mask_r;
reg         lsu_we_r;
assign {lsu_r_func_r, lsu_re_r, lsu_w_mask_r, lsu_we_r} = idu_to_lsu_data_in;

localparam S_IDLE     = 3'd0;
localparam S_WAIT_ARB = 3'd1;
localparam S_SEND_AR  = 3'd2;
localparam S_GET_R    = 3'd3;
localparam S_W_SEND   = 3'd4;
localparam S_GET_B    = 3'd6;
localparam S_WAIT_WBU = 3'd7;

reg [2:0] state, next_state;

always @(posedge clk) begin
    if (!rstn) state <= S_IDLE;
    else state <= next_state;

    if (!rstn) begin
        aw_handshake_r       <= 1'b0;
        w_handshake_r        <= 1'b0;
        lsu_to_exu_ready_out <= 1'b0;
        lsu_to_wbu_valid_out <= 1'b0;
        araddr_out           <= 32'b0;
        arvalid_out          <= 1'b0;
        rready_out           <= 1'b1;
        awaddr_out           <= 32'b0;
        awvalid_out          <= 1'b0;
        wdata_out            <= 32'b0;
        wstrb_out            <= 4'b0;
        wvalid_out           <= 1'b0;
        bready_out           <= 1'b0;
        br_out               <= 1'b0;
        bs_out               <= 1'b0;
    end else begin
        case (state)    
            S_IDLE: begin
                if (exu_to_lsu_valid_in) begin
                    lsu_to_exu_ready_out <= 1'b1;
                    br_out               <= 1'b1;
                end
            end
            S_WAIT_ARB: begin
                if (bg_in) begin
                    if (lsu_re_r) begin
                        araddr_out  <= lsu_r_addr_in;
                        arvalid_out <= lsu_re_r;
                    end else if (lsu_we_r) begin
                        awaddr_out  <= lsu_w_addr_in;
                        awvalid_out <= 1'b1;
                        wdata_out   <= lsu_w_data_in;
                        wstrb_out   <= lsu_w_mask_r;
                        wvalid_out  <= 1'b1;
                    end else begin
                        lsu_to_wbu_valid_out <= 1'b1;
                    end
                    br_out      <= 1'b0;
                    bs_out      <= 1'b1;
                end
            end
            S_SEND_AR: begin
                if (arready_in) begin
                    araddr_out  <= 32'b0;
                    arvalid_out <= 1'b0;
                end
            end
            S_GET_R: begin
                if (rvalid_in) begin
                    rdata_r              <= rdata_in;
                    if (rresp_in != 2'b00) begin
                    end
                    rready_out           <= 1'b0;
                    lsu_to_wbu_valid_out <= 1'b1;
                end
            end
            S_W_SEND: begin
                if (awvalid_out & awready_in) begin
                    aw_handshake_r <= 1'b1;
                    awaddr_out  <= 32'b0;
                    awvalid_out <= 1'b0;
                end
                if (wvalid_out & wready_in) begin
                    w_handshake_r <= 1'b1;
                    wdata_out   <= 32'b0;
                    wstrb_out   <= 4'b0;
                    wvalid_out  <= 1'b0;
                end
                if (aw_handshake_r & aw_handshake_r) begin
                    bready_out <= 1'b1;
                end
            end
            S_GET_B: begin
                if (bvalid_in & bready_out) begin
                    if (bresp_in != 2'b00) begin
                    end
                    bready_out <= 1'b0;
                    lsu_to_wbu_valid_out <= 1'b1;
                end
            end
            S_WAIT_WBU: begin
                if (wbu_to_lsu_ready_in) begin
                    lsu_to_wbu_valid_out <= 1'b0;
                    rready_out <= 1'b1;
                    bs_out     <= 1'b0;
                end
            end
            default: begin
                aw_handshake_r       <= 1'b0;
                w_handshake_r        <= 1'b0;
                lsu_to_exu_ready_out <= 1'b0;
                lsu_to_wbu_valid_out <= 1'b0;
                arvalid_out          <= 1'b0;
                rready_out           <= 1'b1;
                awvalid_out          <= 1'b0;
                wvalid_out           <= 1'b0;
                bready_out           <= 1'b0;
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
            if (exu_to_lsu_valid_in) begin
                next_state = S_WAIT_ARB;
            end
        end
        S_WAIT_ARB: begin
            if (bg_in) begin
                if (lsu_re_r | lsu_we_r) begin
                    next_state = S_SEND_AR & {3{lsu_re_r}} | S_W_SEND & {3{lsu_we_r}};
                end else begin
                    next_state = S_WAIT_WBU;
                end
            end
        end
        S_SEND_AR: begin
            if (arready_in) begin
                next_state = S_GET_R;
            end
        end
        S_GET_R: begin
            if (rvalid_in) begin
                next_state = S_WAIT_WBU;
            end
        end
        S_W_SEND: begin
            if (aw_handshake_r & w_handshake_r) begin
                next_state = S_GET_B;
            end
        end
        S_GET_B: begin
            if (bvalid_in) begin
                next_state = S_WAIT_WBU;
            end
        end
        S_WAIT_WBU: begin
            if (wbu_to_lsu_ready_in) begin
                next_state = S_IDLE;
            end
        end
        default: begin
            next_state = S_IDLE;
        end
    endcase
end

reg     [31:0]  rdata_r;
reg     [1:0]   byte_off_r;
wire    [7:0]   data_b;
wire    [15:0]  data_h;

assign byte_off_r = lsu_r_addr_in[1:0];

assign data_b = {8{byte_off_r == 2'b00}} & rdata_r[7:0]  |
                {8{byte_off_r == 2'b01}} & rdata_r[15:8] |
                {8{byte_off_r == 2'b10}} & rdata_r[23:16]|
                {8{byte_off_r == 2'b11}} & rdata_r[31:24];

assign data_h = byte_off_r[1] == 1'b0 ? rdata_r[15:0] : rdata_r[31:16];

assign lsu_r_data_out = {32{lsu_r_func_r == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LW}}  & rdata_r;

endmodule
