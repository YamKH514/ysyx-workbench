`define FOR_SIMULATION_ENV

module IFU(
    input         clk,
    input         rst,

    input  [31:0] pc_i,
    output [31:0] ifu_pc_o,
    output [31:0] ifu_inst_o,

    input         pc_ifu_valid_i,
    output        pc_ifu_ready_o,

    output        ifu_idu_valid_o,
    input         ifu_idu_ready_i,

    output [ 9:0] ifu_gpr_raddr_o,

    output [11:0] ifu_csr_raddr_o,

    input         fence_i_i,
    input         need_flush_i,

    output [ 3:0] arid_o,
    output [31:0] araddr_o,
    output [ 3:0] arlen_o,
    output [ 2:0] arsize_o,
    output [ 1:0] arburst_o,
    output        arvalid_o,
    input         arready_i,
    input  [ 3:0] rid_i,
    input  [31:0] rdata_i,
    input  [ 1:0] rresp_i,
    input         rlast_i,
    input         rvalid_i,
    output        rready_o,

    output [ 3:0] awid_o,
    output [31:0] awaddr_o,
    output [ 3:0] awlen_o,
    output [ 2:0] awsize_o,
    output [ 1:0] awburst_o,
    output        awvalid_o,
    input         awready_i,
    output [31:0] wdata_o,
    output [ 3:0] wstrb_o,
    output        wlast_o,
    output        wvalid_o,
    input         wready_i,
    input  [ 3:0] bid_i,
    input  [ 1:0] bresp_i,
    input         bvalid_i,
    output        bready_o,

    output        bs_o,
    output        br_o,
    input         bg_i
);

reg [31:0]  ifu_current_pc_r;
reg [31:0]  ic_data_r;

assign ifu_gpr_raddr_o = ic_data_r[24:15];
assign ifu_csr_raddr_o = ic_data_r[31:20];

import "DPI-C" function void mem_tracer_read(input int addr,input int data, input int is_inst);

wire [29:0] ic_paddr = ifu_current_pc_r[31:2];
wire [31:0] ic_pdata;
wire        ic_pvalid = state == S_WAIT_IC;
wire        ic_pready;

assign awid_o    = 4'b0;
assign awaddr_o  = 32'b0;
assign awlen_o   = 4'b0;
assign awsize_o  = 3'b0;
assign awburst_o = 2'b0;
assign awvalid_o = 1'b0;
assign wdata_o   = 32'b0;
assign wstrb_o   = 4'b0;
assign wlast_o   = 1'b0;
assign wvalid_o  = 1'b0;
assign bready_o  = 1'b0;

localparam S_W         = 2;
localparam S_IDLE      = 2'd0;
localparam S_WAIT_IC   = 2'd1;
localparam S_WAIT_IDU  = 2'd2;

reg [S_W-1:0]   state;

wire need_cache = pc_i[31-:4] == 4'ha && pc_i[27-:4] < 4'h9;
reg  need_cache_r;

always @(posedge clk) begin
    if (rst) begin
        need_cache_r <= 0;
    end else if (state == S_IDLE) begin
        if (pc_ifu_valid_i & pc_ifu_ready_o) need_cache_r <= need_cache;
    end
end

assign pc_ifu_ready_o = (state == S_IDLE) && pc_ifu_valid_i;
assign ifu_idu_valid_o= (state == S_WAIT_IDU) & !need_flush_i;

assign ifu_pc_o = ifu_current_pc_r;
assign ifu_inst_o= ic_data_r;

always @(posedge clk) begin
    if (rst) begin
        ic_data_r <= 0;
    end else if (ic_pvalid & ic_pready) begin
        ic_data_r <= ic_pdata;
    end
end

always @(posedge clk) begin
    if (rst) begin
        ifu_current_pc_r <= 32'b0;
    end else if (pc_ifu_valid_i & pc_ifu_ready_o) begin
        ifu_current_pc_r <= pc_i;
    end
end

always @(posedge clk) begin
    if (ic_pvalid & ic_pready & (state == S_WAIT_IC)) begin
        mem_tracer_read(ifu_current_pc_r, ic_pdata, 32'b1);
    end
end

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else begin
        case (state)
            S_IDLE: begin
                if (!need_flush_i & pc_ifu_valid_i & pc_ifu_ready_o) begin
                    state <= S_WAIT_IC;
                end
            end
            S_WAIT_IC: begin
                if (ic_pvalid & ic_pready) begin
                    state <= need_flush_r ? S_IDLE : S_WAIT_IDU;
                end
            end
            S_WAIT_IDU: begin
                if (need_flush_i | (ifu_idu_valid_o && ifu_idu_ready_i)) begin
                    state <= S_IDLE;
                end
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

reg need_flush_r;

always @(posedge clk) begin
    if (rst)
        need_flush_r <= 1'b0;
    else if (need_flush_i)
        need_flush_r <= state == S_WAIT_IC;
    else if (state == S_IDLE)
        need_flush_r <= 1'b0;
end

ICache_top u_ICache_top(
    .clk     	(clk         ),
    .rst     	(rst         ),
    .paddr   	(ic_paddr    ),
    .pdata   	(ic_pdata    ),
    .pvalid  	(ic_pvalid   ),
    .pready  	(ic_pready   ),
    .need_cache (need_cache_r),
    .fence_i    (fence_i_i   ),
    .arid    	(arid_o      ),
    .araddr  	(araddr_o    ),
    .arlen   	(arlen_o     ),
    .arsize  	(arsize_o    ),
    .arburst 	(arburst_o   ),
    .arvalid 	(arvalid_o   ),
    .arready 	(arready_i   ),
    .rid     	(rid_i       ),
    .rdata   	(rdata_i     ),
    .rresp   	(rresp_i     ),
    .rlast   	(rlast_i     ),
    .rvalid  	(rvalid_i    ),
    .rready  	(rready_o    ),
    .bs      	(bs_o        ),
    .br      	(br_o        ),
    .bg      	(bg_i        )
);

`ifdef FOR_SIMULATION_ENV
export "DPI-C" function ifu_commit;
function int ifu_commit();
    if (pc_ifu_ready_o) return 1;
    else return 0;
endfunction
`endif

endmodule
