module IFU(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rst,

    input       [31:0]  ifu_current_pc_in,
    output      [31:0]  ifu_inst_out,

    input               pc_to_ifu_valid_in,
    output              ifu_to_pc_ready_out,

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

wire [3:0]   ic_arid;
wire [31:0]  ic_araddr;
wire [3:0]   ic_arlen;
wire [2:0]   ic_arsize;
wire [1:0]   ic_arburst;
wire         ic_arvalid;
wire         ic_arready = arready_in;
wire [3:0]   ic_rid = rid_in;
wire [31:0]  ic_rdata = rdata_in;
wire [1:0]   ic_rresp = rresp_in;
wire         ic_rlast = rlast_in;
wire         ic_rvalid = rvalid_in;
wire         ic_rready;
wire         ic_br;
wire         ic_bs;
wire         ic_bg;

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

localparam S_W         = 3;
localparam S_IDLE      = 3'd0;
localparam S_WAIT_ARB  = 3'd1;
localparam S_SEND_AR   = 3'd2;
localparam S_WAIT_INST = 3'd3;
localparam S_WAIT_IDU  = 3'd4;
localparam S_WAIT_IC   = 3'd5;

reg [S_W-1:0]   state;

reg [31:0]  ifu_current_pc_r;
reg [31:0]  ic_data_r;
reg [31:0]  inst_r;
reg [3:0]   rid_r;

localparam SDRAM_BASE = 32'ha0000000;
localparam SDRAM_SIZE = 32'h8000000;
wire need_cache = (SDRAM_BASE <= ifu_current_pc_r) && (ifu_current_pc_r < SDRAM_BASE + SDRAM_SIZE);

assign ifu_to_pc_ready_out = (state == S_IDLE) && pc_to_ifu_valid_in;
assign ifu_to_idu_valid_out= (state == S_WAIT_IDU);

assign br_out = (need_cache) ? ic_br : state == S_WAIT_ARB ;
assign bs_out = (need_cache) ? ic_bs:
                state == S_SEND_AR  |
                state == S_WAIT_INST;
assign ic_bg = bg_in;

assign arid_out    = bs_out ? need_cache ? ic_arid : 4'b0 : 0;
assign araddr_out  = bs_out ? need_cache ? ic_araddr : ifu_current_pc_r : 0;
assign arlen_out   = bs_out ? need_cache ? ic_arlen : 4'b0 : 0;
assign arsize_out  = bs_out ? need_cache ? ic_arsize :
                        (state == S_SEND_AR) ? 3'b010 : 3'b0 : 0;
assign arburst_out = bs_out ? need_cache ? ic_arburst :
                        (state == S_SEND_AR) ? 2'b01 : 2'b0 : 0;
assign arvalid_out = bs_out ? need_cache ? ic_arvalid :
                        (state == S_SEND_AR) : 0;
assign rready_out  = bs_out ? need_cache ? ic_rready :
                        (state == S_WAIT_INST) : 0;

assign ifu_inst_out= (need_cache) ? ic_data_r : inst_r;

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
    if (rvalid_in & rready_out & (state == S_WAIT_INST)) begin
        mem_tracer_read(ifu_current_pc_r, rdata_in);
        rid_r                <= rid_in;
        inst_r               <= rdata_in;
        if (rresp_in != 2'b00) begin
            $display("IFU rresp: %d\n", rresp_in);
            if (rresp_in == 2'b11) $fatal;
        end
    end
end

always @(posedge clk) begin
    if (rst) state <= S_IDLE;
    else begin
        case (state)
            S_IDLE: begin
                if (pc_to_ifu_valid_in & ifu_to_pc_ready_out) begin
                    state <= need_cache ? S_WAIT_IC : S_WAIT_ARB;
                end
            end
            S_WAIT_IC: begin
                if (ic_pvalid & ic_pready) begin
                    state <= S_WAIT_IDU;
                end
            end
            S_WAIT_ARB: begin
                if (bg_in) begin
                    state <= S_SEND_AR;
                end
            end
            S_SEND_AR: begin
                if (arvalid_out & arready_in) begin
                    state <= S_WAIT_INST;
                end
            end
            S_WAIT_INST: begin
                if (rvalid_in & rready_out & rlast_in) begin
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
    .clk     	(clk        ),
    .rst     	(rst        ),
    .paddr   	(ic_paddr   ),
    .pdata   	(ic_pdata   ),
    .pvalid  	(ic_pvalid  ),
    .pready  	(ic_pready  ),
    .arid    	(ic_arid    ),
    .araddr  	(ic_araddr  ),
    .arlen   	(ic_arlen   ),
    .arsize  	(ic_arsize  ),
    .arburst 	(ic_arburst ),
    .arvalid 	(ic_arvalid ),
    .arready 	(ic_arready ),
    .rid     	(ic_rid     ),
    .rdata   	(ic_rdata   ),
    .rresp   	(ic_rresp   ),
    .rlast   	(ic_rlast   ),
    .rvalid  	(ic_rvalid  ),
    .rready  	(ic_rready  ),
    .bs      	(ic_bs      ),
    .br      	(ic_br      ),
    .bg      	(ic_bg      )
);

// Perf_CNT
reg [31:0]  access_time, miss_penalty;
reg access_ready;
reg miss_ready;

always @(posedge clk) begin
    access_ready <= (state == S_WAIT_IC) && ic_arvalid && ic_rready;
    miss_ready <= (state == S_WAIT_INST) && rvalid_in && rready_out;
end

always @(posedge clk) begin
    case (state)
        S_WAIT_IC: begin
            access_time <= need_cache ? access_time + 1 : 0;
        end
        default: begin
            access_time <= 1;
        end
    endcase
end

always @(posedge clk) begin
    case (state)
        S_WAIT_IC: begin
            miss_penalty <= (ic_arvalid & ic_rready & !ic_rvalid) ? miss_penalty + 1 : 0;
        end
        S_WAIT_IDU: begin
            miss_penalty <= 0;
        end
        default: begin
            miss_penalty <= need_cache ? miss_penalty + 1 : 0;
        end
    endcase
end

endmodule
