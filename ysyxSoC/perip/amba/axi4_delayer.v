module axi4_delayer(
  input         clock,
  input         reset,

  output        in_arready,
  input         in_arvalid,
  input  [3:0]  in_arid,
  input  [31:0] in_araddr,
  input  [7:0]  in_arlen,
  input  [2:0]  in_arsize,
  input  [1:0]  in_arburst,
  input         in_rready,
  output        in_rvalid,
  output [3:0]  in_rid,
  output [31:0] in_rdata,
  output [1:0]  in_rresp,
  output        in_rlast,
  output        in_awready,
  input         in_awvalid,
  input  [3:0]  in_awid,
  input  [31:0] in_awaddr,
  input  [7:0]  in_awlen,
  input  [2:0]  in_awsize,
  input  [1:0]  in_awburst,
  output        in_wready,
  input         in_wvalid,
  input  [31:0] in_wdata,
  input  [3:0]  in_wstrb,
  input         in_wlast,
                in_bready,
  output        in_bvalid,
  output [3:0]  in_bid,
  output [1:0]  in_bresp,

  input         out_arready,
  output        out_arvalid,
  output [3:0]  out_arid,
  output [31:0] out_araddr,
  output [7:0]  out_arlen,
  output [2:0]  out_arsize,
  output [1:0]  out_arburst,
  output        out_rready,
  input         out_rvalid,
  input  [3:0]  out_rid,
  input  [31:0] out_rdata,
  input  [1:0]  out_rresp,
  input         out_rlast,
  input         out_awready,
  output        out_awvalid,
  output [3:0]  out_awid,
  output [31:0] out_awaddr,
  output [7:0]  out_awlen,
  output [2:0]  out_awsize,
  output [1:0]  out_awburst,
  input         out_wready,
  output        out_wvalid,
  output [31:0] out_wdata,
  output [3:0]  out_wstrb,
  output        out_wlast,
                out_bready,
  input         out_bvalid,
  input  [3:0]  out_bid,
  input  [1:0]  out_bresp
);

  assign in_arready = out_arready;
  assign out_arvalid = in_arvalid;
  assign out_arid = in_arid;
  assign out_araddr = in_araddr;
  assign out_arlen = in_arlen;
  assign out_arsize = in_arsize;
  assign out_arburst = in_arburst;
  assign out_rready = (r_state == S_DELAY) & (r_delay_cnt == 1);
  assign in_rvalid = out_rvalid;
  assign in_rid = out_rid;
  assign in_rdata = out_rdata;
  assign in_rresp = out_rresp;
  assign in_rlast = out_rlast;
  assign in_awready = out_awready;
  assign out_awvalid = in_awvalid;
  assign out_awid = in_awid;
  assign out_awaddr = in_awaddr;
  assign out_awlen = in_awlen;
  assign out_awsize = in_awsize;
  assign out_awburst = in_awburst;
  assign in_wready = out_wready;
  assign out_wvalid = in_wvalid;
  assign out_wdata = in_wdata;
  assign out_wstrb = in_wstrb;
  assign out_wlast = in_wlast;
  assign out_bready = bready_r;
  assign in_bvalid = out_bvalid;
  assign in_bid = out_bid;
  assign in_bresp = out_bresp;

// NPC Max Freq = 430MHz, Devices Frep = 100MHz
// Freq ratio R = 4.3, Amplification factor S = 64

  localparam S_W          = 3;
  localparam S_IDLE       = 3'd0;
  localparam S_WAIT_PERIP = 3'd1;
  localparam S_DELAY      = 3'd2;

// R Channel
  // reg           rready_r;

  reg [S_W-1:0] r_state;
  reg [S_W-1:0] r_target_state;
  reg [31:0]    r_delay_cnt;

  always @(posedge clock) begin
    if (reset) begin
      r_state <= S_IDLE;
      r_target_state <= S_IDLE;
      r_delay_cnt <= 32'd0;
    end else begin
      case (r_state)
        S_IDLE: begin
          if (in_arvalid) begin
            r_state <= S_WAIT_PERIP;
            r_delay_cnt <= r_delay_cnt + 32'd211;
          end
        end
        S_WAIT_PERIP: begin
          if (in_rready) begin
            r_state <= S_DELAY;
            r_target_state <= out_rlast ? S_IDLE : S_WAIT_PERIP;
            r_delay_cnt <= r_delay_cnt >> 6;
          end else begin
            r_delay_cnt <= r_delay_cnt + 32'd211;
          end
        end
        S_DELAY: begin
          if (r_delay_cnt == 1) begin
            r_state <= r_target_state;
            r_delay_cnt <= 32'd0;
          end else begin
            r_delay_cnt <= r_delay_cnt - 1;
          end
        end
        default: begin
          r_state <= S_IDLE;
          r_target_state <= S_IDLE;
          r_delay_cnt <= 32'd0;
        end
      endcase
    end
  end

// always @(posedge clock) begin
//   if (reset) begin
//     rready_r <= 0;
//   end else begin
//     rready_r <= (r_state == S_DELAY) & (r_delay_cnt == 1);
//   end
// end

// W Channel
  reg           bready_r;

  reg [S_W-1:0] w_state;
  reg [31:0]    w_delay_cnt;

  always @(posedge clock) begin
    if (reset) begin
      w_state <= S_IDLE;
      w_delay_cnt <= 32'd0;
    end else begin
      case (w_state)
        S_IDLE: begin
          if (in_awvalid) begin
            w_state <= S_WAIT_PERIP;
            w_delay_cnt <= w_delay_cnt + 32'd211;
          end
        end
        S_WAIT_PERIP: begin
          if (in_bready) begin
            w_state <= S_DELAY;
            w_delay_cnt <= w_delay_cnt >> 6;
          end else begin
            w_delay_cnt <= w_delay_cnt + 32'd211;
          end
        end
        S_DELAY: begin
          if (w_delay_cnt == 1) begin
            w_state <= S_IDLE;
            w_delay_cnt <= 32'd0;
          end else begin
            w_delay_cnt <= w_delay_cnt - 1;
          end
        end
        default: begin
          w_state <= S_IDLE;
          w_delay_cnt <= 32'd0;
        end
      endcase
    end
  end

  always @(posedge clock) begin
    if (reset) begin
      bready_r <= 0;
    end else begin
      bready_r <= (w_state == S_DELAY) & (w_delay_cnt == 1);
    end
  end

endmodule
