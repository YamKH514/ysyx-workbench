// define this macro to enable fast behavior simulation
// for flash by skipping SPI transfers
//`define FAST_FLASH

module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
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

  output                  spi_sck,
  output [spi_ss_num-1:0] spi_ss,
  output                  spi_mosi,
  input                   spi_miso,
  output                  spi_irq_out
);

localparam SPI_BASE = 32'h10001000;
localparam SPI_RX_0_R = 32'h00;
localparam SPI_RX_1_R = 32'h04;
localparam SPI_TX_0_R = 32'h00;
localparam SPI_TX_1_R = 32'h04;
localparam SPI_CTRL_R = 32'h10;
localparam SPI_DIVIDER_R = 32'h14;
localparam SPI_SS_R = 32'h18;

localparam SPI_DIV_SET = 32'h1;
localparam SPI_SS_FLASH = 32'h1;

wire [31:0] paddr;
wire        psel;
wire        penable;
wire [2:0]  pprot;
wire        pwrite;
wire [31:0] pwdata;
wire [3:0]  pstrb;
wire        pready;
wire [31:0] prdata;
wire        pslverr;

reg  [31:0] xpi_paddr;
reg         xpi_psel;
reg         xpi_penable;
reg  [2:0]  xpi_pprot;
reg         xpi_pwrite;
reg  [31:0] xpi_pwdata;
reg  [3:0]  xpi_pstrb;
reg         xpi_pready;
reg  [31:0] xpi_prdata;
reg         xpi_pslverr;
reg  [3:0]  flash_strb;

assign paddr = in_flash ? xpi_paddr : in_paddr;
assign psel = in_flash ? xpi_psel : in_psel;
assign penable = in_flash ? xpi_penable : in_penable;
assign pprot = in_flash ? xpi_pprot : in_pprot;
assign pwrite = in_flash ? xpi_pwrite : in_pwrite;
assign pwdata = in_flash ? xpi_pwdata : in_pwdata;
assign pstrb = in_flash ? xpi_pstrb : in_pstrb;
assign in_pready = in_flash ? xpi_pready : pready;
assign in_prdata = in_flash ? xpi_prdata : prdata;
assign in_pslverr = in_flash ? xpi_pslverr : pslverr;

wire in_flash = (flash_addr_start <= in_paddr) && (in_paddr < flash_addr_end);
wire xpi_start = in_flash && in_psel && !in_penable;
always @(*) begin
  if (in_flash && in_pwrite) begin
    $display("Assertion failed: Unsupport command, only support `03h` read command\n");
    $fatal;
  end
end

localparam S_IDLE = 3'd0;
localparam S_XPI_SET_INST = 3'd1;
localparam S_XPI_SET_DIV = 3'd2;
localparam S_XPI_SET_SS = 3'd3;
localparam S_XPI_SET_CTRL = 3'd4;
localparam S_XPI_WAIT = 3'd5;
localparam S_XPI_GET_DATA = 3'd6;
localparam S_XPI_SEND_DATA = 3'd7;
reg [2:0] state, next_state;
reg       apb_state; // SETUP=0, ACCESS=1


always @(posedge clock) begin
  if (reset) state <= S_IDLE;
  else state <= next_state;

  if (reset) begin
    xpi_paddr <= 32'b0;
    xpi_psel <= 1'b0;
    xpi_penable <= 1'b0;
    xpi_pprot <= 3'b0;
    xpi_pwrite <= 1'b0;
    xpi_pwdata <= 32'b0;
    xpi_pstrb <= 4'b0;
    xpi_pready <= 1'b0;
    xpi_prdata <= 32'b0;
    xpi_pslverr <= 1'b0;
    apb_state <= 1'b0;
    flash_strb <= 4'b0;
  end else begin
    case (state)
      S_IDLE: begin
        if (xpi_start) begin
          xpi_paddr <= SPI_BASE + SPI_TX_1_R;
          xpi_pwrite <= 1'b1;
          xpi_psel <= 1'b1;
          xpi_penable <= apb_state;
          xpi_pwdata <= {8'h03, in_paddr[23:2], 2'b00};
          xpi_pstrb <= 4'hF;
          xpi_pprot <= 3'b001;
          flash_strb <= in_pstrb;
        end
        if (xpi_start & !apb_state) apb_state <= 1'b1;
      end
      S_XPI_SET_INST: begin
        xpi_paddr <= SPI_BASE + SPI_TX_1_R;
        xpi_pwrite <= 1'b1;
        xpi_psel <= 1'b1;
        xpi_penable <= (xpi_penable && pready) ? 1'b0 : apb_state;
        xpi_pwdata <= {8'h03, in_paddr[23:0]};
        xpi_pstrb <= 4'hF;
        xpi_pprot <= 3'b001;
        if (xpi_penable && pready) apb_state <= 1'b0;
      end
      S_XPI_SET_DIV: begin
        xpi_paddr <= SPI_BASE + SPI_DIVIDER_R;
        xpi_pwrite <= 1'b1;
        xpi_psel <= 1'b1;
        xpi_penable <= (xpi_penable && pready) ? 1'b0 : apb_state;
        xpi_pwdata <= SPI_DIV_SET;
        xpi_pstrb <= 4'h3;
        xpi_pprot <= 3'b001;
        if (xpi_penable && pready) apb_state <= 1'b0;
        else if (!apb_state) apb_state <= 1'b1;
      end
      S_XPI_SET_SS: begin
        xpi_paddr <= SPI_BASE + SPI_SS_R;
        xpi_pwrite <= 1'b1;
        xpi_psel <= 1'b1;
        xpi_penable <= (xpi_penable && pready) ? 1'b0 : apb_state;
        xpi_pwdata <= SPI_SS_FLASH;
        xpi_pstrb <= 4'h1;
        xpi_pprot <= 3'b001;
        if (xpi_penable && pready) apb_state <= 1'b0;
        else if (!apb_state) apb_state <= 1'b1;
      end
      S_XPI_SET_CTRL: begin
        xpi_paddr <= SPI_BASE + SPI_CTRL_R;
        xpi_pwrite <= 1'b1;
        xpi_psel <= (xpi_penable && pready) ? 1'b0 : 1'b1;
        xpi_penable <= (xpi_penable && pready) ? 1'b0 : apb_state;
        xpi_pwdata <= 32'h3540;
        xpi_pstrb <= 4'hF;
        xpi_pprot <= 3'b001;
        if (xpi_penable && pready) apb_state <= 1'b0;
        else if (!apb_state) apb_state <= 1'b1;
      end
      S_XPI_WAIT: begin
      end
      S_XPI_GET_DATA: begin
        xpi_paddr <= SPI_BASE + SPI_RX_0_R;
        xpi_pwrite <= 1'b0;
        xpi_psel <= (xpi_penable && pready) ? 1'b0 : 1'b1;
        xpi_penable <= (xpi_penable && pready) ? 1'b0 : apb_state;
        xpi_pstrb <= 4'h0;
        xpi_pprot <= 3'b001;
        if (xpi_penable && pready) begin
          case (flash_strb)
            4'b0001: xpi_prdata <= {24'b0, prdata[31:24]};
            4'b0010: xpi_prdata <= {24'b0, prdata[23:16]};
            4'b0100: xpi_prdata <= {24'b0, prdata[15:8]};
            4'b1000: xpi_prdata <= {24'b0, prdata[7:0]};
            4'b0011: xpi_prdata <= {16'b0, prdata[31:16]};
            4'b1100: xpi_prdata <= {16'b0, prdata[15:0]};
            4'b1111: xpi_prdata <= {prdata[7:0], prdata[15:8], prdata[23:16], prdata[31:24]};
            default: xpi_prdata <= {prdata[7:0], prdata[15:8], prdata[23:16], prdata[31:24]};
          endcase
          xpi_pslverr <= pslverr;
        end
        if (xpi_penable && pready) apb_state <= 1'b0;
        else if (!apb_state) apb_state <= 1'b1;
      end
      S_XPI_SEND_DATA: begin
        if (in_penable) begin
          xpi_pready <= (in_penable && in_pready) ? 1'b0 : 1'b1;
        end
      end
    endcase
  end
end

always @(*) begin
  next_state = state;
  if (in_flash) begin
    // XPI
    case (state)
      S_IDLE: begin
        if (xpi_start) next_state = S_XPI_SET_INST;
      end
      S_XPI_SET_INST: begin
        if (xpi_penable && pready) next_state = S_XPI_SET_DIV;
      end
      S_XPI_SET_DIV: begin
        if (xpi_penable && pready) next_state = S_XPI_SET_SS;
      end
      S_XPI_SET_SS: begin
        if (xpi_penable && pready) next_state = S_XPI_SET_CTRL;
      end
      S_XPI_SET_CTRL: begin
        if (xpi_penable && pready) next_state = S_XPI_WAIT;
      end
      S_XPI_WAIT: begin
        if (spi_irq_out) next_state = S_XPI_GET_DATA;
      end
      S_XPI_GET_DATA: begin
        if (xpi_penable && pready) next_state = S_XPI_SEND_DATA;
      end
      S_XPI_SEND_DATA: begin
        if (in_penable && in_pready) next_state = S_IDLE;
      end
      default: begin
        next_state = S_IDLE;
      end
    endcase
  end
end

`ifdef FAST_FLASH

wire [31:0] data;
parameter invalid_cmd = 8'h0;
flash_cmd flash_cmd_i(
  .clock(clock),
  .valid(in_psel && !in_penable),
  .cmd(in_pwrite ? invalid_cmd : 8'h03),
  .addr({8'b0, in_paddr[23:2], 2'b0}),
  .data(data)
);
assign spi_sck    = 1'b0;
assign spi_ss     = 8'b0;
assign spi_mosi   = 1'b1;
assign spi_irq_out= 1'b0;
assign in_pslverr = 1'b0;
assign in_pready  = in_penable && in_psel && !in_pwrite;
assign in_prdata  = data[31:0];

`else

spi_top u0_spi_top (
  .wb_clk_i(clock),
  .wb_rst_i(reset),
  .wb_adr_i(paddr[4:0]),
  .wb_dat_i(pwdata),
  .wb_dat_o(prdata),
  .wb_sel_i(pstrb),
  .wb_we_i (pwrite),
  .wb_stb_i(psel),
  .wb_cyc_i(penable),
  .wb_ack_o(pready),
  .wb_err_o(pslverr),
  .wb_int_o(spi_irq_out),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

`endif // FAST_FLASH

endmodule
