module ps2_top_apb(
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

  input         ps2_clk,
  input         ps2_data
);

  reg   pready_r;

  assign in_prdata  = {24'b0, data};
  assign in_pready  = pready_r;
  assign in_pslverr = 'b0;

  localparam S_W      = 2;
  localparam S_IDLE   = 2'd0;
  localparam S_BUSY   = 2'd1;
  localparam S_UPDATE = 2'd2;

  reg [S_W-1:0] state;

// APB
  always @(posedge clock) begin
    if (reset) begin
      state     <= S_IDLE;
      pready_r  <= 'b0;
    end else begin
      case (state)
        S_IDLE: begin
          pready_r <= 'b0;
          if (in_psel) begin
            state <= S_BUSY;
          end
        end
        S_BUSY: begin
          if (in_penable & ps2_ready) begin
            pready_r <= 'b1;
            state <= S_UPDATE;
          end else begin
            pready_r <= 'b0;
            state <= in_penable ? S_BUSY : S_IDLE;
          end
        end
        S_UPDATE: begin
          state <= in_psel ? S_BUSY : S_IDLE;
        end
        default: begin
          state     <= S_IDLE;
          pready_r  <= 'b0;
        end
      endcase
    end
  end

  always @(posedge clock) begin
    if (in_psel & in_pwrite) begin
      $display("PS2 Keyboard Controler cannot input\n");
      $fatal;
    end
  end

  wire  [7:0] data;
  wire        ps2_ready;
  wire        ps2_nextdata;
  wire        ps2_overflow;

  assign ps2_nextdata = ~(state == S_UPDATE);

  ps2_kbd u_ps2_kbd(
    .clk        	(clock        ),
    .clrn       	(~reset       ),
    .ps2_clk    	(ps2_clk      ),
    .ps2_data   	(ps2_data     ),
    .nextdata_n 	(ps2_nextdata ),
    .data       	(data         ),
    .ready      	(ps2_ready    ),
    .overflow   	(ps2_overflow )
  );
  

endmodule
