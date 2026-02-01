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

  reg [7:0] rdata_r;
  reg       read_flag;

  assign in_prdata = read_flag ? {24'b0, rdata_r} : 0;
  assign in_pready = in_psel & in_penable & !in_pwrite;

  always @(*) begin
    if (in_psel & in_pwrite) begin
      $display("PS2 Control cannot write\n");
      $fatal;
    end
  end

// PS2 Control
  reg [9:0] buffer;
  reg [3:0] count;
  reg [2:0] ps2_clk_sync;

  always @(posedge clock) begin
      ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
  end

  wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

  always @(posedge clock) begin
      if (reset) begin
          count <= 0;
      end
      else begin
          if (sampling) begin
            if (count == 4'd10) begin
              if ((buffer[0] == 0) &&
                  (ps2_data)       &&
                  (^buffer[9:1])) begin
                  read_flag <= 1;
                  rdata_r <= buffer[8:1];
              end
              count <= 0;
              read_flag <= 0;
            end else begin
              buffer[count] <= ps2_data;
              count <= count + 3'b1;
              read_flag <= 0;
            end
          end
      end
  end

endmodule
