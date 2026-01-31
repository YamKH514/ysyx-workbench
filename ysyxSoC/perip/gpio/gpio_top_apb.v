module gpio_top_apb(
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

  output [15:0] gpio_out,
  input  [15:0] gpio_in,
  output [7:0]  gpio_seg_0,
  output [7:0]  gpio_seg_1,
  output [7:0]  gpio_seg_2,
  output [7:0]  gpio_seg_3,
  output [7:0]  gpio_seg_4,
  output [7:0]  gpio_seg_5,
  output [7:0]  gpio_seg_6,
  output [7:0]  gpio_seg_7
);

  reg [ 3:0]  paddr_r;
  reg         pready_r;

  assign in_pready  = pready_r;
  assign in_pslverr = 'b0;
  assign in_prdata  = {16'b0, gpio_in};

  localparam S_W    = 2;
  localparam S_IDLE = 2'd0;
  localparam S_BUSY = 2'd1;

  reg           write_flag;
  reg [S_W-1:0] state;

// APB
  always @(posedge clock) begin
    if (reset) begin
      state     <= S_IDLE;
      paddr_r   <= 'b0;
      pready_r  <= 'b0;
      write_flag<= 'b0;
    end else begin
      case (state)
        S_IDLE: begin
          pready_r <= 'b0;
          if (in_psel) begin
            paddr_r <= in_paddr[3:0];
            write_flag<= in_pwrite;
            state <= S_BUSY;
          end
        end
        S_BUSY: begin
          if (in_penable) begin
            pready_r <= 'b1;
            write_flag<= 'b0;
            state <= S_IDLE;
          end
        end
        default: begin
          state     <= S_IDLE;
          paddr_r   <= 'b0;
          pready_r  <= 'b0;
        end
      endcase
    end
  end

  reg [15:0] led_r;
  reg [31:0] seg_r;
  assign gpio_out = led_r;

  always @(posedge clock) begin
    if (reset) begin
      led_r <= 'b0;
      seg_r <= 'b0;
    end else begin
      if (write_flag && in_penable) begin
        case (paddr_r)
          // LED
          'h0: begin
            led_r[ 7:0] <= in_pstrb[0] ? in_pwdata[ 7:0] : led_r[ 7:0];
            led_r[15:8] <= in_pstrb[1] ? in_pwdata[15:8] : led_r[15:8];
          end
          // Seg-7
          'h8: begin
            seg_r[ 7: 0] <= in_pstrb[0] ? in_pwdata[ 7: 0] : seg_r[ 7: 0];
            seg_r[15: 8] <= in_pstrb[1] ? in_pwdata[15: 8] : seg_r[15: 8];
            seg_r[23:16] <= in_pstrb[2] ? in_pwdata[23:16] : seg_r[23:16];
            seg_r[31:24] <= in_pstrb[3] ? in_pwdata[31:24] : seg_r[31:24];
          end
          default: begin
          end
        endcase
      end
    end
  end

  wire [7:0] gpio_seg_w [0:7];

  assign gpio_seg_0 = gpio_seg_w[0];
  assign gpio_seg_1 = gpio_seg_w[1];
  assign gpio_seg_2 = gpio_seg_w[2];
  assign gpio_seg_3 = gpio_seg_w[3];
  assign gpio_seg_4 = gpio_seg_w[4];
  assign gpio_seg_5 = gpio_seg_w[5];
  assign gpio_seg_6 = gpio_seg_w[6];
  assign gpio_seg_7 = gpio_seg_w[7];

// Seg-7 Driver
  genvar i;
  generate
      for (i = 0; i < 8; i = i + 1) begin: seg7_drivers
        bcd7seg u_bcd7seg(
          .b  (seg_r[i+3:i] ),
          .en (!reset       ),
          .h  (gpio_seg_w[i])
        );
      end
  endgenerate

endmodule
