module vga_top_apb(
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

  output [7:0]  vga_r,
  output [7:0]  vga_g,
  output [7:0]  vga_b,
  output        vga_hsync,
  output        vga_vsync,
  output        vga_valid
);

localparam H_W = 10;
localparam V_W = 10;

reg[31:0] vmem[2 ** (H_W + V_W)];

// APB
reg [H_W+V_W-1:0]  paddr_r;
reg                pready_r;

assign in_pready  = pready_r;
assign in_pslverr = 'b0;

localparam S_W    = 2;
localparam S_IDLE = 2'd0;
localparam S_BUSY = 2'd1;

reg [S_W-1:0] state;

// APB
always @(posedge clock) begin
  if (reset) begin
    state     <= S_IDLE;
    paddr_r   <= 'b0;
    pready_r  <= 'b0;
  end else begin
    case (state)
      S_IDLE: begin
        pready_r  <= 'b0;
        if (in_psel & in_pwrite) begin
          paddr_r <= in_paddr[21:2];
          state   <= S_BUSY;
        end
      end
      S_BUSY: begin
        if (in_penable) begin
          vmem[paddr_r] <= in_pwdata;
          pready_r      <= 'b1;
          state         <= S_IDLE;
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

wire  [19:0]  vga_addr;
wire  [23:0]  vga_data = vmem[vga_addr][23:0];

vga_ctrl u_vga_ctrl(
  .pclk     	(clock    ),
  .reset    	(reset    ),
  .vga_data 	(vga_data ),
  .vga_addr   (vga_addr ),
  .hsync    	(vga_hsync),
  .vsync    	(vga_vsync),
  .valid    	(vga_valid),
  .vga_r    	(vga_r    ),
  .vga_g    	(vga_g    ),
  .vga_b    	(vga_b    )
);

endmodule
