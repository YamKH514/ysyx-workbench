module IFU(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    input       [31:0]  ifu_current_pc_in,
    output      [31:0]  ifu_inst_out,

    input               pc_to_ifu_valid_in,
    output              ifu_to_pc_ready_out,

    input               fence_i_in,

    // AR
    output      [3:0]   arid_out,
    output      [31:0]  araddr_out,
    output      [3:0]   arlen_out,
    output      [2:0]   arsize_out,
    output      [1:0]   arburst_out,
    output              arvalid_out,
    input               arready_in,

    // R
    input       [3:0]   rid_in,
    input       [31:0]  rdata_in,
    input       [1:0]   rresp_in,
    input               rlast_in,
    input               rvalid_in,
    output              rready_out,

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

    output              ifu_to_idu_valid_out,
    input               idu_to_ifu_ready_in,

    output  reg         bs_out,
    output  reg         br_out,
    input               bg_in
);

import "DPI-C" function void mem_tracer_read(input int addr,input int data);

wire [29:0] ic_paddr = ifu_current_pc_r[31:2];
wire [31:0] ic_pdata;
wire        ic_pvalid = state == S_WAIT_IC;
wire        ic_pready;

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

localparam S_W         = 2;
localparam S_IDLE      = 2'd0;
localparam S_WAIT_IDU  = 2'd1;
localparam S_WAIT_IC   = 2'd2;

reg [S_W-1:0]   state;

reg [31:0]  ifu_current_pc_r;
reg [31:0]  ic_data_r;
reg [31:0]  inst_r;
reg [3:0]   rid_r;

wire need_cache = ifu_current_pc_in[31-:4] == 4'ha && ifu_current_pc_in[27-:4] < 4'h9;
reg  need_cache_r;

always @(posedge clk) begin
    if (rst) begin
        need_cache_r <= 0;
    end else if (state == S_IDLE) begin
        if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) need_cache_r <= need_cache;
    end
end

assign ifu_to_pc_ready_out = (state == S_IDLE) && pc_to_ifu_valid_in;
assign ifu_to_idu_valid_out= (state == S_WAIT_IDU);

assign ifu_inst_out= ic_data_r;

always @(posedge clk) begin
    if (rst) begin
        ic_data_r <= 0;
    end else if (ic_pvalid & ic_pready) begin
        ic_data_r <= ic_pdata;
    end
end

always @(posedge clk) begin
    if (rst) begin
        ifu_current_pc_r     <= 32'b0;
    end else if (state == S_IDLE) begin
        if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) begin
            ifu_current_pc_r    <= ifu_current_pc_in;
        end
    end
end

always @(posedge clk) begin
    if (ic_pvalid & ic_pready & (state == S_WAIT_IC)) begin
        mem_tracer_read(ifu_current_pc_r, ic_pdata);
    end
end

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else begin
        case (state)
            S_IDLE: begin
                if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) begin
                    state <= S_WAIT_IC;
                end
            end
            S_WAIT_IC: begin
                if (ic_pvalid & ic_pready) begin
                    state <= S_WAIT_IDU;
                end
            end
            S_WAIT_IDU: begin
                if (ifu_to_idu_valid_out && idu_to_ifu_ready_in) begin
                    state <= S_IDLE;
                end
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

ICache_top u_ICache_top(
    .clk     	(clk         ),
    .rst     	(rst         ),
    .paddr   	(ic_paddr    ),
    .pdata   	(ic_pdata    ),
    .pvalid  	(ic_pvalid   ),
    .pready  	(ic_pready   ),
    .need_cache (need_cache_r),
    .fence_i    (fence_i_in  ),
    .arid    	(arid_out    ),
    .araddr  	(araddr_out  ),
    .arlen   	(arlen_out   ),
    .arsize  	(arsize_out  ),
    .arburst 	(arburst_out ),
    .arvalid 	(arvalid_out ),
    .arready 	(arready_in  ),
    .rid     	(rid_in      ),
    .rdata   	(rdata_in    ),
    .rresp   	(rresp_in    ),
    .rlast   	(rlast_in    ),
    .rvalid  	(rvalid_in   ),
    .rready  	(rready_out  ),
    .bs      	(bs_out      ),
    .br      	(br_out      ),
    .bg      	(bg_in       )
);

endmodule
