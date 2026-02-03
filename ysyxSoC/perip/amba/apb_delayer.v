module apb_delayer(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output [31:0] out_paddr,
  output        out_psel,
  output        out_penable,
  output [2:0]  out_pprot,
  output        out_pwrite,
  output [31:0] out_pwdata,
  output [3:0]  out_pstrb,
  input         out_pready,
  input  [31:0] out_prdata,
  input         out_pslverr
);

  assign out_paddr   = in_paddr;
  assign out_psel    = in_psel;
  assign out_penable = in_penable;
  assign out_pprot   = in_pprot;
  assign out_pwrite  = in_pwrite;
  assign out_pwdata  = in_pwdata;
  assign out_pstrb   = in_pstrb;
  assign in_pready   = pready_r;
  assign in_prdata   = prdata_r;
  assign in_pslverr  = pslverr_r;

// NPC Max Freq = 430MHz, Devices Frep = 100MHz
// Freq ratio R = 4.3, Amplification factor S = 64

  reg         pready_r;
  reg [31:0]  prdata_r;
  reg         pslverr_r;

  localparam S_W          = 3;
  localparam S_IDLE       = 3'd0;
  localparam S_WAIT_PERIP = 3'd1;
  localparam S_DELAY      = 3'd2;

  reg [S_W-1:0] state;
  reg [31:0] delay_cnt;

  always @(posedge clock) begin
    if (reset) begin
      state <= S_IDLE;
      delay_cnt <= 32'd0;
    end else begin
      case (state)
        S_IDLE: begin
          if (in_psel) begin
            state <= S_WAIT_PERIP;
            delay_cnt <= delay_cnt + 32'd211;
          end
        end
        S_WAIT_PERIP: begin
          if (out_pready) begin
            state <= S_DELAY;
            delay_cnt <= delay_cnt >> 6;
          end else begin
            delay_cnt <= delay_cnt + 32'd211;
          end
        end
        S_DELAY: begin
          if (delay_cnt == 1) begin
            state <= S_IDLE;
            delay_cnt <= 32'd0;
          end else begin
            delay_cnt <= delay_cnt - 1;
          end
        end
        default: begin
          state <= S_IDLE;
          delay_cnt <= 32'd0;
        end
      endcase
    end
  end

  always @(posedge clock) begin
    if (reset) begin
      pready_r  <= 1'b0;
      prdata_r  <= 32'd0;
      pslverr_r <= 1'b0;
    end else begin
      pready_r  <= (state == S_DELAY) & (delay_cnt == 1);
      if (out_pready) begin
        prdata_r  <= out_prdata;
        pslverr_r <= out_pslverr;
      end
    end
  end

endmodule
